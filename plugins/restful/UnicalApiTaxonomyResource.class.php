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

    return $public_fields;
  }

  /**
   * Defines ASC as the default.
   */
  public function defaultSortInfo() {

    return array('label' => 'ASC');
  }

}
