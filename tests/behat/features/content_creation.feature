  Feature: Content creation
  In order to create and moderate content
  As any user
  I should be able to create and moderate

#  @api
#  Scenario: School editor
#    Given I am logged in as a user with the "School editor" role
#      And I am on the homepage
#    Then I should see the text "Content" in "#admin-menu-menu" element
#      And I should see the text "Add content" in "#admin-menu-menu" element
#      And I should see the text "Course" in "#admin-menu-menu" element
#      And I should see the text "Course package" in "#admin-menu-menu" element
#      And I should see the text "Course package template" in "#admin-menu-menu" element
#      And I should see the text "Course template" in "#admin-menu-menu" element
#
#  @api
#  Scenario: School editor add course template
#    Given I am logged in as a user with the "School editor" role
#      And I am on "node/add/course-template"
#      And I fill in "Title" with "test some course"
#      And I press "Save"
#    Then I should see "test some course"
#    Given I am on "admin/content"
#    Then I should see "test some course"
#      And I should see the text "not published" in "#node-admin-content" element
#    Given I am logged in as a user with the "Malmo middle admin" role
#      And I am on "admin/content"
#      And I press element "a:contains('test some course')"
#      And I press element "a:contains('Publish')"
#    Then I should see "Unpublish"
#
#  @api
#  Scenario: Malmo middle admin
#    Given  I am logged in as a user with the "Malmo middle admin" role
#    And I am on the homepage
#    Then I should see the text "Content" in "#admin-menu-menu" element
#    Then I should see the text "Add content" in "#admin-menu-menu" element
#    Then I should see the text "Course" in "#admin-menu-menu" element
#    Then I should see the text "Course package" in "#admin-menu-menu" element
#    Then I should see the text "Course package template" in "#admin-menu-menu" element
#    Then I should see the text "Course template" in "#admin-menu-menu" element
