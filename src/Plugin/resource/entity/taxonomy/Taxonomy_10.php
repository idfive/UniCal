<?php
namespace Drupal\unical\Plugin\resource\entity\taxonomy;

use Drupal\restful\Plugin\resource\DataInterpreter\DataInterpreterInterface;
use Drupal\restful\Plugin\resource\Field\ResourceFieldInterface;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;

/**
 * Class Taxonomy_10
 * @package Drupal\unical\Plugin\resource\entity\taxonomy
 *
 * @Resource(
 *   name = "taxonomy_10:1.0",
 *   resource = "taxonomy_10",
 *   label = "Taxonomy_10",
 *   description = "Read the UniCal calendar_taxonomy_10 vocabulary terms.",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "taxonomy_term",
 *     "bundles": {
 *       "calendar_taxonomy_10"
 *     },
 *   },
 *   formatter = "json",
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */
class Taxonomy_10 extends ResourceEntity implements ResourceInterface {

  /**
   * Overrides RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFields() {

    $public_fields = parent::publicFields();

    return $public_fields;
  }

}
