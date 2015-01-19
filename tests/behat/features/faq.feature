Feature: Faq
  In order to find answer to my question
  As any user
  I should be able to see the faq page

  @javascript
  Scenario: Answers should be hidden
    Given I am on the homepage
    When I click "Frågor och svar"
    Then I should see the heading "Frågor och svar"
    Then I should not see container with class "answer"

  Scenario: Test sort page
    Given I am on "admin/faq"
    Then I should not get a "200" HTTP response
