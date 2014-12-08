@api @course_registration
Feature: Middle admim permission
  Checking middle admin permissions
  As middle admin
  Middle admin has permission from http://conf.propeople.com.ua/pages/viewpage.action?title=Permissions&spaceKey=MAL

  Scenario: Proper content available to add
    Given I am logged in as a user with the "Malmo middle admin" role
    And I am on "node/add"
    And I should see the text "Kurspaket" in ".admin-list" element
    And I should see the text "Enstaka kurs" in ".admin-list" element
    And I should see the text "Kurs mall" in ".admin-list" element
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
    And I fill in "Kurs mall" with "A1 Test course template"
    And I press the "insert" key in the "Kurs mall" field
    And I wait for 1 seconds
    And I press element ".reference-autocomplete"
    Then I press the "edit-submit" button
    # Required
    And I fill in "Kursform" with "Flexkurs"
    And I fill in "Skola" with "A1 Test school (1)"
    And I fill in "Kursgrupp" with "test"

    Then I press the "edit-submit" button

    And I should see "Enstaka kurs A1 Test course template has been created."
    Then I click "Edit"
    And the "edit-status" checkbox should be checked
    Then I am on "node/add/course-packages"
    And I fill in "Titel" with "A1 Test course template"
        # Required for course
    And I fill in "Kurs formulär" with "Flexkurs"
    And I fill in "Skola" with "A1 Test school (1)"
    And I fill in "Kurs group" with "test"
    And I type "test" in "edit-body-und-0-value" WYSIWYG editor
    And I fill in "Kontaktperson" with "test"
    And I fill in "edit-field-course-package-und-0-field-package-course-und-0-value" with "test"
    And I fill in "Poäng" with "233"
    And I fill in "Omfattning " with "23"
    And I fill in "Antal studieveckor" with "2"

    Then I press the "edit-submit" button
    And I should see "Kurspaket A1 Test course template has been created."
    Then I click "Edit"
    And the "edit-status" checkbox should be checked


  Scenario: Unpublished course template and course package template creating
    Given I am logged in as a user with the "Malmo middle admin" role
    And I am on "node/add/course-template"
    And I fill in "edit-title" with "autotest course template"
    And I should see "Publishing options"
    And the "edit-status" checkbox should be checked
    Then I press the "edit-submit" button
    And I should see the text "Kurs mall autotest course template has been created."
