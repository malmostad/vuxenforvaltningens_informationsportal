Feature: Breadcrumbs
  In order to well orient on site
  As any user
  I should see breadcrumbs

  @api
  Scenario: Front page breadcrumb
    And I am on the homepage
    Then I should see the text "Home" in ".breadcrumb" element
    And I should see the text "Information portal" in ".breadcrumb" element
    And I should see the text "Rubrik" in ".breadcrumb" element

  @api
  Scenario: School view breadcrumb
    And I am on "schools"
    And I should see the text "Schools" in ".breadcrumb" element
    When I click "A1 Test school"
    And I should see the text "Schools" in ".breadcrumb" element
    And I should see the text "A1 Test school" in ".breadcrumb" element
