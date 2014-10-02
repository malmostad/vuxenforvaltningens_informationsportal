/* JavaScript for textfield Input Hints */
/* Uses the jQuery CoolInput plugin */

(function ($) {
  "use strict";

  Drupal.behaviors.zentropy_coolinput = {
    attach: function (context, settings) {
      $('input.form-text', context).each(function () {
        // If you want to keep the required asterisks, remove the last replace() call.
        var $t = $(this), $label = $t.prev('label'), text = $label.text().replace(' *', '');
        $t.coolinput(text);

        // Hide field's labels?
        if (settings.coolinput.hide_labels) {
          $label.addClass('element-invisible element-focusable');
        }
      });
    }
  };

/* To manually add input hints to other form elements using the jQuery CoolInput plugin: */
/* Call $('selector', context).coolinput(); */
/* For more information on the coolinput plugin's options check out: https://github.com/alexweber/jquery.coolinput */
}(jQuery));