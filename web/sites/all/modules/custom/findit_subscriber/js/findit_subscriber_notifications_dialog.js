(function ($) {
    Drupal.behaviors.findit_subscriber_notifications_dialog = {
        attach: function(context) {
            $("#dialog-notifications-edit-event").dialog({
                autoOpen: false,
                resizable: false,
                height: "auto",
                width: 430,
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

            $("#edit-submit, #edit-submit--2").click(function(event) {
                if($("#edit-findit-subscriber-notification-enabled").is(':checked')) {
                    event.preventDefault();
                    $("#dialog-notifications-edit-event").dialog( "open" );
                }
            });
        }
    }
})(jQuery);
