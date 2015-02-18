<?php

/**
 * @file
 * Template for global contact box.
 *
 * @see contact_box_global_render()
 */
?>
<aside class="contact-us-global">
  <h2><?php print $title ?></h2>

  <div class="vcard">
    <span><?php print $subtitle ?></span>
    <div><h3><?php print $street_address_title; ?></h3><span class="adr"><?php print $street_address; ?></span></div>
    <div><a class="show-on-map m-icon-location" data-map-selector=".contact-us-map.m-0" data-scroll-to=".visiting-address.v-0" data-poi="<?php print $maps_link; ?>" title="<?php print $maps_link; ?>"><?php print $maps_link_title; ?></a></div>
    <div><h3><?php print $write_to_us_title; ?></h3><span class="tel"><?php print $write_to_us; ?></span></div>
    <div class="adr"><h3><?php print $address_title; ?></h3><span class="fax"><?php print $address; ?></span></div>
    <div class="contact-us-map m-0"></div>
  </div>
</aside>
