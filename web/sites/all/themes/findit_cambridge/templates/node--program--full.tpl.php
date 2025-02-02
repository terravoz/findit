<?php

/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup themeable
 */
?>
<div class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php print render($title_prefix); ?>
  <?php if (!$page): ?>
    <h2<?php print $title_attributes; ?>><a href="<?php print $node_url; ?>"><?php print $title; ?></a></h2>
  <?php endif; ?>
  <?php print render($title_suffix); ?>

  <?php print render($content[FINDIT_FIELD_LOGO]); ?>

  <?php if ($display_submitted): ?>
  <p class="node-submitted">
    <?php print $submitted; ?>
  </p>
  <?php endif; ?>

  <?php print render($content['body']); ?>

  <div class="expandable expandable-is-open">
    <h3 class="expandable-heading"><a href="#"><?php print t('When'); ?></a></h3>
    <div class="expandable-content">
      <?php if ($content[FINDIT_FIELD_ONGOING]['#items'][0]['value'] != 'between'): ?>
        <?php print render($content[FINDIT_FIELD_ONGOING]); ?>
      <?php else: ?>
        <?php print render($content[FINDIT_FIELD_PROGRAM_PERIOD]); ?>
      <?php endif; ?>
      <?php print render($content[FINDIT_FIELD_TIME_DAY_OF_WEEK]); ?>
      <?php print render($content[FINDIT_FIELD_TIME_OF_DAY]); ?>
      <?php print render($content[FINDIT_FIELD_TIME_OF_YEAR]); ?>
      <?php print render($content[FINDIT_FIELD_TIME_OTHER]); ?>
      <?php print render($content[FINDIT_FIELD_WHEN_ADDITIONAL_INFORMATION]); ?>
    </div>
  </div>
  <?php if (!$hide_section_location): ?>
  <div class="expandable expandable-is-open">
    <h3 class="expandable-heading"><a href="#"><?php print t('Location'); ?></a></h3>
    <div class="expandable-content">
      <?php if ($content[FINDIT_FIELD_REACH]['#items'][0]['value'] != 'locations'): ?>
        <?php print render($content[FINDIT_FIELD_REACH]); ?>
      <?php else: ?>
        <?php print render($content[FINDIT_FIELD_LOCATIONS]); ?>
      <?php endif; ?>
      <?php print render($content[FINDIT_FIELD_TRANSPORTATION]); ?>
      <?php print render($content[FINDIT_FIELD_LOCATION_NOTES]); ?>
    </div>
  </div>
  <?php endif; ?>
  <?php if (!$hide_section_websites): ?>
  <div class="expandable expandable-is-open">
    <h3 class="expandable-heading"><a href="#"><?php print t('Program Websites'); ?></a></h3>
    <div class="expandable-content">
      <?php print render($content[FINDIT_FIELD_PROGRAM_URL]); ?>
      <?php print render($content[FINDIT_FIELD_FACEBOOK_PAGE]); ?>
      <?php print render($content[FINDIT_FIELD_TWITTER_HANDLE]); ?>
      <?php print render($content[FINDIT_FIELD_INSTAGRAM_URL]); ?>
      <?php print render($content[FINDIT_FIELD_TUMBLR_URL]); ?>
      <?php print render($content[FINDIT_FIELD_ADDITIONAL_INFORMATION_FILE]); ?>
    </div>
  </div>
  <?php endif; ?>
  <?php if (!$hide_section_contact): ?>
  <div class="expandable expandable-is-open">
    <h3 class="expandable-heading"><a href="#"><?php print t('Contact'); ?></a></h3>
    <div class="expandable-content">
      <?php print render($content[FINDIT_FIELD_CONTACTS]); ?>
      <?php print render($content[FINDIT_FIELD_CONTACTS_ADDITIONAL_INFORMATION]); ?>
    </div>
  </div>
  <?php endif; ?>
  <?php if (!$hide_section_age_and_eligibility): ?>
  <div class="expandable expandable-is-open">
    <h3 class="expandable-heading"><a href="#"><?php print t('Age &amp; Eligibility'); ?></a></h3>
    <div class="expandable-content">
      <?php print render($content[FINDIT_FIELD_AGE_ELIGIBILITY]); ?>
      <?php print render($content[FINDIT_FIELD_GRADE_ELIGIBILITY]); ?>
      <?php print render($content[FINDIT_FIELD_OTHER_ELIGIBILITY]); ?>
      <?php print render($content[FINDIT_FIELD_ELIGIBILITY_NOTES]); ?>
    </div>
  </div>
  <?php endif; ?>
  <?php if (!$hide_section_accessibility_and_amenities): ?>
  <div class="expandable expandable-is-open">
    <h3 class="expandable-heading"><a href="#"><?php print t('Accessibility &amp; Amenities'); ?></a></h3>
    <div class="expandable-content">
      <?php print render($content[FINDIT_FIELD_ACCESSIBILITY]); ?>
      <?php print render($content[FINDIT_FIELD_ACCESSIBILITY_NOTES]); ?>
      <?php print render($content[FINDIT_FIELD_AMENITIES]); ?>
    </div>
  </div>
  <?php endif; ?>
  <?php if (!$hide_section_similar): ?>
  <div class="expandable expandable-is-open">
    <h3 class="expandable-heading"><a href="#"><?php print t('Find Similar Programs'); ?></a></h3>
    <div class="expandable-content">
      <?php print render($content[FINDIT_FIELD_PROGRAM_CATEGORIES]); ?>
    </div>
  </div>
  <?php endif; ?>

  <?php print render($content['links']); ?>

  <?php print render($content['comments']); ?>

</div>
