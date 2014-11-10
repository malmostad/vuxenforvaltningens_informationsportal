<?php

/**
 * @file
 * Template for contact box.
 *
 * @see contact_box_render()
 */
?>
<aside class="contact-us basic">
  <h1><?php print t('Contact us'); ?></h1>

  <div class="vcard">
    <div><?php print t('Write to us'); ?></div>
    <div><?php print $email_title; ?><span class="email"><?php print render($email); ?></span></div>
    <div><?php print $phone_title; ?><span class="tel"><?php print render($phone); ?></span></div>
    <div><?php print $fax_title; ?><span class="fax"><?php print render($fax); ?></span></div>

    <h3><?php print t('Post address'); ?></h3>
    <div class="adr">
      <div class="fn"><?php print render($address); ?></div>
      <div class="post-office-box"><?php print render($post_office); ?></div>
      <div><span class="postal-code"><?php print render($postal_code); ?></span> <span class="locality"><?php print render($locality); ?></span></div>
    </div>

    <h3 class="visiting-address v-0"><?php print t('Visiting Address'); ?></h3>
    <div class="street-address"><?php print render($street_address); ?></div>
    <div><a href="http://www.malmo.se/karta?poi=Föreningsgatan+7A&amp;zoomlevel=4&amp;maptype=karta" class="show-on-map m-icon-location" data-map-selector=".contact-us-map.m-0" data-scroll-to=".visiting-address.v-0" data-poi="Föreningsgatan 7A" title="Föreningsgatan 7A"><?php print t('Write to us'); ?></a></div>
    <div class="contact-us-map m-0"></div>
  </div>
</aside>