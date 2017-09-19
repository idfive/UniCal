<?php
/**
 * @file
 * unical_features.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function unical_features_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admin|node|event|form';
  $field_group->group_name = 'group_admin';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Admin Settings',
    'weight' => '46',
    'children' => array(
      0 => 'date_repeat_entity_clone_state',
      1 => 'date_repeat_entity_master_uuid',
      2 => 'field_exclude_from_main_calendar',
      3 => 'field_featured',
      4 => 'field_promote_in_feed',
      5 => 'field_repeating_date_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-admin field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_admin|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_audience|node|event|form';
  $field_group->group_name = 'group_audience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Audience',
    'weight' => '45',
    'children' => array(
      0 => 'field_taxonomy_2',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_audience|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_category|node|event|form';
  $field_group->group_name = 'group_category';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Category',
    'weight' => '46',
    'children' => array(
      0 => 'field_taxonomy_3',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_category|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|node|event|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Event Contact Info',
    'weight' => '43',
    'children' => array(
      0 => 'field_contact_email',
      1 => 'field_contact_name',
      2 => 'field_contact_phone',
      3 => 'field_organizer_facebook',
      4 => 'field_organizer_twitter',
      5 => 'field_same_as_submitter',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Event Contact Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-contact field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_contact|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cost|node|event|form';
  $field_group->group_name = 'group_cost';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Cost',
    'weight' => '41',
    'children' => array(
      0 => 'field_cost',
      1 => 'field_free_event',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cost field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_cost|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date|node|event|form';
  $field_group->group_name = 'group_date';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Date/Time',
    'weight' => '35',
    'children' => array(
      0 => 'field_date',
      1 => 'field_timezone',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-date field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_date|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_department|node|event|form';
  $field_group->group_name = 'group_department';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'School/Department',
    'weight' => '44',
    'children' => array(
      0 => 'field_taxonomy_1',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_department|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general|node|event|form';
  $field_group->group_name = 'group_general';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General',
    'weight' => '3',
    'children' => array(
      0 => 'group_admin',
      1 => 'group_contact',
      2 => 'group_cost',
      3 => 'group_date',
      4 => 'group_location',
      5 => 'group_rsvp',
      6 => 'group_social_media',
      7 => 'group_submitter',
      8 => 'group_venue',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-general field-group-tabs',
      ),
    ),
  );
  $export['group_general|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_help_text|node|site|form';
  $field_group->group_name = 'group_help_text';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Help Text',
    'weight' => '2',
    'children' => array(
      0 => 'field_calendar_help_link',
      1 => 'field_custom_text_above_filters',
      2 => 'field_custom_text_above_sidebar',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_help_text|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_location|node|event|form';
  $field_group->group_name = 'group_location';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Location',
    'weight' => '37',
    'children' => array(
      0 => 'field_address',
      1 => 'field_map_zoom',
      2 => 'field_map_center_lat',
      3 => 'field_map_center_lng',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-location field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_location|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_rsvp|node|event|form';
  $field_group->group_name = 'group_rsvp';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'RSVP',
    'weight' => '42',
    'children' => array(
      0 => 'field_how_to_rsvp',
      1 => 'field_rsvp_email',
      2 => 'field_rsvp_phone',
      3 => 'field_ticket_url',
      4 => 'field_rsvp_text',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-rsvp field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_rsvp|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_site_specific|node|site|form';
  $field_group->group_name = 'group_site_specific';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Site Specific Settings',
    'weight' => '3',
    'children' => array(
      0 => 'field_add_to_calendar_exclude',
      1 => 'field_allow_archive',
      2 => 'field_allow_event_submit',
      3 => 'field_allow_featured_events',
      4 => 'field_allow_users_to_choose_taxo',
      5 => 'field_default_event_image',
      6 => 'field_google_maps_api_key',
      7 => 'field_main_calendar_site',
      8 => 'field_number_results_per_page',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-site-specific field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_site_specific|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_social_media|node|event|form';
  $field_group->group_name = 'group_social_media';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Social Media',
    'weight' => '45',
    'children' => array(
      0 => 'field_contact_website',
      1 => 'field_social_facebook',
      2 => 'field_social_twitter',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-social-media field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_social_media|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_submitter|node|event|form';
  $field_group->group_name = 'group_submitter';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Submitter Contact Info',
    'weight' => '44',
    'children' => array(
      0 => 'field_submitter_email',
      1 => 'field_submitter_name',
      2 => 'field_submitter_phone',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-submitter field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_submitter|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tax_10|node|event|form';
  $field_group->group_name = 'group_tax_10';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 10',
    'weight' => '55',
    'children' => array(
      0 => 'field_taxonomy_10',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tax-10 field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tax_10|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tax_11|node|event|form';
  $field_group->group_name = 'group_tax_11';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 11',
    'weight' => '56',
    'children' => array(
      0 => 'field_taxonomy_11',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tax-11 field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tax_11|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tax_1|node|event|form';
  $field_group->group_name = 'group_tax_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 1',
    'weight' => '46',
    'children' => array(
      0 => 'field_taxonomy_1',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tax-1 field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tax_1|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tax_2|node|event|form';
  $field_group->group_name = 'group_tax_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 2',
    'weight' => '47',
    'children' => array(
      0 => 'field_taxonomy_2',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tax-2 field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tax_2|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tax_3|node|event|form';
  $field_group->group_name = 'group_tax_3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 3',
    'weight' => '48',
    'children' => array(
      0 => 'field_taxonomy_3',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tax-3 field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tax_3|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tax_4|node|event|form';
  $field_group->group_name = 'group_tax_4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 4',
    'weight' => '49',
    'children' => array(
      0 => 'field_taxonomy_4',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tax-4 field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tax_4|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tax_5|node|event|form';
  $field_group->group_name = 'group_tax_5';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 5',
    'weight' => '51',
    'children' => array(
      0 => 'field_taxonomy_5',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tax-5 field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tax_5|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tax_6|node|event|form';
  $field_group->group_name = 'group_tax_6';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 6',
    'weight' => '52',
    'children' => array(
      0 => 'field_taxonomy_6',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tax-6 field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tax_6|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tax_8|node|event|form';
  $field_group->group_name = 'group_tax_8';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 8',
    'weight' => '53',
    'children' => array(
      0 => 'field_taxonomy_8',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tax-8 field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tax_8|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tax_9|node|event|form';
  $field_group->group_name = 'group_tax_9';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 9',
    'weight' => '54',
    'children' => array(
      0 => 'field_taxonomy_9',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-tax-9 field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_tax_9|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|event|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '4',
    'children' => array(
      0 => 'group_tax_1',
      1 => 'group_tax_2',
      2 => 'group_tax_3',
      3 => 'group_tax_4',
      4 => 'group_tax_5',
      5 => 'group_tax_6',
      6 => 'group_tax_8',
      7 => 'group_tax_9',
      8 => 'group_tax_10',
      9 => 'group_tax_11',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => '',
      ),
    ),
  );
  $export['group_taxonomies|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|site|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '1',
    'children' => array(
      0 => 'group_taxonomy_10',
      1 => 'group_taxonomy_1',
      2 => 'group_taxonomy_2',
      3 => 'group_taxonomy_3',
      4 => 'group_taxonomy_4',
      5 => 'group_taxonomy_5',
      6 => 'group_taxonomy_6',
      7 => 'group_taxonomy_8',
      8 => 'group_taxonomy_9',
      9 => 'group_taxonomy_11',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-taxonomies field-group-tabs',
      ),
    ),
  );
  $export['group_taxonomies|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy_10|node|site|form';
  $field_group->group_name = 'group_taxonomy_10';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 10',
    'weight' => '13',
    'children' => array(
      0 => 'field_taxonomy_10_enabled',
      1 => 'field_taxonomy_10_label',
      2 => 'field_taxonomy_10',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomy-10 field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_taxonomy_10|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy_11|node|site|form';
  $field_group->group_name = 'group_taxonomy_11';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 11',
    'weight' => '14',
    'children' => array(
      0 => 'field_taxonomy_11_enabled',
      1 => 'field_taxonomy_11_label',
      2 => 'field_taxonomy_11',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomy-11 field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_taxonomy_11|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy_1|node|site|form';
  $field_group->group_name = 'group_taxonomy_1';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 1',
    'weight' => '5',
    'children' => array(
      0 => 'field_taxonomy_1',
      1 => 'field_taxonomy_1_enabled',
      2 => 'field_taxonomy_1_label',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Taxonomy 1',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_taxonomy_1|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy_2|node|site|form';
  $field_group->group_name = 'group_taxonomy_2';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 2',
    'weight' => '6',
    'children' => array(
      0 => 'field_taxonomy_2',
      1 => 'field_taxonomy_2_enabled',
      2 => 'field_taxonomy_2_label',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Taxonomy 2',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_taxonomy_2|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy_3|node|site|form';
  $field_group->group_name = 'group_taxonomy_3';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 3',
    'weight' => '7',
    'children' => array(
      0 => 'field_taxonomy_3',
      1 => 'field_taxonomy_3_enabled',
      2 => 'field_taxonomy_3_label',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Taxonomy 3',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-taxonomy-3 field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_taxonomy_3|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy_4|node|site|form';
  $field_group->group_name = 'group_taxonomy_4';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 4',
    'weight' => '8',
    'children' => array(
      0 => 'field_taxonomy_4',
      1 => 'field_taxonomy_4_enabled',
      2 => 'field_taxonomy_4_label',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Taxonomy 4',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-taxonomy-4 field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_taxonomy_4|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy_5|node|site|form';
  $field_group->group_name = 'group_taxonomy_5';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 5',
    'weight' => '9',
    'children' => array(
      0 => 'field_taxonomy_5',
      1 => 'field_taxonomy_5_enabled',
      2 => 'field_taxonomy_5_label',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Taxonomy 5',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-taxonomy-5 field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_taxonomy_5|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy_6|node|site|form';
  $field_group->group_name = 'group_taxonomy_6';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 6',
    'weight' => '10',
    'children' => array(
      0 => 'field_taxonomy_6',
      1 => 'field_taxonomy_6_enabled',
      2 => 'field_taxonomy_6_label',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Taxonomy 6',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-taxonomy-6 field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_taxonomy_6|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy_8|node|site|form';
  $field_group->group_name = 'group_taxonomy_8';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 8',
    'weight' => '11',
    'children' => array(
      0 => 'field_taxonomy_8_enabled',
      1 => 'field_taxonomy_8_label',
      2 => 'field_taxonomy_8',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomy-8 field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_taxonomy_8|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomy_9|node|site|form';
  $field_group->group_name = 'group_taxonomy_9';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'site';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Taxonomy 9',
    'weight' => '12',
    'children' => array(
      0 => 'field_taxonomy_9_enabled',
      1 => 'field_taxonomy_9_label',
      2 => 'field_taxonomy_9',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-taxonomy-9 field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_taxonomy_9|node|site|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_unused_taxonomies|node|event|form';
  $field_group->group_name = 'group_unused_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_taxonomies';
  $field_group->data = array(
    'label' => 'Unused taxonomies',
    'weight' => '47',
    'children' => array(
      0 => 'field_taxonomy_4',
      1 => 'field_taxonomy_5',
      2 => 'field_taxonomy_6',
      3 => 'field_taxonomy_8',
      4 => 'field_taxonomy_9',
      5 => 'field_taxonomy_10',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_unused_taxonomies|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_venue|node|event|form';
  $field_group->group_name = 'group_venue';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Venue Information',
    'weight' => '36',
    'children' => array(
      0 => 'field_venue_name',
      1 => 'field_venue_url',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-venue field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_venue|node|event|form'] = $field_group;

  return $export;
}
