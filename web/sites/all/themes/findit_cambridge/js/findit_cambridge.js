(function ($) {
    Drupal.behaviors.findit_cambridge = {
        attach: function () {
            $('.nav-main-toggle').click(function (e) {
                e.preventDefault();
                $('.l-container').toggleClass('l-container-with-nav-main');
            });

            $('.expandable > h3 > a').click(function (e) {
                e.preventDefault();
                $(this).parents('.expandable').toggleClass('expandable-is-open');
            });

            $('.form-filters .popover').addClass('popover-is-hidden');
            $('.form-filters .form-widget > label > a').click(function (e) {
                e.preventDefault();
                var isHidden = $(this).parents('.form-widget').find('.popover').hasClass('popover-is-hidden');
                $('.popover').addClass('popover-is-hidden');

                if (isHidden) {
                  $(this).parents('.form-widget').find('.popover').removeClass('popover-is-hidden');
                }
            });
        }
    };

})(jQuery);
