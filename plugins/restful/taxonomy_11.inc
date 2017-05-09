<?php

/**
 * @file
 * Defines Taxonomy 11 REST endpoint.
 */

$plugin = array(
  'label' => t('Taxonomy 11'),
  'resource' => 'taxonomy_11',
  'name' => 'taxonomy_11',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'calendar_taxonomy_11',
  'description' => t('Taxonomy 11'),
  'class' => 'UnicalApiTaxonomyResource',
  'render_cache' => array(
    'render' => FALSE,
    'granularity' => DRUPAL_CACHE_PER_ROLE,
  ),
);
