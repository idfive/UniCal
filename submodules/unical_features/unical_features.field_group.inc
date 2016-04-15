<?php
/**
 * @file
 * unical_features.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function unical_features_field_group_info() {
  $field_groups = array();

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
    'weight' => '44',
    'children' => array(
      0 => 'field_featured',
      1 => 'date_repeat_entity_master_uuid',
      2 => 'date_repeat_entity_clone_state',
      3 => 'field_promote_in_feed',
      4 => 'field_repeating_date_description',
      5 => 'field_exclude_from_main_calendar',
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
  $field_groups['group_admin|node|event|form'] = $field_group;

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
    'weight' => '46',
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
  $field_groups['group_audience|node|event|form'] = $field_group;

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
    'weight' => '45',
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
  $field_groups['group_category|node|event|form'] = $field_group;

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
    'weight' => '40',
    'children' => array(
      0 => 'field_contact_name',
      1 => 'field_contact_phone',
      2 => 'field_contact_email',
      3 => 'field_same_as_submitter',
      4 => 'field_organizer_facebook',
      5 => 'field_organizer_twitter',
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
  $field_groups['group_contact|node|event|form'] = $field_group;

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
    'weight' => '38',
    'children' => array(
      0 => 'field_free_event',
      1 => 'field_cost',
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
  $field_groups['group_cost|node|event|form'] = $field_group;

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
  $field_groups['group_date|node|event|form'] = $field_group;

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
  $field_groups['group_department|node|event|form'] = $field_group;

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
    'weight' => '14',
    'children' => array(
      0 => 'group_location',
      1 => 'group_venue',
      2 => 'group_rsvp',
      3 => 'group_contact',
      4 => 'group_date',
      5 => 'group_cost',
      6 => 'group_social_media',
      7 => 'group_admin',
      8 => 'group_submitter',
      9 => 'group_taxonomies',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-general field-group-tabs',
      ),
    ),
  );
  $field_groups['group_general|node|event|form'] = $field_group;

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
  $field_groups['group_help_text|node|site|form'] = $field_group;

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
  $field_groups['group_location|node|event|form'] = $field_group;

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
    'weight' => '39',
    'children' => array(
      0 => 'field_ticket_url',
      1 => 'field_how_to_rsvp',
      2 => 'field_rsvp_phone',
      3 => 'field_rsvp_email',
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
  $field_groups['group_rsvp|node|event|form'] = $field_group;

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
      0 => 'field_allow_event_submit',
      1 => 'field_google_maps_api_key',
      2 => 'field_default_event_image',
      3 => 'field_allow_featured_events',
      4 => 'field_add_to_calendar_exclude',
      5 => 'field_main_calendar_site',
      6 => 'field_number_results_per_page',
      7 => 'field_allow_users_to_choose_taxo',
      8 => 'field_allow_archive',
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
  $field_groups['group_site_specific|node|site|form'] = $field_group;

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
    'weight' => '42',
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
  $field_groups['group_social_media|node|event|form'] = $field_group;

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
    'weight' => '41',
    'children' => array(
      0 => 'field_submitter_name',
      1 => 'field_submitter_phone',
      2 => 'field_submitter_email',
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
  $field_groups['group_submitter|node|event|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_taxonomies|node|event|form';
  $field_group->group_name = 'group_taxonomies';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'event';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general';
  $field_group->data = array(
    'label' => 'Taxonomies',
    'weight' => '43',
    'children' => array(
      0 => 'group_category',
      1 => 'group_audience',
      2 => 'group_department',
      3 => 'group_unused_taxonomies',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Taxonomies',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-taxonomies field-group-tab',
        'description' => 'Tags associate events to a variety of Howard calendars. Uncheck any irrelevant tags.',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_taxonomies|node|event|form'] = $field_group;

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
      0 => 'group_taxonomy_1',
      1 => 'group_taxonomy_2',
      2 => 'group_taxonomy_3',
      3 => 'group_taxonomy_4',
      4 => 'group_taxonomy_5',
      5 => 'group_taxonomy_6',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-taxonomies field-group-tabs',
      ),
    ),
  );
  $field_groups['group_taxonomies|node|site|form'] = $field_group;

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
    'label' => 'School',
    'weight' => '5',
    'children' => array(
      0 => 'field_taxonomy_1',
      1 => 'field_taxonomy_1_enabled',
      2 => 'field_taxonomy_1_label',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'School',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_taxonomy_1|node|site|form'] = $field_group;

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
    'label' => 'Audience',
    'weight' => '6',
    'children' => array(
      0 => 'field_taxonomy_2',
      1 => 'field_taxonomy_2_enabled',
      2 => 'field_taxonomy_2_label',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Audience',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_taxonomy_2|node|site|form'] = $field_group;

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
    'label' => 'Category',
    'weight' => '7',
    'children' => array(
      0 => 'field_taxonomy_3',
      1 => 'field_taxonomy_3_enabled',
      2 => 'field_taxonomy_3_label',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Category',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-taxonomy-3 field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_taxonomy_3|node|site|form'] = $field_group;

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
  $field_groups['group_taxonomy_4|node|site|form'] = $field_group;

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
  $field_groups['group_taxonomy_5|node|site|form'] = $field_group;

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
  $field_groups['group_taxonomy_6|node|site|form'] = $field_group;

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
  $field_groups['group_unused_taxonomies|node|event|form'] = $field_group;

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
  $field_groups['group_venue|node|event|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Admin Settings');
  t('Audience');
  t('Category');
  t('Cost');
  t('Date/Time');
  t('Event Contact Info');
  t('General');
  t('Help Text');
  t('Location');
  t('RSVP');
  t('School');
  t('School/Department');
  t('Site Specific Settings');
  t('Social Media');
  t('Submitter Contact Info');
  t('Taxonomies');
  t('Taxonomy 4');
  t('Taxonomy 5');
  t('Taxonomy 6');
  t('Unused taxonomies');
  t('Venue Information');

  return $field_groups;
}
