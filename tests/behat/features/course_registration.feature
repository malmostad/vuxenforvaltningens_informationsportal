@api @course_registration
Feature: Course register
  Test if registration module and course registration field and registration
  permissions were setupped correctly. Also test how "Register widget works".

  @api
  Scenario: Check if authorized user see register button
    Given I am logged in as a user with the "authenticated user" role
    Given I am on "node/3"
    Then I should see "Registration"
    Then I press the "Save Registration" button
    Then I wait for AJAX to finish
    Then I press the "Unregister" button
