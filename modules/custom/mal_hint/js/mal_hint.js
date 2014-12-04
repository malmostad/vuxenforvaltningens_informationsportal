(function ($) {
  Drupal.behaviors.malHint = {
    attach: function (context, settings) {
      if (typeof($.prototype.tooltip) != 'undefined' && typeof(settings.malHint) != 'undefined' && settings.malHint.length) {
        for (var arg in settings.malHint) {
          var hint = $('<i>&nbsp;</i>').addClass('hint').tooltip({
            title: settings.malHint[arg].hint,
            placement: 'auto'
          });
          $(settings.malHint[arg].selector, context).prepend(hint);
        }
      }
    }
  }
})(jQuery);
