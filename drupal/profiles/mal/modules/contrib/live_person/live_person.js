(function ($) {
Drupal.behaviors.livePerson = {
  attach: function (context, settings) {
    function livePersonGetUrl (url) {
      if (typeof(lpAppendVisitorCookies) != 'undefined') {
        url = lpAppendVisitorCookies(params.url);
      }
      if (typeof(lpMTag) != 'undefined' && typeof(lpMTag.addFirstPartyCookies) != 'undefined') {
        url = lpMTag.addFirstPartyCookies(url);
      }
      return url;
    }

    function livePersonPopUp (params) {
      var url = livePersonGetUrl(params.url);
      var windowName = 'chat' + params.accountId;
      var specs = 'width=' + params.width + ',height=' + params.height + ',resizable=yes';
      window.open(url, windowName, specs);
      return false;
    }

    $('a#live-person', context).click(function() {
      livePersonPopUp(Drupal.settings.livePerson);
    });
  }
}
}(jQuery));