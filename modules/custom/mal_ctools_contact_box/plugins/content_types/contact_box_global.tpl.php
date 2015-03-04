<?php

/**
 * @file
 * Template for global contact box.
 *
 * @see contact_box_global_render()
 */
?>
<aside class="contact-us-global">
  <h1><?php print $title ?></h1>

  <div class="vcard">
    <h2><?php print $subtitle ?></h2>
    <div><?php print $email_title; ?> <span class="email"><?php print $email; ?></span></div>
    <div><?php print $phone_title; ?> <span class="tel"><?php print $phone; ?></span></div>

    <h3><?php print $mailing_address_title; ?></h3>
    <div class="adr">
      <div class="fn"><?php print $address; ?></div>
      <div class="post-address"><?php print $mailing_address; ?></div>
    </div>

    <h3 class="visiting-address v-0"><?php print $street_address_title; ?></h3>
    <div class="street-address"><?php print $street_address; ?></div>
    <div><a class="show-on-map m-icon-location" data-map-selector=".contact-us-map.m-0" data-scroll-to=".visiting-address.v-0" data-poi="<?php print $maps_link; ?>" title="<?php print $maps_link; ?>"><?php print $maps_link_title; ?></a></div>
    <div class="contact-us-map m-0"></div>
  </div>
</aside>
