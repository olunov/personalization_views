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
  $view->description = 'Provides page for reviewing personalization statistic per each of term';
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
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['exposed'] = TRUE;
  $handler->display->display_options['filters']['machine_name']['expose']['operator_id'] = 'machine_name_op';
  $handler->display->display_options['filters']['machine_name']['expose']['label'] = 'Vocabulary';
  $handler->display->display_options['filters']['machine_name']['expose']['operator'] = 'machine_name_op';
  $handler->display->display_options['filters']['machine_name']['expose']['identifier'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
  );

  /* Display: Statistic Page */
  $handler = $view->new_display('page', 'Statistic Page', 'page');
  $handler->display->display_options['path'] = 'admin/config/system/personalization/statistic';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Statistic';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  $views['personalization_views_statistic'] = $view;

  // Suggested content block view.
  $view = new view();
  $view->name = 'personalization_statistic_suggested_content';
  $view->description = 'Shows suggested content based on personalization';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Suggested Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Suggested Content';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view personalization suggested content';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'location' => 0,
    'personalization_geographic_locations' => 0,
    'tags' => 0,
  );
  /* Relationship: Personalization User Scores: User */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'personalization_user_scores';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['relationship'] = 'term_node_tid';
  $handler->display->display_options['relationships']['user']['label'] = 'personalization user';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: SUM(Personalization User Scores: Term Score) */
  $handler->display->display_options['fields']['score']['id'] = 'score';
  $handler->display->display_options['fields']['score']['table'] = 'personalization_user_scores';
  $handler->display->display_options['fields']['score']['field'] = 'score';
  $handler->display->display_options['fields']['score']['relationship'] = 'term_node_tid';
  $handler->display->display_options['fields']['score']['group_type'] = 'sum';
  /* Sort criterion: SUM(Personalization User Scores: Term Score) */
  $handler->display->display_options['sorts']['score']['id'] = 'score';
  $handler->display->display_options['sorts']['score']['table'] = 'personalization_user_scores';
  $handler->display->display_options['sorts']['score']['field'] = 'score';
  $handler->display->display_options['sorts']['score']['relationship'] = 'term_node_tid';
  $handler->display->display_options['sorts']['score']['group_type'] = 'sum';
  $handler->display->display_options['sorts']['score']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Personalization User Scores: User */
  $handler->display->display_options['arguments']['user']['id'] = 'user';
  $handler->display->display_options['arguments']['user']['table'] = 'personalization_user_scores';
  $handler->display->display_options['arguments']['user']['field'] = 'user';
  $handler->display->display_options['arguments']['user']['relationship'] = 'term_node_tid';
  $handler->display->display_options['arguments']['user']['default_action'] = 'default';
  $handler->display->display_options['arguments']['user']['default_argument_type'] = 'personalization_current_user';
  $handler->display->display_options['arguments']['user']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['user']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['user']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Suggested Content Block */
  $handler = $view->new_display('block', 'Suggested Content Block', 'block');

  $views['personalization_statistic_suggested_content'] = $view;

  return $views;
}
