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
      'description' => '',
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
