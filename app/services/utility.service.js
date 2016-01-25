(function() {
  'use strict';
  
  angular
    .module('calendar')
    .factory('utilityService', utilityService);
  
  utilityService.$inject = ['$window'];
  
  function utilityService($window) {
    
    var service = {
      arrayToQueryString: arrayToQueryString,
      getBaseUrl: getBaseUrl
    };
    return service;

    //Get Base URL
    function getBaseUrl() {
      return $window.site_url.replace(/\/?$/, '/');
    };
    
    //Converts an array of strings into query string
    function arrayToQueryString(arr) {
      
      //Queries start with question mark
      var str = '?';
      
      //Build the filter string
      angular.forEach(arr, function(value, key) {
        str += value + '&';
      });
      
      //Returns filter string without the last &
      return str.substring(0, str.length -1);
      
    };

  };
  
})();