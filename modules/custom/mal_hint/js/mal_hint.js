(function ($) {
  Drupal.behaviors.mal_hint = {
    attach: function (context, settings) {
      if (typeof($.prototype.tooltip) != 'undefined' && typeof(settings.mal_hint) != 'undefined' && settings.mal_hint.length) {
        for (var arg in settings.mal_hint) {
          var hint = $('<i>&nbsp;</i>').addClass('hint').tooltip({
            title: settings.mal_hint[arg].hint,
            placement: 'auto'
          });
          $(settings.mal_hint[arg].selector, context).prepend(hint);
        }
      }
    }
  }
})(jQuery);