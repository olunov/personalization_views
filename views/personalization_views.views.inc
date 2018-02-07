<?php

/**
 * @file
 * Contains view handlers.
 */

/**
 * Implements hook_views_data().
 */
function personalization_views_views_data() {
  $data['personalization_user_scores']['table']['group'] = t('Personalization User Scores');
  $data['personalization_user_scores']['table']['join'] = array(
    'taxonomy_term_data' => array(
      'left_field' => 'tid',
      'field' => 'tid',
    ),
  );

  // Loading score.
  $data['personalization_user_scores']['score'] = array(
    'title' => t('Term Score'),
    'help' => t('Contains score of term.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Loading user id for reference.
  $data['personalization_user_scores']['user'] = array(
    'title' => t('User'),
    'help' => t('The user who visited the page with the tag.'),
    'argument' => array(
      'handler' => 'views_handler_argument_user_uid',
      'name field' => 'title',
      'numeric' => TRUE,
      'validate type' => 'uid',
    ),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'base field' => 'uid',
    ),
  );

  // Loading number of time term was loaded in content for specific user.
  $data['personalization_user_scores']['pages'] = array(
    'title' => t('Term views'),
    'help' => t('Number of time term was shown on pages.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Loading number of time term searched for by specific user.
  $data['personalization_user_scores']['searches'] = array(
    'title' => t('Term searching'),
    'help' => t('Number of time term was searched.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Loading number of times term was used for prioritizing content based
  // on user's location.
  $data['personalization_user_scores']['location'] = array(
    'title' => t('Term location'),
    'help' => t("Number of times when term was used for prioritizing content based on user's location."),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Loading datetime when term's score was updated.
  $data['personalization_user_scores']['changed'] = array(
    'title' => t('Changed'),
    'help' => t('Timestamp when score was updated.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_plugins().
 */
function personalization_views_views_plugins() {
  return array(
    'module' => 'personalization_views',
    'argument default' => array(
      'personalization_current_user' => array(
        'title' => t('Personalization: User ID from logged in user or anonymous user'),
        'handler' => 'personalization_views_plugin_argument_default_current_user',
        'path' => drupal_get_path('module', 'personalization_views') . '/views',
      ),
    ),
  );
}
