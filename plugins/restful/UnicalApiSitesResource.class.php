<?php

/**
 * @file
 * Defines taxonomy REST resource.
 */

/**
 * Extends base node.
 */
class UnicalApiSitesResource extends RestfulEntityBaseNode {

  /**
   * Overrides RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {

    $public_fields = parent::publicFieldsInfo();

    /* Taxonomy 1 */

    $public_fields['taxonomy_1_enabled'] = array(
      'property' => 'field_taxonomy_1_enabled',
    );

    $public_fields['taxonomy_1_label'] = array(
      'property' => 'field_taxonomy_1_label',
    );

    $public_fields['taxonomy_1_selected'] = array(
      'property' => 'field_taxonomy_1',
      'sub_property' => 'tid',
    );

    /* Taxonomy 2 */

    $public_fields['taxonomy_2_enabled'] = array(
      'property' => 'field_taxonomy_2_enabled',
    );

    $public_fields['taxonomy_2_label'] = array(
      'property' => 'field_taxonomy_2_label',
    );

    $public_fields['taxonomy_2_selected'] = array(
      'property' => 'field_taxonomy_2',
      'sub_property' => 'tid',
    );

    /* Taxonomy 3 */

    $public_fields['taxonomy_3_enabled'] = array(
      'property' => 'field_taxonomy_3_enabled',
    );

    $public_fields['taxonomy_3_label'] = array(
      'property' => 'field_taxonomy_3_label',
    );

    $public_fields['taxonomy_3_selected'] = array(
      'property' => 'field_taxonomy_3',
      'sub_property' => 'tid',
    );

    /* Taxonomy 4 */

    $public_fields['taxonomy_4_enabled'] = array(
      'property' => 'field_taxonomy_4_enabled',
    );

    $public_fields['taxonomy_4_label'] = array(
      'property' => 'field_taxonomy_4_label',
    );

    $public_fields['taxonomy_4_selected'] = array(
      'property' => 'field_taxonomy_4',
      'sub_property' => 'tid',
    );

    /* Taxonomy 5 */

    $public_fields['taxonomy_5_enabled'] = array(
      'property' => 'field_taxonomy_5_enabled',
    );

    $public_fields['taxonomy_5_label'] = array(
      'property' => 'field_taxonomy_5_label',
    );

    $public_fields['taxonomy_5_selected'] = array(
      'property' => 'field_taxonomy_5',
      'sub_property' => 'tid',
    );

    /* Taxonomy 6 */

    $public_fields['taxonomy_6_enabled'] = array(
      'property' => 'field_taxonomy_6_enabled',
    );

    $public_fields['taxonomy_6_label'] = array(
      'property' => 'field_taxonomy_6_label',
    );

    $public_fields['taxonomy_6_selected'] = array(
      'property' => 'field_taxonomy_6',
      'sub_property' => 'tid',
    );

    /* Add to Calendar Options to exclude */

    $public_fields['add_to_calendar_exclude'] = array(
      'property' => 'field_add_to_calendar_exclude',
      'sub_property' => 'field_ate_id',
    );

    /* General Settings */

    $public_fields['allow_event_submit'] = array(
      'property' => 'field_allow_event_submit',
    );

    $public_fields['allow_featured_events'] = array(
      'property' => 'field_allow_featured_events',
    );

    $public_fields['google_maps_api_key'] = array(
      'property' => 'field_google_maps_api_key',
    );

    $public_fields['default_event_image'] = array(
      'property' => 'field_default_event_image',
      'image_styles' => array('large'),
    );

    $public_fields['text_above_filters'] = array(
      'property' => 'field_custom_text_above_filters',
    );

    $public_fields['help_link'] = array(
      'property' => 'field_calendar_help_link',
      'sub_property' => 'url',
    );

    $public_fields['main_calendar_site'] = array(
      'property' => 'field_main_calendar_site',
    );
    
    if (field_info_field('field_custom_text_above_sidebar')) {
      $public_fields['text_above_sidebar'] = array(
        'property' => 'field_custom_text_above_sidebar',
        'sub_property' => 'value',
      );
    }

    return $public_fields;
  }

}
