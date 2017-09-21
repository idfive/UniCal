API 1.0
-------
This entire application works via REST, so we need to have a pretty robust API.
We based this on the RESTful module by gizra/et al, because, well, we like it.
It is based off the 1x version of the RESTful module. Patches will be accepted
to branch this to the 2x version.
* Uses the RESTful module
* Defines all endpoints in /plugins/restful
* A reference of the API base we used to build this:
  https://github.com/RESTful-Drupal/restful/blob/7.x-1.x/docs/api_url.md
* The API returns events from the MASTER via JSON.
* You may use an HTTP OPTIONS request to the endpoint, to see things like
  taxonomy terms, fields, etc.
* See available endpoints at: http://your.site/api
* EXAMPLE: Events Endpoint: http://your.site/api/events
* Use these endpoints for other fun stuff too!  

Current Endpoints (08/25/16):  
All available Sample endpoints may be seen by pointing a GET request to: http://staging.idfive.com/calendar/api

Used UniCal endpoints:
* Events: Main events endpoint, sample: http://staging.idfive.com/calendar/api/events
* Sites: Gives available sites. Individual sites control what info/etc gets displayed, sample: http://staging.idfive.com/calendar/api/sites
* Event Search: Runs simple event search. This will eventually (likely) replace the Events endpoint, sample: http://staging.idfive.com/calendar/api/eventsearch/%20 (NOTE: the "%20" is simply a blank placeholder for a term)
* Taxonomies 1-11: These are separate endpoints for each taxonomy, to pull terms/etc for filtering, sample: http://staging.idfive.com/calendar/api/taxonomy_1 (NOTE: change endpoint to taxonomy_2, taxonomy_3, etc).

Available for custom applications, but not really used stock:
* CSRF token: CURRENTLY NOT IN PRODUCTION USE. There to authenticate against drupal, if needed, for custom builds.
* Login: CURRENTLY NOT IN PRODUCTION USE. There to authenticate against drupal, if needed, for custom builds.
* User: CURRENTLY NOT IN PRODUCTION USE. There to authenticate against drupal, if needed, for custom builds.


GET Requests:  
GET Requests return the following:
* data: object with the results of the current query
* count: number of results available in current query
* self: array of info on current page
* next: array of info on the next page of results, if applicable  

Options/filters:  
* range: Use this to specify the number of results you wish to receive. E.g.,
  http://your.site/api/events?range=2 returns two results.  
* page: Return a certain page of results, based on using range. E.g.,
  http://your.site/api/v1.0/events?range=2&page=2 returns page two of the above
  request.  
* fields: Use this to reduce which fields are returned via JSON, if
  needed/wanted. E.g., http://your.site/api/events?fields=id,label returns just
  the ID and Label. It is worth noting that any field that contains an array, will need the specifics added, ie, fields=image.image_styles.large,image.alt
* sort: by default it is ascending, but it can be prefixed by a - for DESC. You
  can use most fields returned for this. E.g., http://your.site/api/events?sort=label
  returns results sorted alphabetically by label, while
  http://your.site/api/events?sort=-label returns the same results, DESC.
