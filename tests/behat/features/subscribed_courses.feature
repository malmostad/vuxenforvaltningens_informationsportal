@api @subscribe_courses
Feature: Subscribed course order
  Test if course sorting works properly for user table.

  @api @javascript
  Scenario: Check if day order is displayed correctly
    Given I am logged in as a user with the "authenticated user" role
    Given I am on "search-courses/Test%20course"
    Then I press the "Register" button
    Then I wait for AJAX to finish
    Then I am on "my-planning"
    And "måndag" should precede "tisdag" for the query ".view-my-courses tbody tr td:nth-child(2)"

  @api @javascript
  Scenario: Check if day order is displayed correctly
    Given I am logged in as a user with the "authenticated user" role
    Given I am on "search-courses/Test%20course"
    Then I press the "Register" button
    Then I wait for AJAX to finish
    Then I am on "my-planning"
    Then I should see the text "Test course"
    And I press the "Unregister" button
    And I should not see the text "Test course"
