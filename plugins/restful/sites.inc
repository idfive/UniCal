<?php

/**
 * @file
 * Defines Sites endpoint.
 */

$plugin = array(
  'label' => t('Sites'),
  'resource' => 'sites',
  'name' => 'sites',
  'entity_type' => 'node',
  'bundle' => 'site',
  'description' => t('Read the site content type.'),
  'class' => 'UnicalApiSitesResource',
  'render_cache' => array(
    'render' => FALSE,
    'granularity' => DRUPAL_CACHE_PER_ROLE,
  ),
);
