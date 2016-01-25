(function() {
  'use strict';

  angular
    .module('calendar')
    .controller('eventsDetailController', eventsDetailController);

  eventsDetailController.$inject = ['$routeParams', 'eventService', 'taxonomyService', 'siteService'];

  function eventsDetailController($routeParams, eventService, taxonomyService, siteService) {

    //Shortcut to scope
    var vm = this;

    //Scope variables
    vm.siteSettings = siteService.settings;
    vm.taxonomies = taxonomyService.taxonomies;
    vm.url = window.location.href;

    //Get event
    vm.getEvent = function(id) {
      eventService.getEvent(id)
        .success(function(events) {
          vm.events = events.data;
          console.log(vm.events);
        });
    };

    vm.getEventsByTaxonomy = function(tid, taxonomy) {
      eventService.getEventsByTaxonomy(tid, taxonomy);
    };

    vm.getMapUrl = function(address) {
      return 'https://www.google.com/maps/embed/v1/place?key='+siteService.settings.google_maps_api_key+'&q='+encodeURI(address)+'&zoom=10&maptype=roadmap';
    };

    vm.finishRenderEvents = function() {
      eventService.finishRenderEvents();
    };

    //Init
    (function() {
      vm.getEvent($routeParams.eventId);
    })();

  }

})();
