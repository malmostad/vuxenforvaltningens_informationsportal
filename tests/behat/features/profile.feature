@api @register
Feature: Profile page
  In order to check profile
  As authenticated user
  I should be able to visit user page and see specific text

  @api
  Scenario: Visit profile
    Given I am logged in as a user with the "authenticated user" role
    And I am on "user"
    Then I should see the text "Profilsida"
    And I should see the text "Lorem ipsum dolor sit amet"
    And I should see the text "Min planering"
    And I should see the text "My account"
    And I should see the text "Log out"
    And I should not see the text "Registration"
    And I should not see the text "Log in"
    And the response should not contain "not-logged-in"

  Scenario: Visit front
    Given I am an anonymous user
    And I am on the homepage
    And I should see the text "Registrering"
    And I should see the text "Log in"
    And I should not see the text "My account"
    And I should not see the text "Log out"
