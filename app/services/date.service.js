(function() {
  'use strict';

  angular
    .module('calendar')
    .factory('dateService', dateService);

  dateService.$inject = [];

  function dateService() {

    var _defaultDateFormat = 'YYYY-MM-DD';

    var service = {
      createDrupalDateFromPieces: createDrupalDateFromPieces,
      dateNow: dateNow,
      dateNowUnix: dateNowUnix,
      dateWeekArchiveStart: dateWeekArchiveStart,
      dateMonthArchiveStart: dateMonthArchiveStart,
      dateSixMonthsArchiveStart: dateSixMonthsArchiveStart,
      dateYearArchiveStart: dateYearArchiveStart,
      dateTodayStart: dateTodayStart,
      dateTodayEnd: dateTodayEnd,
      dateTomorrowStart: dateTomorrowStart,
      dateTomorrowEnd: dateTomorrowEnd,
      dateWeekStart: dateWeekStart,
      dateWeekEnd: dateWeekEnd,
      dateMonthStart: dateMonthStart,
      dateMonthEnd: dateMonthEnd,
      dateMonthCurrent: dateMonthCurrent,
      dateYearCurrent: dateYearCurrent
    };
    return service;

    /*
     * Get date-time in correct format for Drupal
     *
     */
    function createDrupalDateFromPieces(date, hour, minute, marker) {
      //Build time
      var time = hour + ':' + minute + ' ' + marker;
      //Build full date
      var dateTime = moment(date + ' ' + time, 'YYYY-MM-DD hh:mm A');
      //Return date in 24-hour format
      return moment(dateTime);
    }

    /*
     * Date right now (Don't get minutes so we can cache better)
     *
     */
    function dateNow(dateFormat) {
      dateFormat = dateFormat || _defaultDateFormat;
      return moment().format(_defaultDateFormat + ' HH') + ':00:00';
    }

    /*
     * Date right now in unix
     *
     */
    function dateNowUnix() {
      return moment().unix();
    }

    /*
    * Date a week ago, for archive
    *
    */
    function dateWeekArchiveStart(dateFormat) {
      dateFormat = dateFormat || _defaultDateFormat;
      return moment().subtract(7, 'days').format(_defaultDateFormat + ' HH') + ':00:00';
    }

    /*
    * Date a month ago, for archive
    *
    */
    function dateMonthArchiveStart(dateFormat) {
      dateFormat = dateFormat || _defaultDateFormat;
      return moment().subtract(1, 'months').format(_defaultDateFormat + ' HH') + ':00:00';
    }

    /*
    * Date six months ago, for archive
    *
    */
    function dateSixMonthsArchiveStart(dateFormat) {
      dateFormat = dateFormat || _defaultDateFormat;
      return moment().subtract(6, 'months').format(_defaultDateFormat + ' HH') + ':00:00';
    }

    /*
    * Date a year ago, for archive
    *
    */
    function dateYearArchiveStart(dateFormat) {
      dateFormat = dateFormat || _defaultDateFormat;
      return moment().subtract(1, 'years').format(_defaultDateFormat + ' HH') + ':00:00';
    }


    /*
     * Date at the start of today
     *
     */
    function dateTodayStart(dateFormat) {
      dateFormat = dateFormat || _defaultDateFormat;
      return moment().format(_defaultDateFormat) + ' 00:00:00';
    }

    /*
     * Date at the end of today
     *
     */
    function dateTodayEnd(dateFormat) {
      dateFormat = dateFormat || _defaultDateFormat;
      return moment().format(_defaultDateFormat) + ' 23:59:59';
    }

    /*
     * Date at the start of tomorrow
     *
     */
    function dateTomorrowStart(dateFormat) {
      dateFormat = dateFormat || _defaultDateFormat;
      return moment().add(1, 'days').format(_defaultDateFormat) + ' 00:00:00';
    }

    /*
     * Date at the end of tomorrow
     *
     */
    function dateTomorrowEnd(dateFormat) {
      dateFormat = dateFormat || _defaultDateFormat;
      return moment().add(1, 'days').format(_defaultDateFormat) + ' 23:59:59';
    }

    /*
     * Date at the start of the week
     *
     */
    function dateWeekStart(dateFormat) {
      dateFormat = dateFormat || _defaultDateFormat;
      return moment().startOf('week').format(_defaultDateFormat + ' HH:mm:ss');
    }

    /*
     * Date at the end of the week
     *
     */
    function dateWeekEnd(dateFormat) {
      dateFormat = dateFormat || _defaultDateFormat;
      return moment().endOf('week').format(_defaultDateFormat + ' HH:mm:ss');
    }

    /*
     * Date at the start of the month
     *
     */
    function dateMonthStart(dateFormat) {
      dateFormat = dateFormat || _defaultDateFormat;
      return moment().startOf('month').format(_defaultDateFormat + ' HH:mm:ss');
    }

    /*
     * Date at the end of the month
     *
     */
    function dateMonthEnd(dateFormat) {
      dateFormat = dateFormat || _defaultDateFormat;
      return moment().endOf('month').format(_defaultDateFormat + ' HH:mm:ss');
    }

    /*
     * Returns current month as full name
     *
     */
    function dateMonthCurrent(dateFormat) {
      dateFormat = dateFormat || 'MMMM';
      return moment().format(dateFormat);
    }

    /*
     * Returns current year as four digit year
     *
     */
    function dateYearCurrent(dateFormat) {
      dateFormat = dateFormat || 'YYYY';
      return moment().format(dateFormat);
    }

  };

})();
