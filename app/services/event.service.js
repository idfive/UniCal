(function () {
  'use strict';

  angular
    .module('calendar')
    .factory('eventService', eventService);

  eventService.$inject = ['$http', '$window', '$q', 'utilityService', 'taxonomyService', 'siteService', 'dateService', '$route', '$location'];

  function eventService($http, $window, $q, utilityService, taxonomyService, siteService, dateService, $route, $location) {

    //Check for external hooks, or set null.
    window.UniCal = window.UniCal || [];

    //Service setup
    var service = {
      cachedPromises: {},
      page: 1,
      nextPage: false,
      eventsCount: 0,
      eventsList: [],
      clndrList: [],
      clearFilters: clearFilters,
      filters: {},
      createNewEvent: createNewEvent,
      filterSearchResults: filterSearchResults,
      finishRenderEvents: finishRenderEvents,
      finishRenderFeatured: finishRenderFeatured,
      finishRenderFilters: finishRenderFilters,
      getClndrEvents: getClndrEvents,
      getEvent: getEvent,
      getEvents: getEvents,
      getEventsByDate: getEventsByDate,
      getEventsByMonth: getEventsByMonth,
      getEventsByTaxonomy: getEventsByTaxonomy,
      getFeaturedEvents: getFeaturedEvents,
      searchEvents: searchEvents,
      getFilterString: getFilterString,
      getFeaturedFilterString: getFeaturedFilterString,
      initEventDetail: initEventDetail,
      initEventsList: initEventsList,
      newEventData: {
        date: [{
          value: '',
          value2: ''
        }],
        address: {
          country: "US"
        }
      },
      newEventDataRaw: {},
      newEventProgress: {},
      processEventResults: processEventResults,
      resetFilterOptions: resetFilterOptions,
      searchTerm: '',
      setFiltersFromUrl: setFiltersFromUrl
    };

    return service;


    /*
     * Clear filters
     *
     */
    function clearFilters() {
      service.resetFilterOptions();
      service.page = 1;
      service.nextPage = false;
    }

    /*
     * Create event
     *
     */
    function createNewEvent(event) {
      return $http.post(utilityService.getBaseUrl() + 'events/', service.newEventData, { timeout: 10000 });
    }

    /*
     * Filter search results
     *
     */
     function filterSearchResults(results) {

       var filteredResults = [];

       angular.forEach(results, function(result, index) {
         var excludeCount = 0;
         if(result.date[0]) {
           if(result.date[0].end_unix < moment().unix()) { //Removes past events
             excludeCount++;
           }
         }
         if(!result.date[0]) { //Removes past events where repeating dates have been removed via cron
           excludeCount++;
         }
         if(siteService.settings.main_calendar_site) { //Removes excluded events (if this is the main calendar)
           if(result.exclude_from_main_calendar == 1) {
             excludeCount++;
           }
         }
         if(excludeCount <= 0) { //If exclude count is 0 or less, this event can be shown
           filteredResults.push(result);
         }
       });

       return filteredResults;
     }

    /*
     * Code to execute when finished rendering events
     *
     */
    function finishRenderEvents() {
      //Add to calendar button
      if(typeof $window.addthisevent !== 'undefined') {
        addthisevent.refresh();
      }

      //Append the help link to the Calendar button, if present
      if(siteService.settings.help_link !== null) {
        jQuery('.addthisevent_dropdown').append('<span class="addtocalendar_help" onclick="window.open(&apos;' + siteService.settings.help_link + '&apos;);">View Calendar Help</span>');
      }

      //Remove any excluded add to calendar options
      if(siteService.settings.add_to_calendar_exclude !== null) {
        for(var i=0;i<siteService.settings.add_to_calendar_exclude.length;i++) {
          jQuery('.addthisevent-drop ' + '.ate' + siteService.settings.add_to_calendar_exclude[i]).remove();
        }
      }

      //Addthis share button
      if(typeof $window.addthis !== 'undefined') {
        addthis.toolbox('.addthis_toolbox');
      }

      //Look for any external eventsRendered JS hooks defined.
      if (window.UniCal && typeof window.UniCal.eventsRendered === "function") {
        window.UniCal.eventsRendered();
      };

      //Hide loading screen
      utilityService.hideLoading();
    }

    /*
     * Code to execute when finished rendering featured events
     *
     */
    function finishRenderFeatured() {

      //Init slider
      $window.swiftSlide.init({
        container: '.swift-slide',
        elements: 'li',
        showPrevNext: true
      });

      //Look for any external eventsFeaturedRendered JS hooks defined.
      if (window.UniCal && typeof window.UniCal.eventsFeaturedRendered === "function") {
        window.UniCal.eventsFeaturedRendered();
      };
    }

    /*
     * Code to execute when finished rendering filters
     *
     */
    function finishRenderFilters() {
      $window.UnicalApiBehaviors.filterToggle();
    }

    /*
     * Get mini calendar events
     *
     */
    function getClndrEvents() {

      //Get filter string
      var filterString = this.getFilterString({
		  range: 1000,
		  fields: 'id,clndrDate,date',
	  });

      return $http.get(utilityService.getBaseUrl() + 'events' + filterString).then(function(response) {
        service.clndrList = response.data.data;
        return response.data;
      });
    }

    /*
     * Get event by id
     *
     */
    function getEvent(id) {
      return $http.get(utilityService.getBaseUrl() + 'events/' + id);
    }

    /*
     * Get events list
     *
     */
    function getEvents() {

      //Get filter string
      var filterString = this.getFilterString();

      //If nextPage var is true, increment the page
      if(service.nextPage) {
        service.page = service.page + 1;
      } else { //Reset page and empty the list
        service.page = 1;
        service.eventsList = [];
      }

      //Add pagination query
      filterString = filterString + '&page=' + service.page;

      /** DEBUG **/ window.console.log(filterString);

      //Reset next page var for next call
      service.nextPage = false;

      //Get the events
      return $http.get(utilityService.getBaseUrl() + 'events' + filterString).then(function(response) {
        service.eventsCount = response.data.count;
        var events = service.processEventResults(response.data.data);
        service.eventsList = service.eventsList.concat(events);
        console.log(response.data);
        return response.data;
      });
    }

    /*
     * Get events by month
     *
     */
    function getEventsByMonth(month, year) {
      //Set filter to custom range
      service.filters.range = 'custom';

      //If current month, only show from today rather than beginning of the month
      if(month == dateService.dateMonthCurrent() && year == dateService.dateYearCurrent()) {
        service.filters.startDate = dateService.dateNow();
      } else {
        service.filters.startDate = moment(month + ' 1,' + year).format('YYYY-MM-DD');
      }

      //Set end date
      service.filters.endDate = moment(month + ' 1,' + year).endOf('month').format('YYYY-MM-DD');
    }

    /*
     * Get events by specific date
     *
     */
    function getEventsByDate(date) {
      service.filters.range = 'custom';
      service.filters.startDate = moment(date).format('YYYY-MM-DD');
      service.filters.endDate = moment(date).format('YYYY-MM-DD');
    }

    /*
     * Get events by specific taxonomy
     *
     */
    function getEventsByTaxonomy(tid, taxonomy) {

      //Reset all filters
      service.resetFilterOptions();

      //Set passed taxonomy in filter and expand the filter
      service.filters.taxonomies[taxonomy].terms[tid] = true;
      service.filters.taxonomies[taxonomy].expanded = true;

      //Remove promise to force new events get
      delete service.cachedPromises.events;
    }

    /*
     * Get featured events
     *
     */
    function getFeaturedEvents() {
      return $http.get(utilityService.getBaseUrl() + 'events/' + this.getFeaturedFilterString({
		  fields: 'id,label,date,image,uri'
	  }));
    }

    /*
     * Get filter string for events list
     *
     */
    function getFilterString(params) {

      //Allows params to be optional parameter
      params = params || {};

      //Default params
      var defaultParams = {
        fields: 'id,label,date.start_month,date.start_day,image.image_styles.large,image.alt,uri,body_trimmed,summary,clndrDate,timezone,venue_name',
        sort: 'date',
        range: siteService.settings.number_results_per_page
      };

      //Vars
      var filters = [];

      //Merge passed in params with default params
      var finalParams = angular.extend({}, defaultParams, params);

      //Add params
      angular.forEach(finalParams, function(value, index) {
        filters.push(index + '=' + value);
      });

      //Taxonomies
      angular.forEach(service.filters.taxonomies, function(taxonomy, key) {
        var index = 0;
        angular.forEach(taxonomy.terms, function(checked, tid) {
          if(checked) {
            filters.push('filter['+ key +'][value]['+ index +']='+ tid +'&filter['+ key +'][operator]['+ index +']="IN"');
            index++;
          }
        });
      });

      //If this is the main calendar site, exclude events that are set to be hidden from it
      if(siteService.settings.main_calendar_site) {
        filters.push('filter[exclude_from_main_calendar][value]=1&filter[exclude_from_main_calendar][operator]="!="');
      }

      //Date range
      if(service.filters.range === 'all') { //ALL
        var start = dateService.dateNow(),
            end = null;
      } else if (service.filters.range === 'today') { //TODAY
        var start = dateService.dateTodayStart(),
            end = dateService.dateTodayEnd();
      } else if (service.filters.range === 'tomorrow') { //TOMORROW
        var start = dateService.dateTomorrowStart(),
            end = dateService.dateTomorrowEnd();
      } else if (service.filters.range === 'week') { //THIS WEEK
        var start = dateService.dateNow(),
            end = dateService.dateWeekEnd();
      } else if (service.filters.range === 'month') { //THIS MONTH
        var start = dateService.dateNow(),
            end = dateService.dateMonthEnd();
      } else if (service.filters.range === 'custom') { //CUSTOM
        var start = service.filters.startDate,
            end = service.filters.endDate + ' 23:59:59';
      }

      if(start !== null) {
        filters.push('filter[date][value][0]='+ start +'&filter[date][operator][0]=">="');
      }

      if(end !== null) {
        filters.push('filter[date][value][1]='+ end +'&filter[date][operator][1]="<="');
      }

      //Returns query string
      return utilityService.arrayToQueryString(filters);
    }

    /*
     * Get filter string for featured events
     *
     */
    function getFeaturedFilterString() {

      var filters = [],
          range = 3;

      //Fields
      filters.push('fields=id,label,venue_name,date.start_month,date.start_day,date.start_time,date.end_time,uri,image.image_styles.large,image.alt');

      //Range
      filters.push('range='+range);

      //Date
      filters.push('filter[featured]=1&filter[date][value][0]='+dateService.dateNow()+'&filter[date][operator][0]=">"');

      //Returns query string
      return utilityService.arrayToQueryString(filters);

    }

    /*
     * Search events
     *
     */
    function searchEvents(keyword) {

      //Sanitize the string
      var sanitizedStr = keyword.replace(/[\-\[\]\/\{\}\(\)\*\+\?\.\\\^\$\|]/g, "\\$&");

      //Encode spaces
      var searchStr = sanitizedStr.replace(' ', '%20');

      //Run the search
      return $http.get(utilityService.getBaseUrl() + 'eventsearch/' + searchStr).then(function(response) {

        //Filter search results
        var results = filterSearchResults(response.data.data[0]);

        //Update service vars
        service.eventsList = results;
        service.eventsCount = results.length;

        //Return the result
        return results;
      });
    }

    /*
     * Initialize events listing page
     *
     */
    function initEventsList() {

      //Show loading screen
      utilityService.showLoading();

      //Look for any external eventsListInitialized JS hooks defined.
      if (window.UniCal && typeof window.UniCal.eventsListInitialized === "function") {
        window.UniCal.eventsListInitialized();
      };

      //Get site settings if not already loaded
      if(typeof service.cachedPromises.site === 'undefined') {
        service.cachedPromises.site = siteService.getSite($window.site_id);
      }

      //Once site settings are loaded
      return $q.all([service.cachedPromises.site]).then(function(results) {

        //Get selected taxonomies
        if(typeof service.cachedPromises.selectedTaxonomies === 'undefined') {
          service.resetFilterOptions();
          service.setFiltersFromUrl();
          service.cachedPromises.selectedTaxonomies = { processed: true };
        }

        //Get taxonomies
        if(typeof service.cachedPromises.taxonomies === 'undefined') {
          service.cachedPromises.taxonomies = taxonomyService.getTaxonomies();
        }

        //Get events
        if(typeof service.cachedPromises.events === 'undefined') {
          service.cachedPromises.events = service.getEvents();
        }

        //Get Clndr Events
        if(typeof service.cachedPromises.clndrEvents === 'undefined') {
          service.cachedPromises.clndrEvents = service.getClndrEvents();
        }

        //Return the data to the controller
        return $q.all([service.cachedPromises.taxonomies, service.cachedPromises.events, service.cachedPromises.clndrEvents]).then(function(results) {
          return results;
        });

      });

    }

    /*
     * Initialize event detail page (also used by form page to load taxonomies)
     *
     */
    function initEventDetail() {

      //Show loading screen
      utilityService.showLoading();

      //Look for any external eventsListInitialized JS hooks defined.
      if (window.UniCal && typeof window.UniCal.eventDetailInitialized === "function") {
        window.UniCal.eventDetailInitialized();
      };

      //Get site settings if not already loaded
      if(typeof service.cachedPromises.site === 'undefined') {
        service.cachedPromises.site = siteService.getSite($window.site_id);
      }

      //Once site settings are loaded
      return $q.all([service.cachedPromises.site]).then(function(results) {

        //Get taxonomies
        if(typeof service.cachedPromises.taxonomies === 'undefined') {
          service.cachedPromises.taxonomies = taxonomyService.getTaxonomies();
        }

        //Return the data to the controller
        return $q.all([service.cachedPromises.taxonomies]).then(function(results) {
          return results;
        });

      });

    }

    /*
     * Function that runs after events are returned so we can do post processing
     *
     */
    function processEventResults(events) {

      var processedResults = [];

      angular.forEach(events, function(event, index) {
        // Remove events that have no date (cleans up repeating events that don't match the filter)
        // NOTE: moved logic of checking empty date[] to custom formatter.
        // keeping function in case further ajustments are needed.
          processedResults.push(event);
      });

      return processedResults;

    }

    /*
     * Reset filter options to defaults
     *
     */
    function resetFilterOptions() {
      service.filters = {
        range: 'all',
        rangeExpanded: true,
        taxonomies: taxonomyService.getSelectedTaxonomies(),
        startDate: null,
        endDate: null
      };
    }

    /*
     * Set filters from URL parameters
     *
     */
    function setFiltersFromUrl() {

      // Loop through each parameter in the URL to set filters
      angular.forEach($route.current.params, function(paramVal, paramKey) {

        service.filters.taxonomies[paramKey]['terms'][paramVal] = true;

        // Unset URL parameter
        $location.search(paramKey, null).replace();

      });

    }



  };

})();
