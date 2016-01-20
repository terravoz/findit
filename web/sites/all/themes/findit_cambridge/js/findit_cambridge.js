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
        }
    };

})(jQuery);
