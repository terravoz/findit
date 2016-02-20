<?php
/**
 * @file
 * Template to display a column
 *
 * - $item: The item to render within a td element.
 */
?>
<td class="<?php print $item['class'] ?>" colspan="<?php print $item['colspan'] ?>" rowspan="<?php print $item['rowspan'] ?>">
  <?php print $item['entry'] ?>
</td>
