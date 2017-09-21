<?php
namespace Drupal\unical\Plugin\resource\entity\node\sites;

use Drupal\restful\Http\RequestInterface;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;
use Drupal\restful\Plugin\resource\ResourceNode;

/**
 * Class Events
 * @package Drupal\unical\Plugin\resource\entity\node\sites
 *
 * @Resource(
 *   name = "sites:1.0",
 *   resource = "sites",
 *   label = "Sites",
 *   description = "Read the UniCal sites content type.",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "site"
 *     },
 *   },
 *   formatter = "json",
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */
 class Sites extends ResourceNode implements ResourceInterface {

  public function publicFields() {

    $public_fields = parent::publicFields();

    /* Taxonomy 1 */
    if (field_info_field('field_taxonomy_1_enabled')) {
      $public_fields['taxonomy_1_enabled'] = array(
        'property' => 'field_taxonomy_1_enabled',
      );
    }
    if (field_info_field('field_taxonomy_1_label')) {
      $public_fields['taxonomy_1_label'] = array(
        'property' => 'field_taxonomy_1_label',
      );
    }
    if (field_info_field('field_taxonomy_1')) {
      $public_fields['taxonomy_1_selected'] = array(
        'property' => 'field_taxonomy_1',
        'sub_property' => 'tid',
      );
    }
    $public_fields['taxonomy_1_weight'] = array(
      'callback' => array($this, 'getTaxonomyOneWeight'),
    );

    /* Taxonomy 2 */
    if (field_info_field('field_taxonomy_2_enabled')) {
      $public_fields['taxonomy_2_enabled'] = array(
        'property' => 'field_taxonomy_2_enabled',
      );
    }
    if (field_info_field('field_taxonomy_2_label')) {
      $public_fields['taxonomy_2_label'] = array(
        'property' => 'field_taxonomy_2_label',
      );
    }
    if (field_info_field('field_taxonomy_2')) {
      $public_fields['taxonomy_2_selected'] = array(
        'property' => 'field_taxonomy_2',
        'sub_property' => 'tid',
      );
    }
    $public_fields['taxonomy_2_weight'] = array(
      'callback' => array($this, 'getTaxonomyTwoWeight'),
    );

    /* Taxonomy 3 */
    if (field_info_field('field_taxonomy_3_enabled')) {
      $public_fields['taxonomy_3_enabled'] = array(
        'property' => 'field_taxonomy_3_enabled',
      );
    }
    if (field_info_field('field_taxonomy_3_label')) {
      $public_fields['taxonomy_3_label'] = array(
        'property' => 'field_taxonomy_3_label',
      );
    }
    if (field_info_field('field_taxonomy_3')) {
      $public_fields['taxonomy_3_selected'] = array(
        'property' => 'field_taxonomy_3',
        'sub_property' => 'tid',
      );
    }
    $public_fields['taxonomy_3_weight'] = array(
      'callback' => array($this, 'getTaxonomyThreeWeight'),
    );


    /* Taxonomy 4 */
    if (field_info_field('field_taxonomy_4_enabled')) {
      $public_fields['taxonomy_4_enabled'] = array(
        'property' => 'field_taxonomy_4_enabled',
      );
    }
    if (field_info_field('field_taxonomy_4_label')) {
      $public_fields['taxonomy_4_label'] = array(
        'property' => 'field_taxonomy_4_label',
      );
    }
    if (field_info_field('field_taxonomy_4')) {
      $public_fields['taxonomy_4_selected'] = array(
        'property' => 'field_taxonomy_4',
        'sub_property' => 'tid',
      );
    }
    $public_fields['taxonomy_4_weight'] = array(
      'callback' => array($this, 'getTaxonomyFourWeight'),
    );

    /* Taxonomy 5 */
    if (field_info_field('field_taxonomy_5_enabled')) {
      $public_fields['taxonomy_5_enabled'] = array(
        'property' => 'field_taxonomy_5_enabled',
      );
    }
    if (field_info_field('field_taxonomy_5_label')) {
      $public_fields['taxonomy_5_label'] = array(
        'property' => 'field_taxonomy_5_label',
      );
    }
    if (field_info_field('field_taxonomy_5')) {
      $public_fields['taxonomy_5_selected'] = array(
        'property' => 'field_taxonomy_5',
        'sub_property' => 'tid',
      );
    }
    $public_fields['taxonomy_5_weight'] = array(
      'callback' => array($this, 'getTaxonomyFiveWeight'),
    );


    /* Taxonomy 6 */
    if (field_info_field('field_taxonomy_6_enabled')) {
      $public_fields['taxonomy_6_enabled'] = array(
        'property' => 'field_taxonomy_6_enabled',
      );
    }
    if (field_info_field('field_taxonomy_6_label')) {
      $public_fields['taxonomy_6_label'] = array(
        'property' => 'field_taxonomy_6_label',
      );
    }
    if (field_info_field('field_taxonomy_6')) {
      $public_fields['taxonomy_6_selected'] = array(
        'property' => 'field_taxonomy_6',
        'sub_property' => 'tid',
      );
    }
    $public_fields['taxonomy_6_weight'] = array(
      'callback' => array($this, 'getTaxonomySixWeight'),
    );

    /* Taxonomy 8 */
    if (field_info_field('field_taxonomy_8_enabled')) {
      $public_fields['taxonomy_8_enabled'] = array(
        'property' => 'field_taxonomy_8_enabled',
      );
    }
    if (field_info_field('field_taxonomy_8_label')) {
      $public_fields['taxonomy_8_label'] = array(
        'property' => 'field_taxonomy_8_label',
      );
    }
    if (field_info_field('field_taxonomy_8')) {
      $public_fields['taxonomy_8_selected'] = array(
        'property' => 'field_taxonomy_8',
        'sub_property' => 'tid',
      );
    }
    $public_fields['taxonomy_8_weight'] = array(
      'callback' => array($this, 'getTaxonomyEightWeight'),
    );


    /* Taxonomy 9 */
    if (field_info_field('field_taxonomy_9_enabled')) {
      $public_fields['taxonomy_9_enabled'] = array(
        'property' => 'field_taxonomy_9_enabled',
      );
    }
    if (field_info_field('field_taxonomy_9_label')) {
      $public_fields['taxonomy_9_label'] = array(
        'property' => 'field_taxonomy_9_label',
      );
    }
    if (field_info_field('field_taxonomy_9')) {
      $public_fields['taxonomy_9_selected'] = array(
        'property' => 'field_taxonomy_9',
        'sub_property' => 'tid',
      );
    }
    $public_fields['taxonomy_9_weight'] = array(
      'callback' => array($this, 'getTaxonomyNineWeight'),
    );


    /* Taxonomy 10 */
    if (field_info_field('field_taxonomy_10_enabled')) {
      $public_fields['taxonomy_10_enabled'] = array(
        'property' => 'field_taxonomy_10_enabled',
      );
    }
    if (field_info_field('field_taxonomy_10_label')) {
      $public_fields['taxonomy_10_label'] = array(
        'property' => 'field_taxonomy_10_label',
      );
    }
    if (field_info_field('field_taxonomy_10')) {
      $public_fields['taxonomy_10_selected'] = array(
        'property' => 'field_taxonomy_10',
        'sub_property' => 'tid',
      );
    }
    $public_fields['taxonomy_10_weight'] = array(
      'callback' => array($this, 'getTaxonomyTenWeight'),
    );


    /* Taxonomy 11 */
    if (field_info_field('field_taxonomy_11_enabled')) {
      $public_fields['taxonomy_11_enabled'] = array(
        'property' => 'field_taxonomy_11_enabled',
      );
    }
    if (field_info_field('field_taxonomy_11_label')) {
      $public_fields['taxonomy_11_label'] = array(
        'property' => 'field_taxonomy_11_label',
      );
    }
    if (field_info_field('field_taxonomy_11')) {
      $public_fields['taxonomy_11_selected'] = array(
        'property' => 'field_taxonomy_11',
        'sub_property' => 'tid',
      );
    }
    $public_fields['taxonomy_11_weight'] = array(
      'callback' => array($this, 'getTaxonomyElevenWeight'),
    );


    /* Add to Calendar Options to exclude */
    if (field_info_field('field_add_to_calendar_exclude')) {
      $public_fields['add_to_calendar_exclude'] = array(
        'property' => 'field_add_to_calendar_exclude',
        'sub_property' => 'field_ate_id',
      );
    }

    /* General Settings */

    // Allow users to submit events
    if (field_info_field('field_allow_event_submit')) {
      $public_fields['allow_event_submit'] = array(
        'property' => 'field_allow_event_submit',
      );
    }

    // Allow users to select taxonomies when submitting
    if (field_info_field('field_allow_users_to_choose_taxo')) {
      $public_fields['allow_users_to_choose_taxonomy_when_submitting'] = array(
        'property' => 'field_allow_users_to_choose_taxo',
      );
    }

    // Allow featured events
    if (field_info_field('field_allow_featured_events')) {
      $public_fields['allow_featured_events'] = array(
        'property' => 'field_allow_featured_events',
      );
    }

    // Allow archives
    if (field_info_field('field_allow_archive')) {
      $public_fields['allow_archive'] = array(
        'property' => 'field_allow_archive',
      );
    }

    // The key for the google maps api
    if (field_info_field('field_google_maps_api_key')) {
      $public_fields['google_maps_api_key'] = array(
        'property' => 'field_google_maps_api_key',
      );
    }

    // The default image for events in the calendar
    if (field_info_field('field_default_event_image')) {
      $public_fields['default_event_image'] = array(
        'property' => 'field_default_event_image',
        'image_styles' => array('large'),
      );
    }

    // The text that displays above filters
    if (field_info_field('field_custom_text_above_filters')) {
      $public_fields['text_above_filters'] = array(
        'property' => 'field_custom_text_above_filters',
      );
    }

    // Custom help link
    if (field_info_field('field_calendar_help_link')) {
      $public_fields['help_link'] = array(
        'property' => 'field_calendar_help_link',
        'sub_property' => 'url',
      );
    }

    // Custom help link for image
    if (field_info_field('field_calendar_image_help_link')) {
      $public_fields['help_link_image'] = array(
        'property' => 'field_calendar_image_help_link',
        'sub_property' => 'url',
      );
    }

    // Is this a main calendar site?
    if (field_info_field('field_main_calendar_site')) {
      $public_fields['main_calendar_site'] = array(
        'property' => 'field_main_calendar_site',
      );
    }

    // The number of results per page
    if (field_info_field('field_number_results_per_page')) {
      $public_fields['number_results_per_page'] = array(
        'property' => 'field_number_results_per_page',
      );
    }

    // Custom text above sidebar
    if (field_info_field('field_custom_text_above_sidebar')) {
      $public_fields['text_above_sidebar'] = array(
        'property' => 'field_custom_text_above_sidebar',
        'sub_property' => 'value',
      );
    }

    return $public_fields;
  }

  public function getTaxonomyOneWeight() {
    $voc = taxonomy_vocabulary_machine_name_load('calendar_taxonomy_1');
    return $voc->weight;
  }

  public function getTaxonomyTwoWeight() {
    $voc = taxonomy_vocabulary_machine_name_load('calendar_taxonomy_2');
    return $voc->weight;
  }

  public function getTaxonomyThreeWeight() {
    $voc = taxonomy_vocabulary_machine_name_load('calendar_taxonomy_3');
    return $voc->weight;
  }

  public function getTaxonomyFourWeight() {
    $voc = taxonomy_vocabulary_machine_name_load('calendar_taxonomy_4');
    return $voc->weight;
  }

  public function getTaxonomyFiveWeight() {
    $voc = taxonomy_vocabulary_machine_name_load('calendar_taxonomy_5');
    return $voc->weight;
  }

  public function getTaxonomySixWeight() {
    $voc = taxonomy_vocabulary_machine_name_load('calendar_taxonomy_6');
    return $voc->weight;
  }

  public function getTaxonomyEightWeight() {
    $voc = taxonomy_vocabulary_machine_name_load('calendar_taxonomy_8');
    return $voc->weight;
  }

  public function getTaxonomyNineWeight() {
    $voc = taxonomy_vocabulary_machine_name_load('calendar_taxonomy_9');
    return $voc->weight;
  }

  public function getTaxonomyTenWeight() {
    $voc = taxonomy_vocabulary_machine_name_load('calendar_taxonomy_10');
    return $voc->weight;
  }

  public function getTaxonomyElevenWeight() {
    $voc = taxonomy_vocabulary_machine_name_load('calendar_taxonomy_11');
    return $voc->weight;
  }
}
