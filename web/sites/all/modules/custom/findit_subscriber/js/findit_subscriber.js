(function ($) {
    Drupal.behaviors.findit_subscriber = {
        attach: function(context) {
            $("#edit-actionfindit-subscriber-cancel-all").click(function() {
                //Cancel all subscriptions button; trigger select all
                $('.vbo-select').attr('checked',true);
            });
        }
    }
})(jQuery);
