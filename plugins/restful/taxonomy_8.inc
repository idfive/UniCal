<?php

/**
 * @file
 * Defines Taxonomy 8 REST endpoint.
 */

$plugin = array(
  'label' => t('Taxonomy 8'),
  'resource' => 'taxonomy_8',
  'name' => 'taxonomy_8',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'calendar_taxonomy_8',
  'description' => t('Taxonomy 8'),
  'class' => 'UnicalApiTaxonomyResource',
  'render_cache' => array(
    'render' => FALSE,
    'granularity' => DRUPAL_CACHE_PER_ROLE,
  ),
);
