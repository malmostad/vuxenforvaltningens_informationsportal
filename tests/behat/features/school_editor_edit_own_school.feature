@api @school
Feature: School editor can edit own school
  In order to edit my school
  As school editor
  I should be able to edit school

  Background:
    Given I am logged in as "editor" with the password "editor"

  Scenario: User can edit own school
    Given I am on "schools"
    When I click "A2 Test school"
      And I click "Edit"
      And I fill in "E-post" with "test@email.com"
      And I press "Save"
    Then I should see the text "has been updated"
    Then I should see the text "test@email.com"

  Scenario: User can't edit others school
    Given I am on "schools"
    When I click "A1 Test school"
    And I should not see the text "Edit"
