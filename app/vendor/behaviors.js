var idfiveCalendarApiBehaviors = (function() {
  
  var self = {};
  
  self.filterToggle = function() {
    
    var el = document.getElementById('idfive-calendar__filters-toggle');
  
    el.onclick = function() {
      var filtersEl = el.nextElementSibling;
      filtersEl.classList.toggle('open');
    };
    
  };
  
  return self;

})();