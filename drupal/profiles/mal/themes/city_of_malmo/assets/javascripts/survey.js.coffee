jQuery ($) ->
  #
  # This bastard creates a survey form and push the answers and some other data into Google Analytics
  # Selection creterias are based on
  #   - Slack time since the user answered before
  #   - Slack time since the user answered Not thanks
  #   - Slack time during session since the user answered snooze
  #   - Time since the sessions started
  #   - User selection by frequenzy if all the above is satisfied
  #

  # Define runSurvey as a global variable and set it to true to run the survey
  if typeof runSurvey isnt "undefined" and runSurvey
    userTracking = sessionTracking = null

    # Selection criteria from user selection for the survey
    # Based on what the user did with the survey in the past and the slection frequenzy

    # Configurable time intervals in msec
    slack =
      afterSessionInit: 30 * 1000
      snooze: 60 * 1000
      answered: 60 * 24 * 60 * 60 * 1000
      notNow: 60 * 24 * 60 * 60 * 1000
    selectUserFrequency = 1 / 10

    # Open survey in modal lightbox and take care of user events
    initSurvey = ->
      surveyName = 'Survey malmo.se'

      # Switch between pages in the survey
      showSlide = (slide) ->
        $survey.find("section").hide()
        $survey.find("section.page-" + slide).show().find("select, button").first().focus()

      # Show form validation errors to user
      validationAlert = (field) ->
        $("#" + field).closest(".form-group").addClass "warning"
        $survey.find(".page-2 p").addClass "warning"

      # Push answers to Google Analytics
      pushToGA = (values) ->
        $.each values, ->
          _gaq.push [
            '_trackEvent'
            # GA "Event Category"
            surveyName
            # GA "Event Action"
            @.name
            # GA "Event label"
            @.value
            # GA "Event Value", if integer
            (if parseInt(@value, 10) is @value then parseInt(@value, 10) else 0)
          ]
          return
        return

      # Collect data from survey form
      collectFormData = (formValues) ->
        answered_before = if userTracking.answered then "No" else $.fn.datepicker.DPGlobal.formatDate(new Date(userTracking.answered), "yyyy-mm-dd", "en")

        # Add aditional data
        formValues.push
          name: "answered_before"
          value: answered_before
        formValues.push
          name: "answered_date"
          value: $.fn.datepicker.DPGlobal.formatDate(new Date(), "yyyy-mm-dd", "en")

        pushToGA(formValues)
        # Update cookies
        writePersistentCookie "answered", msecNow()
        writeSessionCookie "selected", false
        showSlide 3
        return

      # Attach survey markup
      $survey = $(markup)
      $('body > div.wrapper').first().prepend $survey

      # User want to take the survey
      $("#survey-action-ok").on 'click', (event) ->
        showSlide 2

      $('#survey-form').on 'submit', (event) ->
        event.preventDefault()

      # User submits the survey
      $('#survey-action-send').on 'click', (event) ->
        # Validate form
        $("#survey .warning").removeClass("warning")
        validates = true
        formValues = $("#survey-form").serializeArray()
        $.each formValues, () ->
          if not @.value
            validationAlert @.name
            validates = false
            return
        if validates
          collectFormData formValues

      # User do not want to take the survey now
      $("#survey-action-no").on 'click', (event) ->
        writePersistentCookie "not_now", msecNow()
        writeSessionCookie "selected", false
        $survey.remove()

      # User do not want to take the survey right now, she will be reminded during the session
      $("#survey-action-snooze").on 'click', (event) ->
        writeSessionCookie "snooze", msecNow()
        $survey.remove()

      # Close the dialog after the Thank you page
      $("#survey-action-done").on 'click', (event) ->
        $survey.remove()

    # Read persisten and session cookies that keep track of the survey
    # Get the persistent cookie where the user roles is stored
    readCookies = ->
      # Get survey user tracking
      userTracking = if $.cookie('survey_external') then JSON.parse($.cookie('survey_external')) else {}
      sessionTracking = if $.cookie('survey_external_session') then JSON.parse($.cookie('survey_external_session')) else {}

      # Get user roles
      profile = if $.cookie('myprofile') then JSON.parse($.cookie('myprofile')) else {}
      userTracking.department = profile.department or "Ej valt"
      userTracking.workingfield = profile.workingfield or "Ej valt"

    # Update a key/value pair and keep the rest of the sessionTracking for the survey
    writeSessionCookie = (key, value) ->
      sessionTracking[key] = value
      $.cookie 'survey_external_session', JSON.stringify(sessionTracking), { path: '/', domain: 'malmo.se' }

    # Update a key/value pair and keep the rest of the userTracking for the survey
    writePersistentCookie = (key, value) ->
      userTracking[key] = value
      $.cookie 'survey_external', JSON.stringify(userTracking), { expires: 365*5, path: '/', domain: 'malmo.se' }

    # IE 7 dosen't support Date.now()
    msecNow = ->
      d = new Date()
      d.getTime()

    # User is already selected during the session for the survey
    alreadySelected = ->
      sessionTracking.selected

    # Has the user answered the survey less than slack.answered ago?
    answeredRecently = ->
      !!userTracking.answered and msecNow() < userTracking.answered + slack.answered

    # Has the user answered "Not now" less than slack.notNow ago?
    saidNoRecently = ->
      !!userTracking.not_now and msecNow() < userTracking.not_now + slack.notNow

    # Has the user answered snooze @ session less than slack.snooze ago?
    snoozedRecently = ->
      !!sessionTracking.snooze and msecNow() < sessionTracking.snooze + slack.snooze

    # Is the session established more than slack.afterSessionInit ago
    sessionOldEnough = ->
      msecNow() > sessionTracking.created + slack.afterSessionInit

    # Randomly select user by selectByFrequency
    selectByFrequency = ->
      Math.random() <= selectUserFrequency

    # Qualify the user for a survey using the functions above
    # @ will only happen at the start of the sessiob
    qualifyUserForSurvey = ->
      if not answeredRecently() and not saidNoRecently() and selectByFrequency()
        writeSessionCookie "selected", true
        writeSessionCookie "created", msecNow()
      else
        writeSessionCookie "selected", false

    # Get the users survey history data and her roles
    readCookies()
    # Should we show the survey or not?

    debugMode = typeof debugSurvey isnt 'undefined' and debugSurvey

    markup = '<section id="survey" class="box">
      <h1 class="box-title">Vi behöver din åsikt!</h1>
      <form id="survey-form" action="/" method="get">
        <section class="page-1 box-content">
          <p>För att vi ska kunna göra malmo.se bättre behöver vi din åsikt. Det enda du behöver göra är att svara på två frågor. Det tar mindre än 15 sekunder.</p>
          <div class="actions">
            <button type="button" class="btn btn-default" id="survey-action-ok">Ja gärna!</button>
            <button type="button" class="btn btn-default" id="survey-action-no">Nej, inte idag</button>
          </div>
        </section>

        <section class="page-2 box-content">
          <p>Välj ett alternativ för varje fråga.</p>

          <div class="form-group">
            <label for="roll" class="control-label">I vilken roll besöker du malmo.se idag? </label>
            <div class="controls">
              <select id="roll" name="roll" class="form-control">
                <option></option>
                <option value="enkat-bo-malmo">Bor i Malmö</option>
                <option value="enkat-bo-skane">Bor i annan skånsk kommun</option>
                <option value="enkat-flytta">Funderar på att flytta till Malmö</option>
                <option value="enkat-arbetar-malmo">Arbetar i Malmö</option>
                <option value="enkat-anstalld">Anställd av Malmö stad</option>
                <option value="enkat-offentlig">Arbetar i offentlig förvaltning</option>
                <option value="enkat-journalist">Journalist</option>
                <option value="enkat-turist">Turist/besökare</option>
                <option value="enkat-studerar">Studerar</option>
                <option value="enkat-företagare">Företagare/näringsidkare</option>
                <option value="enkat-jobbsokande">Jobbsökande</option>
                <option value="enkat-annan-roll">Annat</option>
              </select>
            </div>
          </div>

          <div class="form-group">
            <label for="syfte" class="control-label">Vad vill du göra på malmo.se just detta besök?</label>
            <div class="controls">
              <select id="syfte" name="syfte" class="form-control">
                <option></option>
                <option value="enkat-tjanst">Använda en tjänst, t.ex.</option>
                <option value="enkat-kontakt">Hitta kontaktuppgifter</option>
                <option value="enkat-jobb">Hitta lediga jobb</option>
                <option value="enkat-verksamhet">Läsa information om viss verksamhet</option>
                <option value="enkat-nyheter">Läsa om nyheter och aktuella händelser</option>
                <option value="enkat-annat-syfte">Annat</option>
              </select>
            </div>
          </div>

          <div class="form-group">
            <label for="nojdhet" class="control-label">Hur nöjd är du med ditt besök på malmo.se idag?</label>
            <div class="controls">
              <select id="nojdhet" name="nojdhet" class="form-control">
                <option></option>
                <option value="5">5 – Mycket nöjd</option>
                <option value="4">4</option>
                <option value="3">3 – Varken nöjd eller missnöjd</option>
                <option value="2">2</option>
                <option value="1">1 – Mycket missnöjd</option>
              </select>
            </div>
          </div>

          <div class="actions">
            <button type="button" class="btn btn-primary" id="survey-action-send">Skicka in</button>
          </div>
        </section>

        <section class="page-3 box-content">
          <h1>Tack för dina svar!</h1>
          <p>Dina svar kommer att användas för att göra malmo.se bättre!</p>
          <div class="actions">
            <button type="button" class="btn btn-default" id="survey-action-done">Stäng</button>
          </div>
        </section>
      </form>
    </section>'

    # The user is already selected, is the session old enough and is the snooze, if any, time over?
    if debugMode || alreadySelected() and sessionOldEnough() and not snoozedRecently()
      initSurvey()

    # The session is new, check if the user should have the survey
    else if not sessionTracking.selected
      qualifyUserForSurvey()
