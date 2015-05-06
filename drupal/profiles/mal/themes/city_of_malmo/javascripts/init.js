/* Place your theme's javascript here! */

(function($) {
  // Use strict mode to avoid errors: https://developer.mozilla.org/en/JavaScript/Strict_mode
  "use strict";

  // To learn more about Javascript in Drupal 7 check out: http://drupal.org/node/756722


  Drupal.behaviors.city_of_malmo = {
    attach: function(context, settings) {
      //------FAQ question/answer-------
      $('.faq-list-questions').find('.question').on('click',openListFAQ);

      $('.nav-logo').children('a')
        .attr('href','/')
          .css('background','url("http://assets.malmo.se/external/v4/logo-x1.png") no-repeat');

      var $flex_group = $('.facetapi-facet-field-course-formname', context);
      var $time_group = $('.facetapi-facet-field-course-periodsvalue', context);
      if ($time_group.length > 0 &&
        $flex_group.find('li').length > 0) {
        $flex_group.parent().hide();
        $flex_group.find('li').detach().appendTo($time_group);
      }
    }
  };

  Drupal.behaviors.searchFilter = {
    attach: function(context, settings) {
      var $filter = $('.search-filter > h2'),
          $popup = $('.search-filter *');

      $filter.click(function(e) {
        if (!$(this).hasClass('active')) {
          $filter.siblings('h2').removeClass('active');
          $(this).toggleClass('active');
        } else {
          $(this).removeClass('active');
        }
      });

      $(document).click(function(e) {
        if (!($(e.target).is($popup) || $(e.target).is('.datepicker *') || $(e.target).is('.month') || $(e.target).is('.year'))) {
          $filter.removeClass('active');
        }
      });
    }
  };

  Drupal.behaviors.searchAccordion = {
    attach: function(context, settings) {
      $('.view-search', context).find('.panel-heading').once().click(function() {
        $(this).siblings('.panel-body').toggle(300);
        if ($.trim($(this).text()) === 'Dölj beskrivning') {
          $(this).text('Visa beskrivning');
        } else {
          $(this).text('Dölj beskrivning');
        }
      });
    }
  };

  Drupal.behaviors.myPlaningTabs = {
    attach: function(context, settings) {
      var navigation = $('.tab-item'),
          tableTabs = $('.table-tabs'),
          secondTable = $('.tab-second');

      secondTable.hide();

      navigation.click(function() {
        if (!$(this).hasClass('active')) {
          navigation.toggleClass('active');
          tableTabs.toggle();
        }
      });
    }
  };

})(jQuery);


// FAQ question/answer
function openListFAQ(){
  $(this).next()
    .toggleClass('open-close',300)
      .parent().toggleClass('icon-open-close');
}
