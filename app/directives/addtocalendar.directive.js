(function() {

  angular
    .module('calendar')
    .directive('addToCalendar', addToCalendar);

  function addToCalendar() {
    return {
      restrict: 'E',
      templateUrl: 'templates/event/addtocalendar.html'
    };
  }

})();
