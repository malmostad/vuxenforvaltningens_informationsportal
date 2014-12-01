@api @course_registration
Feature: Middle admim permission
  Checking middle admin permissions
  As middle admin
  Middle admin has permission from http://conf.propeople.com.ua/pages/viewpage.action?title=Permissions&spaceKey=MAL

  Scenario: Proper content available to add
    Given I am logged in as a user with the "Malmo middle admin" role
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

  @javascript
  Scenario: Published course and course package creating
    Given I am logged in as a user with the "Malmo middle admin" role
    And I am on "node/add/course"
    And I fill in "Course template" with "A1 Test course template"
    And I press the "insert" key in the "Course template" field
    And I wait for 1 seconds
    And I press element ".reference-autocomplete"
    Then I press the "edit-submit" button
    Then I press the "edit-submit" button
    And I should see "Course A1 Test course template has been created."
    Then I click "Edit"
    And the "edit-status" checkbox should be checked
    Then I am on "node/add/course-packages"
    And I fill in "Course template" with "A1 Test course template"
    And I press the "insert" key in the "Course template" field
    And I wait for 1 seconds
    And I press element ".reference-autocomplete"
    Then I press the "edit-submit" button
    Then I press the "edit-submit" button
    And I should see "Course package A1 Test course template has been created."
    Then I click "Edit"
    And the "edit-status" checkbox should be checked


  Scenario: Unpublished course template and course package template creating
    Given I am logged in as a user with the "Malmo middle admin" role
    And I am on "node/add/course-template"
    And I fill in "edit-title" with "autotest course template"
    And I should see "Publishing options"
    And the "edit-status" checkbox should be checked
    Then I press the "edit-submit" button
    And I should see the text "Course template autotest course template has been created."
