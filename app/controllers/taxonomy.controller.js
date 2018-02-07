(function() {
  'use strict';
  
  angular
    .module('calendar')
    .controller('taxonomyController', taxonomyController);

  taxonomyController.$inject = ['$routeParams', 'taxonomyService'];

  function taxonomyController($routeParams, taxonomyService) {
    var vm = this;
    
  }
  
})();