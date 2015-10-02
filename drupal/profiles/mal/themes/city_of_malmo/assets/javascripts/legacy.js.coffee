jQuery ($) ->
  # For missing placeholder support (IE9)
  unless 'placeholder' of document.createElement('input')
    setPlaceholder = (self) ->
      if $(self).val() is '' or $(self).val() is $(self).attr('placeholder')
        $(self).addClass('placeholder')
        $(self).val($(self).attr('placeholder'))

    # Bind events
    $('.mf-v4 input[placeholder]').focus ->
      if $(@).val() is $(@).attr('placeholder')
        $(@).val('')
        $(@).removeClass('placeholder')
    .blur ->
      setPlaceholder(this)

    # Set on load
    $('input[placeholder]').each ->
      setPlaceholder(@)

    # Clear before submit
    $('input[placeholder]').parents('form').submit ->
      $(@).find('input[placeholder]').each ->
        if $(@).val() is $(@).attr('placeholder')
          $(@).val('')
