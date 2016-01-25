<?php

$plugin = array(
  'label' => t('Events'),
  'resource' => 'events',
  'name' => 'events',
  'entity_type' => 'node',
  'bundle' => 'event',
  'description' => t('Read the event content type.'),
  'allowed_origin' => '*',
  'class' => 'unicalApiEventsResource',
  'render_cache' => array(
    'render' => FALSE,
    'granularity' => DRUPAL_CACHE_PER_ROLE,
  ),
);
