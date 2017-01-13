var swiftSlide = (function() {
  'use strict';

  var self = {};
  var currentSlide = 0;
  var pages = []; // Create pages array to indicate each page

  self.els = {};
  self.init = function(parameters) {


    // ================
    // Setup
    // ================

    // Assign variables to previously mentioned elements
    self.els.container = document.querySelector(parameters.container);

    // Return if no container elements found
    if(!self.els.container) {
      return false;
    }

    // Get slides
    self.els.slides = document.querySelectorAll(parameters.container + ' ' + parameters.elements);

    // Return if no elements found
    if(!self.els.slides) {
      return false;
    }

    // Controller Setup
    // ----------------

    // Create controller container
    self.els.controller = document.createElement('div');
    self.els.controller.classList.add('controls');

    // Append controller to the swift-slide container
    self.els.container.appendChild(self.els.controller);

    //Create controls
    if(parameters.showPrevNext) {

      //start the auto slider
      self.slider = setInterval(self.nextSlide, 5000);

      // Create previous control
      self.els.prev = document.createElement('button');
      self.els.prev.innerHTML = '<span class="screen-reader-text">Previous</span>';
      self.els.prev.addEventListener('click', self.clearIntervalprevious, false);

      // Create next control
      self.els.next = document.createElement('button');
      self.els.next.innerHTML = '<span class="screen-reader-text">Next</span>';
      self.els.next.addEventListener('click', self.clearIntervalnext, false);

      // Append controls to the controller
      self.els.controller.appendChild(self.els.prev);
      self.els.controller.appendChild(self.els.next);

    }



    // Pager Setup
    // ----------------

    // Create pager
    self.els.pager = document.createElement('div');
    self.els.pager.classList.add('pager');

    // Append pager to the swift-slide container
    self.els.container.appendChild(self.els.pager);

    // For each slide
    for (var index = 0; index < self.els.slides.length; index++) {

      // Create a page
      pages.push(document.createElement('span'));

      // Add an event listener to that page
      pages[index].addEventListener('click', self.slide.bind(null, index), false);

      // Append that page into the pager
      self.els.pager.appendChild(pages[index]);

    }

    // Activate the first slide by default
    pages[currentSlide].click();

  };

  // ================
  // Actions
  // ================

  self.clearIntervalnext = function() {

    // Go to next slide, and clear the autoslide interval
    self.nextSlide();
    clearInterval(self.slider);

  };

  self.clearIntervalprevious = function() {

    // Go to previous slide, and clear the autoslide interval
    self.previousSlide();
    clearInterval(self.slider);

  };

  self.clearClasses = function() {

    // Remove active class from all pages and slides
    for (var i = 0; i < self.els.slides.length; i++) {

      if(typeof pages[i] !== 'undefined') {
        pages[i].classList.remove('active');
      }
      self.els.slides[i].classList.remove('active');
    }

  };

  self.assignClasses = function(index) {

    // Add active class to the selected page and slide
    pages[index].classList.add('active');
    self.els.slides[index].classList.add('active');

  };

  self.slide = function(index) {

    self.clearClasses();
    self.assignClasses(index);

  };

  self.previousSlide = function() {

    if(currentSlide === 0) {
      currentSlide = self.els.slides.length;
    }

    currentSlide = currentSlide - 1;

    self.slide(currentSlide);

  };

  self.nextSlide = function() {

    if (currentSlide === self.els.slides.length - 1) {
      currentSlide = -1;
    }

    currentSlide = currentSlide + 1;

    self.slide(currentSlide);

  };

  return self;

}());
