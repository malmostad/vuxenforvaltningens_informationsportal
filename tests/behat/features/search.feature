@api @search
Feature: Search the site
  In order to find courses on the site
  As any user
  I should be able to search for courses

  Background:
    Given "type_of_education" terms:
      | name      |
      | Test course 1    |

    Given "course" nodes:
      | title      | field_course_type_education |
      | Course 1   | Test course 1                      |
      | Course 2   | Test course 1                      |
    And Search index "node" is fresh
  @api
  Scenario: Use the global search field
    Given I am on the homepage
    When I fill in "edit-keys" with "Course"
      And I press "Search"
    Then I should see the link "Course 1"
      And I should see the link "Course 2"
      And I should see the link "Test course 1"
