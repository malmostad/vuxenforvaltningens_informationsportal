/* Place your theme's javascript here! */

(function($) {
  // Use strict mode to avoid errors: https://developer.mozilla.org/en/JavaScript/Strict_mode
  "use strict";

  // To learn more about Javascript in Drupal 7 check out: http://drupal.org/node/756722
  
  
  Drupal.behaviors.city_of_malmo = {
    attach: function(context, settings) {

    	//------FAQ question/answer-------
    	$('.faq-list-questions').find('.question').on('click',openListFAQ);
    


      
/*      $('.nav-logo').children('a')
          .attr('href','/')
              .css('background','url("http://assets.malmo.se/external/v4/logo-x1.png") no-repeat');
      
      $('.dropdown-menu')
          .html('<li><a role="menuitem" href="/node/1">Detail content</a></li>'+
                '<li><a role="menuitem" href="/faq">FAQ</a></li>');
*/
    }
  };

})(jQuery);


// FAQ question/answer
function openListFAQ(){
	$(this).next()
		.toggleClass('open-close',300)
			.parent().toggleClass('icon-open-close');
}


