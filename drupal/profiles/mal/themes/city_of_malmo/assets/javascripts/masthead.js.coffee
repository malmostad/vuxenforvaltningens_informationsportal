jQuery ($) ->
  # Inject the masthead from the stringified html code
  $(malmoMasthead).prependTo('body')

  # Set navigation height to force vertical scroll
  setNavHeight = ->
    $("#main-nav ul").css("max-height", " #{$(window).height() - 41}px")
  $(window).on 'resize load', ->
    setNavHeight();
  $("#main-nav button").click ->
    hideSearch()

  # Register main nav as a Bootstrap dropdown
  $('#main-nav [data-toggle=dropdown]').dropdown()

  $mastheadSearch = $("#masthead-search")

  hideSearch = ->
    $mastheadSearch.removeClass("boxed").find("input").blur()

  showSearch = ->
    $mastheadSearch.addClass("boxed").find("input.q").focus()

    # Close on click outside the searchbox
    $('body > *').not('#malmo-masthead').one 'click', (event) ->
      hideSearch()

    if $("body.touch").length
      times = 0
      i = setInterval ->
        window.scrollTo(0, $mastheadSearch.offset().top)
        if times++ > 100
          clearInterval(i)
      , 5

  $("#search-trigger").click (event) ->
    if $mastheadSearch.is(":hidden") then showSearch() else hideSearch()

  # Hide on escape
  $(document).on 'keyup', (event) ->
    if event.which is 27
      hideSearch()


  $mastheadSearch.find(".q").focus ->
    if $("body.touch").length and not $mastheadSearch.hasClass("boxed")
      $malmoMasthead = $("#malmo-masthead")
      times = 0
      i = setInterval ->
        window.scrollTo(0, $malmoMasthead.offset().top)
        if times++ > 100
          clearInterval(i)
      , 5
