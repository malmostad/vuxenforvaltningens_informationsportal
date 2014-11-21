<?php

use Behat\Behat\Context\ClosuredContextInterface,
  Behat\Behat\Context\TranslatedContextInterface,
  Behat\Behat\Context\BehatContext,
  Behat\Behat\Exception\PendingException;
use Behat\Gherkin\Node\PyStringNode,
  Behat\Gherkin\Node\TableNode;
use Drupal\DrupalExtension\Context\DrupalContext;

use Symfony\Component\Process\Process;
use Behat\Behat\Context\Step\Given;
use Behat\Behat\Context\Step\When;
use Behat\Behat\Context\Step\Then;
use Behat\Behat\Event\ScenarioEvent;
use Behat\Behat\Event\StepEvent;
use Behat\Mink\Exception\ElementNotFoundException;

require 'vendor/autoload.php';

//
// Require 3rd-party libraries here:
//
//   require_once 'PHPUnit/Autoload.php';
//   require_once 'PHPUnit/Framework/Assert/Functions.php';
//

/**
 * Features context.
 */
class FeatureContext extends DrupalContext {
  /**
   * Initializes context.
   * Every scenario gets its own context object.
   *
   * @param array $parameters context parameters (set them up through behat.yml)
   */
  public function __construct(array $parameters) {
    // Initialize your context here
  }

  /**
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

  protected function randomString($number = 10) {
    return 'abcdefghijk';
  }

  /**
   * @Given /^I (?:should |)see the following <links>$/
   */
  public function iShouldSeeTheFollowingLinks(TableNode $table) {
    $page = $this->getSession()->getPage();
    $table = $table->getHash();
    foreach ($table as $key => $value) {
      $link = $table[$key]['links'];
      $result = $page->findLink($link);
      if(empty($result)) {
        throw new Exception("The link '" . $link . "' was not found");
      }
    }
  }

  /**
   * @Given /^I should not see the following <links>$/
   */
  public function iShouldNotSeeTheFollowingLinks(TableNode $table) {
    $page = $this->getSession()->getPage();
    $table = $table->getHash();
    foreach ($table as $key => $value) {
      $link = $table[$key]['links'];
      $result = $page->findLink($link);
      if(!empty($result)) {
        throw new Exception("The link '" . $link . "' was found");
      }
    }
  }

  /**
   * Function to check if the field specified is outlined in red or not
   *
   * @Given /^the field "([^"]*)" should be outlined in red$/
   *
   * @param string $field
   *   The form field label to be checked.
   */
  public function theFieldShouldBeOutlinedInRed($field) {
    $page = $this->getSession()->getPage();
    // get the object of the field
    $formField = $page->findField($field);
    if (empty($formField)) {
      throw new Exception('The page does not have the field with label "' . $field . '"');
    }
    // get the 'class' attribute of the field
    $class = $formField->getAttribute("class");
    // we get one or more classes with space separated. Split them using space
    $class = explode(" ", $class);
    // if the field has 'error' class, then the field will be outlined with red
    if (!in_array("error", $class)) {
      throw new Exception('The field "' . $field . '" is not outlined with red');
    }
  }

  /**
   * @Given /^I fill in "([^"]*)" with random text$/
   */
  public function iFillInWithRandomText($label) {
    // A @Tranform would be more elegant.
    $randomString = $this->randomString(10);

    $step = "I fill in \"$label\" with \"$randomString\"";
    return new Then($step);
  }

  /**
   * Helper function to fetch user details stored in behat.local.yml.
   *
   * @param string $type
   *   The user type, e.g. drupal.
   *
   * @param string $name
   *   The username to fetch the password for.
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
    } catch (Exception $e) {
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
      throw new Exception('No submit button at ' . $this->getSession()->getCurrentUrl());
    }

    // Log in.
    $submit->click();

    // Successfully logged in.
    return;
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
   * @When /^(?:|I )click on Quick Edit link$/
   *
   * Click on Quick edit.
   */
  public function clickOnQuickEdit() {
    $this->getSession()->getPage()->clickLink('Quick edit');
    $this->getSession()->wait(5000, 'jQuery(".entity-commerce-order").length > 0');
  }

  /**
   * @Given /^(?:|I )wait for AJAX loading to finish$/
   *
   * Wait for the jQuery AJAX loading to finish. ONLY USE FOR DEBUGGING!
   */
  public function iWaitForAJAX() {
    $this->getSession()->wait(5000, 'jQuery.active === 0');
  }

  /**
   * @Given /^(?:|I )wait(?:| for) (\d+) seconds?$/
   *
   * Wait for the given number of seconds. ONLY USE FOR DEBUGGING!
   */
  public function iWaitForSeconds($arg1) {
    sleep($arg1);
  }

  /**
   * @Then /^I should not see container with class "([^"]*)"$/
   */
  public function iShouldNotSeeContainerWithClass($class) {
    $session = $this->getSession(); // assume extends RawMinkContext
    $page = $session->getPage();

    $element = $page->find('css', '.' . $class);

    if (null === $element) {
      return;
    }

    if ($element->isVisible()) {
      throw new \LogicException('Element is visible...');
    }
  }

  /**
   * @Given /^I am reset the session$/
   */
  public function iAmResetTheSession()
  {
    $session = $this->getSession();
    $session->restart();
    $session->reset();
    $session->reload();
  }

  /**
   * @When /^I press element "([^"]*)"$/
   */
  public function iPressElement($selector) {
    $session = $this->getSession(); // assume extends RawMinkContext
    $page = $session->getPage();

    $element = $page->find('css', $selector);
    $element->press();
  }

  /**
   * @Then /^I should see container with class "([^"]*)"$/
   */
  public function iShouldSeeContainerWithClass($selector) {
    $session = $this->getSession(); // assume extends RawMinkContext
    $page = $session->getPage();

    $element = $page->find('css', '.' . $selector);

    if (null === $element) {
      throw new \LogicException('Could not find the element');
    }

    if (!$element->isVisible()) {
      throw new \LogicException('Element is not visible...');
    }
  }

  /**
   * @Then /^I should have "([^"]*)" get params$/
   */
  public function iShouldHaveGetParams($arg1) {
    var_dump($_GET);
  }

  /**
   * @Then /^I should see the text "([^"]*)" in "([^"]*)" element$/
   */
  public function iShouldSeeTheTextInElement($text, $selector) {
    $session = $this->getSession();
    $regionObj = $session->getPage()->find('css', $selector);

    // Find the text within the region
    $regionText = $regionObj->getText();

    if (strpos($regionText, $text) === FALSE) {
      throw new \Exception(sprintf("The text '%s' was not found in the region '%s' on the page %s", $text, $selector, $this->getSession()->getCurrentUrl()));
    }
  }
}
