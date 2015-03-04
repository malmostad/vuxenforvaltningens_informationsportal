@api @school
Feature: School
  In order to check out all courses
  As anonymous user
  I should be able to visit school page and go to search with all courses from this school

  @api
  Scenario: Visit school
    Given I am on the homepage
    When I click "Utbildningsanordnare"
    Then I should see the text "A1 Test school"
    When I click "A1 Test school"
    Then I should see the text "A1 Test school"
    Then I should see the text "Test body"
    Then I should see the text "View all school courses"
    Then I should see the text "Contact us"
    Then I should see the text "E-post"
    Then I should see the text "school@email.test"
    Then I should see the text "Tel"
    Then I should see the text "380932312332"
    Then I should see the text "Fax"
    Then I should see the text "777777"
    Then I should see the text "Post address"
    Then I should see the text "Test school address"
    Then I should see the text "Visiting Address"
    Then I should see the text "Test school street address"
    Then I should see the text "Show on map"
