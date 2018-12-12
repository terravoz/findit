<?php
/**
 * The view is grouped by this field but this field allows multiple values so
 * when it was being rendered it wasn't always was returning the expected value
 * that  was used to sort the view producing unexpected groups (like dates out of
 * order) so instead of rely on the rendered field to group the view we are just
 * going to use the date that was used to order the view.
 */
$event_date = strtotime($row->field_data_field_event_date_field_event_date_value);
print format_date($event_date, 'compact_day');

?>