* filter: (see https://github.com/RESTful-Drupal/RESTful/blob/7.x-1.x/docs/api_url.md)
  In general, we can filter entities that have properties defined in the entity,
  or the field API.

We can also use limited operators--see examples in code for more--but this gets
complex fast. It can also take multiples. E.g., http://your.site/api/events?filter[taxonomy_2][value][0]=31&filter[taxonomy_2][operator][0]="IN"
returns results with taxonomy TID 31 in taxonomy_2 field.

Additional Filter Fields:
* featured | 1,0 | Used to define if an event is featured in slider for site
  calendars, if enabled.
* promoted | 1,0 | Used to define if an event should show in a secondary feed,
  usually on a homepage/etc.
* see /plugins/restful/TYPE.class files for field definitions in the API.  

Specific Endpoint Definitions:
------------------------------
Below is a loose definition of endpoint data, see referenced example links for exact structure.

Events:
(http://staging.idfive.com/calendar/api/events, or http://staging.idfive.com/calendar/api/events/ID for individual events)

id: Drupal node ID
label: Node Title
self: link to REST endpoint for individual event
body: main body text
body_trimmed: teaser
summary: content summary
image: image object of size options
date: object of dates formatted for different areas of the application
clndrDate: object of dates, if it should be added to mini calendar
timezone: timezone;
uri: the slug the angular app should use for this event
address: object with street address
map_zoom: Zoom level of google map
map_center_lat: Latitude of map center, for address override
map_center_lng: Longitude of map center, for address override
taxonomy_1 through taxonomy_6: object with the ID's of any terms for each vocabulary
venue_name: Name of venue
venue_url: url link to venue
cost: cost, in USD
free: boolean, if free event or not
rsvp_text: Custom text for "How to RSVP"
rsvp_ticket: external ticket URL
rsvp_how_to: text on how to rsvp
rsvp_phone: phone number to call to rsvp
rsvp_email: email to rsvp
organizer_name: name of the organizer
organizer_phone: phone number of organizer
organizer_email: email of organizer
organizer_facebook: facebook event page of organizer
organizer_twitter: twitter feed of organizer
submitter_name: name of person submitting event
submitter_phone: phone number of person submitting event
submitter_email: email of person submitting event
organizer_same_as_submitter: boolean, if organizer and submitter are same person
event_website: URL of event website
event_facebook: URL of event facebook page
event_twitter: URL of event twitter feed
featured: boolean, if this event should be featured in slider or custom places
promoted: boolean, used for custom applications, ie, "show this on my homepage feed"
repeating_date_description: If this is a repeating event, it "repeats every sunday" or the like
exclude_from_main_calendar: boolean, excludes the event from master calendar if true


Sites:
(http://staging.idfive.com/calendar/api/sites or http://staging.idfive.com/calendar/api/sites/ID for individual)

id: node id
label: node Title
self: REST endpoint for individual site
taxonomy_1_enabled through taxonomy_11_enabled: boolean, whether or not each specific taxonomy is enabled for this site/calendar
taxonomy_1_label through taxonomy_11_label: The label you want to give that taxonomy
taxonomy_1_selected through taxonomy_11_selected: object of term ID's that should be preselected
taxonomy_1_weight through taxonomy_11_weight: The vocabularies weight, for ordering of filters
add_to_calendar_exclude: boolean, whether or not to exclude the add to calendar feature
allow_event_submit: boolean, to allow the event submit form or not
allow_users_to_choose_taxonomy_when_submitting: boolean, whether or not to allow users to choose categories when submitting
allow_featured_events: boolean, whether or not to show the featured events slider
allow_archive: boolean, whether to show the events archive or not
google_maps_api_key: api key for google map address preview
default_event_image: image object of default image for events, if none chosen on actual event
text_above_filters: any help text above the filters
help_link: URL where a user can go for help with this calendar
main_calendar_site: boolean, main calendar for organization or not
number_results_per_page: how many results are shown on the events page
text_above_sidebar: any custom text above the sidebar


Event Search:
(http://staging.idfive.com/calendar/api/eventsearch/%20)
A slimmed down version of events endpoint for search results. This will likely become main endpoint in UniCal 2.0 (with above fields added)

id: Node ID
relevance: relevance related to search request
label: Title
body_trimmed: truncated version of body
image: image object of size options
date: object of dates formatted for different areas of the application
timezone: timezone;
uri: the slug the angular app should use for this event
address: object with street address
exclude_from_main_calendar: boolean, excludes the event from master calendar if true


Taxonomies:
(http://staging.idfive.com/calendar/api/taxonomy_1, http://staging.idfive.com/calendar/api/taxonomy_2, etc)

id: drupal TID
label: term name
self: REST url to individual term
