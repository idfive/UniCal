<?php
namespace Drupal\unical\Plugin\resource\entity\node\events;

use Drupal\restful\Http\RequestInterface;
use Drupal\restful\Plugin\resource\ResourceEntity;
use Drupal\restful\Plugin\resource\ResourceInterface;
use Drupal\restful\Plugin\resource\ResourceNode;
/**
 * Class Events
 * @package Drupal\unical\Plugin\resource\entity\node\events
 *
 * @Resource(
 *   name = "events:1.0",
 *   resource = "events",
 *   label = "Events",
 *   description = "Read the UniCal event content type.",
 *   authenticationTypes = TRUE,
 *   authenticationOptional = TRUE,
 *   dataProvider = {
 *     "entityType": "node",
 *     "bundles": {
 *       "event"
 *     },
 *   },
 *   formatter = "json",
 *   majorVersion = 1,
 *   minorVersion = 0
 * )
 */
 class Events extends ResourceNode implements ResourceInterface {

  public function publicFields() {
    $add = true;

    $public_fields = parent::publicFields();

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
    if (field_info_field('field_address')) {
      $public_fields['address'] = array(
        'property' => 'field_address',
        'process_callbacks' => array(
          array($this, 'processAddress'),
        ),
      );
    }

    // Map Settings -------------------------.
    if (field_info_field('field_map_zoom')) {
      $public_fields['map_zoom'] = array(
        'property' => 'field_map_zoom',
      );
    }

    if (field_info_field('field_map_center_lat')) {
      $public_fields['map_center_lat'] = array(
        'property' => 'field_map_center_lat',
      );
    }

    if (field_info_field('field_map_center_lng')) {
      $public_fields['map_center_lng'] = array(
        'property' => 'field_map_center_lng',
      );
    }

    // Taxonomies ----------------------.
    if (field_info_field('field_taxonomy_1')) {
      $public_fields['taxonomy_1'] = array(
        'property' => 'field_taxonomy_1',
        'sub_property' => 'tid',
      );
    }

    if (field_info_field('field_taxonomy_2')) {
      $public_fields['taxonomy_2'] = array(
        'property' => 'field_taxonomy_2',
        'sub_property' => 'tid',
      );
    }

    if (field_info_field('field_taxonomy_3')) {
      $public_fields['taxonomy_3'] = array(
        'property' => 'field_taxonomy_3',
        'sub_property' => 'tid',
      );
    }

    if (field_info_field('field_taxonomy_4')) {
      $public_fields['taxonomy_4'] = array(
        'property' => 'field_taxonomy_4',
        'sub_property' => 'tid',
      );
    }

    if (field_info_field('field_taxonomy_5')) {
      $public_fields['taxonomy_5'] = array(
        'property' => 'field_taxonomy_5',
        'sub_property' => 'tid',
      );
    }

    if (field_info_field('field_taxonomy_6')) {
      $public_fields['taxonomy_6'] = array(
        'property' => 'field_taxonomy_6',
        'sub_property' => 'tid',
      );
    }

    if (field_info_field('field_taxonomy_8')) {
      $public_fields['taxonomy_8'] = array(
        'property' => 'field_taxonomy_8',
        'sub_property' => 'tid',
      );
    }

    if (field_info_field('field_taxonomy_9')) {
      $public_fields['taxonomy_9'] = array(
        'property' => 'field_taxonomy_9',
        'sub_property' => 'tid',
      );
    }

    if (field_info_field('field_taxonomy_10')) {
      $public_fields['taxonomy_10'] = array(
        'property' => 'field_taxonomy_10',
        'sub_property' => 'tid',
      );
    }

    if (field_info_field('field_taxonomy_11')) {
      $public_fields['taxonomy_11'] = array(
        'property' => 'field_taxonomy_11',
        'sub_property' => 'tid',
      );
    }

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
    if (field_info_field('field_rsvp_text')) {
      $public_fields['rsvp_text'] = array(
        'property' => 'field_rsvp_text',
      );
    }

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
   * Formats a date into all the formats we need on front-end
   */
  private function formatDate($date) {
    //$date = $date['und'];
    //To store the formats
    $dateFormats = array();

    // Calculate UNIX timestamps
    $unix_start = strtotime($date['value']);
    $unix_end = strtotime($date['value2']);

    // Store UNIX timestamps
    $dateFormats['start_unix'] = $unix_start;
    $dateFormats['end_unix'] = $unix_end;

    // Specific formats for event list display.
    $dateFormats['start_month'] = date('M', $unix_start);
    $dateFormats['start_day'] = date('j', $unix_start);
    $dateFormats['start_time'] = date('g:i A', $unix_start);
    $dateFormats['end_time'] = date('g:i A', $unix_end);

    // Specific formats for event detail display.
    $dateFormats['start_date'] = date('F j, Y', $unix_start);
    $dateFormats['end_date'] = date('F j, Y', $unix_end);

    // Specific formats for "Add to Calendar" button
    // (see https://addthisevent.com)
    $dateFormats['start_addto'] = date('m/d/Y g:i A', $unix_start);
    $dateFormats['end_addto'] = date('m/d/Y g:i A', $unix_end);

    // Return formats
    return $dateFormats;
    //return $date;
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
    // Remove special chars
    $path = preg_replace("/(™|®|©|&trade;|&reg;|&copy;|&#8482;|&#174;|&#169;)/", "", $path);

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

    // To store dates
    $dates = array();

    // If this is a repeating event
    if(sizeof($data) > 1) {

      //Get Request (so we can access filters)
      // $request = $this->getRequest();
      $request = drupal_get_query_parameters();

      // Loop through each date
      foreach ($data as $date) {

        // Get formatted date
        $formatted_date = $this->formatDate($date);

        //Default from date is now
        // The from date passed to the filter
        $from_date = time();
        // The to date passed to the filter
        $to_date = false;
        $exclude_date = false;
        $query = drupal_get_query_parameters();

        // Check that we have a filter
        if(isset($request['filter']) && isset($request['filter']['date'])) {
          $filter_date = $request['filter']['date'];

          if(isset($filter_date['value'][0])) {
            $from_date = strtotime($filter_date['value'][0]);
          }

          if(isset($filter_date['value'][1])) {
            $to_date = strtotime($filter_date['value'][1]);
          }
        }

        // Exclude any event dates that do meet the start date criteria. If the end date
        // is less than the from date passed to the filter.
        if($formatted_date['end_unix'] < $from_date) {
          $exclude_date = true;
          $add = false;
        }

        // Exclude any event dates that do meet the end date criteria
        // if there is an end date, and that date is greater than the to date passed in the filter
        if($to_date && $formatted_date['end_unix']  > $to_date) {
          $exclude_date = true;
          $add = false;
        }

        // Push dates not marked to be excluded
        if(!$exclude_date) {
          array_push($dates, $formatted_date);
        }
      }

    } else {

      $formatted_date = $this->formatDate($data[0]);
      array_push($dates, $formatted_date);

    }

    // exit;
    // Return dates
    return $dates;
  }

  /**
   * Process the date for the clndr feature.
   */
  public function processClndrDate($data) {

    foreach ($data as $key => $date) {
        return $data[$key]['value'];
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
