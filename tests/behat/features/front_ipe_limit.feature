@api @course_registration
Feature: Front page in-place-editor
  In order to use ipe comfortable
  As any top malmo admin and administrator

  @api @javascript
  Scenario Outline: Other underlying roles not see in-place editor
  Given I am logged in as a user with the "<role>" role
    And I am on the homepage
    And I press "Customize this page"
    Then I wait for AJAX to finish
    Then I press "Add new pane"
    Then I wait for AJAX to finish
    Then I should see the text "New custom content"
    And I should see the text "Global pane"
    And I should not see the text "<pane_types>"

  Examples:
  |  role               |
  |  Malmo top admin    |
  |  administrator      |

  Examples:
  |  pane_types       |
  |  Activity         |
  |  Facet API        |
  |  Menus            |
  |  Mini panel       |
  |  Miscellaneous    |
  |  Page elements    |
  |  Propeople        |
  |  Search API Sorts |
  |  View panes       |
  |  Views            |
  |  Widgets          |