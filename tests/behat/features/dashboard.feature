@api
Feature: Dashboard
  In order to edit content
  As any user higher than auth
  I should can visit dashboard

  Scenario: Go to dashboard
    Given I am logged in as a user with the "School editor" role
    And I am on the homepage
    Then I should see "Instrumentbräda"
    Given I am logged in as a user with the "authenticated user" role
    And I am on the homepage
    Then I should not see "Instrumentbräda"
