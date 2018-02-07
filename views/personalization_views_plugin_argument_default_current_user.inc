<?php

/**
 * @file
 * Contains the personalization current user argument default plugin.
 */

/**
 * Default argument plugin to extract the global $user
 */
class personalization_views_plugin_argument_default_current_user extends views_plugin_argument_default {
  function get_argument() {
    // @see: personalization_get_user().
    module_load_include('inc', 'personalization', 'personalization.tracker');
    $uid = personalization_get_user();
    return $uid;
  }
}
