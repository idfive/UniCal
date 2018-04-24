<?php
/**
 * @file
 * unical_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function unical_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function unical_features_node_info() {
  $items = array(
    'event' => array(
      'name' => t('Event'),
      'base' => 'node_content',
      'description' => t('An event is the main node that interacts with the  Calendar API'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'site' => array(
      'name' => t('Site'),
      'base' => 'node_content',
      'description' => t('A site is a website that is allowed to interface with the Calendar API'),
      'has_title' => '1',
      'title_label' => t('Site Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function unical_features_default_search_api_index() {
  $items = array();
  $items['events_index'] = entity_import('search_api_index', '{
    "name" : "Events Index",
    "machine_name" : "events_index",
    "description" : "Index of UniCal Events.",
    "server" : "database_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "event" ] },
      "index_directly" : 1,
      "cron_limit" : "50",
      "fields" : {
        "body:value" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "title" : { "type" : "text" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function unical_features_default_search_api_server() {
  $items = array();
  $items['database_server'] = entity_import('search_api_server', '{
    "name" : "Database Server",
    "machine_name" : "database_server",
    "description" : "",
    "class" : "search_api_db_service",
    "options" : {
      "database" : "default:default",
      "min_chars" : "1",
      "partial_matches" : 1,
      "indexes" : { "events_index" : {
          "title" : {
            "table" : "search_api_db_events_index_text",
            "type" : "text",
            "boost" : "1.0"
          },
          "search_api_language" : {
            "table" : "search_api_db_events_index",
            "column" : "search_api_language",
            "type" : "string",
            "boost" : "1.0"
          },
          "body:value" : {
            "table" : "search_api_db_events_index_text",
            "type" : "text",
            "boost" : "1.0"
          }
        }
      }
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
