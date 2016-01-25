<?php

$plugin = array(
  'resource' => 'eventsearch',
  'name' => 'eventsearch',
  'label' => t('Event Search'),
  'description' => t('Search events'),
  'data_provider_options' => array(
    'search_index' => 'events_index',
  ),
  'class' => 'unicalApiEventsSearchResource',
  'authentication_types' => TRUE,
  'authentication_optional' => TRUE,
  // Use pass_through to expose the complete search result objects. This is
  // useful while developing to allow you to know how to do the field mappings.
  //'pass_through' => TRUE,
);
