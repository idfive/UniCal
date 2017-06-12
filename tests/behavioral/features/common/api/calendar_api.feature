Feature: Test Programs API

 As an admin
 I want to test restful API of the calendar
 So that we can be sure it is up and running

 Scenario: Test the calendar event API endpoint
   Given I call "/api/events"
     Then I get a response
     And the response is JSON
     And the response contains at least one item

Scenario: Test the calendar event search API endpoint
  Given I call "/api/eventsearch/%20"
    Then I get a response
    And the response is JSON
    And the response contains at least one item

Scenario: Test the calendar site API endpoint
  Given I call "/api/sites"
    Then I get a response
    And the response is JSON
    And the response contains at least one item

Scenario: Test the calendar taxonomy 1 endpoint
  Given I call "/api/taxonomy_1"
    Then I get a response
    And the response is JSON
    And the response contains at least one item

Scenario: Test the calendar taxonomy 2 endpoint
  Given I call "/api/taxonomy_2"
    Then I get a response
    And the response is JSON
    And the response contains at least one item

Scenario: Test the calendar taxonomy 3 endpoint
  Given I call "/api/taxonomy_3"
    Then I get a response
    And the response is JSON
    And the response contains at least one item

Scenario: Test the calendar taxonomy 4 endpoint
  Given I call "/api/taxonomy_4"
    Then I get a response
    And the response is JSON
    And the response contains at least one item

Scenario: Test the calendar taxonomy 5 endpoint
  Given I call "/api/taxonomy_5"
    Then I get a response
    And the response is JSON
    And the response contains at least one item

Scenario: Test the calendar taxonomy 6 endpoint
  Given I call "/api/taxonomy_6"
    Then I get a response
    And the response is JSON
    And the response contains at least one item

Scenario: Test the calendar taxonomy 7 endpoint
  Given I call "/api/taxonomy_7"
    Then I get a response
    And the response is JSON
    And the response contains at least one item

Scenario: Test the calendar taxonomy 8 endpoint
  Given I call "/api/taxonomy_8"
    Then I get a response
    And the response is JSON
    And the response contains at least one item

Scenario: Test the calendar taxonomy 9 endpoint
  Given I call "/api/taxonomy_9"
    Then I get a response
    And the response is JSON
    And the response contains at least one item

Scenario: Test the calendar taxonomy 10 endpoint
  Given I call "/api/taxonomy_10"
    Then I get a response
    And the response is JSON
    And the response contains at least one item

Scenario: Test the calendar taxonomy 11 endpoint
  Given I call "/api/taxonomy_11"
    Then I get a response
    And the response is JSON
    And the response contains at least one item
