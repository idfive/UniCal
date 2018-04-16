(function() {

  angular
    .module('calendar')
    .directive('backLink', backLink);
  
  function backLink() {
    return {
      restrict: 'E',
      template: '<a class="back">{{text}}</a>',
      scope: {
        text: '@text'
      },
      link: function(scope, element, attrs) {
        jQuery(element[0]).on('click', function() {
          history.back();
          scope.$apply();
        });
      }
    };
  }
  
})();