(function ($) {
    Drupal.behaviors.findit2 = {
        attach: function (context) {
            //On node edit pages with next/prev scroll user to Prev/Next buttons instead of fieldgroup
            window.location.hash = '#organization-node-form';
        }
    }
})(jQuery);
