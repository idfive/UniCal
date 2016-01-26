var UnicalApiBehaviors = (function() {
  
  var self = {};
  
  self.filterToggle = function() {
    
    var el = document.getElementById('unical-calendar__filters-toggle');
  
    el.onclick = function() {
      var filtersEl = el.nextElementSibling;
      filtersEl.classList.toggle('open');
    };
    
  };
  
  return self;

})();