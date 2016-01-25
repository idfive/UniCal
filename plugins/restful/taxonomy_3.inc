<?php

$plugin = array(
  'label' => t('Taxonomy 3'),
  'resource' => 'taxonomy_3',
  'name' => 'taxonomy_3',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'calendar_taxonomy_3',
  'description' => t('Taxonomy 3'),
  'class' => 'unicalApiTaxonomyResource',
  'render_cache' => array(
    'render' => FALSE,
    'granularity' => DRUPAL_CACHE_PER_ROLE,
  ),
);
