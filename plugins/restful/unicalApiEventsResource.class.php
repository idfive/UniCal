<?php

require 'unicalApiEventsFields.class.php';

class unicalApiEventsResource extends unicalApiEventsFields {
  
  /**
   * Overrides RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    
    return parent::publicFieldsInfo();
  }    
}