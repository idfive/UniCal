(function() {

  angular
    .module('calendar')
    .directive('onFinishRender', onFinishRender);

  function onFinishRender($timeout) {
    return {
      restrict: 'A',
      link: function (scope, element, attr) {
        if (scope.$last === true) {
          $timeout(function() {
            scope.$evalAsync(attr.onFinishRender);
          });
        }
      }
    };
  }

})();
