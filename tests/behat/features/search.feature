@api @search
Feature: Search the site
  In order to find courses on the site
  As any user
  I should be able to search for courses

  @api
  Scenario: Use the global search field
    Given I am on the homepage
    When I fill in "edit-keys" with "Course"
    And I press "Search"
    Then I should be on "search-courses/Course"

  @api
  Scenario: Check facets
    Given I am on the homepage
    And I press "Search"
    # Check facet minipanel block
    And I should see the text "Filtrera sökresultat"
#     @see mal_search_property_global_type_of_education_getter_callback()
    Then I should see the text "Utbildningsform"
    And I should see the text "Kursform"
    And I should see the text "Utbildningsanordnare"
    And I should see the text "Ämnesområden för kurser"
    And I should see the text "Gymnasieprogram"
    # Check date facet minipanel block
    And I should see the text "Kursstart, tider och veckodagar"
    And I should see an "#edit-date" element
    And I should see the text "Veckodagar"
    And I should see the text "Monday"
    And I should not see the text "Sunday"
    And I should not see the text "Saturday"
    And I should see the text "Tider"
    And I should see the text "Morning"
    And I should see the text "Afternoon"
    And I should see the text "Evening"
    And I should see the text "Show only searchable courses"
    And I should see the text "Enstaka kurs eller kurspaket"

  @api @sort
  Scenario: Check sort
    Given I am on the homepage
    And I press "Search"
    Then the response should contain "Sort by"
    Then the response should contain "Alfabetic"
    Then the response should contain "Strartdate"

  @javascript @search-facet
  Scenario: Use start date facet
    Given I am on the homepage
    Then I should not see container with class "ui-datepicker"
    And I press "Search"
    And I press element ".minipanel-search-facet-date"
    And I wait for 1 seconds
    When I press element "#edit-date"
    And I press element ".datepicker-days .day"

  @api @sort-fields
  Scenario: Check how fields renders
    And I am on "search-courses/Test%20course"
    Then I should see the text "Test course"
    Then I should see the text "Mon Tue 00:05 - 12:15"
    Then I should see the text "The course is searchable from"
