(function() {
  'use strict';

  angular
    .module('calendar')
    .factory('utilityService', utilityService);

  utilityService.$inject = ['$window'];

  function utilityService($window) {

    var service = {
      arrayToQueryString: arrayToQueryString,
      getBaseUrl: getBaseUrl,
      shareFB: shareFB,
      shareTW: shareTW
    };
    return service;

    //Get Base URL
    function getBaseUrl() {
      return $window.site_url.replace(/\/?$/, '/');
    };

    // Share to Facebook
    function shareFB(url, id, uri) {
      window.open("https://www.facebook.com/sharer/sharer.php?u=" + url + "event/" + id + "/" + uri, "Facebook", "width=600, height=400, scrollbars=no");
    };

    // Share to Twitter
    function shareTW(title, url, id, uri) {
      window.open("https://twitter.com/home?status=" + title + " " + url + "event/" + id + "/" + uri, "Twitter", "width=600, height=400, scrollbars=no");
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
