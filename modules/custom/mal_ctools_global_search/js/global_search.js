(function($) {

  Drupal.behaviors.ccGlobalSearch = {
    attach: function(context) {
      $("#edit-keys").autocomplete({
        source: function(request, response) {
          $.ajax({
            url: "/search_api_autocomplete/search_api_views_search/-/" + request.term,
            dataType: "json",
            success: function(data) {
              var result = [];
              for (var value in data) {
                result[result.length] = value;
              }
              response(result);
            }
          });
        },
        minLength: 2
      });
    }
  };
})(jQuery);
