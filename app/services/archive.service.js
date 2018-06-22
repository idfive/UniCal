(function () {
  'use strict';

  angular
    .module('calendar')
    .factory('archiveService', archiveService);

  archiveService.$inject = ['$http', '$window', '$q', 'utilityService', 'taxonomyService', 'siteService', 'dateService'];

  function archiveService($http, $window, $q, utilityService, taxonomyService, siteService, dateService) {

    //Service setup
    var service = {
      cachedPromises: {},
      page: 1,
      nextPage: false,
      eventsCount: 0,
      eventsList: [],
      clearFilters: clearFilters,
      filters: {
        range: 'archived'
      },
      filterSearchResults: filterSearchResults,
      finishRenderEvents: finishRenderEvents,
      finishRenderFilters: finishRenderFilters,
      getEvents: getEvents,
      getEventsByDate: getEventsByDate,
      getEventsByTaxonomy: getEventsByTaxonomy,
      searchEvents: searchEvents,
      getFilterString: getFilterString,
      initEventsList: initEventsList,
      processEventResults: processEventResults,
      resetFilterOptions: resetFilterOptions,
      searchTerm: ''
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
     * Filter search results
     *
     */
    function filterSearchResults(results) {

      var filteredResults = [];

      angular.forEach(results, function(result, index) {
        var excludeCount = 0;
        if(result.date[0]) {
          if(result.date[0].start_unix > moment().unix()) { //Removes future events
            excludeCount++;
          }
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

    }


    /*
     * Code to execute when finished rendering filters
     *
     */
    function finishRenderFilters() {
      $window.UnicalApiBehaviors.filterToggle();
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
        //Hide loading screen
        utilityService.hideLoading();
        return response.data;
      });
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
     * Get filter string for events list
     *
     */
    function getFilterString(params) {

      //Allows params to be optional parameter
      params = params || {};

      //Default params
      var defaultParams = {
        fields: 'id,label,date.start_month,date.start_day,image.image_styles.large,image.alt,uri,body_trimmed,summary,clndrDate,timezone,venue_name',
        sort: '-date',
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
      if(service.filters.range === 'archived') { //All Before Today
        var start = null,
            end = dateService.dateNow();
      } else if (service.filters.range === 'past_week') { //Past Week
        var start = dateService.dateWeekArchiveStart(),
            end = dateService.dateNow();
      } else if (service.filters.range === 'past_month') { //Past Month
        var start = dateService.dateMonthArchiveStart(),
            end = dateService.dateNow();
      } else if (service.filters.range === 'past_six_months') { //Past Six Months
        var start = dateService.dateSixMonthsArchiveStart(),
            end = dateService.dateNow();
      } else if (service.filters.range === 'past_year') { //Past Year
        var start = dateService.dateYearArchiveStart(),
            end = dateService.dateNow();
      } else if (service.filters.range === 'custom') { //Custom
        var start = service.filters.startDate,
            end = service.filters.endDate + ' 23:59:59';
      }

      if(start !== null) {
        filters.push('filter[date][value][0]='+ start +'&filter[date][operator][0]=">="');
      }

      if(end !== null && service.filters.range !== 'archived') {
        filters.push('filter[date][value][1]='+ end +'&filter[date][operator][1]="<="');
      } else if(end !== null && service.filters.range === 'archived') {
        filters.push('filter[date][value][0]='+ end +'&filter[date][operator][0]="<="');
      }

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
      //Get site settings if not already loaded
      if(typeof service.cachedPromises.site === 'undefined') {
        service.cachedPromises.site = siteService.getSite($window.site_id);
      }

      //Once site settings are loaded
      return $q.all([service.cachedPromises.site]).then(function(results) {

        //Get selected taxonomies
        if(typeof service.cachedPromises.selectedTaxonomies === 'undefined') {
          service.resetFilterOptions();
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


        //Return the data to the controller
        return $q.all([service.cachedPromises.taxonomies, service.cachedPromises.events]).then(function(results) {
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
        range: 'archived',
        rangeExpanded: true,
        taxonomies: taxonomyService.getSelectedTaxonomies(),
        startDate: null,
        endDate: null
      };
    }

  };

})();
