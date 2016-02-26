(function() {
  'use strict';

  angular
    .module('calendar')
    .config(config);

  function config($routeProvider, $locationProvider, $sceDelegateProvider) {

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
      .otherwise({
        redirectTo: '/'
      });

    $locationProvider.html5Mode(true);

    //Whitelist URLs
    $sceDelegateProvider.resourceUrlWhitelist([
      'self',
      'https://www.google.com/maps/embed/**',
    ]);

  }

})();
