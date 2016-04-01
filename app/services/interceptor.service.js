(function () {
  'use strict';

  angular
    .module('calendar')
    .factory('interceptorService', interceptorService);

  interceptorService.$inject = [];

  function interceptorService() {

    return {
      'request': function(config) {
        jQuery('.loadingAsync').show();
        return config;
      },
      'response': function(response) {
        jQuery('.loadingAsync').hide();
        return response;
      },
    };

  };

})();
