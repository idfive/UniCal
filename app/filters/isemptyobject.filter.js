(function() {
  'use strict';
  
  angular
    .module('calendar')
    .filter('isEmptyObject', isEmptyObject);
  
  function isEmptyObject() {
    return function (obj) {
      return angular.equals({}, obj);
    };
  }

})();