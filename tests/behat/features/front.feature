Feature: Front
  In order to find best blocks ever
  As any user
  I should be able to see the blocks on homepage

  @api
  Scenario: Front blocks
    Given I am on the homepage
    Then I should see the text "Title 1"
    Then I should see the text "Title 2"
    Then I should see the text "Title 3"
    Then I should see the text "Show more"

