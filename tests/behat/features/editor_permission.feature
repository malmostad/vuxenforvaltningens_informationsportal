@api @course_registration
Feature: Editors permission
  Checking editors permissions
  As editor
  Editor has permission from http://conf.propeople.com.ua/pages/viewpage.action?title=Permissions&spaceKey=MAL

  Scenario: Proper content available to add
    Given I am logged in as a user with the "School editor" role
    And I am on "node/add"
    And I should see the text "Kurspaket" in ".node-type-list" element
    And I should see the text "Enstaka kurs" in ".node-type-list" element
    And I should see the text "Course template" in ".node-type-list" element
#    Then I am on "admin"
#    And I should not see "Structure"
#    And I should not see "Configuration"
#    or
     Then I am on "admin/structure"
     And I should see the text "You do not have any administrative items."

  @javascript
  Scenario: Published course and course package creating
    Given I am logged in as a user with the "School editor" role
    And I am on "node/add/course"
    And I fill in "Course template" with "A1 Test course template"
    And I press the "insert" key in the "Course template" field
    And I wait for 1 seconds
    And I press element ".reference-autocomplete"
    Then I press the "edit-submit" button
    # Required
    And I fill in "Course form" with "Flexkurs"
    And I fill in "Course Group" with "test"
    And I select "Inactive" from "Searchable type"

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
    # Required for course
    And I fill in "Course form" with "Flexkurs"
    And I fill in "Course Group" with "test"
    And I select "Inactive" from "Searchable type"
    And I type "test" in "edit-body-und-0-value" WYSIWYG editor
    And I fill in "Contact Person" with "test"
    And I fill in "Number of points" with "100"
    And I fill in "edit-field-course-package-und-0-field-package-course-und-0-value" with "test"
    And I fill in "Point" with "233"
    And I fill in "Prerequisites" with "233"
    And I fill in "Scope" with "20"
    And I fill in "Weeks of study" with "2"

    Then I press the "edit-submit" button
    And I should see "Course package A1 Test course template has been created."
    And I should see "20%"
    Then I click "Edit"
    And the "edit-status" checkbox should be checked



  Scenario: Unpublished course template and course package template creating
    Given I am logged in as a user with the "School editor" role
    And I am on "node/add/course-template"
    And I fill in "edit-title" with "autotest course template"
    And I should not see "Publishing options"
    Then I press the "edit-submit" button
    And I should see the text "Course template autotest course template has been created."
