@api @course_registration
Feature: top admim permission
  Checking administration permissions
  As administrator
  Administrator has permission from http://conf.propeople.com.ua/pages/viewpage.action?title=Permissions&spaceKey=MAL


  Scenario: General permission
    Given I am logged in as a user with the "administrator" role
    And I am on "admin"
    Then I should see the link "Dashboard"
    And I should see the link "Content"
    And I should see the link "Structure"
    And I should see the link "Appearance"
    And I should see the link "People"
    And I should see the link "Modules"
    And I should see the link "Configuration"
    And I should see the link "Reports"
    And I should see the link "Help"
    Then I am on "admin/content"
    And I should see the link "Add content"
    Then I am on "admin/people"
    And I should see the link "Add user"
    Then I am on "admin/structure"
    And I should see the link "Content types"
    And I should see the link "Features"
    And I should see the link "Menus"
    And I should see the link "Panels"
    And I should see the link "Taxonomy"
    Then I am on "admin/config"
    And I should see the heading "People"
    And I should see the heading "System"

@javascript
  Scenario: user creation
    Given I am logged in as a user with the "administrator" role
    And I am on "admin/people"
    Then I click "Add user"
    And I fill in "edit-name" with "tester"
    And I fill in "edit-mail" with "tester@malmo.se"
    And I fill in "edit-pass-pass1" with "tester"
    And I fill in "edit-pass-pass2" with "tester"
    And the "edit-roles-2" checkbox should be checked
    Then I press the "edit-submit" button
    And I should see "Created a new user account for tester"
    Then I am on "admin/people"
    And I click "tester"
    Then I click "Edit"
    Then I press the "edit-cancel" button
    Then I select the radio button "Delete the account and its content." with the id "edit-user-cancel-method--5"
    Then I press "edit-submit"
    Then I should see "tester has been deleted."


