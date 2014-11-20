@api @course_registration
Feature: Course register
  Test if registration module and course registration field and registration
  permissions were setupped correctly. Also test how "Register widget works".

  @api @javascript
  Scenario: Check if authorized user see register button
    Given I am logged in as a user with the "authenticated user" role
    Given I am on "search-courses/Test%20course"
    Then I press the "Save Registration" button
    Then I wait for AJAX to finish
    Then I press the "Unregister" button
    Then I wait for AJAX to finish
    Then I click "Test course"
    Then I press the "Save Registration" button
    Then I wait for AJAX to finish
    Then I press the "Unregister" button
    Then I wait for AJAX to finish
    Then I press the "Save Registration" button
    Then I wait for AJAX to finish
    Then I am on "my-planning"
    And I should see the text "Test course"

  Scenario: Anonymous user does not see Registration button.
    Given I am on "search-courses/Test%20course"
    Then I should not see a "asdf" element