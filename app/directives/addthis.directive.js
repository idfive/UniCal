(function() {

  angular
    .module('calendar')
    .directive('addThis', addThis);

  function addThis() {
    return {
      restrict: 'E',
      templateUrl: 'templates/event/addthis.html'
    };
  }

})();
