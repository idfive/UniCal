(function() {
  'use strict';

  angular
    .module('calendar')
    .config(config);

  function config($routeProvider, $locationProvider, $sceDelegateProvider, $httpProvider) {

    //Routes
    $routeProvider
      .when('/', {
        templateUrl: 'templates/event/list.html',
        controller: 'eventsListController',
        controllerAs: 'vm',
        resolve: {
          initialData: function(eventService) {
            return eventService.initEventsList();
          }
        }
      })
      .when('/event/:eventId/:eventName?', {
        templateUrl: 'templates/event/detail.html',
        controller: 'eventsDetailController',
        controllerAs: 'vm',
        resolve: {
          initialData: function(eventService) {
            return eventService.initEventDetail();
          }
        }
      })
      .when('/submit-event', {
        templateUrl: 'templates/event/form.html',
        controller: 'eventSubmitController',
        controllerAs: 'vm',
        resolve: {
          initialData: function(eventService) {
            return eventService.initEventDetail();
          }
        }
      })
      .when('/archive', {
        templateUrl: 'templates/event/archive.html',
        controller: 'eventsArchiveController',
        controllerAs: 'vm',
        resolve: {
          initialData: function(archiveService) {
            return archiveService.initEventsList();
          }
        }
      })
      .otherwise({
        redirectTo: '/'
      });

    // For providing clean url's
    $locationProvider.html5Mode(true);

    // For loading spinner
    $httpProvider.interceptors.push('interceptorService');

    // Whitelist URLs
    $sceDelegateProvider.resourceUrlWhitelist([
      'self',
      'https://www.google.com/maps/embed/**',
    ]);

  }

})();
