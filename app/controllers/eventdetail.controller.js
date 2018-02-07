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
          var current = window.location.href;
          current = current.split("evnt=")[1];
          events.data[0].date = events.data[0].date.filter(function(d){
            if(current == d.start_unix){
              return 1;
            }
          });
          vm.events = events.data;
        });
    };

    vm.getEventsByTaxonomy = function(tid, taxonomy) {
      eventService.getEventsByTaxonomy(tid, taxonomy);
    };

    vm.getMapUrl = function(address, zoom, lat, lng) {
      //Default zoom of 10 if not specified.
      zoom = zoom || 10;
      lat = lat || false;
      lng = lng || false;

      //return street address, or via lat/lng if specified.
      if (lat && lng) {
        return 'https://www.google.com/maps/embed/v1/place?key='+siteService.settings.google_maps_api_key+'&q='+lat+','+lng+'&zoom='+zoom+'&maptype=roadmap';
      }

      return 'https://www.google.com/maps/embed/v1/place?key='+siteService.settings.google_maps_api_key+'&q='+encodeURI(address)+'&zoom='+zoom+'&maptype=roadmap';
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
