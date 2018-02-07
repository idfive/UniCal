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
      getAddEventID: getAddEventID,
      shareFB: shareFB,
      shareTW: shareTW,
      showLoading: showLoading,
      hideLoading: hideLoading
    };
    return service;

    // Get Base URL
    function getBaseUrl() {
      return $window.site_url.replace(/\/?$/, '/');
    };

    // Get Add Event ID
    function getAddEventID() {
      return $window.addevent_id;
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

    /*
     * Show the loading div.
     * A custom loading div may overwrite this by adding a div with the ID
     * "unical-calendar-loading" Somewhere in your HTML markup. If that div exists
     * the function will hide/show it, rather than create one.
     *
     */
    function showLoading() {
      if(jQuery("#unical-calendar-loading").length == 0) {
        var loader = jQuery("<div>", {id: "unical-calendar-loading", "class": "loading"});
        jQuery("body").append(loader);
      } else {
        jQuery('#unical-calendar-loading').show();
      }
    }

    /*
     * Hide the loading div.
     *
     */
    function hideLoading() {
      jQuery('#unical-calendar-loading').hide();
    }

  };

})();
