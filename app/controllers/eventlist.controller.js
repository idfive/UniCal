(function() {
  'use strict';

  angular
    .module('calendar')
    .controller('eventsListController', eventsListController);

  eventsListController.$inject = ['$q', '$scope', 'eventService', 'taxonomyService', 'siteService', 'dateService', 'initialData', 'utilityService'];

  function eventsListController($q, $scope, eventService, taxonomyService, siteService, dateService, initialData, utilityService) {

    //Shortcut to scope
    var vm = this;

    //Scope variables
    vm.clndrOptions = {
      constraints: {
        startDate: moment().format('YYYY-MM-DD')
      },
      dateParameter: 'clndrDate'
    };
    vm.clndrEvents = eventService.clndrList;
    vm.currentMonth = eventService.currentMonth;
    vm.eventsCount = eventService.eventsCount;
    vm.events = eventService.eventsList;
    vm.filters = eventService.filters;
    vm.searchTerm = eventService.searchTerm;
    vm.requestInProcess = false;
    vm.selectedTaxonomies = taxonomyService.selectedTaxonomies;
    vm.siteSettings = siteService.settings;
    vm.taxonomies = taxonomyService.taxonomies;
    vm.url = window.location.href;

    //Clear filters
    vm.clearFilters = function() {
      //Clear filters
      eventService.clearFilters();
      //Let view know that the model was updated
      vm.filters = eventService.filters;
    };

    //Clear search (happens after search has been executed)
    vm.clearSearch = function() {
      eventService.searchTerm = '';
      vm.searchForm.$setPristine();
      vm.searchForm.$setUntouched();
    };

    //Code to execute when events have rendered
    vm.finishRenderEvents = function() {
      eventService.finishRenderEvents();
    };

    //Code to execute when featured events have rendered
    vm.finishRenderFeatured = function() {
      eventService.finishRenderFeatured();
    };

    //Code to execute when filters have rendered
    vm.finishRenderFilters = function() {
      eventService.finishRenderFilters();
    };

    //Get events
    vm.getEvents = function() {
      if(!vm.requestInProcess) {
        vm.requestInProcess = true;
        eventService.getEvents().then(function() {
          vm.modelUpdated();
        });
      }
    };

    //Show calendar events by date, from the mini-calendar
    vm.getEventsByDate = function(events) {
      eventService.getEventsByDate(events[0].clndrDate);
      vm.getEvents();
    };

    //Show calendar events by month
    vm.getEventsByMonth = function(month, year) {
      eventService.getEventsByMonth(month, year);
      vm.getEvents();
    };

    //Get next page of events
    vm.getEventsNextPage = function() {
      eventService.nextPage = true;
      vm.getEvents();
    };

    //Get featured events
    vm.getFeaturedEvents = function() {
      eventService.getFeaturedEvents()
        .success(function(events) {
          vm.featuredEvents = events.data;
        });
    };

    //Returns true if month and year is the current month and year
    vm.isCurrentMonth = function(month, year) {
      return (month == dateService.dateMonthCurrent() && year == dateService.dateYearCurrent()) ? true : false;
    };

    //Let view know that the model was updated
    vm.modelUpdated = function() {
      vm.searchTerm = eventService.searchTerm;
      vm.currentMonth = eventService.currentMonth;
      vm.eventsCount = eventService.eventsCount;
      vm.events = eventService.eventsList;
      vm.requestInProcess = false;
    };

    //Search events
    vm.searchEvents = function() {
      if(vm.searchTerm !== '') {
        eventService.searchEvents(vm.searchTerm).then(function() {
          vm.clearSearch();
          vm.clearFilters();
          vm.modelUpdated();
        });
      } else {
        vm.getEvents();
      }
    };

    //Show all events
    vm.showAllEvents = function() {
      vm.clearFilters();
      vm.getEvents();
    };

    //Share to Facebook
    vm.shareFB = function(url, id, uri) {
      utilityService.shareFB(url, id, uri);
    };

    //Share to Twitter
    vm.shareTW = function(title, url, id, uri) {
      utilityService.shareTW(title, url, id, uri);
    };

    //Init
    (function() {
      vm.featuredEvents = vm.getFeaturedEvents();
    })();

  }

})();
