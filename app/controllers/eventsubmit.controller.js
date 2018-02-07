(function() {
  'use strict';

  angular
    .module('calendar')
    .controller('eventSubmitController', eventSubmitController);

  eventSubmitController.$inject = ['$routeParams', '$location', '$window', 'eventService', 'taxonomyService', 'utilityService', 'dateService', 'siteService', 'Upload'];

  function eventSubmitController($routeParams, $location, $window, eventService, taxonomyService, utilityService, dateService, siteService, Upload) {

    //Shortcut to scope
    var vm = this;

    //Scope variables
    vm.customValidation = {
      endDateAfterStartDate: true
    };
    vm.newEventData = eventService.newEventData;
    vm.newEventDataRaw = eventService.newEventDataRaw;
    vm.newEventProgress = eventService.newEventProgress;
    vm.pages = 9;
    vm.submitted = false;
    vm.taxonomies = taxonomyService.taxonomies;
    vm.siteSettings = siteService.settings;

    //Hide loading screen
    utilityService.hideLoading();

    /*
     * Create the event
     *
     */
    vm.createEvent = function() {
      vm.submitted = true;
      vm.processDataRaw();
      eventService.createNewEvent().then(function() {
        // Reset the events service
        eventService.newEventData = {
          date: [{
            value: '',
            value2: ''
          }],
          address: {
            country: "US"
          }
        };
        eventService.newEventDataRaw = {};
        vm.page = 10;
        vm.submitted = false;
      }, function(response) {
        vm.submitted = false;
        $window.alert('Sorry, there was a problem submitting your event.');
      });
    };

    /*
     * Next page
     *
     */
    vm.nextPage = function(numberPages) {
      vm.newEventProgress[vm.page] = true;
      vm.page = vm.page + numberPages;
      $location.hash(vm.page);
    }

    /*
     * previous page
     *
     */
    vm.prevPage = function(numberPages) {
      vm.newEventProgress[vm.page] = false;
      vm.page = vm.page - numberPages;
      $location.hash(vm.page);
    }

    /*
     * Process any raw data (data that needs to be massaged before being added to Drupal node object)
     *
     */
    vm.processDataRaw = function() {
      //Start date
      vm.newEventData.date[0].value = dateService.createDrupalDateFromPieces(vm.newEventDataRaw.startDate, vm.newEventDataRaw.startTime.hour, vm.newEventDataRaw.startTime.minute, vm.newEventDataRaw.startTime.AMPM).format('YYYY-MM-DD HH:mm:ss');
      //End date
      vm.newEventData.date[0].value2 = dateService.createDrupalDateFromPieces(vm.newEventDataRaw.endDate, vm.newEventDataRaw.endTime.hour, vm.newEventDataRaw.endTime.minute, vm.newEventDataRaw.endTime.AMPM).format('YYYY-MM-DD HH:mm:ss');
    };

    /*
     * Check to see if any taxonomies have been pre-selected in Drupal
     *
     */
    vm.hasPrecheckedTaxonomies = function() {
      var hasChecked = false;
      //Loop through each taxonomy
      angular.forEach(vm.taxonomies, function(taxonomy, taxonomyId) {
        //Create key variable
        var taxonomySelectedKey = taxonomyId + '_selected';
        //If this taxonomy is not null (and we haven't already determined checked taxonomies from a previous pass of the loop)
        if(vm.siteSettings[taxonomySelectedKey] && !hasChecked) {
          hasChecked = true;
        }
      });
      return hasChecked;
    };

    /*
     * Pre-check a taxonomy and add to new data collection
     *
     */
    vm.isTermPrechecked = function(taxonomyId, term, index) {
      //Create key variable
      var taxonomySelectedKey = taxonomyId + '_selected';
      //Only continue if we have preselected terms for this taxonomy
      if(vm.siteSettings[taxonomySelectedKey]) {
        //If passed term is in selected array, we will check it on the form and add the key to new data collection
        if(vm.siteSettings[taxonomySelectedKey].indexOf(term.toString()) > -1) {
          //Make sure the taxonomy is already an object in new data collection, else create it
          if(typeof vm.newEventData[taxonomyId] !== 'object') {
            vm.newEventData[taxonomyId] = {};
          }
          //Add the term to the new data collection
          vm.newEventData[taxonomyId][index] = term;
          //Return true so box is checked
          return true;
        }
      }
      //Catch all
      return false;
    };

    /*
     * Check that at least one taxonomy option is selected
     *
     */
    vm.taxonomyValidateSelected = function() {
      var checked = 0;
      angular.forEach(vm.taxonomies, function(taxonomy, taxonomyId) {
        if(typeof vm.newEventData[taxonomyId] !== 'undefined') {
          angular.forEach(vm.newEventData[taxonomyId], function(value, key) {
            if(typeof value !== 'undefined' && value != '') {
              checked++;
            }
          });
        }
      });
      return checked;
    };

    /*
     * Upload image
     *
     */

    vm.uploadImage = function(image, errors) {

      //Any validation errors are caught here
      vm.imageValidationError = errors && errors[0];

      //If an image was selected
      if(image) {
        image.upload = Upload.upload({
          url: utilityService.getBaseUrl() + 'file-upload',
          data: {
            file: image
          }
        }).then(function(response) {
          var data = response.data.data[0];
          vm.newEventData.image = data.id;
          vm.imageName = data.label;
        }, function(response) {
          if(response.status > 0) {
            vm.imageUploadError = response.status + ': ' + response.data;
          }
        });
      }
    }

    vm.clearImage = function() {
      vm.newEventData.image = undefined;
      vm.imageName = '';
    }

    /*
     * Validate that end date is after start date
     *
     */
    vm.validateDates = function() {
      //Start date
      var startDate = dateService.createDrupalDateFromPieces(vm.newEventDataRaw.startDate, vm.newEventDataRaw.startTime.hour, vm.newEventDataRaw.startTime.minute, vm.newEventDataRaw.startTime.AMPM);
      //End date
      var endDate = dateService.createDrupalDateFromPieces(vm.newEventDataRaw.endDate, vm.newEventDataRaw.endTime.hour, vm.newEventDataRaw.endTime.minute, vm.newEventDataRaw.endTime.AMPM);

      if(endDate.isAfter(startDate)) {
        vm.customValidation.endDateAfterStartDate = true;
      } else {
        vm.customValidation.endDateAfterStartDate = false;
      }
    };

    /*
     * Validate that the user is permitted to view this page (stops user directly loading anything but first page initially)
     *
     */
    vm.validatePage = function() {
      //If not page 1
      if(vm.page > 1) {
        //Assume false until proven otherwise
        var validPage = true,
            stepCount = 0;
        //Look at each previous page to make sure steps are complete
        angular.forEach(vm.newEventProgress, function(value, key) {
          stepCount++;
          if(key < vm.page && !value) {
            validPage = false;
          }
        });
        //if not valid, send to step 1
        if(!validPage || stepCount < 1) {
          vm.page = 1;
          $location.hash(vm.page);
        }
      }
    };

    //Init
    (function() {
      vm.page = parseInt($location.hash()) || 1;
      vm.validatePage();
    })();

  }

})();
