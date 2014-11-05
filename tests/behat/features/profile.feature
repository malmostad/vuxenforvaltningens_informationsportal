@api @register
Feature: Profile page
  In order to check profile
  As authenticated user
  I should be able to visit user page and see specific text

  @api
  Scenario: Visit profile
    Given I am logged in as a user with the "authenticated" role
    And I am on "user"
    Then I should see the text "Profilsida"
    And I should see the text "Lorem ipsum dolor sit amet"
    And the response should not contain "not-logged-in"
    # add tests