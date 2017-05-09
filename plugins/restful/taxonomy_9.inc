<?php

/**
 * @file
 * Defines Taxonomy 9 REST endpoint.
 */

$plugin = array(
  'label' => t('Taxonomy 9'),
  'resource' => 'taxonomy_9',
  'name' => 'taxonomy_9',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'calendar_taxonomy_9',
  'description' => t('Taxonomy 9'),
  'class' => 'UnicalApiTaxonomyResource',
  'render_cache' => array(
    'render' => FALSE,
    'granularity' => DRUPAL_CACHE_PER_ROLE,
  ),
);
