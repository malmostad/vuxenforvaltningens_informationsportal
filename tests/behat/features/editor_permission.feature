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
    And I should see the link "Course package template"
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
    And I fill in "edit-title" with "autotest course node"
    And I select "Matematik" from "field_course_template[und]"
    And I wait for AJAX to finish
    And I check the box "edit-field-course-available-search-und"
    And I fill in "edit-field-course-form-und" with "Klassrumsundervisning"
    And I fill in "edit-field-course-subject-areas-und" with "Naturvetenskap"
    And I fill in "edit-field-course-orientation-und" with "Hotell och turism"
    And I fill in "edit-field-course-gymnasie-program-und" with "Ekonomi"
    And I fill in "edit-field-course-periods-und-0-value" with "4:00AM"
    And I fill in "edit-field-course-periods-und-0-value2" with "11:00AM"
    And I check the box "edit-field-course-periods-und-0-days-mon"
    And I check the box "edit-field-course-periods-und-0-days-wed"
    And I check the box "edit-field-course-periods-und-0-days-fri"
    Then I press the "edit-submit" button
    And I should see "Course autotest course node has been created."
    Then I click "Edit"
    And the "edit-status" checkbox should be checked
    Then I am on "node/add/course-packages"
    And I fill in "edit-title" with "autotest course package node"
    And I select "Melior" from "edit-field-course-package-template-und"
    And I fill in "edit-field-course-weeks-of-study-und-0-value" with "40"
    And I fill in "edit-field-course-prerequisites-und-0-value" with "Svenska"
    And I fill in "edit-field-course-scope-und-0-value" with "50"
#    And I fill in "edit-field-course-school-und" with "A1 Test school (1)" editor can't choose school
    And I fill in "edit-field-course-number-of-points-und-0-value" with "100"
    And I type "sadsad" in "edit-body-und-0-value" WYSIWYG editor
    And I fill in "edit-field-course-contact-person-und-0-value" with "contact person"
  And I fill in "edit-field-course-package-und-0-field-package-course-und-0-value" with "test course"
  And I fill in "edit-field-course-package-und-0-field-package-point-und-0-value" with "100"
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
    Then I am on "node/add/course-package-template"
    And I fill in "edit-title" with "autotest course package template"
    And I should not see "Publishing options"
    Then I press the "edit-submit" button
    And I should see the text "Course package template autotest course package template has been created."







