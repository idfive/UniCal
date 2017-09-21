(function() {
  'use strict';

  angular
    .module('calendar')
    .controller('eventsArchiveController', eventsArchiveController);

  eventsArchiveController.$inject = ['$q', '$scope', 'archiveService', 'taxonomyService', 'siteService', 'dateService', 'initialData', 'utilityService'];

  function eventsArchiveController($q, $scope, archiveService, taxonomyService, siteService, dateService, initialData, utilityService) {

    //Shortcut to scope
    var vm = this;

    //Scope variables
    vm.eventsCount = archiveService.eventsCount;
    vm.events = archiveService.eventsList;
    vm.filters = archiveService.filters;
    vm.filtersReset = false;
    vm.searchTerm = archiveService.searchTerm;
    vm.requestInProcess = false;
    vm.selectedTaxonomies = taxonomyService.selectedTaxonomies;
    vm.siteSettings = siteService.settings;
    vm.taxonomies = taxonomyService.taxonomies;
    vm.url = window.location.href;
    vm.today = dateService.dateNow();


    //Clear filters
    vm.clearFilters = function() {
      //Clear filters
      archiveService.clearFilters();
      //Let view know that the model was updated
      vm.filters = archiveService.filters;
      // Reset the filtersRest flag, by setting this flag for modelUpdated()
      vm.clearFiltersHit = true;
    };

    //Clear search (happens after search has been executed)
    vm.clearSearch = function() {
      archiveService.searchTerm = '';
      vm.searchForm.$setPristine();
      vm.searchForm.$setUntouched();
    };

    //Code to execute when events have rendered
    vm.finishRenderEvents = function() {
      archiveService.finishRenderEvents();
    };

    //Code to execute when filters have rendered
    vm.finishRenderFilters = function() {
      archiveService.finishRenderFilters();
    };

    //Get events
    vm.getEvents = function() {
      if(!vm.requestInProcess) {
        vm.requestInProcess = true;
        archiveService.getEvents().then(function() {
          vm.modelUpdated();
        });
      }
    };

    //Get next page of events
    vm.getEventsNextPage = function() {
      archiveService.nextPage = true;
      vm.getEvents();
    };


    //Let view know that the model was updated
    vm.modelUpdated = function() {
      vm.searchTerm = archiveService.searchTerm;
      vm.currentMonth = archiveService.currentMonth;
      vm.eventsCount = archiveService.eventsCount;
      vm.events = archiveService.eventsList;
      vm.requestInProcess = false;
      // Show hide the filters reset button, depending on if vm.clearFilters() was run
      if(vm.clearFiltersHit === true || vm.initialPageLoad !== true) {
        vm.filtersReset = false;
        vm.clearFiltersHit = false;
        vm.initialPageLoad = true;
      } else {
        vm.filtersReset = true;
      }
    };

    //Search events
    vm.searchEvents = function() {
      if(vm.searchTerm !== '') {
        archiveService.searchEvents(vm.searchTerm).then(function() {
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

    //Init
    (function() {
      vm.getEvents();
    })();

  }

})();
