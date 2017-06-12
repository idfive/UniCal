Feature: Calendar
  In order to see events
    As a site visitor
    The calendar should display events.

  @javascript
  Scenario: Calendar Should be visible
    Given I am on "/calendar"
    When I wait for the app to load
    Then I should see "calendar"
        And I should see "events"

  @javascript
  Scenario: Calendar Should Filter
    Given I am on "/calendar"
    When I select "today" from "date-filter"
    Then I should see "Date range: Today"

  @javascript
  Scenario: Calendar Should load event detail on click
    Given I am on "/calendar"
    When I wait for the app to load
    When I click the ".unical-calendar__event-title a" element
    When I wait for the app to load
    Then I should see "Back to Calendar"
