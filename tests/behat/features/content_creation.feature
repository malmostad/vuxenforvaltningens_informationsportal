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
      And I should see the text "Course template" in ".admin-list" element

  @api
  Scenario: School editor: Auto set school
    Given I am logged in as "editor" with the password "editor"
    And I am on "node/add/course"
    And I fill in "Kurs mall" with "A1 Test course template"
        # Required
    And I fill in "Course form" with "Flexkurs"
    And I fill in "School" with "A1 Test school (1)"
    And I fill in "Course Group" with "test"
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
      And I fill in "Title" with "A1 test some course"
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