@api @custom_hint
Feature: Custom hints
  In order to provide/get more information about elements
  As any top malmo admin and administrator
  I should be able to add hints to any page element
  As any user i should be able to see hints

  @api @javascript
  Scenario: Check ability to add and see hints
  Given I am logged in as a user with the "administrator" role
    And I am on "admin/config/system/mal-hint"
    And I fill in "edit-hints-items-0-selector" with ".pane-menu-menu-global-menu .pane-title"
    And I fill in "edit-hints-items-0-hint" with "Test hint"
    And I press "Save"
    Then I am on the homepage
    And I hover over the element ".hint"
    And I should see the text "Test hint"
