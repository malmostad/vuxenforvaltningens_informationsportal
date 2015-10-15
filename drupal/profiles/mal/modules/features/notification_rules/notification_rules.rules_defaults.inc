<?php
/**
 * @file
 * notification_rules.rules_defaults.inc
 */

/**
 * Implements hook_default_rules_configuration().
 */
function notification_rules_default_rules_configuration() {
  $items = array();
  $items['rules_notification_on_new_template_content'] = entity_import('rules_config', '{ "rules_notification_on_new_template_content" : {
      "LABEL" : "Notification on new template content",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "TAGS" : [ "Mail notifications" ],
      "REQUIRES" : [ "rules" ],
      "ON" : { "node_insert--course_template" : { "bundle" : "course_template" } },
      "DO" : [
        { "mail_to_users_of_role" : {
            "roles" : { "value" : { "3" : "3" } },
            "subject" : "New [node:type-name] templates was created",
            "message" : "New [node:type-name] content is available:\\r\\n\\r\\n[node:title] (Url: [node:url])\\r\\n\\r\\n"
          }
        }
      ]
    }
  }');
  $items['rules_notification_on_unpublish_courses'] = entity_import('rules_config', '{ "rules_notification_on_unpublish_courses" : {
      "LABEL" : "Notification on unpublish courses",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules", "mal_rules_send_email_action" ],
      "ON" : {
        "node_update--course" : { "bundle" : "course" },
        "node_update--course_packages" : { "bundle" : "course_packages" }
      },
      "IF" : [
        { "NOT node_is_published" : { "node" : [ "node" ] } },
        { "AND" : [
            { "data_is" : { "data" : [ "node:field-dont-send-mail" ], "value" : "0" } }
          ]
        }
      ],
      "DO" : [
        { "mal_rules_send_email_action" : {
            "node" : [ "node" ],
            "subject" : "The [node:content-type] [node:title] became an unpublished.",
            "message" : "Link: [node:url]"
          }
        },
        { "data_set" : { "data" : [ "node:field-dont-send-mail" ], "value" : "1" } }
      ]
    }
  }');
  $items['rules_uncheck_dont_send_mail_checkbox_when_course_is_published'] = entity_import('rules_config', '{ "rules_uncheck_dont_send_mail_checkbox_when_course_is_published" : {
      "LABEL" : "Uncheck Don\\u0027t send mail checkbox when course is published",
      "PLUGIN" : "reaction rule",
      "OWNER" : "rules",
      "REQUIRES" : [ "rules" ],
      "ON" : {
        "node_update--course" : { "bundle" : "course" },
        "node_update--course_packages" : { "bundle" : "course_packages" }
      },
      "IF" : [ { "node_is_published" : { "node" : [ "node" ] } } ],
      "DO" : [
        { "data_set" : { "data" : [ "node:field-dont-send-mail" ], "value" : "0" } }
      ]
    }
  }');
  return $items;
}
