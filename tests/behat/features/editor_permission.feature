@api @course_registration
Feature: Editors permission
  Checking editors permissions
  As editor
  Editor has permission from http://conf.propeople.com.ua/pages/viewpage.action?title=Permissions&spaceKey=MAL

  Scenario: Proper content available to add
    Given I am logged in as a user with the "School editor" role
    And I am on "node/add"
    Then I should see the link "Course"
    And I should see the link "Course package"
    And I should see the link "Course template"
#    Then I am on "admin"
#    And I should not see "Structure"
#    And I should not see "Configuration"
#    or
     Then I am on "admin/structure"
     And I should see the text "You do not have any administrative items."


  Scenario: Published course and course package creating
    Given I am logged in as a user with the "School editor" role
    And I am on "node/add/course"
    And I fill in "edit-title" with "autotest course node"
    Then I press the "edit-submit" button
    And I should see "Course autotest course node has been created."
    Then I click "Edit"
    And the "edit-status" checkbox should be checked
    Then I am on "node/add/course-packages"
    And I fill in "edit-title" with "autotest course package node"
    Then I press the "edit-submit" button
    And I should see "Course package autotest course package node has been created."
    Then I click "Edit"
    And the "edit-status" checkbox should be checked


  Scenario: Unpublished course template and course package template creating
    Given I am logged in as a user with the "School editor" role
    And I am on "node/add/course-template"
    And I fill in "edit-title" with "autotest course template"
    And I should not see "Publishing options"
    Then I press the "edit-submit" button
    And I should see the text "Course template autotest course template has been created."
