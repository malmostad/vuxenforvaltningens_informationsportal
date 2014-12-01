Feature: Content creation
  In order to create and moderate content
  As any user
  I should be able to create and moderate

  @api
  Scenario: School editor
    Given I am logged in as a user with the "School editor" role
      And I am on the homepage
    Then I should see the text "Content" in "#admin-menu-menu" element
      And I should see the text "Add content" in "#admin-menu-menu" element
      And I should see the text "Course" in "#admin-menu-menu" element
      And I should see the text "Course package" in "#admin-menu-menu" element
      And I should see the text "Course template" in "#admin-menu-menu" element

  @api
  Scenario: School editor: Auto set school
    Given I am logged in as "editor" with the password "editor"
    And I am on "node/add/course"
    And I fill in "Course template" with "A1 Test course template"
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
  Scenario: Malmo middle admin
    Given  I am logged in as a user with the "Malmo middle admin" role
    And I am on the homepage
    Then I should see the text "Content" in "#admin-menu-menu" element
    Then I should see the text "Add content" in "#admin-menu-menu" element
    Then I should see the text "Course" in "#admin-menu-menu" element
    Then I should see the text "Course package" in "#admin-menu-menu" element
    Then I should see the text "Course template" in "#admin-menu-menu" element

  @api
  Scenario: Pure authenticated user
    Given  I am logged in as a user with the "authenticated user" role
    And I am on the homepage
    Then I should not see the text "Content" in "#admin-menu-menu" element
    Then I should not see the text "Add content" in "#admin-menu-menu" element
    Then I should not see the text "Course" in "#admin-menu-menu" element
    Then I should not see the text "Course package" in "#admin-menu-menu" element
    Then I should not see the text "Course template" in "#admin-menu-menu" element
