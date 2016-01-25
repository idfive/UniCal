<?php

$plugin = array(
  'label' => t('Taxonomy 6'),
  'resource' => 'taxonomy_6',
  'name' => 'taxonomy_6',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'calendar_taxonomy_6',
  'description' => t('Taxonomy 6'),
  'class' => 'unicalApiTaxonomyResource',
  'render_cache' => array(
    'render' => FALSE,
    'granularity' => DRUPAL_CACHE_PER_ROLE,
  ),
);
