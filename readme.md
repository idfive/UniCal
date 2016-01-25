About UniCal
===============================
UniCal stands for either Universal Calendar, or University Calendar. Dealers choice. It is an Angular.js based events calendar application based on the headless/decoupled drupal approach, and the COPE principle.

This app/module is designed and maintained by IDFIVE. It serves a sortable list/calendar of events that can be embedded as a page in a third party CLIENT site(s) as either a native drupal module, or simply via JS/HTML embed code. The UniCal system consists of two modules:

- UniCal (unical): This module provides both the API, files, content types, and magic that provides everything.
- UniCal Client (unical_client): This module allows you to embed a calendar in any drupal site, anywhere, that will read via REST to the install where a UniCal site exists.


The idea here is that any enterprise/organization utilizing UniCal, will most likely need a "clean" drupal install to act as the MASTER, for serving events via REST to be consumed elsewhere. This module "may" be deployed on existing installs, but extensive testing against pre-existing modules/config will need to be done. READ: We haven't tested against your specific existing install, nor will we.

It would be helpful to know a few basic principles we refer to:
- MASTER: Generally, we mean the drupal install that is running the UniCal module. The install that serves the REST endpoint, and where you input content.
- CLIENT: Either the same install, or any other, where you will be running the front end code. Either on the MASTER install by looking at the SITE node page, or by using either UniCal client module, or embedding the SITE JS wherever you darn well please.
- SITE: Essentially, a SITE is what ends up being one of your (possibly many) calendars. You create it in the MASTER install, then reference the site ID via the CLIENT, and thats what gives you all your nifty pre-filters/etc.

So essentially you:
- Create a SITE on MASTER install. In doing this, you can choose which types of events will appear/etc, by choosing to pre-filter by taxonomy. Maybe you want to make a "arts" SITE, that serves only events tagged with "art department" in one of your taxonomies.
- Use the UniCal Client Module, or provided JS/HTML to render that SITE you just made on any CLIENT server you choose, as long as it can connect to the MASTER for the REST call.
- Repeat. Make as many SITES as you want. SITES for the athletics dept, SITES for the english dept. The more the merrier. The strength of the SITE approach is that you can customize which events/taxonomies get used, and are available.

Install
===============================
UniCal:
- Spin up default drupal Install
- Add module dependencies
-- restful
-- restful search api
-- cors
-- jquery update
-- Views
-- Features
- Install/enable this module.
- Check that server is serving REST at the endpoints!

UniCal Client:
- Install Drupal Module, or copy/paste JS from desired Site page.
- If using client drupal module, use provided site URL, and site ID form desired site page (from MASTER).


API 1.0
==============================
So, since this entire application works via REST, we need to have a pretty robust API. We based this on the restful module by gizra/et all, because, well, we like it. It is based off the 1x version of the restful module. Patches will certainly be accepted to branch this to the 2x version, If anyone is feeling feisty.
- Uses the restful module
- All endpoints defined in /plugins/restful
- A reference of the api base we used to build this: https://github.com/RESTful-Drupal/restful/blob/7.x-1.x/docs/api_url.md
- The API returns events from the MASTER via JSON.
- You may use a HTTP OPTIONS request to the endpoint, to see things like taxonomy terms, fields, etc.
- See Available endpoints at: http://your.site/api
- EXAMPLE: Events Endpoint: http://your.site/api/events
- Use these endpoints for other fun stuff too!

GET Requests
---------------------------

GET Requests return the following:
- data: object with the results of the current query
- count: number of results available in current query
- self: array of Info on current page
- next: array of info on the next page of results, if applicable

Options/filters
---------------------------

range: Use this to specify the number of results you wish to receive. http://your.site/api/events?range=2 returns two results.

page: Return a certain page of results, based on using range. http://your.site/api/v1.0/events?range=2&page=2 returns page two of the above request.

fields: Use this to reduce what fields are returned via JSON, if needed/wanted. example, http://your.site/api/events?fields=id,label returns just the ID and Label.

filter: (see https://github.com/RESTful-Drupal/restful/blob/7.x-1.x/docs/api_url.md) In general we can filter entities that have properties defined in the entity, or the field API. We can also use limited operators, see examples in code for more, this gets complex fast. It can also take multiples. For example, http://your.site/api/events?filter[taxonomy_2][value][0]=31&filter[taxonomy_2][operator][0]="IN" returns results with taxonomy TID 31 in taxonomy_2 field.

some other useful available filter fields:
- featured | 1,0 | Used to define if an event is featured in slider for site calendars, if enabled.
- promoted | 1,0 | Used to define if an event should show in a secondary feed, usually on a homepage/etc.
- see /plugins/restful/TYPE.class files for field definitions in the API.

sort: by default it is ascending, but can be prefixed by a - for DESC. You can use most fields returned for this. For example, http://your.site/api/events?sort=label returns results sorted alphabetically by label, while http://your.site/api/events?sort=-label returns the same results, DESC.


Content Types
=========================
We employ two different Content Types for the UniCal: Events, and Sites.

Event CT
------------------------
- Exactly as it sounds, used for defining events that then show up on the calendar, and throughout the API.
- Each Event can be categorized within the taxonomies (1-6), and then subsequentlty filtered on the front end.

Site CT
-----------------------
- This content type is used to define presets/etc for embedding the front end of the calendar elsewhere. Essentially, think of a site as an instance of the calendar that you can customize.
- Sites can be set up to pre-filter by taxonomy (1-6) and can also handle custom naming conventions/labels for each taxonomy.
- Sites CT uses a custom .tpl located in /templates/node--site.tpl. We use this, so we can show things like the custom embed code/etc per site, to the admins, in order to pass along the code with all presets/etc needed. It also provides the JS embeds/etc needed to show the calendar (per site) so simply going to the node page of the site will show end users that calendar/etc.

Taxonomies
=======================
The MASTER module comes set up with 6 predefined taxonomies (taxonomy_1 through taxonomy_6). These can eventually be renamed/etc, just so long as THE MACHINE NAME STAYS THE SAME. Sorry for yelling, but that's important.

Admin Stuff/etc
=======================
- Views. There are a few predefined views available to the admin so that they can sort/see content.
- Workbench. This setup can utilize the workbench module to make sections/etc available to admins, and to ease the approval process.

Development Notes
=======================
- DEV dependencies:
-- npm
-- gulp

Development setup steps
-----------------------
- git clone
- cd your.new.folder
- npm install
- gulp
