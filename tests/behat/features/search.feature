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

  @api @javascript
  Scenario: Use the global search field
    Given I am on the homepage
    When I fill in "edit-keys" with "Course"
    And I press "Search"
    Then I should be on "search-courses/Course"
  # add tests

  @api
  Scenario: Check facets
    Given I am on the homepage
    And I press "Search"
    Then I should see the text "Utbildningsform"
    And I should see the text "Kursform"
    And I should see the text "Skolor"
    And I should see the text "Ämnesområden"
    And I should see the text "Inriktning"
    And I should see the text "Gymnasieprogram"
    And I should see the text "Filtrera sökresultat"
    And I should see the text "Kursstart, tider och veckodagar"
    And I should see an "#edit-date" element
    And I should see the text "Veckodagar"
    And I should see the text "monday"

  @api @sort
  Scenario: Check sort
    Given I am on the homepage
    And I press "Search"
    Then the response should contain "Sort by startdate"


  @javascript @search-facet
  Scenario: Use start date facet
    Given I am on the homepage
    Then I should not see container with class "ui-datepicker"
    And I press "Search"
    When I press element "#edit-date"
    Then I should see container with class "ui-datepicker"
    When I press element ".ui-datepicker-week-end"
