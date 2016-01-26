<?php

/**
 * @file
 * Defines events REST resource.
 */

require 'UnicalApiEventsFields.class.php';

/**
 * Extend fields.
 */
class UnicalApiEventsResource extends UnicalApiEventsFields {

  /**
   * Overrides RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {

    return parent::publicFieldsInfo();
  }

}
