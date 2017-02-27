(function ($) {
    Drupal.behaviors.findit_subscriber_notifications_dialog = {
        attach: function(context) {
            $("#dialog-notifications-edit-event").dialog({
                autoOpen: false,
                resizable: false,
                height: "auto",
                width: 400,
                modal: true,
                buttons: {
                    "Update and Send Notification": function() {
                        $("#edit-findit-subscriber-notification-enabled").attr('checked', true);
                        $(this).dialog("close");
                        $("#event-node-form").submit();
                    },
                    "Just Update": function() {
                        $("#edit-findit-subscriber-notification-enabled").attr('checked', false);
                        $(this).dialog("close");
                        $("#event-node-form").submit();
                    }
                }
            });

            $("#edit-submit").click(function(event) {
                event.preventDefault();
                $("#dialog-notifications-edit-event").dialog( "open" );
            });
        }
    }
})(jQuery);
