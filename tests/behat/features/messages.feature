@api @user_registration
Feature: Warning messages
  In order to see some information from site
  As any user
  I should be able to see status messages

  @api
  Scenario: Try login with fake data
    Given I am on "user/login"
    When I fill in "Username" with "wrong"
    And I fill in "Password" with "wrong"
    And I press "Log in"
    And I should see the text "Sorry, unrecognized username or password" in ".warning" element
