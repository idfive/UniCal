<?php

class unicalApiTaxonomyResource extends \RestfulEntityBaseTaxonomyTerm {

  protected $range = 1000;
  
  /**
   * Overrides RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    
    $public_fields = parent::publicFieldsInfo();

    return $public_fields;
  }
  
  public function defaultSortInfo()
  {
    return array('label' => 'ASC');
  }
      
}