/**
 * @file
 * Zentropy javascript ajax laoder core
 *
 * - Provides some nifty ajax loader functions:
 *   - Zentropy.msgBox(text, status, duration)
 *   - Zentropy.ajaxStartLoad(block, text)
 *   - Zentropy.ajaxStopLoad(block, text)
 */

// Initialize namespace
Zentropy = Zentropy || {};

(function ($) {
  "use strict";
  
  /**
   * Displays a dropdown message
   * A duration can optionally be specified, if not the message stays on the screen for 2000 milliseconds
   * 
   * @param text string
   * @param status string, similar to drupal_set_message().
   * @param duration int, in milliseconds
   */
  Zentropy.msgBox = function (text, status, duration) {
    duration = duration || 2000;
    Zentropy.ajaxStartLoad(false, text, status);

    setTimeout(function () {
      Zentropy.ajaxStopLoad(false);
    }, parseInt(duration, 10));
  };

  /**
   * Displays the Ajax Loader image
   * By default, the loader will block the User Interface
   * If a non-blocking loader is used, a message can optionally be displayed
   * 
   * 
   * @param block bool
   * @param msg string
   * @param status string, similar to drupal_set_message().
   */
  Zentropy.ajaxStartLoad = function (block, msg, status) {
    var $loader, $body = $('body');
    block = typeof block !== 'undefined' ? block : true;

    if (block) {
      $loader = $body.find('#zentropy-loader');

      if (!$loader.length) {
        $loader = $('<div id="zentropy-loader" class="zentropy-loader" style="display:none;"><span class="zentropy-loader-image"></span></div>');
        $body.append($loader);
      }

      $loader.show();
    } else {
      $loader = $body.find('#zentropy-load-msg');

      if (!$loader.length) {
        msg = msg || Drupal.t('Please wait...');
        status = status || 'status';
        $loader = $('<div id="zentropy-load-msg" class="zentropy-load-msg" style="display:none;"><span class="zentropy-load-msg-text ' + status + '">' + msg + '</span></div>');
        $body.append($loader);
      }

      $loader.slideDown('fast');
    }
  };

  /**
   * Hides the Ajax Loader image
   * If a non-blocking loader is used, a message can optionally be displayed
   * 
   * @param block bool
   * @param msg string
   */
  Zentropy.ajaxStopLoad = function (block, msg) {
    var $loader, $body = $('body');
    block = typeof block !== 'undefined' ? block : true;
    msg = msg || null;

    if (block) {
      $loader = $body.find('#zentropy-loader');

      if ($loader.length) {
        $loader.remove();
      }
    } else {
      $loader = $body.find('#zentropy-load-msg');

      if ($loader.length) {
        if (msg) {
          $loader.find('span').text(msg);
          setTimeout(function () {
            $loader.slideUp('fast', function () {
              $(this).remove();
            });
          }, 1200);
        } else {
          $loader.slideUp('fast', function () {
            $(this).remove();
          });
        }
      }
    }
  };
}(jQuery));