<?php

/**
 * @file
 * Defines Taxonomy 10 REST endpoint.
 */

$plugin = array(
  'label' => t('Taxonomy 10'),
  'resource' => 'taxonomy_10',
  'name' => 'taxonomy_10',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'calendar_taxonomy_10',
  'description' => t('Taxonomy 10'),
  'class' => 'UnicalApiTaxonomyResource',
  'render_cache' => array(
    'render' => FALSE,
    'granularity' => DRUPAL_CACHE_PER_ROLE,
  ),
);
