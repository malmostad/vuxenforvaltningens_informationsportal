(function($) {

  Drupal.behaviors.ccFacetapiPopupCalendar = {
    attach: function(context) {
      $(".date-popup-calendar-form-input").datepicker({
        minDate: "-3Y",
        maxDate: "+3Y",
        dateFormat: Drupal.settings.DateFormatForPopup
      });
    }
  };
})(jQuery);

