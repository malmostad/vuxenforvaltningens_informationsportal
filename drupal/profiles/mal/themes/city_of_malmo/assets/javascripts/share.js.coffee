# Inject sharing icons in .m-share
jQuery ($) ->
  url =   encodeURIComponent document.location.href
  title = encodeURIComponent $("title").text()
  $('.m-share').append("<a class='m-icon-twitter' href='https://twitter.com/intent/tweet?text=#{title}&url=#{url}' title='Twittra om sidan'></a>")
    .append("<a class='m-icon-facebook' href='https://www.facebook.com/sharer/sharer.php?u=#{url}' title='Dela sidan på Facebook'></a>")
    .append("<a class='m-icon-googleplus' href='https://plus.google.com/share?url=#{url}' title='Dela sidan på Google+'></a>")
