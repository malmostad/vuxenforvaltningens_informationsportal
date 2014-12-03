@api @front_banner_default
Feature: Front banner default
  In order to check functionality of default value for front banner
  As any user
  I should be able to see image of the banner

  @javascript
  Scenario: Image should be available
    Given I am on the homepage
    And the response should contain "banner-image"
