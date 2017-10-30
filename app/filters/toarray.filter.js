(function() {
  'use strict';

  angular
    .module('calendar')
    .filter('toArray', toArray);

  function toArray() {
    return function(obj) {
      var result = [];
      angular.forEach(obj, function(val) {
        result.push(val);
      });
     return result;
   };
  }

})();
