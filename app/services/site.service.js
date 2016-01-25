(function() {
  'use strict';

  angular
    .module('calendar')
    .factory('siteService', siteService);

  siteService.$inject = ['$http', 'utilityService'];

  function siteService($http, utilityService) {

    var service = {
      getSite: getSite,
      settings: {}
    };

    return service;


    //Single site
    function getSite(id) {
      return $http.get(utilityService.getBaseUrl() + 'sites/' + id).then(function(response) {
        service.settings = response.data.data[0];
        return response.data;
      });
    };

  };

})();
