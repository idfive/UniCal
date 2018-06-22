<?php
/**
 * @file
 * unical_features.features.uuid_term.inc
 */

/**
 * Implements hook_uuid_features_default_terms().
 */
function unical_features_uuid_features_default_terms() {
  $terms = array();

  $terms[] = array(
    'name' => 'Yahoo (Online)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '7fe91c1c-23e8-4615-86ac-404e46e94bad',
    'vocabulary_machine_name' => 'calendar_taxonomy_7',
    'field_ate_id' => array(),
  );
  $terms[] = array(
    'name' => 'Apple iCal',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => '8c168096-2022-4ead-bba7-b032e40c4bc4',
    'vocabulary_machine_name' => 'calendar_taxonomy_7',
    'field_ate_id' => array(),
  );
  $terms[] = array(
    'name' => 'Google (Online)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'cdd2da18-269d-4dc4-83a6-27f838c5e2ec',
    'vocabulary_machine_name' => 'calendar_taxonomy_7',
    'field_ate_id' => array(),
  );
  $terms[] = array(
    'name' => 'Outlook',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'e950dbc7-ed11-47a9-9b09-78921e28af4b',
    'vocabulary_machine_name' => 'calendar_taxonomy_7',
    'field_ate_id' => array(),
  );
  $terms[] = array(
    'name' => 'Outlook (Online)',
    'description' => '',
    'format' => 'filtered_html',
    'weight' => 0,
    'uuid' => 'fd7daf94-f10e-424d-ad35-41b2f31128b8',
    'vocabulary_machine_name' => 'calendar_taxonomy_7',
    'field_ate_id' => array(),
  );
  return $terms;
}
