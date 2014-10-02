### Zentropy - The ultimate responsive HTML5 base theme ###

This file contains additional information for using CSS3Pie with Zentropy.

-------
WARNING
-------

This is not, by any means, a comprehensive documentation or final guide. Just a couple tips to get you started! :)

For more additional information please check out the official documentation: http://css3pie.com/documentation/


-----------
BASIC USAGE
-----------

1 - Basically, all you need to do is add an extra line to each CSS selector that you want to enable PIE for:

    behavior: url(/sites/all/themes/zentropy/js/opt/PIE.htc);

2 - If you are targetting IE6 or IE7 specifically, you should use the "star hack" to avoid having newer versions of IE load it:

    *behavior: url(/sites/all/themes/zentropy/js/opt/PIE.htc);

Example:

    .rounded-corners {
      -moz-border-radius: 6px;
      -webkit-border-radius: 6px;
      border-radius: 6px;
      behavior: url(/sites/all/themes/zentropy/js/opt/PIE.htc); // notice the absolute path!
    }

3 - If you are having trouble with certain elements, adding "position: relative;" can help fix things! (but might break others!)


---------------
TROUBLESHOOTING
---------------

1 - Make sure the path in the behavior is absolute and valid.

2 - Please make sure to check your server configuration and update it to use the correct content-type if needed.
    You can do this in a .htaccess file:

    AddType text/x-component .htc