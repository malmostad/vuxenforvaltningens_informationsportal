jQuery ($) ->
  # Fix the footer to the viewport bottom if content doesn't push it down
  positionFooter = () ->
    $malmoFooter = $("#malmo-footer")
    if $("body").height() + $malmoFooter.outerHeight() <= $(window).height()
      $malmoFooter.addClass "fix"
    else
      $malmoFooter.removeClass "fix"

  if not $("body").hasClass "no-footer"
    # Inject the footer from the js stringified variable malmoFooter
    $(malmoFooter).appendTo('body')
    positionFooter()
    $(window).resize ->
      clearTimeout(fixit)
      fixit = setTimeout(positionFooter, 100);
