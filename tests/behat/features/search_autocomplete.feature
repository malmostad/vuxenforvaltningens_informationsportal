@api @javascript
Feature: Search autocomplete
  In order to find courses convinintly
  As any user
  I should be able to see autocomplete on all pages where search field exist

  Scenario Outline: Use autocomplete
    Given I am on "<page>"
    When I fill in "edit-keys" with "cours"
    And I press the "insert" key in the "edit-keys" field
    And I wait for 2 seconds
    Then I should see "course"

  Examples:
    | page           |
    | front_page     |
    | search-courses |
