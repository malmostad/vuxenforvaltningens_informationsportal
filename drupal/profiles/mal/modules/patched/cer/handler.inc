<?php

/**
 * @file
 * Contains base code for CER handlers, which are objects responsible for
 * creating, updating and deleting corresponding references between entities.
 */

/**
 * Exception related to CER operations.
 */
class CerException extends Exception {
}

interface CerHandlerInterface {

  /**
   * @constructor
   *
   * @param string $preset
   *  The CER preset string, in the format:
   *  entity_a*bundle_a*field_a*entity_b*bundle_b*field_b.
   *
   * @param $entity.
   *  The local (home) entity to be wrapped by this instance.
   */
  public function __construct($preset, $entity);

  /**
   * Create reciprocal references on referenced entities after the
   * local entity has been created.
   */
  public function insert();

  /**
   * Delete reciprocal references on entities the local entity is no
   * longer referencing, and create new reciprocal references, after
   * the local entity has been updated.
   */
  public function update();

  /**
   * Delete all reciprocal references after the local entity is deleted.
   */
  public function delete();
  
  /**
   * Check if $entity is referenced by the local entity.
   *
   * @param object $entity
   *  The remote entity.
   *
   * @return boolean
   */
  public function references($entity);

  /**
   * Check if the local entity is referenced by $entity.
   *
   * @param object $entity
   *  The remote entiy.
   *
   * @return boolean
   */
  public function referencedBy($entity);
  
  /**
   * Check if the remote entity can reference the local entity, and vice-versa.
   *
   * @param object $entity
   *  The remote entity.
   *
   * @return boolean
   */
  public function referenceable($entity);

  /**
   * Create a reference to the local entity on the remote entity, and vice-versa
   * if needed. Should throw CerException if the reference(s) can't be created
   * for any reason.
   *
   * @param object $entity
   */
  public function reference($entity);

  /**
   * Delete all references to the remote entity from the local entity,
   * and delete reciprocal references from the remote entity.
   *
   * @param object $entity.
   */
  public function dereference($entity);

}

/**
 * @class
 * Base class for CER handlers. All this does is parse the preset
 * and store instance info about the local and remote fields.
 */
abstract class CerHandlerBase {

  /**
   * Local field instance definition.
   */
  protected $local;

  /**
   * Remote field instance definition.
   */
  protected $remote;

  public function __construct($preset) {
    $keys = explode('*', $preset);

    if (sizeof($keys) != 6) {
      throw new CerException(t('Invalid configuration: @preset', array('@preset' => $preset)));
    }

    $this->local = field_info_instance($keys[0], $keys[2], $keys[1]);
    if ($this->local) {
      $this->local['field'] = field_info_field($keys[2]);
    }
    else {
      throw new CerException(t('Local field instance does not exist.'));
    }

    $this->remote = field_info_instance($keys[3], $keys[5], $keys[4]);
    if ($this->remote) {
      $this->remote['field'] = field_info_field($keys[5]);
    }
    else {
      throw new CerException(t('Remote field instance does not exist.'));
    }
  }

}

/**
 * @class
 * Generic CER handler with rudimentary language handling.
 */
class CerHandler extends CerHandlerBase implements CerHandlerInterface {

  /**
   * The local (home) entity.
   */
  protected $entity;

  /**
   * The local entity's ID.
   */
  protected $id;

  /**
   * Implements CerHandlerInterface::__construct().
   */
  public function __construct($preset, $entity) {
    parent::__construct($preset);

    // If $entity is of the wrong type, entity_extract_IDs()
    // will throw EntityMalformedException here.
    $extract_ids = entity_extract_IDs($this->local['entity_type'], $entity);
    $this->id = array_shift($extract_ids);

    $this->entity = $entity;
  }

  /**
   * Implements CerHandlerInterface::insert().
   */
  public function insert($ids = NULL) {

    if (empty($ids)) {
      $entities = $this->getReferencedEntities();
    }
    else {
      $entities = entity_load($this->remote['entity_type'], $ids);
    }

    foreach ($entities as $referenced_entity) {
      $this->reference($referenced_entity);
      _cer_update($this->remote['entity_type'], $referenced_entity);
    }
  }

