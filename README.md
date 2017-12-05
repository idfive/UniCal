INTRODUCTION
============
UniCal stands for either Universal Calendar or University Calendar. Dealer’s
choice. It is an Angular.js-based events calendar application, based on the
headless/decoupled Drupal approach, and the COPE principle.  For more information
see the project homepage at http://unical.idfive.com.

This app/module is collaboratively designed and maintained by idfive and Howard
University. It serves a sortable list/calendar of events that can be embedded as
a page in third-party CLIENT site(s) as either a native Drupal module, or simply
via JS/HTML embed code.

The complete UniCal system consists of the following:

* UniCal (unical): This module provides the API, files, content types, and magic
  that generates everything.
* Unical Features (unical_features): This sub module is included with UniCal, and its
  function is to provide initial content type/taxonomy setup.
* Unical Feeds (unical_feeds): This sub module is included with UniCal, and its
  function is to provide initial feed setup/etc if you would like to use UniCal in
  conjunction with the feeds module.
* UniCal Client (unical_client): This module is it's own project, and available for download at
  (https://github.com/idfive/UniCal-Client) This module allows you to embed a calendar in
  any Drupal site, anywhere, that will read via REST to the install where a
  UniCal site exists.
* UniCal Styles (unical_styles): This module is it's own project, and available for download at
  (https://github.com/idfive/UniCal-Styles) This module allows you to customize the calendar css,
  and have them available to all client sites that choose to reference it.

The idea is that any enterprise/organization utilizing UniCal will most likely
need a "clean" Drupal install to act as the MASTER, serving events via REST to
be consumed elsewhere. This module "may" be deployed on existing installs, but
we would strongly encourage extensive testing against your pre-existing
modules/config. READ: We haven't tested against your specific, existing install,
nor do we plan to.

Here are few basic principles we refer to:
* MASTER: Generally, we mean the Drupal install that is running the UniCal
  module. This is the install that serves the REST endpoint, and where you input
  content.
* CLIENT: Either the same install, or any other, where you run the front-end code.
  This may occur: * on the MASTER install by looking at the SITE node page,
  - using either UniCal client module, or 
  - embedding the SITE JS wherever you darn well please.
* SITE: Essentially, the result of your calendar(s). You create it in the MASTER
  install, then reference the site ID via the CLIENT. That gives you all your
  nifty pre-filters/etc.

The basic process:
* Create a SITE on MASTER install. Determine the types of   events that will
  appear by choosing to pre-filter by taxonomy. E.g., create an "arts" SITE that
  only serves events tagged with "art department" in one of your taxonomies.
* Use the UniCal Client Module, or provided JS/HTML, to render that SITE on any
  CLIENT server you choose, as long as it can connect to the MASTER for the REST
  call.
* Repeat. Make as many SITES as you want: athletics, English department, etc.
  The more the merrier. The strength of the SITE approach is that you can
  customize the selected, and available, events and taxonomies.

REQUIREMENTS
------------
The UniCal module requires the following modules:
* Plug (https://www.drupal.org/project/plug)
* RESTful (https://www.drupal.org/project/restful) 2.x
* RESTful Search API (https://www.drupal.org/project/restful_search_api)
* Search API (https://www.drupal.org/project/search_api)
* CORS (https://www.drupal.org/project/cors)
* Entity API (https://www.drupal.org/project/entity)
* jQuery Update (https://www.drupal.org/project/jquery_update)
* UniCal Client (https://github.com/idfive/UniCal-Client)

The Unical Features module requires the following modules to create the site and
event content types:
* Features (https://www.drupal.org/project/features)
* Entity API (https://www.drupal.org/project/entity)
* Date (https://www.drupal.org/project/date)
* Address Field (https://www.drupal.org/project/addressfield)
* Email (https://www.drupal.org/project/email)
* Field Group (https://www.drupal.org/project/field_group)
* Link (https://www.drupal.org/project/link)
* Time Zone Field (https://www.drupal.org/project/tzfield)
* UUID (https://www.drupal.org/project/uuid)
* UUID Features (https://www.drupal.org/project/uuid_features)
* Search API (https://www.drupal.org/project/search_api)
* Search API DB (https://www.drupal.org/project/search_api_db

The UniCal Feeds module requires the following, to set up automated event feed ingestion:
* Features (https://www.drupal.org/project/features)
* ctools (https://www.drupal.org/project/ctools)
* Entity API (https://www.drupal.org/project/entity)
* Feeds (https://www.drupal.org/project/feeds)
* Job Scheduler (https://www.drupal.org/project/job_scheduler)
* Date iCal (https://www.drupal.org/project/date_ical)
* Libraries (https://www.drupal.org/project/libraries)
* Views (https://www.drupal.org/project/views)

RECOMMENDED MODULES
-------------------
* Markdown filter (https://www.drupal.org/project/markdown): When enabled, this
  module displays the UniCal project's README.md Help will be rendered with
  markdown, on the help page.
* UniCal Styles (https://github.com/idfive/UniCal-Styles) This module allows you
  to customize the calendar css, and have them available to all client sites that
  reference it, letting you set global styles for all your SITE calendars.

INSTALLATION
------------
* Install as you would normally install a contributed Drupal module. See:
  https://drupal.org/documentation/install/modules-themes/modules-7 for further
  information.
* UniCal module should be installed in sites/all/modules folder, or the JS embed
  code for sites will need to be modified, to use a different path.
* Enable and set up UniCal Features to use the content types and taxonomies needed.
  This module has its own dependencies, but can be turned off once Content Types,
  Taxonomies, etc are created.
* If desired, enable and set up UniCal Feeds, if you wish to utilize the iCal importer.
  This module has its own dependencies, but provides a basis for feeds support that
  can be extended via stock, and custom importers based around the feeds module.
* Check that the server is serving REST at the endpoints.
* If serving across other sites/servers, be sure CORS is properly set up.
* Modify .htaccess file, as shown in configuration.

CONFIGURATION
=============
The module has no menu or modifiable settings. You will however, need to configure the
UniCal Features module, and search api endpoint.

You will need to modify your .htaccess (or make a similar mod on non apache servers)
In order to be able to go directly to non-hashbang url's in the app. This is because
we are using html5 mode in the angular application,

.htaccess MODS:
--------------
Some modifications are necessary to both re-route social bots the actual node
page (php) of the main site, in order for bots to be able to scrape event information, and another
to allow use of non-hashbang urls. The second is necessary to tell/trick drupal into not looking for
a page at that path, but rather redirect to the calendar, and let it take the url from there. Necessary
in order to go directly to an event page/etc. The following rules assume that your events are in the
standard UniCal format of /event/NID/TITLE.

  ```
  # Allow social media crawlers to work by redirecting them to a server-rendered static version on the page
  RewriteCond %{HTTP_USER_AGENT} (facebookexternalhit/[0-9]|Twitterbot|Pinterest|Google.*snippet)
  RewriteRule event/(.*)/(.*) %{HTTP_HOST}/node/$1 [P]

  # Workaround to be able to use non # url in the calendar
  RewriteCond %{HTTP_USER_AGENT} !(facebookexternalhit/[0-9]|Twitterbot|Pinterest|Google.*snippet)
  RewriteCond %{REQUEST_URI} !^/admin
  RewriteRule event/(.*)/(.*) http://%{HTTP_HOST}/#%1/event/$1/$2 [NE,L]
  ```

SEARCH API SETUP
---------------
* Create an index of node type event (events_index) with your chosen search api server. Enable title and body fields on the index. This is created by default if using unical_features.
* This is now available via REST at /api/eventsearch/YOUR_TERM. This is what powers the events search box.

GENERAL INFO
===============

CRON
---------------
UniCal adds a cron job to remove past repeating events from single nodes, which happens on standard cron run. If you are using Date Repeat Entity Module to make repeated dates individual nodes, this should be skipped. This fix has been hardcoded for now, but roadmap plans include a settings option to run unical cron or not.

TROUBLESHOOTING
---------------
* If the endpoint does not display, check the following:   - Is CORS set up?
-- Have you added some test content?

KNOWN CONFLICTS
---------------
* Global Redirect Module. Affects the angular form submit. Will look into as time
  allows.
* Workbench Module. Can affect Feeds importers, depending on settings. May need to
  be temporarily disabled to import, as a workaround.
* AdvAgg Module. Moving all inline js to the bottom of the page can break the client/embed,
  as its settings potentially can be called before drupal.js.
* Date Repeat Entity Module. Requires unical cron function for standard events to be skipped.
  This fix has been hardcoded for now, but roadmap plans include a settings option to
  run unical cron or not.

API 1.0
-------
This entire application works via REST, so we need to have a pretty robust API.
We based this on the RESTful module by gizra/et al, because, well, we like it.

* Uses the RESTful module
* Defines all endpoints in /plugins/restful
* A reference of the API base we used to build this:
  https://github.com/RESTful-Drupal/restful/blob/7.x-1.x/docs/api_url.md
* The API returns events from the MASTER via JSON.
* You may use an HTTP OPTIONS request to the endpoint, to see things like
  taxonomy terms, fields, etc.
* See all available endpoints at: http://your.site/api
* EXAMPLE: Events Endpoint: http://your.site/api/events
* Use these endpoints for other fun stuff too!

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

CONTENT TYPES
-------------
We employ two different Content Types for UniCal: Events and Sites. These are
defined in the UniCal Features Module.

Event Content Type:
* Defines events that show up on the calendar and throughout the API.
* Each Event can be categorized within the taxonomies (1-6), and then subsequently
  filtered on the front end.

Site Content Type:
* Used to define presets/etc for embedding the front end of the calendar
  elsewhere. Essentially, think of a site as an instance of the calendar that
  you can customize.
* Sites can be set up to pre-filter by taxonomy (1-6) and can also handle custom
  naming conventions/labels for each taxonomy.
* Sites CT uses a custom .tpl located in /templates/node--site.tpl. We use this,
  so we can show things to the admins, like the custom embed code/etc per site,
  in order to pass along the code with all presets/etc needed. It also provides
  the JS embeds/etc needed to show the calendar (per site) so simply going to the
  node page of the site will show end users that calendar/etc.

TAXONOMIES
----------
UniCal uses 11 predefined taxonomies (machine names calendar_taxonomy_1 through calendar_taxonomy_11).
These can eventually be renamed/etc, as long as THE MACHINE NAME STAYS THE SAME. One taxonomy
(calendar_taxonomy_7) is predefined as a list to show/hide "Add To Calendar" Links.
* calendar_taxonomy_1 through calendar_taxonomy_6, and calendar_taxonomy_8 through
  calendar_taxonomy_11 are custom "event category taxonomies". These titles/etc can
  be changed, as long as THE MACHINE NAME STAYS THE SAME. Also, these can also be deleted,
  if needed. Essentially, this gives you the use of up to 10 custom event taxonomies.
* Taxonomies can include a "Hide From Submission field (field_hide_from_submission)" that if checked,
  will hide that particular term in the UniCal submission form.
* calendar_taxonomy_7 is the add to calendar taxonomy, which should not be modified.
  This taxonomy is called for in the SITE, and relies on field_ate_id to remove unwanted "Add This Event" options. We have added these into the features, but for reference, here they are
  in the format of Name | ATE ID:
  * Apple iCal | appleical
  * Google (Online) | google
  * Outlook | outlook
  * Outlook (Online) | outlookcom
  * Yahoo (Online) | yahoo

Extending UniCal
=========

PRE-POPULATING RESULTS
----------------------
Taxonomies may be pre-populated on a page by passing parameters through the url.
To do this, pass the following:
* Pass the taxonomy_machine_name
* Pass the TID of the term you wish.

For example, http://your.site/calendar?taxonomy_1=1&taxonomy_2=2 would pre-populate
taxonomy_1 with TID 1, and pre-populate taxonomy_2 with TID 2.

CUSTOM LOADING SCREEN
---------------------
By default a div with the parameters of
  ```
  <div id="unical-calendar-loading" class="loading">
  ```
gets added to the application when loading the events list, or individual events. You may override
this, by adding your own div with the ID of "unical-calendar-loading", and styling as desired.
The JS would then hide/show that div instead. The class "loading" on the stock div is what
gives it the moving circle and overlay. Note that this class is still used when filtering events.

HOOKS
-----
Several JS hooks are available for hooking custom JS functions into UniCal events.
To use these, add var UniCal into your own custom JS, which is called before unical.js.

The following hooks are available, with more to be added as needed:
* eventsRendered : Fires after the list of events renders on the list template, and the individual event fires on the detail template.
* eventsFeaturedRendered : Fires after the list of featured events renders on the list template.
* eventsListInitialized : Fires when the list template initializes.
* eventDetailInitialized : Fires when the detail template initializes.

Example:

  ```
  var UniCal = ({
    eventsRendered: function() {console.log('eventsRendered')},
    eventsFeaturedRendered: function() { console.log('eventsFeaturedRendered') },
    eventsListInitialized: function() {console.log('eventsListInitialized')},
    eventDetailInitialized: function() { console.log('eventDetailInitialized')}
  });
  ```

WORKBENCH
---------
- Workbench. This setup can utilize the workbench module to make sections/etc
  available to admins, and to ease the approval/moderation process.

STYLING
---------
To avoid overwrite upon module update, and to make styles available to all CLIENT SITES,
all custom styles should be enacted in the unical_styles module. (https://github.com/idfive/UniCal-Styles)

SEO/SOCIAL SHARING
---------
See the .htaccess modifications above in configuration. The general idea, is to
serve the php version of the page to social share scrapers/etc, and to search
bots that cannot yet scrape angular rendered pages. So that social sharers/etc
actually scrape /node/123 (which returns content via php) rather than /event/123/event-name,
which renders the event via js, and is at the moment not fully compatible with
facebook, twitter, etc.

The event detail page supports posting the following meta information to the
rendered js pages, to aid in search/rendering/etc:
- title
- og:type (Article for detail, Website for list)
- og:url
- og:title
- og:description

FEEDS
---------------
UniCal is fully compatible with the Feeds module (https://www.drupal.org/project/feeds)
So any number of custom event importers are possible. UniCal comes with a default iCal
feed importer, that you may use by enabling the unical_feeds module.
 * Enable unical_feeds, and its dependencies.
    * NOTE: The iCalcreator library v2.20.2 is required for date_ical.
      Please see the project documentation for that module for more.
 * The Feed settings can now be edited (if needed) at /admin/structure/feeds/unical_ical_importer
 * Importing can now be done from /import/unical_ical_importer

 Any number of options can be configured on this, or any custom importer, such as
 scheduling, file upload, etc. See the Feeds module documentation for more advanced
 use cases.

DEVELOPMENT
=========
* DEV dependencies:
-- npm
-- gulp

Development setup steps:
* git clone
* cd your.new.folder
* npm install
* gulp
