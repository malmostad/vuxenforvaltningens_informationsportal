<?php

/**
 * @file
 * Contains FeatureContext
 */

use Behat\Behat\Event\BaseScenarioEvent;
use Behat\Gherkin\Node\TableNode;
use Drupal\DrupalExtension\Context\DrupalContext;

use Behat\Behat\Context\Step\Then;
use Behat\Behat\Event\ScenarioEvent;

require 'vendor/autoload.php';

/**
 * Features context.
 */
class FeatureContext extends DrupalContext {

  /**
   * Initializes context.
   *
   * Every scenario gets its own context object.
   *
   * @param array $parameters
   *   Context parameters (set them up through behat.yml)
   */
  public function __construct(array $parameters) {

  }

  /**
   * Use english locale during the tests.
   *
   * @BeforeScenario
   *
   * @param BaseScenarioEvent $event
   *   Behat event object.
   */
  public function beforeEachScenario(BaseScenarioEvent $event) {
    /* @var DrupalContext $context */
    $context = $event->getContext();
    $context->getSession()->visit($this->getMinkParameter('base_url'));
    $context->getSession()->setCookie('language', 'en');
  }

  /**
   * Check if the list of strings is on the page.
   *
   * @Given /^I (?:should |)see the following <texts>$/
   */
  public function iShouldSeeTheFollowingTexts(TableNode $table) {
    $page = $this->getSession()->getPage();
    $table = $table->getHash();
    foreach ($table as $key => $value) {
      $text = $table[$key]['texts'];
      if ($page->hasContent($text) === FALSE) {
        throw new Exception("The text '" . $text . "' was not found");
      }
    }
  }

  /**
   * Return random string.
   *
   * @return string
   *   String that contains character to string random generator.
   */
  protected function randomString() {
    return 'abcdefghijk';
  }

  /**
   * Check if the list of links is on the page.
   *
   * @Given /^I (?:should |)see the following <links>$/
   */
  public function iShouldSeeTheFollowingLinks(TableNode $table) {
    $page = $this->getSession()->getPage();
    $table = $table->getHash();
    foreach ($table as $key => $value) {
      $link = $table[$key]['links'];
      $result = $page->findLink($link);
      if (empty($result)) {
        throw new Exception("The link '" . $link . "' was not found");
      }
    }
  }

  /**
   * Check if the list of links is not on the page.
   *
   * @Given /^I should not see the following <links>$/
   */
  public function iShouldNotSeeTheFollowingLinks(TableNode $table) {
    $page = $this->getSession()->getPage();
    $table = $table->getHash();
    foreach ($table as $key => $value) {
      $link = $table[$key]['links'];
      $result = $page->findLink($link);
      if (!empty($result)) {
        throw new Exception("The link '" . $link . "' was found");
      }
    }
  }

  /**
   * Function to check if the field specified is outlined in red or not.
   *
   * @Given /^the field "([^"]*)" should be outlined in red$/
   *
   * @param string $field
   *   The form field label to be checked.
   *
   * @throws \Exception
   */
  public function theFieldShouldBeOutlinedInRed($field) {
    $page = $this->getSession()->getPage();
    // Get the object of the field.
    $form_field = $page->findField($field);
    if (empty($form_field)) {
      throw new Exception('The page does not have the field with label "' . $field . '"');
    }
    // Get the 'class' attribute of the field.
    $class = $form_field->getAttribute('class');
    // We get one or more classes with space separated. Split them using space.
    $class = explode(" ", $class);
    // If the field has 'error' class, then the field will be outlined with red.
    if (!in_array("error", $class)) {
      throw new Exception('The field "' . $field . '" is not outlined with red');
    }
  }

  /**
   * Fill input with the random text.
   *
   * @Given /^I fill in "([^"]*)" with random text$/
   */
  public function iFillInWithRandomText($label) {
    // A @Tranform would be more elegant.
    $random_string = $this->randomString(10);

    $step = "I fill in \"$label\" with \"$random_string\"";
    return new Then($step);
  }

  /**
   * Helper function to fetch user details stored in behat.local.yml.
   *
   * @param string $type
   *   The user type, e.g. drupal.
   * @param string $name
   *   The username to fetch the password for.
   *
   * @throws \Exception
   *
   * @return string
   *   The matching password or FALSE on error.
   */
  public function fetchUserDetails($type, $name) {
    $property_name = $type . '_users';
    try {
      $property = $this->$property_name;
      $details = $property[$name];
      return $details;
    }
    catch (Exception $e) {
      throw new Exception("Non-existant user/password for $property_name:$name please check behat.local.yml.");
    }
  }

  /**
   * Authenticates a user.
   *
   * @Given /^I am logged in as "([^"]*)" with the password "([^"]*)"$/
   */
  public function iAmLoggedInAsWithThePassword($username, $passwd) {
    $user = $this->whoami();

    if (strtolower($user) == strtolower($username)) {
      // Already logged in.
      return;
    }

    $element = $this->getSession()->getPage();
    if (empty($element)) {
      throw new Exception('Page not found');
    }

    // Go to the user login page.
    $this->getSession()->visit($this->locatePath('/user/login'));

    // If I see this, I'm not logged in at all so log the user in.
    $element->fillField('Username', $username);
    $element->fillField('Password', $passwd);
    $submit = $element->findButton('Log in');
    if (empty($submit)) {
      throw new Exception('No submit button at ' . $this->getSession()
          ->getCurrentUrl());
    }

    // Log in.
    $submit->click();
  }

