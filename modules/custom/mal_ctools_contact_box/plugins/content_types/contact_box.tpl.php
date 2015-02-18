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
    <h2><?php print $title ?></h2>
    <div><?php print $email_title; ?><span class="email"><?php print render($email); ?></span></div>
    <div><?php print $phone_title; ?><span class="tel"><?php print render($phone); ?></span></div>
    <div><?php print $fax_title; ?><span class="fax"><?php print render($fax); ?></span></div>

    <h3><?php print t('Post address'); ?></h3>
    <div class="adr">
      <div class="fn"><?php print render($address); ?></div>
      <div><span class="postal-code"><?php print render($postal_code); ?></span></div>
    </div>

    <h3 class="visiting-address v-0"><?php print t('Visiting Address'); ?></h3>
    <div class="street-address"><?php print render($street_address); ?></div>

    <div><a class="show-on-map m-icon-location" data-map-selector=".contact-us-map.m-0" data-scroll-to=".visiting-address.v-0" data-poi="<?php print $maps_link; ?>" title="<?php print $maps_link; ?>"><?php print t('Show on map'); ?></a></div>
    <div class="contact-us-map m-0"></div>
  </div>
</aside>
