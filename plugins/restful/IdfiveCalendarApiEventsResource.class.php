<?php

require 'IdfiveCalendarApiEventsFields.class.php';

class IdfiveCalendarApiEventsResource extends IdfiveCalendarApiEventsFields {
  
  /**
   * Overrides RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {
    
    return parent::publicFieldsInfo();
  }    
}