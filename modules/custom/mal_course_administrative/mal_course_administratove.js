(function ($) {

  Drupal.behaviors.malCourseAdministrative = {
    attach: function (context, settings) {
      var $continuesCheckbox = $('#edit-field-course-continuos-und', context),
        $coursePeriodStart = $('#edit-field-course-date-und-0-value-datepicker-popup-0', context),
        $coursePeriodEnd = $('#edit-field-course-date-und-0-value2-datepicker-popup-0', context),
        $courseApplicationPeriodStart = $('#edit-field-course-application-period-und-0-value-datepicker-popup-0', context),
        $courseApplicationPeriodEnd = $('#edit-field-course-application-period-und-0-value2-datepicker-popup-0', context);

      $continuesCheckbox.change(function () {
        if (!$continuesCheckbox.is(':checked')) {
          $coursePeriodStart.add($courseApplicationPeriodStart).val(new Date());
        }
        else {
          $coursePeriodStart.add($coursePeriodEnd).add($courseApplicationPeriodStart).add($courseApplicationPeriodEnd).val('');
        }
      });
    }
  };

})(jQuery);
