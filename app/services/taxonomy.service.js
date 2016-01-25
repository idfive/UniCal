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
        'taxonomy_6'
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
            function(data) {
              service.taxonomies[taxonomy] = {
                terms: data.data.data,
                label: siteService.settings[taxonomyLabel] || taxonomy,
                enabled: siteService.settings[taxonomyEnabled]
              };
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