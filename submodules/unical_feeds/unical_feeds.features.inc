<?php
/**
 * @file
 * unical_feeds.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function unical_feeds_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
}
