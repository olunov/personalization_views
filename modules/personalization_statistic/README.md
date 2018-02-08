# Personalization Statistic

##INTRODUCTION
Contains views for Statistic page and Suggested content block. Main purpose is
to show examples of Personalization Views usage.


##REQUIREMENTS
This module requires the following module(s):
* Personalization (https://www.drupal.org/project/personalization_views)

##INSTALLATION
* Install as you would normally install a contributed Drupal module. See: 
https://drupal.org/documentation/install/modules-themes/modules-7 for further
information.
* Configure Personalization module. See more information on the modules page
and in README.txt
* Make sure some statistic is collected (check table 
`personalization_user_scores`) in DB.
* Check imported views: 
  * Personalization Views Statistic (Configuration > System > Site
  personalization > Statistic).
  * Suggested content block, add it some where to view results.
* Add permission to users roles to view Statistic and suggested content.
* Create own view with reference to taxonomy terms used for scoring content. It
is possible to use data loaded from fields score, pages, searches, location and
changed for viewing, filtering or sorting data.

##Recommended modules
* Views Aggregator Plus (https://www.drupal.org/project/views_aggregator)
* Ajax Blocks (https://www.drupal.org/project/ajaxblocks)

##MAINTAINERS
Current maintainers:
* Oleksandr Lunov ([alunyov](https://www.drupal.org/user/103985))

Supporting organizations: 
* [EPAM Systems](https://www.drupal.org/epam-systems) 
