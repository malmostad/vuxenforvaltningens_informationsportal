@api
Feature: Front page in-place editor
  In order to edit front page comfortably
  As any top malmo admin and administrator
  I should be edit page in place

  Scenario Outline: Other underlying roles not see in-place editor
    Given I am logged in as a user with the "<role>" role
    And I am on the homepage
    Then I should <visibility> the text "Customize this page"

  Examples:
    |  role               | visibility |
    |  anonymous user     |  not see   |
    |  authenticated user |  not see   |
    |  School editor      |  not see   |
    |  Malmo middle admin |  not see   |
    |  Malmo top admin    |   see      |
    |  administrator      |   see      |
