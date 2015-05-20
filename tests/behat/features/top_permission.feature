@api @course_registration
Feature: top admim permission
  Checking top admin permissions
  As top admin
  Top admin has permission from http://conf.propeople.com.ua/pages/viewpage.action?title=Permissions&spaceKey=MAL

# Temporary commented because of http://jira.propeople.com.ua/browse/MAL-74
#  Scenario: Proper content available to add
#    Given I am logged in as a user with the "Malmo top admin" role
#    And I am on "node/add"
#    Then I should see the link "Course"
#    And I should see the link "Course package"
#    And I should see the link "Course template"
#    And I should see the link "Course package template"
#
#
#  Scenario: Published course and course package creating
#    Given I am logged in as a user with the "Malmo top admin" role
#    And I am on "node/add/course"
#    And I fill in "edit-title" with "autotest course node"
#    Then I press the "edit-submit" button
#    And I should see "Course autotest course node has been created."
#    Then I click "Edit"
#    And the "edit-status" checkbox should be checked
#    Then I am on "node/add/course-packages"
#    And I fill in "edit-title" with "autotest course package node"
#    Then I press the "edit-submit" button
#    And I should see "Course package autotest course package node has been created."
#    Then I click "Edit"
#    And the "edit-status" checkbox should be checked
#
#
#  Scenario: Unpublished course template and course package template creating
#    Given I am logged in as a user with the "Malmo top admin" role
#    And I am on "node/add/course-template"
#    And I fill in "edit-title" with "autotest course template"
#    And I should see "Publishing options"
#    And the "edit-status" checkbox should be checked
#    Then I press the "edit-submit" button
#    And I should see the text "Course template autotest course template has been created."
#    Then I am on "node/add/course-package-template"
#    And I fill in "edit-title" with "autotest course package template"
#    And I should see "Publishing options"
#    And the "edit-status" checkbox should be checked
#    Then I press the "edit-submit" button
#    And I should see the text "Course package template autotest course package template has been created."

  @extra
  Scenario: Extra permissions for top admin
    Given I am logged in as a user with the "Malmo top admin" role
    And I am on "admin/structure/menu"
    Then I should see the link "Add menu"
    And I should see the link "edit menu"
    And I should see the link "list links"
    And I should see the link "add link"
    Then I am on "admin/structure/pages"
    And I should see the link "Create a new page"
    And I should see the link "Edit"
    Then I am on "admin/config/development"
    And I should see the link "Generate content"
    And I should see the link "Generate menus"

