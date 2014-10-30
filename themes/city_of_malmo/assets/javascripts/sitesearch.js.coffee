# Autocomplete for site search
jQuery ($) ->
  # Covers both masthead search and the search page form
  searchFields = ["#full-search #q", "#masthead-search .q"]
  for searchField in searchFields
    do ->
      $searchField = $(searchField)
      if $searchField.length
        requestTerm = ""
        $searchField.autocomplete
          minLength: 2
          source: (request, response) ->
            requestTerm = request.term
            remoteData($searchField, request, response)
          select: (event, ui) ->
            if ui.item.link
              event.preventDefault()
              logToGaAndGo(ui.item, requestTerm)
            else
              $searchField.val(ui.item.value).closest("form").submit()
          open: ->
            $widget = $searchField.autocomplete("widget").addClass('site-search')
            recommendationHeader($widget)
            suggestionHeader($widget)
            fullSearchItem($widget, requestTerm)
        .data("ui-autocomplete")._renderItem = (ul, item) ->
          item.caller = $searchField.attr("data-caller")
          if item.link
            item.type = "Recommendation"
            recommendationItem(ul, item, $searchField.attr("data-images-url"), $searchField.attr("data-caller"))
          else if item.suggestion
            item.type = "Suggestion"
            suggestionItem(ul, item)

  remoteData = ($searchField, request, response) ->
    logAcToGa($searchField, request.term.toLowerCase())
    $.ajax
      url: $searchField.attr("data-autocomplete-url")
      data:
        q: request.term.toLowerCase()
      dataType: "jsonp"
      success: (data) ->
        if data.length
          response $.map data, (item) ->
            $.extend item, { value: item.name or item.suggestion }
        else
          $searchField.autocomplete("close")

  recommendationItem = (ul, item, imagesUrl) ->
    $img = $("<img>").attr("src", imagesUrl + item.images.mini)
    $("<li>")
      .addClass('recommendation')
      .append($("<a><p>#{item.name}</p></a>").prepend($img))
      .appendTo ul

  suggestionItem = (ul, item) ->
    $("<li>")
      .addClass('suggestion')
      .append("<a><span class='hits'>#{item.nHits}</span>#{item.suggestionHighlighted}</a>")
      .appendTo ul

  fullSearchItem = ($widget, term) ->
    $("<li class='more-search-results ui-menu-item' role='presentation'><a class='ui-corner-all'>Visa alla sökresultat</a></li>")
      .data("ui-autocomplete-item", { value: term })
      .appendTo $widget

  recommendationHeader = ($widget) ->
    $("<li class='ui-autocomplete-category'>Gå direkt till:</li>")
      .insertBefore $widget.find(".recommendation:first")

  suggestionHeader = ($widget) ->
    $("<li class='ui-autocomplete-category'>Sök på:</li>")
      .insertBefore $widget.find(".suggestion:first")

  logToGaAndGo = (item, requestTerm) ->
    GALabel = requestTerm
    GAValue = "#{item.value} #{item.link}"

    # Track all clicks on recommendations and suggestions (type)
    _gaq.push(['_trackEvent', "#{item.caller}AutoComplete#{item.type}Click", GALabel, GAValue])

    setTimeout("document.location = '#{item.link}'", 200)

  logAcToGa = ($searchField, chars) ->
    # Track the chars that the user entered
    _gaq.push(['_trackEvent', "#{$searchField.attr("data-caller")}AutoComplete", "EnteredCharacters", chars])
