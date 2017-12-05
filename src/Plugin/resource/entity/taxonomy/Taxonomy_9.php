<?php
namespace Drupal\unical\Plugin\resource\entity\taxonomy;

use Drupal\restful\Plugin\resource\DataInterpreter\DataInterpreterInterface;
use Drupal\restful\Plugin\resource\Field\ResourceFieldInterface;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class Taxonomy_9
 * @package Drupal\unical\Plugin\resource\entity\taxonomy
 *
 * @Resource(
 *   name = "taxonomy_9:1.0",
 *   resource = "taxonomy_9",
 *   label = "Taxonomy_9",
 *   description = "Read the UniCal calendar_taxonomy_9 vocabulary terms.",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "calendar_taxonomy_9"
 *     },
 *   },
 *   formatter = "json",
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */
class Taxonomy_9 extends ResourceEntity implements ResourceInterface {

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

    return $public_fields;
  }

}
