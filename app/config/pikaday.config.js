(function() {
  'use strict';

  angular
    .module('calendar')
    .config(pikadayConfig);

  pikadayConfig.$inject = ['pikadayConfigProvider'];

  function pikadayConfig(pikadayConfigProvider) {
      pikadayConfigProvider.setConfig({
        format: 'YYYY-MM-DD',
      });
  }

})();
