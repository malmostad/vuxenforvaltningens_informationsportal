; mal make file for d.o. usage
core = "7.x"
api = "2"

; +++++ Core +++++
projects[drupal][type] = core
projects[drupal][version] = 7.34

; +++++ Patches +++++
projects[panels][patch][] = "https://www.drupal.org/files/issues/panels-add-render-last-for-minipanel-1669918-14.patch"

projects[facetapi][patch][] = "https://www.drupal.org/files/issues/facetapi-override_facet_label-1665164-22.patch"

projects[timefield][patch][] = "https://www.drupal.org/files/issues/timefield-customize-template-2145341-1.patch"
projects[timefield][patch][] = "https://www.drupal.org/files/issues/timefield-change-weekly-summary-days-2379749-3.patch"
projects[timefield][patch][] = "https://www.drupal.org/files/issues/timefield-isset-2132811-5.patch"

projects[cer][patch][] = "https://www.drupal.org/files/issues/cer-entity_save.patch"

;projects[panels][patch][] = "https://www.drupal.org/files/issues/reroll-2120849-42.patch"

projects[auto_nodetitle][patch][] = "https://www.drupal.org/files/issues/auto_nodetitle-881170-50.patch"

; +++++ Modules +++++

projects[menu_import][version] = "1.6"
projects[menu_import][subdir] = "contrib"

projects[coffee][version] = "2.2"
projects[coffee][subdir] = "contrib"

projects[module_filter][version] = "2.0-alpha2"
projects[module_filter][subdir] = "contrib"

projects[ctools][version] = "1.6"
projects[ctools][subdir] = "contrib"

projects[date][version] = "2.8"
projects[date][subdir] = "contrib"

projects[devel][version] = "1.5"
projects[devel][subdir] = "contrib"

projects[profiler_builder][version] = "1.2"
projects[profiler_builder][subdir] = "contrib"

projects[features][version] = "2.3"
projects[features][subdir] = "contrib"

projects[field_collection][version] = "1.0-beta8"
projects[field_collection][subdir] = "contrib"

projects[field_collection_table][version] = "1.0-beta1"
projects[field_collection_table][subdir] = "contrib"

projects[field_group][version] = "1.4"
projects[field_group][subdir] = "contrib"

projects[field_permissions][version] = "1.0-beta2"
projects[field_permissions][subdir] = "contrib"

projects[entityreference][version] = "1.1"
projects[entityreference][subdir] = "contrib"

projects[link][version] = "1.3"
projects[link][subdir] = "contrib"

projects[live_person][version] = "1.x-dev"
projects[live_person][subdir] = "contrib"

projects[inline_entity_display][version] = "1.0-beta3"
projects[inline_entity_display][subdir] = "contrib"

projects[timefield][subdir] = "contrib"
projects[timefield][download][type] = "git"
projects[timefield][download][url] = "http://git.drupal.org/project/timefield.git"
projects[timefield][download][revision] = "d0a518eb41c5d506c4b743d3805a9839978ccf0b"


projects[diff][version] = "3.2"
projects[diff][subdir] = "contrib"

projects[entity][version] = "1.6"
projects[entity][subdir] = "contrib"

projects[entity_view_mode][version] = "1.0-rc1"
projects[entity_view_mode][subdir] = "contrib"

projects[libraries][version] = "2.2"
projects[libraries][subdir] = "contrib"

projects[strongarm][version] = "2.0"
projects[strongarm][subdir] = "contrib"

projects[ultimate_cron][version] = "2.0-beta8"
projects[ultimate_cron][subdir] = "contrib"

projects[panels][subdir] = "contrib"
projects[panels][download][type] = "git"
projects[panels][download][url] = "http://git.drupal.org/project/panels.git"
projects[panels][download][revision] = "f7ed1af2a50c0eef9f0be0420a6bdad85811ab92"

projects[panels_everywhere][version] = "1.0-rc2"
projects[panels_everywhere][subdir] = "contrib"

projects[pps][version] = "1.0"
projects[pps][subdir] = "contrib"

projects[registration][version] = "1.3"
projects[registration][subdir] = "contrib"

projects[search_api][version] = "1.14"
projects[search_api][subdir] = "contrib"

projects[search_api_autocomplete][version] = "1.x-dev"
projects[search_api_autocomplete][subdir] = "contrib"

projects[search_api_solr][version] = "1.6"
projects[search_api_solr][subdir] = "contrib"

projects[search_api_sorts][version] = "1.x-dev"
projects[search_api_sorts][subdir] = "contrib"

projects[facetapi][version] = "1.5"
projects[facetapi][subdir] = "contrib"

projects[facetapi_bonus][version] = "1.1"
projects[facetapi_bonus][subdir] = "contrib"

projects[jquery_update][version] = "2.5"
projects[jquery_update][subdir] = "contrib"

projects[wysiwyg][version] = "2.2"
projects[wysiwyg][subdir] = "contrib"

projects[views][version] = "3.10"
projects[views][subdir] = "contrib"

projects[publishcontent][version] = "1.3"
projects[publishcontent][subdir] = "contrib"

projects[view_unpublished][version] = "1.2"
projects[view_unpublished][subdir] = "contrib"

projects[admin_views][version] = "1.3"
projects[admin_views][subdir] = "contrib"

