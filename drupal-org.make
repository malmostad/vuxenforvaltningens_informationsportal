; mal make file for d.o. usage
core = "7.x"
api = "2"

; +++++ Core +++++
projects[drupal][type] = core
projects[drupal][version] = 7.32

; +++++ Patches +++++
projects[panels][patch][] = "https://www.drupal.org/files/issues/panels-add-render-last-for-minipanel-1669918-14.patch"

projects[facetapi][patch][] = "https://www.drupal.org/files/issues/facetapi-override_facet_label-1665164-22.patch"

projects[facetapi_ranges][patch][] = "https://www.drupal.org/files/issues/term-query-type-2295751-10.patch"

projects[timefield][patch][] = "https://www.drupal.org/files/issues/timefield-customize-template-2145341-1.patch"
projects[timefield][patch][] = "https://www.drupal.org/files/issues/timefield-isset-2132811-5.patch"

; +++++ Modules +++++

projects[admin_menu][version] = "3.0-rc4"
projects[admin_menu][subdir] = "contrib"

projects[menu_import][version] = "1.6"
projects[menu_import][subdir] = "contrib"

projects[coffee][version] = "2.2"
projects[coffee][subdir] = "contrib"

projects[module_filter][version] = "2.0-alpha2"
projects[module_filter][subdir] = "contrib"

projects[ctools][version] = "1.4"
projects[ctools][subdir] = "contrib"

projects[date][version] = "2.8"
projects[date][subdir] = "contrib"

projects[devel][version] = "1.5"
projects[devel][subdir] = "contrib"

projects[profiler_builder][version] = "1.2"
projects[profiler_builder][subdir] = "contrib"

projects[features][version] = "2.2"
projects[features][subdir] = "contrib"

projects[field_collection][version] = "1.0-beta7"
projects[field_collection][subdir] = "contrib"

projects[field_collection_table][version] = "1.0-beta1"
projects[field_collection_table][subdir] = "contrib"

projects[field_group][version] = "1.4"
projects[field_group][subdir] = "contrib"

projects[entityreference][version] = "1.1"
projects[entityreference][subdir] = "contrib"

projects[link][version] = "1.3"
projects[link][subdir] = "contrib"

projects[inline_entity_display][version] = "1.0-beta3"
projects[inline_entity_display][subdir] = "contrib"

projects[timefield][subdir] = "contrib"
projects[timefield][download][type] = "git"
projects[timefield][download][url] = "http://git.drupal.org/project/timefield.git"
projects[timefield][download][revision] = "d0a518eb41c5d506c4b743d3805a9839978ccf0b"


projects[diff][version] = "3.2"
projects[diff][subdir] = "contrib"

projects[entity][version] = "1.5"
projects[entity][subdir] = "contrib"

projects[entity_view_mode][version] = "1.0-rc1"
projects[entity_view_mode][subdir] = "contrib"

projects[libraries][version] = "2.2"
projects[libraries][subdir] = "contrib"

projects[strongarm][version] = "2.0"
projects[strongarm][subdir] = "contrib"

projects[ultimate_cron][version] = "2.0-beta7"
projects[ultimate_cron][subdir] = "contrib"

projects[panels][version] = "3.4"
projects[panels][subdir] = "contrib"

projects[panels_everywhere][version] = "1.0-rc1"
projects[panels_everywhere][subdir] = "contrib"

projects[pps][version] = "1.0"
projects[pps][subdir] = "contrib"

projects[registration][version] = "1.3"
projects[registration][subdir] = "contrib"

projects[search_api][version] = "1.13"
projects[search_api][subdir] = "contrib"

projects[search_api_solr][version] = "1.6"
projects[search_api_solr][subdir] = "contrib"

projects[search_api_sorts][version] = "1.x-dev"
projects[search_api_sorts][subdir] = "contrib"

projects[facetapi][version] = "1.5"
projects[facetapi][subdir] = "contrib"

projects[facetapi_ranges][version] = "1.x-dev"
projects[facetapi_ranges][subdir] = "contrib"

projects[facetapi_bonus][version] = "1.1"
projects[facetapi_bonus][subdir] = "contrib"

projects[jquery_update][version] = "2.4"
projects[jquery_update][subdir] = "contrib"

projects[wysiwyg][version] = "2.2"
projects[wysiwyg][subdir] = "contrib"

projects[views][version] = "3.8"
projects[views][subdir] = "contrib"

; +++++ Themes +++++

; bootstrap
projects[bootstrap][type] = "theme"
projects[bootstrap][version] = "3.0"
projects[bootstrap][subdir] = "contrib"

; +++++ Libraries +++++

; jquery.timepicker
libraries[jquery.timepicker][directory_name] = "jquery.timepicker"
libraries[jquery.timepicker][type] = "library"
libraries[jquery.timepicker][destination] = "libraries"
libraries[jquery.timepicker][download][type] = "get"
libraries[jquery.timepicker][download][url] = "https://fgelinas.com/code/timepicker/releases/jquery-ui-timepicker-0.3.3.zip"
