@api @course_registration
Feature: Editors permission
  Checking editors permissions
  As editor
  Editor has permission from http://conf.propeople.com.ua/pages/viewpage.action?title=Permissions&spaceKey=MAL

  Scenario: Unpublished course template and course package template creating
    Given I am logged in as a user with the "School editor" role
    And I am on "node/add/course-template"
    And I fill in "edit-title" with "autotest course template"
    And I select "Gymnasial vuxenutbildning" from "Utbildningsform"
    And I should not see "Publishing options"
    Then I press the "edit-submit" button
    And I should see the text "Kurs mall autotest course template has been created."
