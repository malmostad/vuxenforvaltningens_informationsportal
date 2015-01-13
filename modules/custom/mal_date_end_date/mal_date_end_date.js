(function ($) {
    // Use strict mode to avoid errors: https://developer.mozilla.org/en/JavaScript/Strict_mode
    "use strict";
    Drupal.behaviors.datepickertweaks = {
        attach: function (context, settings) {
            for (var key in Drupal.settings.mal_date_end_date) {
                var field = Drupal.settings.mal_date_end_date[key];
                (function (field) {
                    $('#' + field + '-value-datepicker-popup-0').change(function(){
                        $('#' + field + '-value2-datepicker-popup-0').val($(this).val());
                    });
                })(field)
            }
        }
    };
})(jQuery);
