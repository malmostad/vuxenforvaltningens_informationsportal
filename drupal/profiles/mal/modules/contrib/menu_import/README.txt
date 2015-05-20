$Id

WHAT IS THIS MODULE FOR?

You may need it when you want to:

- export and/or import menu(s)

- create a menu, without specific details about where the menu links
  will point to. You may need this when you want to create a prototype of your future site,
  or when you haven't decided yet where each menu link will point to. The module will
  create the menu for you using optionally provided external URLs or local Drupal paths.
  See the import file structure for details.

- create a menu with some/all links pointing to stub content.
  You may need this when you want to create a prototype of your future site,
  and you haven't decided yet about the content but you need some tangible content
  to be available.

- update an existing menu by adding new items. You may add new items the same way as described
  in points 1 and 2 above.

- reorganize existing menu by means of a text file instead of manual dragging.

- create a site from scratch using exportables (features) and need a way to create menus

USAGE INSTRUCTIONS

IMPORT

1. Install the module and configure permissions to allow import.

2. Prepare a site map file

  Menu structure must follow this example:

    Page1
    - Page2
    - Page3
    Page4
    - Page5
    -- Page6

  or this

  Page1
  * Page2
  ** Page3
  Page4
  * Page5
  ** Page6
  *** Page7

  You may optionally specify path alias (alternative path)
  or external URL. You need to put it after node's title using JSON format:
  External URLs should ALWAYS start with "http://". Also, you can provide
  a description for menu item(s), language code ("en","it","fr" etc.), hidden/expanded attributes.
  Use examples from "tests" directory for better understanding of the syntax.

  Here is a quick sample:
    Page1 {"url": "node/1", "description": "This is an optional description"}
    - Page2 {"hidden":true}
    - Page3 {"description": "The line above and this one will point to <front>"}
    Page4 {"url": "http://domain.com/", "description": "Visit domain.com!", "expanded":true}
    - Page5 {"url": "http://mail.com/index.php"}
    -- Page6 {"url": "non/existent/path", "description": "will be replaced with <front>"}

  Space(s) between indentation symbol "*" or "-" and menu/node title are optional,
  however you cannot put spaces between indentation symbols like "* * *" or "-- - -".

3. Go to "Structure" -> "Menus"

4. Select "Menu import" tab.

5. Select the site map file created earlier and specify necessary options.
   You may want to create empty nodes on import here. If this is the case,
   you have to specify additional information. A handy feature could be creation
   stub nodes with path aliases instead of default node/x. Be sure to provide
  aliases and choose "Create path alias" option.

6. Submit and see the new menu structure with stub content created automatically.

EXPORT

1. Go to "Structure" -> "Menus"

2. Select "Menu export" tab.

3. Select the menu and your options.

4. Save the file (and probably use it later for import)
