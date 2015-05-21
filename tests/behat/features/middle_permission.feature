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
    And I should see the text "Kursmall" in ".admin-list" element
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
    And I select "Gymnasial vuxenutbildning" from "Utbildningsform"
    And I wait for AJAX to finish
    And I select "A1 Test course template" from "Kurs mall"
    # Required
    And I select "Flexkurs" from "Kursform"
    And I select "A2 Test school" from "Skola"
    And I fill in "Sökkod" with "test"

    Then I press the "edit-submit" button

    And I should see "Enstaka kurs A1 Test course template has been created."
    Then I click "Edit"
#    And the "edit-status" checkbox should be checked
    Then I am on "node/add/course-packages"
    And I fill in "Titel" with "A1 Test course template"
        # Required for course
    And I check the box "Klassrumsundervisning"
    And I select "A2 Test school" from "Skola"
    And I fill in "Sökkod" with "test"
    And I type "test" in "edit-body-und-0-value" WYSIWYG editor
    And I fill in "Kontaktperson" with "test"
    And I fill in "edit-field-course-package-und-0-field-package-course-und-0-value" with "test"
    And I fill in "edit-field-course-package-und-0-field-package-point-und-0-value" with "233"
    And I fill in "Omfattning " with "23"
    And I fill in "Antal studieveckor" with "2"

    Then I press the "edit-submit" button
    And I should see "Kurspaket A1 Test course template has been created."
    Then I click "Edit"
#    And the "edit-status" checkbox should be checked
    # todo need add test course package and return to search.feature
    Given I am on the homepage
    And I press "Search"
    And I press element ".minipanel-search-facet.pane-title"
    And I should see the text "Inriktningar för kurspaket"



  Scenario: Unpublished course template and course package template creating
    Given I am logged in as a user with the "Malmo middle admin" role
    And I am on "node/add/course-template"
    And I fill in "edit-title" with "autotest course template"
    And I select "Gymnasial vuxenutbildning" from "Utbildningsform"
#    And I should see "Publishing options"
#    And the "edit-status" checkbox should be checked
    Then I press the "edit-submit" button
    And I should see the text "Kursmall autotest course template has been created."
