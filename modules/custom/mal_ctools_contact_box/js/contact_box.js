(function($) {

  Drupal.behaviors.malCtoolsContactBox = {
    attach: function(context) {
      $(".map-autocomplete").autocomplete({
        source: function(request, response) {
          return $.ajax({
            url: "//xyz.malmo.se/rest/1.0/addresses/",
            dataType: "jsonp",
            data: {
              q: request.term,
              items: 10
            },
            success: function(data) {
              return response($.map(data.addresses, function(item) {
                return {
                  label: "" + item.name + " (" + item.towndistrict + ")",
                  value: item.name
                };
              }));
            }
          });
        },
        minLength: 2
      })
    }
  };
})(jQuery);
