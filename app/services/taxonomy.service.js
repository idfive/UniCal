(function() {
  'use strict';

  angular
    .module('calendar')
    .factory('taxonomyService', taxonomyService);

  taxonomyService.$inject = ['$http', '$q', '$window', 'utilityService', 'siteService'];

  function taxonomyService($http, $q, $window, utilityService, siteService) {

    var _promises = [];

    var service = {
      single: single,
      getSelectedTaxonomies: getSelectedTaxonomies,
      getTaxonomies: getTaxonomies,
      allowedTaxonomies: [
        'taxonomy_1',
        'taxonomy_2',
        'taxonomy_3',
        'taxonomy_4',
        'taxonomy_5',
        'taxonomy_6',
        // taxonomy_7 is the add to calendar, which should not be changed
        'taxonomy_8',
        'taxonomy_9',
        'taxonomy_10',
        'taxonomy_11'
      ],
      taxonomies: {},
      selectedTaxonomies: {}
    };

    return service;

    //Get single taxonomy
    function single(taxonomy) {
      return $http.get(utilityService.getBaseUrl() + taxonomy);
    };

    /*
     * Gets taxonomies from Drupal
     *
     */
    function getTaxonomies() {

      angular.forEach(service.allowedTaxonomies, function(taxonomy) {

        //Create vars that can be used as keys
        var taxonomyLabel = taxonomy + '_label';
        var taxonomyEnabled = taxonomy + '_enabled';

        _promises.push(
            service.single(taxonomy).then(
              // Success Function
              function(data) {
                if(data.data.count > 0) {
                  service.taxonomies[taxonomy] = {
                    terms: data.data.data,
                    label: siteService.settings[taxonomyLabel] || taxonomy,
                    enabled: siteService.settings[taxonomyEnabled]
                  };
                }
              },
              // Fail Function
              function(data) {
                console.log('Error retrieving data for:' . taxonomy);
                console.log('See release notes for version 1.2. New/additional taxonomies are available to configure.');
              }
            )
          );

      });

      return $q.all(_promises).then(function() {
        return service.taxonomies;
      });

    };

    /*
     * Checks "pre-selected" taxonomy items returned from the site node
     *
     */
    function getSelectedTaxonomies() {

      angular.forEach(service.allowedTaxonomies, function(taxonomy) {

        //Create var that can be used as key
        var taxonomyLabel = taxonomy + '_selected';

        //If we have settings for this taxonomy
        if(typeof siteService.settings[taxonomyLabel] !== 'undefined')
        {
          service.selectedTaxonomies[taxonomy] = {};
          service.selectedTaxonomies[taxonomy].terms = {};

          angular.forEach(siteService.settings[taxonomyLabel], function(tid) {
            service.selectedTaxonomies[taxonomy].terms[tid] = true;
          });
        }

      });

      return service.selectedTaxonomies;

    };

  };

})();
