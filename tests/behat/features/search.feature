  @api @search
  Feature: Search the site
  In order to find courses on the site
  As any user
  I should be able to search for courses

  Background:
    Given "type_of_education" terms:
      | name      |
      | Test course 235    |

    Given "course" nodes:
      | title      | field_course_type_education |
      | Course 235   | Test course 235                      |
    And Search index "node" on "apache_solr" server is fresh
    And I am reset the session

  @api @javascript
  Scenario: Use the global search field
    Given I am on the homepage
    When I fill in "edit-keys" with "Course"
    And I press "Search"
    # add tests