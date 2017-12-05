<?php

/**
 * @file
 * Defines taxonomy REST resource.
 */

/**
 * Extends base taxonomy term.
 */
class UnicalApiTaxonomyResource extends \RestfulEntityBaseTaxonomyTerm {

  protected $range = 1000;

  /**
   * Overrides RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {

    $public_fields = parent::publicFieldsInfo();

    if (field_info_field('field_hide_from_submission')) {
      $public_fields['hidden_for_submit'] = array(
        'property' => 'field_hide_from_submission',
      );
    }

    return $public_fields;
  }

  /**
   * Defines ASC as the default.
   */
  public function defaultSortInfo() {

    return array('label' => 'ASC');
  }

}
