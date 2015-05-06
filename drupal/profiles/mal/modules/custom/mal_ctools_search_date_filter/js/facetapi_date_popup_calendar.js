(function($) {

  Drupal.behaviors.ccFacetapiPopupCalendar = {
    attach: function(context) {
      $('#start-date').datepicker({
        format: 'yyyy-mm-dd',
        weekStart: 1,
        language: "sv",
        autoclose: true,
        todayHighlight: true,
       // startDate: '-3d'
      }).on('changeDate', function(ev) {
        $(this).closest('form').submit();
      });
    }
  };
})(jQuery);

