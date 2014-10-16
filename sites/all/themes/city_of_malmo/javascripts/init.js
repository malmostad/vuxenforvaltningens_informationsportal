/* Place your theme's javascript here! */

(function($) {
  // Use strict mode to avoid errors: https://developer.mozilla.org/en/JavaScript/Strict_mode
  "use strict";

  // To learn more about Javascript in Drupal 7 check out: http://drupal.org/node/756722
  
  
  Drupal.behaviors.city_of_malmo = {
    attach: function(context, settings) {

    	//------FAQ question/answer-------
    	$('.faq-list-questions').find('.question').on('click',openListFAQ);
    
    }
  };

})(jQuery);


// FAQ question/answer
function openListFAQ(){
	$(this).next()
		.toggleClass('open-close',300)
			.parent().toggleClass('icon-open-close');
}


