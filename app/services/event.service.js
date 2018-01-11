(function () {
  'use strict';

  angular
    .module('calendar')
    .factory('eventService', eventService);

  eventService.$inject = ['$http', '$window', '$q', 'utilityService', 'taxonomyService', 'siteService', 'dateService'];

  function eventService($http, $window, $q, utilityService, taxonomyService, siteService, dateService) {

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
      reserve:[],
      resetFilterOptions: resetFilterOptions,
      searchTerm: '',
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
        if(result.date[0].start_unix < moment().unix()) { //Removes past events
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
    }

    /*
     * Code to execute when finished rendering events
     *
     */
    function finishRenderFeatured() {
      $window.swiftSlide.init({
        container: '.swift-slide',
        elements: 'li',
        showPrevNext: true
      });
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
        var replicate = false;
        // if module to split repeated events into separate nodes is turned on
        if(replicate == false){
          // if more dates in the array add them as objects at the end of the response.data.data
          // this get the repeating dates out of nodes
          for(var x in response.data.data){
            if(response.data.data[x].date.length > 1){
              for(var y in response.data.data[x].date){
                var d = new Date(response.data.data[x].date[y].start_unix * 1000);
                response.data.data.push({id:response.data.data[x].id , date:[d] , clndrDate:d});
              }
            }
            // if clndrEvent is null add one
            if( !response.data.data[x].clndrDate ){
              var d = new Date(response.data.data[x].date[0].start_unix * 1000);
              response.data.data[x].clndrDate = d;
            }
          }
        }
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
        service.reserve = [];
      }

      //Add pagination query
      filterString = filterString + '&page=' + service.page;

      /** DEBUG **/ //window.console.log(filterString);

      //Reset next page var for next call
      service.nextPage = false;

      //Get the events
      return $http.get(utilityService.getBaseUrl() + 'events' + filterString).then(function(response) {   
        var r;
        var unix = dateService.dateNowUnix();
        var replicate = false;
        // if module to split repeated events into separate nodes is turned on
        if(replicate == true){
          r = replicateEnabled(response,unix);
        }else{
          r = splitNode(response,unix,filterString);
        }

        var events = service.processEventResults(r);
        service.eventsList = service.eventsList.concat(events);

        // controls first number in the Showing # of # events
        service.eventsCount = parseInt(service.eventsList.length) + parseInt(service.reserve.length);  
        response.data.data = r;
        return response.data;
      });
    }

    function splitNode(response,unix,filterString){
      var filteredList = response.data;

      // will contain all the events data
      var data = {};
      var z = 0;   //used to find the date index in the array 
      // loop though events
      for(var x in filteredList.data){
        z = 0;
        // if is or is not a repeating event
        if(filteredList.data[x].date.length > 2){
          // loop through the dates of the repeating events and pull out the object for it to loop of it with the index
          filteredList.data[x].date.forEach(function(n){
            // Check Start Date and End Date. Only needed for All filter
            var start = new Date(filterString.split('filter[date][value][0]=')[1].split('&')[0].split(' ')[0]).getTime() / 1000;
            if( filterString.includes('filter[date][value][1]=') ){          
              var end = new Date(filterString.split('filter[date][value][1]=')[1].split('&')[0].split(' ')[0]).getTime() / 1000;
              if(n.start_unix > start && n.end_unix < end){
                var copy = Object.assign({}, filteredList.data[x]);  // make hard copy of this object
                copy.item = z;     //give the index for the calendar
                data[n.start_unix] = copy;     
              } 
            }else{
              if(n.start_unix > start){    
                var copy = Object.assign({}, filteredList.data[x]);
                copy.item = z;
                data[n.start_unix] = copy;  
              }  
            }  
            z++;
          });  
        }else{
          data[filteredList.data[x].date[0].start_unix] = filteredList.data[x];  // for dates that aren't repeating
        }
      }

      var obj = {};
      for(var x in data){
          // if from split node
        if(data[x].item){
          // sort the responses based on start_unix. Push in object array
          if( !obj[data[x].date[ data[x].item ].start_unix] ){  
            obj[data[x].date[ data[x].item ].start_unix] = [];
          }
          if( data[x].date[data[x].item].start_unix > unix || ( data[x].date[data[x].item].start_addto.includes("12:00 AM") && data[x].date[data[x].item].end_addto.includes("11:59 PM") )  ){   // removed times that have passed. Dont exclude All Day events that have that time
            obj[data[x].date[ data[x].item ].start_unix].push(data[x]);   
          }
        }else{
          // sort the responses based on start_unix. Push in object array
          if( !obj[data[x].date[0].start_unix] ){  
            obj[data[x].date[0].start_unix] = [];
          }
          if( data[x].date[0].start_unix > unix || ( data[x].date[0].start_addto.includes("12:00 AM") && data[x].date[0].end_addto.includes("11:59 PM") )  ){   // removed times that have passed. Dont exclude All Day events that have that time
            obj[data[x].date[0].start_unix].push(data[x]);   
          }     
        }
      }

      var n = 0;
      var temp = [];
      var r = [];
      
      // put reserved events into the show queue. Only put up to the number per page
      for(var x in service.reserve){
        // limit results and push into the current shown or reserve
        if(n < siteService.settings.number_results_per_page ){
          r.push(service.reserve[x]);
        }else{
          temp.push(service.reserve[x]);
        }          
        n++;
      }

      // update reserve array
      service.reserve = temp;

      // put new results into queue if amount put in is less than the number per page
      for(var x in obj){
        for(var y in obj[x]){
          // limit results
          if(n < siteService.settings.number_results_per_page ){
            r.push(obj[x][y]);
          }else{
            service.reserve.push(obj[x][y]);
          }          
          n++;
        }
      }
      return r;
    }

    function replicateEnabled(response,unix){
      var r = [];
      var obj = {};
      for(var x in response.data.data){
        if( response.data.data[x].date[0].start_unix > unix || ( response.data.data[x].date[0].start_addto.includes("12:00 AM") && response.data.data[x].date[0].end_addto.includes("11:59 PM") )  ){   // removed times that have passed. Dont exclude All Day events that have that time
          // sort the responses based on start_unix. Push in object array
          if( !obj[response.data.data[x].date[0].start_unix] ){  
            obj[response.data.data[x].date[0].start_unix] = [];
          }
          obj[response.data.data[x].date[0].start_unix].push(response.data.data[x]);            
        }
      }

      // put result into normal array
      for(var x in obj){
        for(var y in obj[x]){
          r.push(obj[x][y]);
        }
      }

      return r;
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
        fields: 'id,label,date,image,uri,address,body_trimmed,summary,clndrDate,timezone,venue_name',
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
        var start = dateService.dateTodayStart(),
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
      filters.push('fields=id,label,venue_name,date,uri,image');

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
        var results = filterSearchResults(response.data.data);

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

  };

})();
