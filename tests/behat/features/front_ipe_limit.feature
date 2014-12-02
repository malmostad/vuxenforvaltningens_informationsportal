@api @course_registration
Feature: Front page in-place-editor
  In order to use ipe comfortable
  As any top malmo admin and administrator
  I should not see redundant page content panes

  @api @javascript
  Scenario: Administrators see only required page content panes
  Given I am logged in as a user with the "administrator" role
    And I am on the homepage
    And I press element "a:contains('Customize this page')"
    Then I wait for AJAX to finish
    And I press element "a:contains('Add new pane')"
    Then I wait for AJAX to finish
    Then I should see the text "New custom content"
    And I should see the text "Global pane"
    And I should not see the text "Activity"
    And I should not see the text "FacetAPI"
    And I should not see the text "Menus"
    And I should not see the text "Minipanel"
    And I should not see the text "Miscellaneous"
    And I should not see the text "Pageelements"
    And I should not see the text "Propeople"
    And I should not see the text "SearchAPISorts"
    And I should not see the text "Viewpanes"
    And I should not see the text "Views"
    And I should not see the text "Widgets"
