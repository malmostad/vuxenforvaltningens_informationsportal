(function($) {

  Drupal.behaviors.ccGlobalSearch = {
    attach: function(context) {
      $("#edit-keys").autocomplete({
        source: function(request, response) {
          $.ajax({
            url: "/mal_ctools_global_search/search_api_views_search/-/" + request.term,
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
