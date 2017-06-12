
INTRODUCTION
------------

This testing suite runs on behat, to test various parts of unical.

REQUIREMENTS
------------

This requires (see composer json):

* composer
* behat
* behat drupal extension
* Selenium
* mink
* chromedriver

See composer.json for versions. Selenium standalone, and gecko/chrome drivers
added to codebase for ease in sharing.

INSTALLATION
------------

* composer install


STARTING THE SELENIUM SERVER
------------------------

The selenium server is needed to run the JS based behat tests.
Chrome is currently preferred, due to selenium moveto errors on FF.

From behavioral folder:

bin/selenium-server-standalone

////////////////////////////////////////////////////////////////////////////////
IMPORTANT! Leave this terminal window open, and running.
////////////////////////////////////////////////////////////////////////////////

Kill selenium server, if needed: kill -9 $(lsof -ti tcp:4444)


CONFIG BEHAT FOR THE SITE YOU WISH TO TEST
------------------------------------------

To set a specific url (local/stg/etc) set the base_url in behat.yml to whatever site you wish.


RUN BEHAT TESTS
---------------

////////////////////////////////////////////////////////////////////////////////
IMPORTANT! Open a new terminal window for this, leaving the selenium server running.
////////////////////////////////////////////////////////////////////////////////

Running behat, or bin/behat (depending on your environment) will begin to run all tests
built for this install.

* All tests, in all folders (lots will fail!): behat
* Specific feature: behat features/common/api/calendar_api.feature


WRITE BEHAT TESTS
-----------------

Writing behat tests is a bit above the scope of this readme, but multiple online resources exist.

In general, site specifics should go in their own folder, keep everything general for now.