  /**
   * Implements CerHandlerInterface::update().
   */
  public function update() {
    $original = isset($this->entity->original) ? $this->entity->original : $this->entity;

    $deleted = array_diff($this->getReferenceIDs($original, $this->local), $this->getLocalReferenceIDs());
    if ($deleted) {
      $entities = entity_load($this->remote['entity_type'], $deleted);
      foreach ($entities as $referenced_entity) {
        $this->dereference($referenced_entity);
        _cer_update($this->remote['entity_type'], $referenced_entity);
      }
    }

    $added = array_diff($this->getLocalReferenceIDs(), $this->getReferenceIDs($original, $this->local));

    if (!empty($added)) {
      $this->insert($added);
    }
  }

  /**
   * Implements CerHandlerInterface::delete().
   */
  public function delete() {
    foreach ($this->getReferencedEntities() as $referenced_entity) {
      $this->dereference($referenced_entity);
      _cer_update($this->remote['entity_type'], $referenced_entity);
    }
  }

  /**
   * Implements CerHandlerInterface::references().
   */  
  public function references($entity) {
    return in_array($this->getRemoteEntityID($entity), $this->getLocalReferenceIDs());
  }

  /**
   * Implements CerHandlerInterface::referencedBy().
   */
  public function referencedBy($entity) {
    return in_array($this->id, $this->getRemoteReferenceIDs($entity));
  }

  /**
   * Implements CerHandlerInterface::referenceable().
   */
  public function referenceable($entity) {
    $id = $this->getRemoteEntityID($entity);

    $allowed = array(
      entityreference_get_selection_handler(
        $this->local['field'],
        $this->local,
        $this->local['entity_type'],
        $this->entity
      )
        ->validateReferencableEntities(array($id)),
      entityreference_get_selection_handler(
        $this->remote['field'],
        $this->remote,
        $this->remote['entity_type'],
        $entity
      )
        ->validateReferencableEntities(array($this->id)),
    );

    return in_array($id, $allowed[0]) && in_array($this->id, $allowed[1]);
  }

  /**
   * Implements CerHandlerInterface::reference().
   */
  public function reference($entity) {
    if ($this->referenceable($entity)) {
      try {
        $this->addReferenceTo($entity);
      }
      catch (CerException $e) {
        // Fail silently
      }
    
      try {
        $this->addReferenceFrom($entity);
      }
      catch (CerException $e) {
        // Fail silently
      }
    }
    else {
      $variables = array(
        '!local_field' => $this->local['field_name'],
        '!local_type' => $this->local['entity_type'],
        '!local_id' => $this->id,
        '!remote_field' => $this->remote['field_name'],
        '!remote_type' => $this->remote['entity_type'],
        '!remote_id' => $this->getRemoteEntityID($entity),
      );
      watchdog('cer', 'Failed to reference !remote_field on !remote_type !remote_id from !local_field on !local_type !local_id.', $variables, WATCHDOG_ERROR);
    }
  }

  /**
   * Implements CerHandlerInterface::dereference().
   */
  public function dereference($entity) {
    if ($this->references($entity)) {
      $id = $this->getRemoteEntityID($entity);

      foreach ($this->entity->{$this->local['field_name']} as $language => $references) {
        foreach ($references as $delta => $reference) {
          if ($reference['target_id'] == $id) {
            unset($this->entity->{$this->local['field_name']}[$language][$delta]);
          }
        }
      }
    }

    if ($this->referencedBy($entity)) {
      foreach ($entity->{$this->remote['field_name']} as $language => $references) {
        foreach ($references as $delta => $reference) {
          if ($reference['target_id'] == $this->id) {
            unset($entity->{$this->remote['field_name']}[$language][$delta]);
          }
        }
      }
    }
  }

