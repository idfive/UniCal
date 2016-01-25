<?php

$plugin = array(
  'label' => t('Taxonomy 5'),
  'resource' => 'taxonomy_5',
  'name' => 'taxonomy_5',
  'entity_type' => 'taxonomy_term',
  'bundle' => 'calendar_taxonomy_5',
  'description' => t('Taxonomy 5'),
  'class' => 'IdfiveCalendarApiTaxonomyResource',
  'render_cache' => array(
    'render' => FALSE,
    'granularity' => DRUPAL_CACHE_PER_ROLE,
  ),
);
