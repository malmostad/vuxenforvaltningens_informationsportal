/**
 * @file
 * JS for custom_breadcrumbs_features.
 *
 * Generate a crumb's name (hence a machine name) when a given form element is updated.
 */

(function ($) {

Drupal.behaviors.customBreadcrumbsFeatures = {
  attach: function (context) {

    // Declare elements used to generate cb name.
    var sources = {
      'custom-breadcrumbs-form':                     '#edit-node-type',
      'custom-breadcrumbsapi-form':                  '#edit-module-page',
      'custom-breadcrumbs-paths-form':               '#edit-specific-path',
      'custom-breadcrumbs-panels-form':              '#edit-panel-id',
      'custom-breadcrumbs-taxonomy-term-form':       '#edit-tid',
      'custom-breadcrumbs-taxonomy-vocabulary-form': '#edit-vid',
      'custom-breadcrumbs-views-form':               '#edit-views-path'
    };

    var generated = !$('#edit-name', context).val();

    // Find out which element we should use.
    $.each(sources, function(form, source) {
      if (context['forms'][form] != null) {

        // Add event handler so the name is updated when we change the source.
        $(source, context).change(function() {
          var val = '';
          switch ($(source)[0].tagName.toLowerCase()) {
            case 'select':
              if ($(source).val()) {
                val = $(source + ' option:selected').text();
              }
              break;
            default:
              val = $(source).val();
          }
          var name = $('#edit-name', context);
          if (!name.val() || generated) {
            name.val(val);
            name.change();
          }
        });

        // Assume that if the user edited the name, we do not need to generate one.
        $('#edit-name', context).focus(function() {
          generated = false;
        });

        // No need to loop over all elements.
        return false;

      }
    });
  }
};

})(jQuery);