  /**
   * Creates a reference to the local entity on the remote entity. Throws CerException
   * if the local entity is already referenced by the remote entity, or if the remote
   * field cannot hold any more values.
   *
   * @param object $entity
   *  The remote entity.
   */ 
  protected function addReferenceFrom($entity) {
    if ($this->referencedBy($entity)) {
      throw new CerException(t('Cannot create duplicate reference from remote entity.'));
    }
    elseif ($this->filled($this->getRemoteReferenceIDs($entity), $this->remote['field'])) {
      throw new CerException(t('Remote field cannot support any more references.'));
    }
    else {
      $languages = field_available_languages($this->remote['entity_type'], $this->remote['field']);
      foreach ($languages as $language) {
        $entity->{$this->remote['field_name']}[$language][] = array('target_id' => $this->id);
      }
    }
  }

  /**
   * Creates a reference to the remote entity on the local entity. Throws CerException
   * if the local entity already references the remote entity, or if the field cannot
   * hold any more values.
   *
   * @param object $entity
   *  The remote entity.
   */
  protected function addReferenceTo($entity) {
    $id = $this->getRemoteEntityID($entity);

    if ($this->references($entity)) {
      throw new CerException(t('Cannot create duplicate reference to remote entity.'));
    }
    elseif ($this->filled($this->getLocalReferenceIDs(), $this->local['field'])) {
      throw new CerException(t('Local field cannot support any more references.'));
    }
    else {
      $languages = field_available_languages($this->local['entity_type'], $this->local['field']);
      foreach ($languages as $language) {
        $this->entity->{$this->local['field_name']}[$language][] = array('target_id' => $id);
      }
    }
  }

  /**
   * Get the ID of the remote entity. If the entity is of the wrong type,
   * EntityMalformedException will be thrown.
   *
   * @param object $entity
   *  The remote entity.
   *
   * @return mixed
   *  The remote entity ID.
   */
  protected function getRemoteEntityID($entity) {
    $extract_ids = entity_extract_IDs($this->remote['entity_type'], $entity);
    return array_shift($extract_ids);
  }

  /**
   * Gets all the entities referenced by the local entity.
   *
   * @return array
   *  Array of fully loaded referenced entities keyed by ID, or empty
   *  array if nothing has been referenced.
   */
  protected function getReferencedEntities() {
    $IDs = $this->getLocalReferenceIDs();
    return $IDs ? entity_load($this->remote['entity_type'], $IDs) : array();
  }

  /**
   * Gets the IDs of the entities referenced by the local entity.
   *
   * @return array
   *  Array of entity IDs, empty array if there are no references.
   */
  protected function getLocalReferenceIDs() {
    return $this->getReferenceIDs($this->entity, $this->local);
  }

  /**
   * Gets the IDs of the entities referenced by $entity.
   *
   * @param object $entity
   *  The remote entity.
   *
   * @return array
   *  Array of entity IDs, empty array if there are no references.
   */
  protected function getRemoteReferenceIDs($entity) {
    return $this->getReferenceIDs($entity, $this->remote);
  }

  /**
   * Check if a field can support any more values. Formerly known as
   * "reference overloading".
   *
   * @param array $references
   *  The values in the field.
   *
   * @param $field
   *  Field definition (i.e., from field_info_field).
   *
   * @return boolean
   */
  private function filled($references, $field) {
    return $field['cardinality'] != FIELD_CARDINALITY_UNLIMITED && sizeof($references) >= $field['cardinality'];
  }

  /**
   * Gets all the referenced entity IDs from a specific field on $entity.
   *
   * @param object $entity
   *  The entity to scan for references.
   *
   * @param array $field
   *  Field or instance definition.
   *
   * @return array
   *  Array of unique IDs, empty if there are no references or the field
   *  does not exist on $entity.
   */
  private function getReferenceIDs($entity, $field) {
    $IDs = array();
    if (isset($entity->{$field['field_name']})) {
      foreach ($entity->{$field['field_name']} as $references) {
        foreach ($references as $reference) {
          $IDs[] = $reference['target_id'];
        }
      }
    }
    return array_unique(array_filter($IDs));
  }

}