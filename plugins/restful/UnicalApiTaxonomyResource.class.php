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

    // Hide from fiilter
    if (field_info_field('field_hide_from_filter')) {
      $public_fields['hide_from_filter'] = array(
        'property' => 'field_hide_from_filter',
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
