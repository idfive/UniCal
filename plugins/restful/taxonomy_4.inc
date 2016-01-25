<?php

$plugin = array(
  'label' => t('Taxonomy 4'),
  'resource' => 'taxonomy_4',
  'name' => 'taxonomy_4',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'calendar_taxonomy_4',
  'description' => t('Taxonomy 4'),
  'class' => 'unicalApiTaxonomyResource',
  'render_cache' => array(
    'render' => FALSE,
    'granularity' => DRUPAL_CACHE_PER_ROLE,
  ),
);
