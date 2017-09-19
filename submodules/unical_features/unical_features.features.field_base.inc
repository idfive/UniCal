<?php
/**
 * @file
 * unical_features.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function unical_features_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'body'.
  $field_bases['body'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(
      0 => 'node',
    ),
    'field_name' => 'body',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'date_repeat_entity_clone_state'.
  $field_bases['date_repeat_entity_clone_state'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'date_repeat_entity_clone_state',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 1,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'date_repeat_entity_master_uuid'.
  $field_bases['date_repeat_entity_master_uuid'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'date_repeat_entity_master_uuid',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 1,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_add_to_calendar_exclude'.
  $field_bases['field_add_to_calendar_exclude'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_add_to_calendar_exclude',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'calendar_taxonomy_7',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_address'.
  $field_bases['field_address'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_address',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'addressfield',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'addressfield',
  );

  // Exported field_base: 'field_allow_archive'.
  $field_bases['field_allow_archive'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_allow_archive',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_allow_event_submit'.
  $field_bases['field_allow_event_submit'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_allow_event_submit',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_allow_featured_events'.
  $field_bases['field_allow_featured_events'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_allow_featured_events',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_allow_users_to_choose_taxo'.
  $field_bases['field_allow_users_to_choose_taxo'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_allow_users_to_choose_taxo',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_ate_id'.
  $field_bases['field_ate_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ate_id',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 50,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_calendar_help_link'.
  $field_bases['field_calendar_help_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_calendar_help_link',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_contact_email'.
  $field_bases['field_contact_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_contact_email',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'email',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'email',
  );

  // Exported field_base: 'field_contact_name'.
  $field_bases['field_contact_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_contact_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_contact_phone'.
  $field_bases['field_contact_phone'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_contact_phone',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 50,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_contact_website'.
  $field_bases['field_contact_website'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_contact_website',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_cost'.
  $field_bases['field_cost'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cost',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_custom_text_above_filters'.
  $field_bases['field_custom_text_above_filters'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_custom_text_above_filters',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_custom_text_above_sidebar'.
  $field_bases['field_custom_text_above_sidebar'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_custom_text_above_sidebar',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_date'.
  $field_bases['field_date'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_date',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'granularity' => array(
        'day' => 'day',
        'hour' => 'hour',
        'minute' => 'minute',
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'repeat' => 1,
      'timezone_db' => '',
      'todate' => 'optional',
      'tz_handling' => 'none',
    ),
    'translatable' => 0,
    'type' => 'datetime',
  );

  // Exported field_base: 'field_default_event_image'.
  $field_bases['field_default_event_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_default_event_image',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_exclude_from_main_calendar'.
  $field_bases['field_exclude_from_main_calendar'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_exclude_from_main_calendar',
    'field_permissions' => array(
      'type' => 1,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_featured'.
  $field_bases['field_featured'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_featured',
    'field_permissions' => array(
      'type' => 2,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_free_event'.
  $field_bases['field_free_event'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_free_event',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 0,
        1 => 1,
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_google_maps_api_key'.
  $field_bases['field_google_maps_api_key'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_google_maps_api_key',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_how_to_rsvp'.
  $field_bases['field_how_to_rsvp'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_how_to_rsvp',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_image'.
  $field_bases['field_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_image',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_main_calendar_site'.
  $field_bases['field_main_calendar_site'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_main_calendar_site',
    'field_permissions' => array(
      'type' => 2,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_map_center_lat'.
  $field_bases['field_map_center_lat'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_map_center_lat',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_map_center_lng'.
  $field_bases['field_map_center_lng'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_map_center_lng',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_map_zoom'.
  $field_bases['field_map_zoom'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_map_zoom',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_number_results_per_page'.
  $field_bases['field_number_results_per_page'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_number_results_per_page',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  // Exported field_base: 'field_organizer_facebook'.
  $field_bases['field_organizer_facebook'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_organizer_facebook',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_organizer_twitter'.
  $field_bases['field_organizer_twitter'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_organizer_twitter',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_promote_in_feed'.
  $field_bases['field_promote_in_feed'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_promote_in_feed',
    'field_permissions' => array(
      'type' => 2,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_repeating_date_description'.
  $field_bases['field_repeating_date_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_repeating_date_description',
    'field_permissions' => array(
      'type' => 1,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_rsvp_email'.
  $field_bases['field_rsvp_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_rsvp_email',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'email',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'email',
  );

  // Exported field_base: 'field_rsvp_phone'.
  $field_bases['field_rsvp_phone'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_rsvp_phone',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 20,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_rsvp_text'.
  $field_bases['field_rsvp_text'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_rsvp_text',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_same_as_submitter'.
  $field_bases['field_same_as_submitter'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_same_as_submitter',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 0,
        1 => 1,
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_social_facebook'.
  $field_bases['field_social_facebook'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_social_facebook',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_social_twitter'.
  $field_bases['field_social_twitter'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_social_twitter',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_submitter_email'.
  $field_bases['field_submitter_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_submitter_email',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'email',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'email',
  );

  // Exported field_base: 'field_submitter_name'.
  $field_bases['field_submitter_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_submitter_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_submitter_phone'.
  $field_bases['field_submitter_phone'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_submitter_phone',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_taxonomy_1'.
  $field_bases['field_taxonomy_1'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_1',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'calendar_taxonomy_1',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_taxonomy_10'.
  $field_bases['field_taxonomy_10'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_10',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'calendar_taxonomy_10',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_taxonomy_10_enabled'.
  $field_bases['field_taxonomy_10_enabled'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_10_enabled',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_taxonomy_10_label'.
  $field_bases['field_taxonomy_10_label'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_10_label',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_taxonomy_11'.
  $field_bases['field_taxonomy_11'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_11',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'calendar_taxonomy_11',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_taxonomy_11_enabled'.
  $field_bases['field_taxonomy_11_enabled'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_11_enabled',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_taxonomy_11_label'.
  $field_bases['field_taxonomy_11_label'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_11_label',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_taxonomy_1_enabled'.
  $field_bases['field_taxonomy_1_enabled'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_1_enabled',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_taxonomy_1_label'.
  $field_bases['field_taxonomy_1_label'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_1_label',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 50,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_taxonomy_2'.
  $field_bases['field_taxonomy_2'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_2',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'calendar_taxonomy_2',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_taxonomy_2_enabled'.
  $field_bases['field_taxonomy_2_enabled'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_2_enabled',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_taxonomy_2_label'.
  $field_bases['field_taxonomy_2_label'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_2_label',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 50,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_taxonomy_3'.
  $field_bases['field_taxonomy_3'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_3',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'calendar_taxonomy_3',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_taxonomy_3_enabled'.
  $field_bases['field_taxonomy_3_enabled'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_3_enabled',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_taxonomy_3_label'.
  $field_bases['field_taxonomy_3_label'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_3_label',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 50,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_taxonomy_4'.
  $field_bases['field_taxonomy_4'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_4',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'calendar_taxonomy_4',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_taxonomy_4_enabled'.
  $field_bases['field_taxonomy_4_enabled'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_4_enabled',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_taxonomy_4_label'.
  $field_bases['field_taxonomy_4_label'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_4_label',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_taxonomy_5'.
  $field_bases['field_taxonomy_5'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_5',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'calendar_taxonomy_5',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_taxonomy_5_enabled'.
  $field_bases['field_taxonomy_5_enabled'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_5_enabled',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_taxonomy_5_label'.
  $field_bases['field_taxonomy_5_label'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_5_label',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_taxonomy_6'.
  $field_bases['field_taxonomy_6'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_6',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'calendar_taxonomy_6',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_taxonomy_6_enabled'.
  $field_bases['field_taxonomy_6_enabled'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_6_enabled',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_taxonomy_6_label'.
  $field_bases['field_taxonomy_6_label'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_6_label',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_taxonomy_8'.
  $field_bases['field_taxonomy_8'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_8',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'calendar_taxonomy_8',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_taxonomy_8_enabled'.
  $field_bases['field_taxonomy_8_enabled'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_8_enabled',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_taxonomy_8_label'.
  $field_bases['field_taxonomy_8_label'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_8_label',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_taxonomy_9'.
  $field_bases['field_taxonomy_9'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_9',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'calendar_taxonomy_9',
          'parent' => 0,
        ),
      ),
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_taxonomy_9_enabled'.
  $field_bases['field_taxonomy_9_enabled'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_9_enabled',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_taxonomy_9_label'.
  $field_bases['field_taxonomy_9_label'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_taxonomy_9_label',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_ticket_url'.
  $field_bases['field_ticket_url'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_ticket_url',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_timezone'.
  $field_bases['field_timezone'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_timezone',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'tzfield',
    'settings' => array(
      'exclude' => array(
        'Africa/Abidjan' => 'Africa/Abidjan',
        'Africa/Accra' => 'Africa/Accra',
        'Africa/Addis_Ababa' => 'Africa/Addis_Ababa',
        'Africa/Algiers' => 'Africa/Algiers',
        'Africa/Asmara' => 'Africa/Asmara',
        'Africa/Bamako' => 'Africa/Bamako',
        'Africa/Bangui' => 'Africa/Bangui',
        'Africa/Banjul' => 'Africa/Banjul',
        'Africa/Bissau' => 'Africa/Bissau',
        'Africa/Blantyre' => 'Africa/Blantyre',
        'Africa/Brazzaville' => 'Africa/Brazzaville',
        'Africa/Bujumbura' => 'Africa/Bujumbura',
        'Africa/Cairo' => 'Africa/Cairo',
        'Africa/Casablanca' => 'Africa/Casablanca',
        'Africa/Ceuta' => 'Africa/Ceuta',
        'Africa/Conakry' => 'Africa/Conakry',
        'Africa/Dakar' => 'Africa/Dakar',
        'Africa/Dar_es_Salaam' => 'Africa/Dar_es_Salaam',
        'Africa/Djibouti' => 'Africa/Djibouti',
        'Africa/Douala' => 'Africa/Douala',
        'Africa/El_Aaiun' => 'Africa/El_Aaiun',
        'Africa/Freetown' => 'Africa/Freetown',
        'Africa/Gaborone' => 'Africa/Gaborone',
        'Africa/Harare' => 'Africa/Harare',
        'Africa/Johannesburg' => 'Africa/Johannesburg',
        'Africa/Juba' => 'Africa/Juba',
        'Africa/Kampala' => 'Africa/Kampala',
        'Africa/Khartoum' => 'Africa/Khartoum',
        'Africa/Kigali' => 'Africa/Kigali',
        'Africa/Kinshasa' => 'Africa/Kinshasa',
        'Africa/Lagos' => 'Africa/Lagos',
        'Africa/Libreville' => 'Africa/Libreville',
        'Africa/Lome' => 'Africa/Lome',
        'Africa/Luanda' => 'Africa/Luanda',
        'Africa/Lubumbashi' => 'Africa/Lubumbashi',
        'Africa/Lusaka' => 'Africa/Lusaka',
        'Africa/Malabo' => 'Africa/Malabo',
        'Africa/Maputo' => 'Africa/Maputo',
        'Africa/Maseru' => 'Africa/Maseru',
        'Africa/Mbabane' => 'Africa/Mbabane',
        'Africa/Mogadishu' => 'Africa/Mogadishu',
        'Africa/Monrovia' => 'Africa/Monrovia',
        'Africa/Nairobi' => 'Africa/Nairobi',
        'Africa/Ndjamena' => 'Africa/Ndjamena',
        'Africa/Niamey' => 'Africa/Niamey',
        'Africa/Nouakchott' => 'Africa/Nouakchott',
        'Africa/Ouagadougou' => 'Africa/Ouagadougou',
        'Africa/Porto-Novo' => 'Africa/Porto-Novo',
        'Africa/Sao_Tome' => 'Africa/Sao_Tome',
        'Africa/Tripoli' => 'Africa/Tripoli',
        'Africa/Tunis' => 'Africa/Tunis',
        'Africa/Windhoek' => 'Africa/Windhoek',
        'America/Adak' => 'America/Adak',
        'America/Anchorage' => 'America/Anchorage',
        'America/Anguilla' => 'America/Anguilla',
        'America/Antigua' => 'America/Antigua',
        'America/Araguaina' => 'America/Araguaina',
        'America/Argentina/Buenos_Aires' => 'America/Argentina/Buenos_Aires',
        'America/Argentina/Catamarca' => 'America/Argentina/Catamarca',
        'America/Argentina/Cordoba' => 'America/Argentina/Cordoba',
        'America/Argentina/Jujuy' => 'America/Argentina/Jujuy',
        'America/Argentina/La_Rioja' => 'America/Argentina/La_Rioja',
        'America/Argentina/Mendoza' => 'America/Argentina/Mendoza',
        'America/Argentina/Rio_Gallegos' => 'America/Argentina/Rio_Gallegos',
        'America/Argentina/Salta' => 'America/Argentina/Salta',
        'America/Argentina/San_Juan' => 'America/Argentina/San_Juan',
        'America/Argentina/San_Luis' => 'America/Argentina/San_Luis',
        'America/Argentina/Tucuman' => 'America/Argentina/Tucuman',
        'America/Argentina/Ushuaia' => 'America/Argentina/Ushuaia',
        'America/Aruba' => 'America/Aruba',
        'America/Asuncion' => 'America/Asuncion',
        'America/Atikokan' => 'America/Atikokan',
        'America/Bahia' => 'America/Bahia',
        'America/Bahia_Banderas' => 'America/Bahia_Banderas',
        'America/Barbados' => 'America/Barbados',
        'America/Belem' => 'America/Belem',
        'America/Belize' => 'America/Belize',
        'America/Blanc-Sablon' => 'America/Blanc-Sablon',
        'America/Boa_Vista' => 'America/Boa_Vista',
        'America/Bogota' => 'America/Bogota',
        'America/Boise' => 'America/Boise',
        'America/Cambridge_Bay' => 'America/Cambridge_Bay',
        'America/Campo_Grande' => 'America/Campo_Grande',
        'America/Cancun' => 'America/Cancun',
        'America/Caracas' => 'America/Caracas',
        'America/Cayenne' => 'America/Cayenne',
        'America/Cayman' => 'America/Cayman',
        'America/Chihuahua' => 'America/Chihuahua',
        'America/Costa_Rica' => 'America/Costa_Rica',
        'America/Creston' => 'America/Creston',
        'America/Cuiaba' => 'America/Cuiaba',
        'America/Curacao' => 'America/Curacao',
        'America/Danmarkshavn' => 'America/Danmarkshavn',
        'America/Dawson' => 'America/Dawson',
        'America/Dawson_Creek' => 'America/Dawson_Creek',
        'America/Detroit' => 'America/Detroit',
        'America/Dominica' => 'America/Dominica',
        'America/Edmonton' => 'America/Edmonton',
        'America/Eirunepe' => 'America/Eirunepe',
        'America/El_Salvador' => 'America/El_Salvador',
        'America/Fortaleza' => 'America/Fortaleza',
        'America/Glace_Bay' => 'America/Glace_Bay',
        'America/Godthab' => 'America/Godthab',
        'America/Goose_Bay' => 'America/Goose_Bay',
        'America/Grand_Turk' => 'America/Grand_Turk',
        'America/Grenada' => 'America/Grenada',
        'America/Guadeloupe' => 'America/Guadeloupe',
        'America/Guatemala' => 'America/Guatemala',
        'America/Guayaquil' => 'America/Guayaquil',
        'America/Guyana' => 'America/Guyana',
        'America/Halifax' => 'America/Halifax',
        'America/Havana' => 'America/Havana',
        'America/Hermosillo' => 'America/Hermosillo',
        'America/Indiana/Indianapolis' => 'America/Indiana/Indianapolis',
        'America/Indiana/Knox' => 'America/Indiana/Knox',
        'America/Indiana/Marengo' => 'America/Indiana/Marengo',
        'America/Indiana/Petersburg' => 'America/Indiana/Petersburg',
        'America/Indiana/Tell_City' => 'America/Indiana/Tell_City',
        'America/Indiana/Vevay' => 'America/Indiana/Vevay',
        'America/Indiana/Vincennes' => 'America/Indiana/Vincennes',
        'America/Indiana/Winamac' => 'America/Indiana/Winamac',
        'America/Inuvik' => 'America/Inuvik',
        'America/Iqaluit' => 'America/Iqaluit',
        'America/Jamaica' => 'America/Jamaica',
        'America/Juneau' => 'America/Juneau',
        'America/Kentucky/Louisville' => 'America/Kentucky/Louisville',
        'America/Kentucky/Monticello' => 'America/Kentucky/Monticello',
        'America/Kralendijk' => 'America/Kralendijk',
        'America/La_Paz' => 'America/La_Paz',
        'America/Lima' => 'America/Lima',
        'America/Lower_Princes' => 'America/Lower_Princes',
        'America/Maceio' => 'America/Maceio',
        'America/Managua' => 'America/Managua',
        'America/Manaus' => 'America/Manaus',
        'America/Marigot' => 'America/Marigot',
        'America/Martinique' => 'America/Martinique',
        'America/Matamoros' => 'America/Matamoros',
        'America/Mazatlan' => 'America/Mazatlan',
        'America/Menominee' => 'America/Menominee',
        'America/Merida' => 'America/Merida',
        'America/Metlakatla' => 'America/Metlakatla',
        'America/Mexico_City' => 'America/Mexico_City',
        'America/Miquelon' => 'America/Miquelon',
        'America/Moncton' => 'America/Moncton',
        'America/Monterrey' => 'America/Monterrey',
        'America/Montevideo' => 'America/Montevideo',
        'America/Montserrat' => 'America/Montserrat',
        'America/Nassau' => 'America/Nassau',
        'America/Nipigon' => 'America/Nipigon',
        'America/Nome' => 'America/Nome',
        'America/Noronha' => 'America/Noronha',
        'America/North_Dakota/Beulah' => 'America/North_Dakota/Beulah',
        'America/North_Dakota/Center' => 'America/North_Dakota/Center',
        'America/North_Dakota/New_Salem' => 'America/North_Dakota/New_Salem',
        'America/Ojinaga' => 'America/Ojinaga',
        'America/Panama' => 'America/Panama',
        'America/Pangnirtung' => 'America/Pangnirtung',
        'America/Paramaribo' => 'America/Paramaribo',
        'America/Phoenix' => 'America/Phoenix',
        'America/Port-au-Prince' => 'America/Port-au-Prince',
        'America/Port_of_Spain' => 'America/Port_of_Spain',
        'America/Porto_Velho' => 'America/Porto_Velho',
        'America/Puerto_Rico' => 'America/Puerto_Rico',
        'America/Rainy_River' => 'America/Rainy_River',
        'America/Rankin_Inlet' => 'America/Rankin_Inlet',
        'America/Recife' => 'America/Recife',
        'America/Regina' => 'America/Regina',
        'America/Resolute' => 'America/Resolute',
        'America/Rio_Branco' => 'America/Rio_Branco',
        'America/Santa_Isabel' => 'America/Santa_Isabel',
        'America/Santarem' => 'America/Santarem',
        'America/Santiago' => 'America/Santiago',
        'America/Santo_Domingo' => 'America/Santo_Domingo',
        'America/Sao_Paulo' => 'America/Sao_Paulo',
        'America/Scoresbysund' => 'America/Scoresbysund',
        'America/Sitka' => 'America/Sitka',
        'America/St_Barthelemy' => 'America/St_Barthelemy',
        'America/St_Johns' => 'America/St_Johns',
        'America/St_Kitts' => 'America/St_Kitts',
        'America/St_Lucia' => 'America/St_Lucia',
        'America/St_Thomas' => 'America/St_Thomas',
        'America/St_Vincent' => 'America/St_Vincent',
        'America/Swift_Current' => 'America/Swift_Current',
        'America/Tegucigalpa' => 'America/Tegucigalpa',
        'America/Thule' => 'America/Thule',
        'America/Thunder_Bay' => 'America/Thunder_Bay',
        'America/Tijuana' => 'America/Tijuana',
        'America/Toronto' => 'America/Toronto',
        'America/Tortola' => 'America/Tortola',
        'America/Vancouver' => 'America/Vancouver',
        'America/Whitehorse' => 'America/Whitehorse',
        'America/Winnipeg' => 'America/Winnipeg',
        'America/Yakutat' => 'America/Yakutat',
        'America/Yellowknife' => 'America/Yellowknife',
        'Antarctica/Casey' => 'Antarctica/Casey',
        'Antarctica/Davis' => 'Antarctica/Davis',
        'Antarctica/DumontDUrville' => 'Antarctica/DumontDUrville',
        'Antarctica/Macquarie' => 'Antarctica/Macquarie',
        'Antarctica/Mawson' => 'Antarctica/Mawson',
        'Antarctica/McMurdo' => 'Antarctica/McMurdo',
        'Antarctica/Palmer' => 'Antarctica/Palmer',
        'Antarctica/Rothera' => 'Antarctica/Rothera',
        'Antarctica/Syowa' => 'Antarctica/Syowa',
        'Antarctica/Troll' => 'Antarctica/Troll',
        'Antarctica/Vostok' => 'Antarctica/Vostok',
        'Arctic/Longyearbyen' => 'Arctic/Longyearbyen',
        'Asia/Aden' => 'Asia/Aden',
        'Asia/Almaty' => 'Asia/Almaty',
        'Asia/Amman' => 'Asia/Amman',
        'Asia/Anadyr' => 'Asia/Anadyr',
        'Asia/Aqtau' => 'Asia/Aqtau',
        'Asia/Aqtobe' => 'Asia/Aqtobe',
        'Asia/Ashgabat' => 'Asia/Ashgabat',
        'Asia/Baghdad' => 'Asia/Baghdad',
        'Asia/Bahrain' => 'Asia/Bahrain',
        'Asia/Baku' => 'Asia/Baku',
        'Asia/Bangkok' => 'Asia/Bangkok',
        'Asia/Beirut' => 'Asia/Beirut',
        'Asia/Bishkek' => 'Asia/Bishkek',
        'Asia/Brunei' => 'Asia/Brunei',
        'Asia/Chita' => 'Asia/Chita',
        'Asia/Choibalsan' => 'Asia/Choibalsan',
        'Asia/Colombo' => 'Asia/Colombo',
        'Asia/Damascus' => 'Asia/Damascus',
        'Asia/Dhaka' => 'Asia/Dhaka',
        'Asia/Dili' => 'Asia/Dili',
        'Asia/Dubai' => 'Asia/Dubai',
        'Asia/Dushanbe' => 'Asia/Dushanbe',
        'Asia/Gaza' => 'Asia/Gaza',
        'Asia/Hebron' => 'Asia/Hebron',
        'Asia/Ho_Chi_Minh' => 'Asia/Ho_Chi_Minh',
        'Asia/Hong_Kong' => 'Asia/Hong_Kong',
        'Asia/Hovd' => 'Asia/Hovd',
        'Asia/Irkutsk' => 'Asia/Irkutsk',
        'Asia/Jakarta' => 'Asia/Jakarta',
        'Asia/Jayapura' => 'Asia/Jayapura',
        'Asia/Jerusalem' => 'Asia/Jerusalem',
        'Asia/Kabul' => 'Asia/Kabul',
        'Asia/Kamchatka' => 'Asia/Kamchatka',
        'Asia/Karachi' => 'Asia/Karachi',
        'Asia/Kathmandu' => 'Asia/Kathmandu',
        'Asia/Khandyga' => 'Asia/Khandyga',
        'Asia/Kolkata' => 'Asia/Kolkata',
        'Asia/Krasnoyarsk' => 'Asia/Krasnoyarsk',
        'Asia/Kuala_Lumpur' => 'Asia/Kuala_Lumpur',
        'Asia/Kuching' => 'Asia/Kuching',
        'Asia/Kuwait' => 'Asia/Kuwait',
        'Asia/Macau' => 'Asia/Macau',
        'Asia/Magadan' => 'Asia/Magadan',
        'Asia/Makassar' => 'Asia/Makassar',
        'Asia/Manila' => 'Asia/Manila',
        'Asia/Muscat' => 'Asia/Muscat',
        'Asia/Nicosia' => 'Asia/Nicosia',
        'Asia/Novokuznetsk' => 'Asia/Novokuznetsk',
        'Asia/Novosibirsk' => 'Asia/Novosibirsk',
        'Asia/Omsk' => 'Asia/Omsk',
        'Asia/Oral' => 'Asia/Oral',
        'Asia/Phnom_Penh' => 'Asia/Phnom_Penh',
        'Asia/Pontianak' => 'Asia/Pontianak',
        'Asia/Pyongyang' => 'Asia/Pyongyang',
        'Asia/Qatar' => 'Asia/Qatar',
        'Asia/Qyzylorda' => 'Asia/Qyzylorda',
        'Asia/Rangoon' => 'Asia/Rangoon',
        'Asia/Riyadh' => 'Asia/Riyadh',
        'Asia/Sakhalin' => 'Asia/Sakhalin',
        'Asia/Samarkand' => 'Asia/Samarkand',
        'Asia/Seoul' => 'Asia/Seoul',
        'Asia/Shanghai' => 'Asia/Shanghai',
        'Asia/Singapore' => 'Asia/Singapore',
        'Asia/Srednekolymsk' => 'Asia/Srednekolymsk',
        'Asia/Taipei' => 'Asia/Taipei',
        'Asia/Tashkent' => 'Asia/Tashkent',
        'Asia/Tbilisi' => 'Asia/Tbilisi',
        'Asia/Tehran' => 'Asia/Tehran',
        'Asia/Thimphu' => 'Asia/Thimphu',
        'Asia/Tokyo' => 'Asia/Tokyo',
        'Asia/Ulaanbaatar' => 'Asia/Ulaanbaatar',
        'Asia/Urumqi' => 'Asia/Urumqi',
        'Asia/Ust-Nera' => 'Asia/Ust-Nera',
        'Asia/Vientiane' => 'Asia/Vientiane',
        'Asia/Vladivostok' => 'Asia/Vladivostok',
        'Asia/Yakutsk' => 'Asia/Yakutsk',
        'Asia/Yekaterinburg' => 'Asia/Yekaterinburg',
        'Asia/Yerevan' => 'Asia/Yerevan',
        'Atlantic/Azores' => 'Atlantic/Azores',
        'Atlantic/Bermuda' => 'Atlantic/Bermuda',
        'Atlantic/Canary' => 'Atlantic/Canary',
        'Atlantic/Cape_Verde' => 'Atlantic/Cape_Verde',
        'Atlantic/Faroe' => 'Atlantic/Faroe',
        'Atlantic/Madeira' => 'Atlantic/Madeira',
        'Atlantic/Reykjavik' => 'Atlantic/Reykjavik',
        'Atlantic/South_Georgia' => 'Atlantic/South_Georgia',
        'Atlantic/St_Helena' => 'Atlantic/St_Helena',
        'Atlantic/Stanley' => 'Atlantic/Stanley',
        'Australia/Adelaide' => 'Australia/Adelaide',
        'Australia/Brisbane' => 'Australia/Brisbane',
        'Australia/Broken_Hill' => 'Australia/Broken_Hill',
        'Australia/Currie' => 'Australia/Currie',
        'Australia/Darwin' => 'Australia/Darwin',
        'Australia/Eucla' => 'Australia/Eucla',
        'Australia/Hobart' => 'Australia/Hobart',
        'Australia/Lindeman' => 'Australia/Lindeman',
        'Australia/Lord_Howe' => 'Australia/Lord_Howe',
        'Australia/Melbourne' => 'Australia/Melbourne',
        'Australia/Perth' => 'Australia/Perth',
        'Australia/Sydney' => 'Australia/Sydney',
        'Europe/Amsterdam' => 'Europe/Amsterdam',
        'Europe/Andorra' => 'Europe/Andorra',
        'Europe/Athens' => 'Europe/Athens',
        'Europe/Belgrade' => 'Europe/Belgrade',
        'Europe/Berlin' => 'Europe/Berlin',
        'Europe/Bratislava' => 'Europe/Bratislava',
        'Europe/Brussels' => 'Europe/Brussels',
        'Europe/Bucharest' => 'Europe/Bucharest',
        'Europe/Budapest' => 'Europe/Budapest',
        'Europe/Busingen' => 'Europe/Busingen',
        'Europe/Chisinau' => 'Europe/Chisinau',
        'Europe/Copenhagen' => 'Europe/Copenhagen',
        'Europe/Dublin' => 'Europe/Dublin',
        'Europe/Gibraltar' => 'Europe/Gibraltar',
        'Europe/Guernsey' => 'Europe/Guernsey',
        'Europe/Helsinki' => 'Europe/Helsinki',
        'Europe/Isle_of_Man' => 'Europe/Isle_of_Man',
        'Europe/Istanbul' => 'Europe/Istanbul',
        'Europe/Jersey' => 'Europe/Jersey',
        'Europe/Kaliningrad' => 'Europe/Kaliningrad',
        'Europe/Kiev' => 'Europe/Kiev',
        'Europe/Lisbon' => 'Europe/Lisbon',
        'Europe/Ljubljana' => 'Europe/Ljubljana',
        'Europe/London' => 'Europe/London',
        'Europe/Luxembourg' => 'Europe/Luxembourg',
        'Europe/Madrid' => 'Europe/Madrid',
        'Europe/Malta' => 'Europe/Malta',
        'Europe/Mariehamn' => 'Europe/Mariehamn',
        'Europe/Minsk' => 'Europe/Minsk',
        'Europe/Monaco' => 'Europe/Monaco',
        'Europe/Moscow' => 'Europe/Moscow',
        'Europe/Oslo' => 'Europe/Oslo',
        'Europe/Paris' => 'Europe/Paris',
        'Europe/Podgorica' => 'Europe/Podgorica',
        'Europe/Prague' => 'Europe/Prague',
        'Europe/Riga' => 'Europe/Riga',
        'Europe/Rome' => 'Europe/Rome',
        'Europe/Samara' => 'Europe/Samara',
        'Europe/San_Marino' => 'Europe/San_Marino',
        'Europe/Sarajevo' => 'Europe/Sarajevo',
        'Europe/Simferopol' => 'Europe/Simferopol',
        'Europe/Skopje' => 'Europe/Skopje',
        'Europe/Sofia' => 'Europe/Sofia',
        'Europe/Stockholm' => 'Europe/Stockholm',
        'Europe/Tallinn' => 'Europe/Tallinn',
        'Europe/Tirane' => 'Europe/Tirane',
        'Europe/Uzhgorod' => 'Europe/Uzhgorod',
        'Europe/Vaduz' => 'Europe/Vaduz',
        'Europe/Vatican' => 'Europe/Vatican',
        'Europe/Vienna' => 'Europe/Vienna',
        'Europe/Vilnius' => 'Europe/Vilnius',
        'Europe/Volgograd' => 'Europe/Volgograd',
        'Europe/Warsaw' => 'Europe/Warsaw',
        'Europe/Zagreb' => 'Europe/Zagreb',
        'Europe/Zaporozhye' => 'Europe/Zaporozhye',
        'Europe/Zurich' => 'Europe/Zurich',
        'Indian/Antananarivo' => 'Indian/Antananarivo',
        'Indian/Chagos' => 'Indian/Chagos',
        'Indian/Christmas' => 'Indian/Christmas',
        'Indian/Cocos' => 'Indian/Cocos',
        'Indian/Comoro' => 'Indian/Comoro',
        'Indian/Kerguelen' => 'Indian/Kerguelen',
        'Indian/Mahe' => 'Indian/Mahe',
        'Indian/Maldives' => 'Indian/Maldives',
        'Indian/Mauritius' => 'Indian/Mauritius',
        'Indian/Mayotte' => 'Indian/Mayotte',
        'Indian/Reunion' => 'Indian/Reunion',
        'Pacific/Apia' => 'Pacific/Apia',
        'Pacific/Auckland' => 'Pacific/Auckland',
        'Pacific/Bougainville' => 'Pacific/Bougainville',
        'Pacific/Chatham' => 'Pacific/Chatham',
        'Pacific/Chuuk' => 'Pacific/Chuuk',
        'Pacific/Easter' => 'Pacific/Easter',
        'Pacific/Efate' => 'Pacific/Efate',
        'Pacific/Enderbury' => 'Pacific/Enderbury',
        'Pacific/Fakaofo' => 'Pacific/Fakaofo',
        'Pacific/Fiji' => 'Pacific/Fiji',
        'Pacific/Funafuti' => 'Pacific/Funafuti',
        'Pacific/Galapagos' => 'Pacific/Galapagos',
        'Pacific/Gambier' => 'Pacific/Gambier',
        'Pacific/Guadalcanal' => 'Pacific/Guadalcanal',
        'Pacific/Guam' => 'Pacific/Guam',
        'Pacific/Honolulu' => 'Pacific/Honolulu',
        'Pacific/Johnston' => 'Pacific/Johnston',
        'Pacific/Kiritimati' => 'Pacific/Kiritimati',
        'Pacific/Kosrae' => 'Pacific/Kosrae',
        'Pacific/Kwajalein' => 'Pacific/Kwajalein',
        'Pacific/Majuro' => 'Pacific/Majuro',
        'Pacific/Marquesas' => 'Pacific/Marquesas',
        'Pacific/Midway' => 'Pacific/Midway',
        'Pacific/Nauru' => 'Pacific/Nauru',
        'Pacific/Niue' => 'Pacific/Niue',
        'Pacific/Norfolk' => 'Pacific/Norfolk',
        'Pacific/Noumea' => 'Pacific/Noumea',
        'Pacific/Pago_Pago' => 'Pacific/Pago_Pago',
        'Pacific/Palau' => 'Pacific/Palau',
        'Pacific/Pitcairn' => 'Pacific/Pitcairn',
        'Pacific/Pohnpei' => 'Pacific/Pohnpei',
        'Pacific/Port_Moresby' => 'Pacific/Port_Moresby',
        'Pacific/Rarotonga' => 'Pacific/Rarotonga',
        'Pacific/Saipan' => 'Pacific/Saipan',
        'Pacific/Tahiti' => 'Pacific/Tahiti',
        'Pacific/Tarawa' => 'Pacific/Tarawa',
        'Pacific/Tongatapu' => 'Pacific/Tongatapu',
        'Pacific/Wake' => 'Pacific/Wake',
        'Pacific/Wallis' => 'Pacific/Wallis',
        'UTC' => 'UTC',
      ),
    ),
    'translatable' => 0,
    'type' => 'tzfield',
  );

  // Exported field_base: 'field_venue_name'.
  $field_bases['field_venue_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_venue_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_venue_url'.
  $field_bases['field_venue_url'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_venue_url',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  return $field_bases;
}
