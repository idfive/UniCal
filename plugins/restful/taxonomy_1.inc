<?php

/**
 * @file
 * Defines Taxonomy 1 REST endpoint.
 */

$plugin = array(
  'label' => t('Taxonomy 1'),
  'resource' => 'taxonomy_1',
  'name' => 'taxonomy_1',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'calendar_taxonomy_1',
  'description' => t('Taxonomy 1'),
  'class' => 'UnicalApiTaxonomyResource',
  'render_cache' => array(
    'render' => FALSE,
    'granularity' => DRUPAL_CACHE_PER_ROLE,
  ),
);
