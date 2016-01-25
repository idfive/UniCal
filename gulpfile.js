// ========================================
// Required plugins
// ========================================

var gulp = require('gulp'),
    plugins = require('gulp-load-plugins')(),
    templateCache = require('gulp-angular-templatecache'),
    include = require('gulp-include'),
    uglify = require('gulp-uglify');


// ========================================
// Paths
// ========================================

var paths = {
  scss: {
    src:  'assets/scss/**/*.scss',
    dest: 'assets/css'
  }
};


// ========================================
// Compile Sass
// ========================================

// Compile scss files within assets/scss/
gulp.task('compile-sass', function() {
  return gulp.src(paths.scss.src)
    // https://www.npmjs.com/package/gulp-css-globbing
    .pipe(plugins.cssGlobbing({
      extensions: ['.scss']
    }))
    // https://www.npmjs.com/package/gulp-ruby-sass
    .pipe(plugins.rubySass({
      "sourcemap=none": true,
      style: 'compressed',
      precision: 8
    }))
    .on('error', function (err) {
      console.error('Error!', err.message);
    })
    .pipe(plugins.autoprefixer({
      browsers: ['last 2 versions'],
      cascade: false
    }))
    .pipe(gulp.dest(paths.scss.dest));
});


// ========================================
// Compile templates
// ========================================

gulp.task('compile-templates', function () {
  return gulp.src('app/templates/**/*.html')
    .pipe(templateCache({
      module: 'calendar',
      root: 'templates'
    }))
    .pipe(gulp.dest('app/'));
});


// ========================================
// Compile js
// ========================================

gulp.task('compile-js', function() {
  return gulp.src('unical.js')
    .pipe(include())
    .pipe(uglify({
      mangle: false
    }))
    .pipe(gulp.dest('app/build'));
});


// ========================================
// Create Watch Task
// ========================================

gulp.task('watch', function() {
  gulp.watch(paths.scss.src, ['compile-sass']);
  gulp.watch('app/templates/**/*.html', ['compile-templates']);
  gulp.watch(['unical.js', 'app/**/*.js', '!app/build/*.js'], ['compile-js']);
});


// ========================================
// Default 'gulp' task
// ========================================

gulp.task('default', ['compile-templates', 'compile-js', 'watch']);
