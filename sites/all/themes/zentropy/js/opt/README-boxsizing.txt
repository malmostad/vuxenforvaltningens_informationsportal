### Zentropy - The ultimate responsive HTML5 base theme ###

This file contains additional information for using the box-sizing polyfill.

-------
WARNING
-------

This is not, by any means, a comprehensive documentation or final guide. Just a couple tips to get you started! :)

For more additional information please check out the official project page: https://github.com/Schepp/box-sizing-polyfill


-----------
BASIC USAGE
-----------

1 - Basically, all you need to do is add an extra line to each CSS selector that you want to enable "box-sizing: border-box;".

2 - Since this polyfill targets IE6 and IE7 specifically, you should use the "star hack" to avoid having newer versions of IE load it:

   *behavior: url('/sites/all/themes/zentropy/js/opt/boxsizing.htc');

Example:

    .border-box {
      box-sizing: border-box;
      *behavior: url('/sites/all/themes/zentropy/js/opt/boxsizing.htc'); // notice the star hack and absolute path!
    }


---------------
TROUBLESHOOTING
---------------

1 - Make sure the path in the behavior is absolute and valid.

2 - Please make sure to check your server configuration and update it to use the correct content-type if needed.
    You can do this in a .htaccess file:

    AddType text/x-component .htc