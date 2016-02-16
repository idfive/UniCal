<?php

/**
 * @file
 * Defines events fields.
 */

/**
 * Extends base node.
 */
class UnicalApiEventsFields extends RestfulEntityBaseNode {

  // Override by passing range in the API call, but cannot exceed this number.
  protected $range = 1000;

  /**
   * Overrides RestfulEntityBaseNode::publicFieldsInfo().
   */
  public function publicFieldsInfo() {

    $public_fields = parent::publicFieldsInfo();

    $public_fields['body'] = array(
      'property' => 'body',
      'sub_property' => 'value',
    );

    $public_fields['body_trimmed'] = array(
      'property' => 'body',
      'sub_property' => 'value',
      'process_callbacks' => array(
        array($this, 'processBody'),
      ),
    );

    $public_fields['summary'] = array(
      'property' => 'body',
      'sub_property' => 'summary',
    );

    $public_fields['image'] = array(
      'property' => 'field_image',
      'image_styles' => array('thumbnail', 'medium', 'large'),
    );

    $public_fields['date'] = array(
      'property' => 'field_date',
      'process_callbacks' => array(
        array($this, 'processDate'),
      ),
    );

    $public_fields['clndrDate'] = array(
      'property' => 'field_date',
      'process_callbacks' => array(
        array($this, 'processClndrDate'),
      ),
    );

    $public_fields['timezone'] = array(
      'property' => 'field_timezone',
    );

    $public_fields['uri'] = array(
      'property' => 'nid',
      'process_callbacks' => array(
        array($this, 'processUri'),
      ),
    );

    // Address -------------------------.
    $public_fields['address'] = array(
      'property' => 'field_address',
      'process_callbacks' => array(
        array($this, 'processAddress'),
      ),
    );

    // Taxonomies ----------------------.
    $public_fields['taxonomy_1'] = array(
      'property' => 'field_taxonomy_1',
      'sub_property' => 'tid',
    );

    $public_fields['taxonomy_2'] = array(
      'property' => 'field_taxonomy_2',
      'sub_property' => 'tid',
    );

    $public_fields['taxonomy_3'] = array(
      'property' => 'field_taxonomy_3',
      'sub_property' => 'tid',
    );

    $public_fields['taxonomy_4'] = array(
      'property' => 'field_taxonomy_4',
      'sub_property' => 'tid',
    );

    $public_fields['taxonomy_5'] = array(
      'property' => 'field_taxonomy_5',
      'sub_property' => 'tid',
    );

    $public_fields['taxonomy_6'] = array(
      'property' => 'field_taxonomy_6',
      'sub_property' => 'tid',
    );

    // Venue --------------------------.
    $public_fields['venue_name'] = array(
      'property' => 'field_venue_name',
    );

    $public_fields['venue_url'] = array(
      'property' => 'field_venue_url',
    );

    // Cost ----------------------------.
    $public_fields['cost'] = array(
      'property' => 'field_cost',
    );

    $public_fields['free'] = array(
      'property' => 'field_free_event',
    );

    // RSVP ------------------------------.
    $public_fields['rsvp_ticket'] = array(
      'property' => 'field_ticket_url',
    );

    $public_fields['rsvp_how_to'] = array(
      'property' => 'field_how_to_rsvp',
    );

    $public_fields['rsvp_phone'] = array(
      'property' => 'field_rsvp_phone',
    );

    $public_fields['rsvp_email'] = array(
      'property' => 'field_rsvp_email',
    );

    // Organizer Info ----------------------.
    $public_fields['organizer_name'] = array(
      'property' => 'field_contact_name',
    );

    $public_fields['organizer_phone'] = array(
      'property' => 'field_contact_phone',
    );

    $public_fields['organizer_email'] = array(
      'property' => 'field_contact_email',
    );

    $public_fields['organizer_facebook'] = array(
      'property' => 'field_organizer_facebook',
    );

    $public_fields['organizer_twitter'] = array(
      'property' => 'field_organizer_twitter',
    );

    $public_fields['organizer_same_as_submitter'] = array(
      'property' => 'field_same_as_submitter',
    );

    // Submitter Info ----------------------.
    $public_fields['submitter_name'] = array(
      'property' => 'field_submitter_name',
    );

    $public_fields['submitter_phone'] = array(
      'property' => 'field_submitter_phone',
    );

    $public_fields['submitter_email'] = array(
      'property' => 'field_submitter_email',
    );

    // Social Media -----------------------.
    $public_fields['event_website'] = array(
      'property' => 'field_contact_website',
    );
    $public_fields['event_facebook'] = array(
      'property' => 'field_social_facebook',
    );

    $public_fields['event_twitter'] = array(
      'property' => 'field_social_twitter',
    );

    // Admin -----------------------.
    $public_fields['featured'] = array(
      'property' => 'field_featured',
    );

    $public_fields['promoted'] = array(
      'property' => 'field_promote_in_feed',
    );

    $public_fields['repeating_date_description'] = array(
      'property' => 'field_repeating_date_description',
    );

    $public_fields['exclude_from_main_calendar'] = array(
      'property' => 'field_exclude_from_main_calendar',
    );

    return $public_fields;
  }

