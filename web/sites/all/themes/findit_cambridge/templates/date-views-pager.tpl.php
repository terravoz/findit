<?php
/**
 * @file
 * Template file for the example display.
 *
 * Variables available:
 *
 * $plugin: The pager plugin object. This contains the view.
 *
 * $plugin->view
 *   The view object for this navigation.
 *
 * $nav_title
 *   The formatted title for this view. In the case of block
 *   views, it will be a link to the full view, otherwise it will
 *   be the formatted name of the year, month, day, or week.
 *
 * $prev_url
 * $next_url
 *   Urls for the previous and next calendar pages. The links are
 *   composed in the template to make it easier to change the text,
 *   add images, etc.
 *
 * $prev_options
 * $next_options
 *   Query strings and other options for the links that need to
 *   be used in the l() function, including rel=nofollow.
 */
?>
<?php if (!empty($pager_prefix)) : ?>
<?php print $pager_prefix; ?>
<?php endif; ?>
<div class="calendar-nav">
  <ul class="calendar-nav-pager">
    <?php if (!empty($prev_url)) : ?>
    <li class="calendar-nav-pager-prev">
      <?php
      $text = $mini ? '' : ' ' . t('◀', array(), array('context' => 'date_nav'));
      print l(t($text), $prev_url, $prev_options);
      ?>
    </li>
    <?php endif; ?>
    <?php if (!empty($next_url)) : ?>
    <li class="calendar-nav-pager-next">
      <?php print l(($mini ? '' : t('▶', array(), array('context' => 'date_nav')) . ' '), $next_url, $next_options); ?>
    </li>
    <?php endif; ?>
    <?php if (!empty($toggle_display)) : ?>
      <li class="calendar-nav-pager-toggle-display">
        <a href="#"><?php print t('Toggle display'); ?></a>
      </li>
    <?php endif; ?>
  </ul>
  <h2 class="calendar-nav-heading"><?php print $nav_title ?></h2>
</div>
