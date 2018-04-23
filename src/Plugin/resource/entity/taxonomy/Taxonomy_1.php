<?php
namespace Drupal\unical\Plugin\resource\entity\taxonomy;

use Drupal\restful\Plugin\resource\DataInterpreter\DataInterpreterInterface;
use Drupal\restful\Plugin\resource\Field\ResourceFieldInterface;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class Taxonomy_1
 * @package Drupal\unical\Plugin\resource\entity\taxonomy
 *
 * @Resource(
 *   name = "taxonomy_1:1.0",
 *   resource = "taxonomy_1",
 *   label = "Taxonomy_1",
 *   description = "Read the UniCal calendar_taxonomy_1 vocabulary terms.",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "calendar_taxonomy_1"
 *     },
 *   },
 *   formatter = "json",
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */
class Taxonomy_1 extends ResourceEntity implements ResourceInterface {

  /**
   * Overrides RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFields() {

    $public_fields = parent::publicFields();

    // Hide from submit form or not -------------------------.
    if (field_info_field('field_hide_from_submission')) {
      $public_fields['hidden_for_submit'] = array(
        'property' => 'field_hide_from_submission',
      );
    }

    // Hide from fiilter
    if (field_info_field('field_hide_from_filter')) {
      $public_fields['hide_from_filter'] = array(
        'property' => 'field_hide_from_filter',
      );
    }
    
    return $public_fields;
  }

}
