<?php

/**
 * @file
 * Views 3 support for Location Phone.
 */

/**
 * Implements hook_views_data().
 */
function locative_address_3_views_data() {
  // locative_address_3 table -- basic table information.
  // Define the base group of this table.
  // Fields that don' have a group defined will go into this field by default.
  $data['locative_address_3']['table']['group'] = t('Location', array(), array('context' => 'geolocation'));

  // Join locative_address_3 to all the tables that would be useful.
  $data['locative_address_3']['table']['join'] = array(
    // locative_address_3 links to location via lid.
    'location' => array(
      'left_field' => 'lid',
      'field' => 'lid',
    ),
    // locative_address_3 links to node through location_instance via lid.
    'node' => array(
      'left_table' => 'location_instance',
      'left_field' => 'lid',
      'field' => 'lid',
    ),
    // locative_address_3 links to node_revision through location_instance via lid.
    'node_revision' => array(
      'left_table' => 'location_instance',
      'left_field' => 'lid',
      'field' => 'lid',
    ),
    // locative_address_3 links to users through location_instance via lid.
    'users' => array(
      'left_table' => 'location_instance',
      'left_field' => 'lid',
      'field' => 'lid',
    ),
  );

  // locative_address_3 table -- fields.
  $data['locative_address_3']['address3'] = array(
    'title' => t('Address3'),
    'help' => t('The address 3 of the selected location.'),
    'field' => array(
      'click sortable' => TRUE,
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
      'empty field name' => t('None'),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
      'allow empty' => TRUE,
    ),
  );

  return $data;
}
