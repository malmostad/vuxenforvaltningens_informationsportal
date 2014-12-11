@api @course_registration
Feature: Course register
  Test if registration module and course registration field and registration
  permissions were setupped correctly. Also test how "Register widget works".

  @api @javascript
  Scenario: Anonymous user does not see Registration button.
    Given I am on "search-courses/Test%20course%203"
    Then I should not see a "#user-register-unregister-form" element
    Then I should not see a "#registration-form" element
    Then I click "Test course 3"
    Then I should not see a "#user-register-unregister-form" element
    Then I should not see a "#registration-form" element
    Then I should see "Log in or register to subscribe the course."

  @api @javascript
  Scenario: Check if registration updates sedebar menu
    Given I am logged in as a user with the "authenticated user" role
    Given I am on "search-courses/Test%20course%203"
    Then I follow "Test course 3"
    Then I press the "Register" button
    Then I wait for AJAX to finish
    And I should see the text "Mina val" in ".courses-menu-block" element
    And I should see the text "Test course 3" in ".courses-menu-block" element

  @api @javascript
  Scenario: Check if authorized user see and can use register button
    Given I am logged in as a user with the "authenticated user" role
    Given I am on "search-courses/Test%20course%203"
    Then I press the "Register" button
    Then I wait for AJAX to finish
    Then I press the "Unregister" button
    Then I wait for AJAX to finish
    Then I click "Test course 3"
    Then I press the "Register" button
    Then I wait for AJAX to finish
    Then I press the "Unregister" button
    Then I wait for AJAX to finish
    Then I press the "Register" button
    Then I wait for AJAX to finish
    Then I am on "my-planning"
    And I should see the text "Test course 3"

  @api @javascript
  Scenario: Check that "My planning" components are hidden while there's no corresponding courses in subscription.
    Given I am logged in as a user with the "authenticated user" role
    Given I am on "my-planning"
    Then I should not see the text "Kurs" in ".tabs" element
    Then I should not see the text "Kurspaket" in ".tabs" element
    Then I should not see the text "Veckoöversikt" in ".tabs" element
    Then I should not see the text "Ansökningslista" in ".tabs" element
    Then I should not see the text "Överlappande kurser" in ".tabs" element

  @api @javascript
  Scenario: Check that course subscription doesn't reveal components for course packages.
    Given I am logged in as a user with the "authenticated user" role
    Given I am on "search-courses/Test%20course%203"
    Then I follow "Test course 3"
    Then I press the "Register" button
    Then I wait for AJAX to finish
    Then I am on "my-planning"
    And I should see the text "Kurs"
    And I should not see the text "Kurspaket" in ".tabs" element

  @api @javascript
  Scenario: Check that course package subscription doesn't reveal components for courses.
    Given I am logged in as a user with the "authenticated user" role
    Given I am on "search-courses/Test%20course%20package"
    Then I follow "Test course package"
    Then I press the "Register" button
    Then I wait for AJAX to finish
    Then I am on "my-planning"
    And I should see the text "Kurspaket" in ".tabs" element
    And I should not see the text ">Kurs<" in ".tabs" element
