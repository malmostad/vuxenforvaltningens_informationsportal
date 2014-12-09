Feature: Faq
  In order to find answer to my question
  As any user
  I should be able to see the faq page

  Background:
    Given I am on the homepage
    When I click "Frågor och svar"
    Then I should see the heading "Frågor och svar"
    Then I should see the text "Gemensam" in ".faq-list-questions" element

  @javascript
  Scenario: Answers should be hidden
    Then I should not see container with class "answer"
