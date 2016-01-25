<?php

/**
 * @file
 * Contains \IdfiveCalendarEventsSearchResource.
 */

class IdfiveCalendarApiEventsSearchResource extends \RestfulDataProviderSearchAPI implements \RestfulInterface {

  /**
   * Overrides \RestfulBase::publicFieldsInfo().
   */
  public function publicFieldsInfo() {

    $public_fields['id'] = array(
      'property' => 'search_api_id',
      'process_callbacks' => array(
        'intVal',
      ),
    );

    $public_fields['version_id'] = array(
      'property' => 'vid',
      'process_callbacks' => array(
        'intVal',
      ),
    );

    $public_fields['relevance'] = array(
      'property' => 'search_api_relevance',
    );
    
    $public_fields['label'] = array(
      'property' => 'title',
    );

    $public_fields['body_trimmed'] = array(
      'property' => 'body',
      'sub_property' => 'value',
      'process_callbacks' => array(
        array($this, 'processBody'),
      ),
    );

    $public_fields['image'] = array(
      'property' => 'field_image',
      'image_styles' => array('thumbnail', 'medium', 'large'),
      'process_callbacks' => array(
        array($this, 'processImage'),
      ),
    );

    $public_fields['date'] = array(
      'property' => 'field_date',
      'process_callbacks' => array(
        array($this, 'processDate'),
      ),
    );
    
    $public_fields['timezone'] = array(
      'property' => 'field_timezone',
      'process_callbacks' => array(
        array($this, 'processArrayValue'),
      ),
    );

    $public_fields['uri'] = array(
      'property' => 'nid',
      'process_callbacks' => array(
        array($this, 'processURI'),
      ),
    );

    $public_fields['address'] = array(
      'property' => 'field_address',
      'process_callbacks' => array(
        array($this, 'processAddress')
      ),
    );
    
    $public_fields['exclude_from_main_calendar'] = array(
      'property' => 'field_exclude_from_main_calendar',
      'process_callbacks' => array(
        array($this, 'processArrayValue')
      ),
    );

    

    return $public_fields;
  }

  /**
   * Functions below to return the fields we need. restful sub_property only goes 1 level deep, so wee need to parse a few arrays as well here.
   */

  // Body function
  public function processBody($data)
  {
    return text_summary(drupal_html_to_text($data['und'][0]['value'], array('<strong>','<em>')), null, 250);
  }
  
  // Image
  public function processImage($data){
    $data = $data['und'][0];
    $data['image_styles']['medium'] = image_style_url('medium', $data['uri']);
    $data['image_styles']['large'] = image_style_url('large', $data['uri']);
    return $data;
  }
  
  // Date
  public function processDate($data)
  {
    $data = $data['und'];
    
    //Get timestamps based on date as stored in DB (no timeszone conversion)
    $unixStart = strtotime($data[0]['value']);
    $unixEnd = strtotime($data[0]['value2']);
    
    //Get UNIX timestamp
    $data[0]['start_unix'] = $unixStart;
    $data[0]['end_unix'] = $unixEnd;
    
    //Specific formats for event list display
    $data[0]['start_month'] = date('M', $unixStart);
    $data[0]['start_day'] = date('j', $unixStart);
    $data[0]['start_time'] = date('g:i A', $unixStart);
    $data[0]['end_time'] = date('g:i A', $unixEnd);
      
    //Specific formats for "Add to Calendar" button (see https://addthisevent.com)
    $data[0]['start_addto'] = date('m/d/Y g:i A', $unixStart);
    $data[0]['end_addto'] = date('m/d/Y g:i A', $unixEnd);

    //Return
    return $data;
  }
  
  // Removes value from array so we have data in same format as regular events JSON
  public function processArrayValue($data)
  {
    $data = $data['und'][0]['value'];

    //Return
    return $data;
  }
  
  // URI
  public function processURI($id){
    $path = drupal_get_path_alias('node/'.$id);
    //If the path contains more than one part, get the last part
      if(strpos($path, '/') !== false){
          $parts = explode('/', $path);
          $path = $parts[sizeof($parts)-1];
      }
    return $path;
  }
  
  // Address
  public function processAddress($data){
    //Unserialize data so we have formatted address, longitude etc.
    //$data['address']['und'][0] = unserialize($data['und'][0]);
    $data['data'] = unserialize($data['und'][0]['data']);
    return $data;
  }

}
