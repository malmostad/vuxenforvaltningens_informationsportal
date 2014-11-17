Feature: Front
  In order to find best blocks ever
  As any user
  I should be able to see the blocks on homepage

  @api
  Scenario: Front blocks
    Given I am on the homepage
    Then I should see the text "Grundläggande vuxenutbildning"
    Then I should see the text "Mer om grundläggande vuxenutbildning"
    Then I should see the text "Gymnasial vuxenutbildning"
    Then I should see the text "Boxrubrik"
    Then I should see the text "Footer social"
    Then I should see the text "Facebook"
    Then I should see the text "Linkedin"

