<?php
/**
 * @file
 * notification_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function notification_rules_default_rules_configuration() {
  $items = array();
  $items['rules_notification_on_new_template_content'] = entity_import('rules_config', '{ "rules_notification_on_new_template_content" : {
      "LABEL" : "Notification on new template content",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Mail notifications" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--course_template" : { "bundle" : "course_template" } },
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "3" : "3" } },
            "subject" : "New [node:type-name] templates was created",
            "message" : "New [node:type-name] content is available:\\r\\n\\r\\n[node:title] (Url: [node:url])\\r\\n\\r\\n"
          }
        }
      ]
    }
  }');
  $items['rules_notification_on_unpublish_courses'] = entity_import('rules_config', '{ "rules_notification_on_unpublish_courses" : {
      "LABEL" : "Notification on unpublish courses",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_update--course" : { "bundle" : "course" },
        "node_update--course_packages" : { "bundle" : "course_packages" }
      },
      "IF" : [ { "NOT node_is_published" : { "node" : [ "node" ] } } ],
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "5" : "5" } },
            "subject" : "The [node:content-type] [node:title] became an unpublished.",
            "message" : "Link: [node:url]"
          }
        }
      ]
    }
  }');
  return $items;
}
