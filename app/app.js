(function() {
  'use strict';

  angular
    .module('calendar', ['ngRoute', 'ngSanitize', 'ngAria', 'ngMessages', 'tien.clndr', 'pikaday', 'ngFileUpload']);
  
  addthisevent.settings({
    css: false
  });

})();