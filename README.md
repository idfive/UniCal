INTRODUCTION
------------  
UniCal stands for either Universal Calendar or University Calendar. Dealer’s
choice. It is an Angular.js-based events calendar application, based on the
headless/decoupled Drupal approach, and the COPE principle.  

This app/module is collaboratively designed and maintained by idfive and Howard
University. It serves a sortable list/calendar of events that can be embedded as
a page in third-party CLIENT site(s) as either a native Drupal module, or simply
via JS/HTML embed code.

The UniCal system consists of two modules:  

* UniCal (unical): This module provides the API, files, content types, and magic
  that generates everything.
* UniCal Client (unical_client): This module allows you to embed a calendar in
  any Drupal site, anywhere, that will read via REST to the install where a
  UniCal site exists.  

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
This module requires the following modules:   
* UniCal Features (TBD)  
* RESTful (https://www.drupal.org/project/restful)  
* CORS (https://www.drupal.org/project/cors)  
* jQuery Update(https://www.drupal.org/project/jquery_update)  

RECOMMENDED MODULES
-------------------   
* UniCal Client (https://www.drupal.org/sandbox/rogerseyebyte/2653140): When
  enabled, this module allows the display of Sites in separate installs.  
* Markdown filter (https://www.drupal.org/project/markdown): When enabled, this
  module displays the UniCal project's README.md Help will be rendered with
  markdown, on the help page.  

INSTALLATION
------------  
* Install as you would normally install a contributed Drupal module. See:  
  https://drupal.org/documentation/install/modules-themes/modules-7 for further
  information.
* Enable and set up UniCal Features to use the content types and taxonomies needed.
* Check that the server is serving REST at the endpoints.
* If serving across other sites/servers, be sure CORS is properly set up.  
* Modify .htaccess file, as shown in configuration.

CONFIGURATION
-------------  
The module has no menu or modifiable settings. You will need to configure the
UniCal Features module.  

### .htaccess modifications: ###

Some modifications are neccesary to both re-route social bots the actual node
page (php) of the main site, in order to scrape, and to allow use of non # urls.
The following rules assume that your events are in the format /event/NID/TITLE,
and be sure to modify YOUR_MAIN_INSTALL_URL with actual url of your main site, so
that facebook bots/are redirected to the stock drupal node of the event.

  # Allow social media crawlers to work by redirecting them to a server-rendered static version on the page
  RewriteCond %{HTTP_USER_AGENT} (facebookexternalhit/[0-9]|Twitterbot|Pinterest|Google.*snippet)
  RewriteRule event/(.*)/(.*) YOUR_MAIN_INSTALL_URL/node/$1 [P]

  # Workaround to be able to use non # url in the calendar
  RewriteCond %{HTTP_USER_AGENT} !(facebookexternalhit/[0-9]|Twitterbot|Pinterest|Google.*snippet)
  RewriteRule event/(.*)/(.*) http://%{HTTP_HOST}/#%1/event/$1/$2 [NE,L]

TROUBLESHOOTING
---------------  
* If the endpoint does not display, check the following:   - Is CORS set up?   
-- Have you added some test content?   

KNOWN CONFLICTS
---------------  
* Global Redirect Module. Affects the angular form submit. Will look into as time
  allows.    

API 1.0
-------
This entire application works via REST, so we need to have a pretty robust API.
We based this on the RESTful module by gizra/et al, because, well, we like it.
It is based off the 1x version of the RESTful module. Patches will be accepted
to branch this to the 2x version . . . if anyone is feeling feisty.
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
  the ID and Label.  
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
We employ two different Content Types for UniCal: Events and Sites. These will be
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
UniCal uses 6 predefined taxonomies (taxonomy_1 through taxonomy_6). These can
eventually be renamed/etc, as long as THE MACHINE NAME STAYS THE SAME.  

WORKBENCH
---------
- Workbench. This setup can utilize the workbench module to make sections/etc
  available to admins, and to ease the approval/moderation process.  

DEVELOPMENT
-----------
* DEV dependencies:
-- npm
-- gulp  
Development setup steps:
* git clone
* cd your.new.folder
* npm install
* gulp