projects[views_bulk_operations][version] = "3.2"
projects[views_bulk_operations][subdir] = "contrib"

projects[language_cookie][version] = "1.8"
projects[language_cookie][subdir] = "contrib"

projects[rules][version] = "2.8"
projects[rules][subdir] = "contrib"

projects[l10n_update][version] = "1.1"
projects[l10n_update][subdir] = "contrib"

projects[custom_breadcrumbs][version] = "2.0-beta1"
projects[custom_breadcrumbs][subdir] = "contrib"

projects[custom_breadcrumbs_features][version] = "2.0-rc1"
projects[custom_breadcrumbs_features][subdir] = "contrib"

projects[token][version] = "1.5"
projects[token][subdir] = "contrib"

projects[auto_nodetitle][version] = "1.0"
projects[auto_nodetitle][subdir] = "contrib"

projects[varnish][version] = "1.0-beta3"
projects[varnish][subdir] = "contrib"

projects[memcache][version] = "1.5"
projects[memcache][subdir] = "contrib"

projects[advagg][version] = "2.7"
projects[advagg][subdir] = "contrib"

projects[entitycache][version] = "1.2"
projects[entitycache][subdir] = "contrib"

projects[i18n][version] = "1.12"
projects[i18n][subdir] = "contrib"

projects[variable][version] = "2.5"
projects[variable][subdir] = "contrib"

projects[navbar][version] = "1.5"
projects[navbar][subdir] = "contrib"

projects[hide_formats][version] = "1.1"
projects[hide_formats][subdir] = "contrib"

projects[override_node_options][version] = "1.13"
projects[override_node_options][subdir] = "contrib"

projects[node_edit_protection][version] = "1.1"
projects[node_edit_protection][subdir] = "contrib"

projects[chosen][version] = "2.0-beta4"
projects[chosen][subdir] = "contrib"

projects[publish_button][version] = "1.1"
projects[publish_button][subdir] = "contrib"

projects[better_formats][version] = "1.0-beta1"
projects[better_formats][subdir] = "contrib"

projects[media][version] = "2.0-alpha4"
projects[media][subdir] = "contrib"

projects[file_entity][version] = "2.0-beta1"
projects[file_entity][subdir] = "contrib"

projects[administerusersbyrole][version] = "2.0-beta1"
projects[administerusersbyrole][subdir] = "contrib"

projects[role_delegation][version] = "1.1"
projects[role_delegation][subdir] = "contrib"


projects[draggableviews][version] = "2.x-dev"
projects[draggableviews][subdir] = "contrib"

projects[transliteration][version] = "3.2"
projects[transliteration][subdir] = "contrib"

projects[redirect][version] = "1.0-rc1"
projects[redirect][subdir] = "contrib"

projects[globalredirect][version] = "1.5"
projects[globalredirect][subdir] = "contrib"

projects[metatag][version] = "1.4"
projects[metatag][subdir] = "contrib"

projects[pathauto][version] = "1.2"
projects[pathauto][subdir] = "contrib"

projects[cer][version] = "3.x-dev"
projects[cer][subdir] = "contrib"

projects[elements][version] = "1.4"
projects[elements][subdir] = "contrib"

; +++++ Themes +++++

; bootstrap
projects[bootstrap][type] = "theme"
projects[bootstrap][version] = "3.x-dev"
projects[bootstrap][subdir] = "contrib"

projects[ember][type] = "theme"
projects[ember][version] = "2.0-alpha2"
projects[ember][subdir] = "contrib"

projects[shiny][type] = "theme"
projects[shiny][version] = "1.6"
projects[shiny][subdir] = "contrib"

; +++++ Libraries +++++

; Library jquery.timepicker
; ---------------------------------------
libraries[jquery.timepicker][directory_name] = "jquery.timepicker"
libraries[jquery.timepicker][type] = "library"
libraries[jquery.timepicker][destination] = "libraries"
libraries[jquery.timepicker][download][type] = "get"
libraries[jquery.timepicker][download][url] = "https://fgelinas.com/code/timepicker/releases/jquery-ui-timepicker-0.3.3.zip"

; Library: backbone
; ---------------------------------------
libraries[backbone][destination] = "libraries"
libraries[backbone][download][type] = "get"
libraries[backbone][download][url] = "https://github.com/jashkenas/backbone/archive/1.0.0.zip"
libraries[backbone][directory] = "backbone"

; Library: underscore
; ---------------------------------------
libraries[underscore][destination] = "libraries"
libraries[underscore][download][type] = "get"
libraries[underscore][download][url] = "https://github.com/jashkenas/underscore/archive/1.5.0.zip"
libraries[underscore][directory] = "underscore"

; Library: chosen
; ---------------------------------------
libraries[chosen][destination] = "libraries"
libraries[chosen][download][type] = "get"
libraries[chosen][download][url] = "https://github.com/harvesthq/chosen/releases/download/1.0.0/chosen_v1.0.0.zip"
libraries[chosen][directory] = "chosen"

; Library: modernizr
; ---------------------------------------
libraries[modernizr][destination] = "libraries"
libraries[modernizr][download][type] = git
libraries[modernizr][download][url] = https://github.com/BrianGilbert/modernizer-navbar.git
libraries[modernizr][download][revision] = 5b89d9225320e88588f1cdc43b8b1e373fa4c60f
libraries[modernizr][directory] = "modernizr"