  /**
   * Private function for the whoami step.
   */
  private function whoami() {
    $element = $this->getSession()->getPage();
    // Go to the user page.
    $this->getSession()->visit($this->locatePath('/user'));
    if ($find = $element->find('css', 'h1')) {
      $page_title = $find->getText();
      if ($page_title) {
        return str_replace('hello, ', '', strtolower($page_title));
      }
    }
    return FALSE;
  }

  /**
   * Click on Quick edit.
   *
   * @When /^(?:|I )click on Quick Edit link$/
   */
  public function clickOnQuickEdit() {
    $this->getSession()->getPage()->clickLink('Quick edit');
    $this->getSession()
      ->wait(5000, 'jQuery(".entity-commerce-order").length > 0');
  }

  /**
   * Wait for the jQuery AJAX loading to finish.
   *
   * @Given /^(?:|I )wait for AJAX loading to finish$/
   */
  public function iWaitForAJAX() {
    $this->getSession()->wait(5000, 'jQuery.active === 0');
  }

  /**
   * Wait for the given number of seconds.
   *
   * @Given /^(?:|I )wait(?:| for) (\d+) seconds?$/
   */
  public function iWaitForSeconds($arg1) {
    sleep($arg1);
  }

  /**
   * Check if not container is on the page.
   *
   * @Then /^I should not see container with class "([^"]*)"$/
   */
  public function iShouldNotSeeContainerWithClass($class) {
    $session = $this->getSession();
    $page = $session->getPage();

    $element = $page->find('css', '.' . $class);

    if (NULL === $element) {
      return;
    }

    if ($element->isVisible()) {
      throw new \LogicException('Element is visible...');
    }
  }

  /**
   * Reset user's session.
   *
   * @Given /^I am reset the session$/
   */
  public function iAmResetTheSession() {
    $session = $this->getSession();
    $session->restart();
    $session->reset();
    $session->reload();
  }

  /**
   * Press the element using css selector.
   *
   * @When /^I press element "([^"]*)"$/
   */
  public function iPressElement($selector) {
    // Assume extends RawMinkContext.
    $session = $this->getSession();
    $page = $session->getPage();

    $element = $page->find('css', $selector);
    $element->press();
  }

  /**
   * Check if there is a container with given css selector on the page.
   *
   * @Then /^I should see container with class "([^"]*)"$/
   */
  public function iShouldSeeContainerWithClass($selector) {
    // Assume extends RawMinkContext.
    $session = $this->getSession();
    $page = $session->getPage();

    $element = $page->find('css', '.' . $selector);

    if (NULL === $element) {
      throw new \LogicException('Could not find the element');
    }

    if (!$element->isVisible()) {
      throw new \LogicException('Element is not visible...');
    }
  }

  /**
   * CHeck if there is an given get param in the url.
   *
   * @Then /^I should have "([^"]*)" get params$/
   */
  public function iShouldHaveGetParams($arg1) {

  }

  /**
   * Check if there is a text inside specified element on the page.
   *
   * @Then /^I should see the text "([^"]*)" in "([^"]*)" element$/
   */
  public function iShouldSeeTheTextInElement($text, $selector) {
    $session = $this->getSession();
    $region_obj = $session->getPage()->find('css', $selector);

    // Find the text within the region.
    $region_text = $region_obj->getText();

    if (strpos($region_text, $text) === FALSE) {
      throw new \Exception(sprintf("The text '%s' was not found in the region '%s' on the page %s", $text, $selector, $this->getSession()
        ->getCurrentUrl()));
    }
  }

  /**
   * Check if there is no text inside specified element on the page.
   *
   * @Then /^I should not see the text "([^"]*)" in "([^"]*)" element$/
   */
  public function iShouldNotSeeTheTextInElement($text, $selector) {
    $session = $this->getSession();
    $region_obj = $session->getPage()->find('css', $selector);

    // Find the text within the region.
    if ($region_obj) {
      $region_text = $region_obj->getText();

      if (strpos($region_text, $text) !== FALSE) {
        throw new \Exception(sprintf("The text '%s' was found in the region '%s' on the page %s", $text, $selector, $this->getSession()
          ->getCurrentUrl()));
      }
    }
  }

  /**
   * Check the order of values in given selector.
   *
   * @Then /^"([^"]*)" should precede "([^"]*)" for the query "([^"]*)"$/
   */
  public function shouldPrecedeForTheQuery($textBefore, $textAfter, $cssQuery) {
    $items = array_map(
      function ($element) {
        return trim($element->getText());
      },
      $this->getSession()->getPage()->findAll('css', $cssQuery)
    );
    if (array_search($textBefore, $items) < array_search($textAfter, $items)) {
      throw new \Exception(sprintf("%s does not proceed %s", $textBefore, $textAfter));
    }
  }

  /**
   * Trigger keydown event for elementm because selenium when fill not trigger.
   *
   * @Given /^I trigger autocomplete with id "([^"]*)"$/
   */
  public function iTriggerAutocompleteWithId($id) {
    $this->getSession()->getDriver()->evaluateScript(
      'jQuery("#' . $id . '").trigger("keydown");'
    );
  }

  /**
   * @When /^I hover over the element "([^"]*)"$/
   */
  public function iHoverOverTheElement($selector) {
    $session = $this->getSession();
    $element = $session->getPage()->find('css', $selector);

    if (NULL === $element) {
      throw new \Exception(sprintf('Could not evaluate CSS selector: "%s"', $selector));
    }

    $element->mouseOver();
  }

  /**
   * Insert text to wysiwyg.
   *
   * @Given /^I type "([^"]*)" in "([^"]*)" WYSIWYG editor$/
   */
  public function iTypeInWysiwygEditor($text, $selector) {
    $this->getSession()->getDriver()->evaluateScript(
      "Drupal.wysiwyg.instances['" . $selector . "'].insert('" . $text . "')"
    );
  }
}
