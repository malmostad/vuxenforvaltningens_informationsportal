Feature: Content creation
  In order to create and moderate content
  As any user
  I should be able to create and moderate

  @api
  Scenario: School editor
    Given I am logged in as a user with the "School editor" role
      And I am on "node/add"
      And I should see the text "Kurspaket" in ".admin-list" element
      And I should see the text "Enstaka kurs" in ".admin-list" element
      And I should see the text "Kursmall" in ".admin-list" element

  @api @javascript
  Scenario: School editor: Auto set school
    Given I am logged in as "editor" with the password "editor"
    And I am on "node/add/course"
    And I select "Gymnasial vuxenutbildning" from "Utbildningsform"
    And I wait for AJAX to finish
    And I select "A1 Test course template" from "Kurs mall"
        # Required
    And I select "Flexkurs" from "Kursform"
    And I select "A2 Test school" from "Skola"
    And I fill in "Sökkod" with "test"
    When I press "Save"
    Then I should see the text "A2 Test school"

  @api @javascript
  Scenario: School editor don't see registration field on course and course package creation
    Given I am logged in as "editor" with the password "editor"
    And I am on "node/add/course"
    Then I should not see the text "Course registration"
    And I am on "node/add/course-packages"
    Then I should not see the text "Course package registration"

  @api @javascript
  Scenario: School editor add course template
    Given I am logged in as a user with the "School editor" role
      And I am on "node/add/course-template"
      And I fill in "Titel" with "A1 test some course"
      And I select "Gymnasial vuxenutbildning" from "Utbildningsform"
      And I press "Save"
    Then I should see "A1 test some course"
    Given I am on "admin/content"
    Then I should not see the text "A1 test some course"
    Then I should not see the text "not published" in "#node-admin-content > div > table.sticky-enabled.tableheader-processed.sticky-table" element
    Given I am logged in as a user with the "Malmo middle admin" role
      And I am on "admin/content"
      And I press element "a:contains('A1 test some course')"
      And I press element "a:contains('Publish')"
    Then I should see "Unpublish"

  @api
  Scenario: Pure authenticated user
    Given  I am logged in as a user with the "authenticated user" role
    And I am on "node/add"
    And I should not see the text "Kurspaket" in ".admin-list" element
    And I should not see the text "Enstaka kurs" in ".admin-list" element
    And I should not see the text "Course template" in ".admin-list" element

  @api @javascript
  Scenario: Check if course is automatically assigned to correct Searchable type
    Given I am logged in as a user with the "authenticated user" role
    Given I am on "search-courses/Test%20course%204"
    Then I follow "Test course 4"
    Then I press the "Register" button
    Then I wait for AJAX to finish
    Then I am on "/my-planning"
    And I should see the text "Test course 4" in ".pane-my-courses-course-pane" element