  /**
   * Define the default sort.
   */
  public function defaultSortInfo() {

    return array('date' => 'ASC');
  }

  /**
   * Process the URI.
   */
  public function processUri($id) {

    // Get Drupal path.
    $path = drupal_get_path_alias('node/' . $id);

    // If the path contains more than one part, get the last part.
    if (strpos($path, '/') !== FALSE) {
      $parts = explode('/', $path);
      $path = $parts[sizeof($parts) - 1];
    }

    // Return.
    return $path;
  }

  /**
   * Process the Date.
   */
  public function processDate($data) {

    // Loop through each date.
    foreach ($data as $key => $date) {

      // Get timestamps based on date as stored in DB (no timeszone conversion).
      $unix_start = strtotime($data[$key]['value']);
      $unix_end = strtotime($data[$key]['value2']);

      if ($unix_start >= time()) {
        // If date is not in the past
        // Get UNIX timestamp.
        $data[$key]['start_unix'] = $unix_start;
        $data[$key]['end_unix'] = $unix_end;

        // Specific formats for event list display.
        $data[$key]['start_month'] = date('M', $unix_start);
        $data[$key]['start_day'] = date('j', $unix_start);
        $data[$key]['start_time'] = date('g:i A', $unix_start);
        $data[$key]['end_time'] = date('g:i A', $unix_end);

        // Specific formats for event detail display.
        $data[$key]['start_date'] = date('F j, Y', $unix_start);
        $data[$key]['end_date'] = date('F j, Y', $unix_end);

        // Specific formats for "Add to Calendar" button
        // (see https://addthisevent.com)
        $data[$key]['start_addto'] = date('m/d/Y g:i A', $unix_start);
        $data[$key]['end_addto'] = date('m/d/Y g:i A', $unix_end);

      }
      else {
        // Disregard this date, since it is past.
        unset($data[$key]);

      }

    }

    // Return (and reset array values).
    return $data = array_values($data);
  }

  /**
   * Process the date for the clndr feature.
   */
  public function processClndrDate($data) {

    foreach ($data as $key => $date) {
      $unix_start = strtotime($data[$key]['value']);

      if ($unix_start >= time()) {
        // If date is not in the past.
        return $data[$key]['value'];
      }
    }
  }

  /**
   * Process the Address.
   */
  public function processAddress($data) {

    $data['full_address'] = '';
    
    if(!empty($data['thoroughfare'])) {
      $data['full_address'] .= $data['thoroughfare'] . ', ';
    }
    
    if(!empty($data['premise'])) {
      $data['full_address'] .= $data['premise'] . ', ';
    }
    
    if(!empty($data['locality'])) { //City
      $data['full_address'] .= $data['locality'] . ' ';
    }
    
    if(!empty($data['administrative_area'])) { //State
      $data['full_address'] .= $data['administrative_area'] . ' ';
    }
    
    if(!empty($data['postal_code'])) { //Zip
      $data['full_address'] .= $data['postal_code'];
    }
    
    if(!empty($data['country']) && $data['full_address'] !== '') {
      $data['full_address'] .= ', ' . $data['country'];
    }
    
    $dirty_strings = array(' , ', ',,');
    $clean_strings = array(', ', ',');
    
    //Cleanup
    $data['full_address'] = str_replace($dirty_strings, $clean_strings, $data['full_address']);
    
    return $data;
  }

  /**
   * Process the Body.
   */
  public function processBody($data) {

    return text_summary(drupal_html_to_text($data, array('<strong>', '<em>')), NULL, 250);
  }

}
