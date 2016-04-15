(function() {
  'use strict';

  angular
    .module('calendar')
    .controller('eventsDetailController', eventsDetailController);

  eventsDetailController.$inject = ['$routeParams', 'eventService', 'taxonomyService', 'siteService', 'utilityService', 'dateService'];

  function eventsDetailController($routeParams, eventService, taxonomyService, siteService, utilityService, dateService) {

    //Shortcut to scope
    var vm = this;

    //Scope variables
    vm.siteSettings = siteService.settings;
    vm.taxonomies = taxonomyService.taxonomies;
    vm.url = window.location.protocol+"//"+window.location.host + "/";
    vm.today = dateService.dateNowUnix();

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
      vm.getEvent($routeParams.eventId);
    })();

    addthisevent.settings({
      css: false,
      license: utilityService.getAddEventID(),
    });

  }

})();
