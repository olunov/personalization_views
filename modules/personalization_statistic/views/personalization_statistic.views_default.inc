<?php

/**
 * @file
 * Contains default views for showing statistic and suggestions.
 */

/**
 * Implements hook_views_default_views().
 */
function personalization_statistic_views_default_views() {
  $views = array();

  $view = new view();
  $view->name = 'personalization_views_statistic';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Personalization Views Statistic';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Personalization Statistic';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view personalization statistic';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'name_1' => 'name_1',
    'pages' => 'pages',
    'location' => 'location',
    'searches' => 'searches',
    'score' => 'score',
  );
  $handler->display->display_options['style_options']['default'] = 'score';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'pages' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'location' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'searches' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'score' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Field: Taxonomy vocabulary: Name */
  $handler->display->display_options['fields']['name_1']['id'] = 'name_1';
  $handler->display->display_options['fields']['name_1']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['name_1']['field'] = 'name';
  $handler->display->display_options['fields']['name_1']['label'] = 'Vocabulary';
  /* Field: SUM(Personalization User Scores: Term views) */
  $handler->display->display_options['fields']['pages']['id'] = 'pages';
  $handler->display->display_options['fields']['pages']['table'] = 'personalization_user_scores';
  $handler->display->display_options['fields']['pages']['field'] = 'pages';
  $handler->display->display_options['fields']['pages']['group_type'] = 'sum';
  $handler->display->display_options['fields']['pages']['label'] = 'Views';
  /* Field: SUM(Personalization User Scores: Term location) */
  $handler->display->display_options['fields']['location']['id'] = 'location';
  $handler->display->display_options['fields']['location']['table'] = 'personalization_user_scores';
  $handler->display->display_options['fields']['location']['field'] = 'location';
  $handler->display->display_options['fields']['location']['group_type'] = 'sum';
  $handler->display->display_options['fields']['location']['label'] = 'Location';
  /* Field: SUM(Personalization User Scores: Term searching) */
  $handler->display->display_options['fields']['searches']['id'] = 'searches';
  $handler->display->display_options['fields']['searches']['table'] = 'personalization_user_scores';
  $handler->display->display_options['fields']['searches']['field'] = 'searches';
  $handler->display->display_options['fields']['searches']['group_type'] = 'sum';
  $handler->display->display_options['fields']['searches']['label'] = 'Searching';
  /* Field: SUM(Personalization User Scores: Term Score) */
  $handler->display->display_options['fields']['score']['id'] = 'score';
  $handler->display->display_options['fields']['score']['table'] = 'personalization_user_scores';
  $handler->display->display_options['fields']['score']['field'] = 'score';
  $handler->display->display_options['fields']['score']['group_type'] = 'sum';
  $handler->display->display_options['fields']['score']['label'] = 'Score';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/config/system/personalization/statistic';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Statistic';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views['personalization_views_statistic'] = $view;

  return $views;
}
