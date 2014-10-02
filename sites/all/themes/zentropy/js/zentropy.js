/**
 * @file
 * Zentropy javascript core
 *
 * - Initialize Zentropy namespace
 * - Provides frequently used functions:
 *   - Zentropy.trim(string)
 *   - Zentropy.indexOf(array, element, startFrom)
 *   - Zentropy.log(text)
 *   - Zentropy.imagePreload(image1, image2, ...)
 * - jQuery browser detection tweak for IE7
 */

// Initialize namespace
var Zentropy = Zentropy || {};

// jQuery Browser Detect Tweak For IE7
jQuery.browser.version = jQuery.browser.msie && parseInt(jQuery.browser.version, 10) === 6 && window.XMLHttpRequest ? "7.0" : jQuery.browser.version;

(function ($) {
  "use strict";

  /**
   * Trim a string
   * 
   * @param str string
   * @return String
   */
  Zentropy.trim = function (str) {
    return str.replace(/\s+$/, '').replace(/^\s+/, '');
  };

  /**
   * Find index of element in an array
   * Optionally starts from an index
   * Optionally use non-strict comparison
   * 
   * @param arr array
   * @param element mixed
   * @param startFrom int
   * @param strict bool
   */
  Zentropy.indexOf = function (arr, element, startFrom, strict) {
    var i, j;
    strict = strict || true;

    if (startFrom === null) {
      startFrom = 0;
    } else if (startFrom < 0) {
      startFrom = Math.max(0, arr.length + startFrom);
    }

    for (i = startFrom, j = arr.length; i < j; i += 1) {
      if (strict) {
        if (arr[i] === element) {
          return i;
        }
      } else {
        if (arr[i] == element) {
          return i;
        }
      }
    }

    return -1;
  };

  /**
   * Console.log wrapper to avoid errors when console is not present
   * usage: Zentropy.log('inside coolFunc', this, arguments);
   * 
   * @link http://paulirish.com/2009/log-a-lightweight-wrapper-for-consolelog/
   */
  Zentropy.log = function () {
    Zentropy.log.history = Zentropy.log.history || [];  // store logs to an array for reference
    Zentropy.log.history.push(arguments);
    if (window.console) {
      console.log(Array.prototype.slice.call(arguments));
    }
  };

  /**
   * Preloads one or more images
   */
  Zentropy.imagePreload = function () {
    var i, cacheImage = document.createElement('img');
    Zentropy.imagePreload.cache = Zentropy.imagePreload.cache || [];
    for (i = arguments.length; i > 0; i -= 1) {
      cacheImage.src = arguments[i];
      Zentropy.imagePreload.cache.push(cacheImage);
    }
  };
  
  /**
   * Add classes to HTML for different browsers.
   * IE should be targetted using using the provided conditional stylesheets.
   * However this is here to help just in case.
   * 
   * Also remove js class from html.
   */
  Drupal.behaviors.zentropy = {
    attach: function (context, settings) {
      var $html = $('html', context);

      if ($.browser.webkit || $.browser.safari) { // "safari" is deprecated but kept for older versions of jQuery
        $html.addClass('webkit');
      } else if ($.browser.mozilla) {
        $html.addClass('mozilla');
      } else if ($.browser.opera) {
        $html.addClass('opera');
      }
      
      $html.removeClass('no-js');
    }
  };
}(jQuery));