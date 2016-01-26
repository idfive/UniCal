<?php

/**
 * @file
 * Defines Taxonomy 2 REST endpoint.
 */

$plugin = array(
  'label' => t('Taxonomy 2'),
  'resource' => 'taxonomy_2',
  'name' => 'taxonomy_2',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'calendar_taxonomy_2',
  'description' => t('Taxonomy 2'),
  'class' => 'UnicalApiTaxonomyResource',
  'render_cache' => array(
    'render' => FALSE,
    'granularity' => DRUPAL_CACHE_PER_ROLE,
  ),
);
