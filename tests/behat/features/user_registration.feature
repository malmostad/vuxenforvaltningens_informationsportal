@api @user_registration
Feature: User register
  In order to register on the site
  As anonymous user
  I should be able to visit register page and submit registration form

  @api
  Scenario: Try register
    Given I am on homepage
    Given I am on "register"
    When I fill in "edit-name" with "behat_register_user"
    And I fill in "edit-mail" with "behat_test@propeople.com.ua"
    And I fill in "edit-pass-pass1" with "1234"
    And I fill in "edit-pass-pass2" with "1234"
    And I press "Create new account"
    And I should be on homepage
    And I should see the text "Thank you for applying for an account"
    And the response should contain "not-logged-in"
    # add tests
