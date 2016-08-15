(function ($) {
    Drupal.behaviors.findit_cambridge = {
        attach: function (context, settings) {
            $('.nav-main-toggle').click(function (e) {
                e.preventDefault();
                $('.l-nav').toggleClass('l-nav-active');
            });

            $('.expandable > h3 > a').click(function (e) {
                e.preventDefault();
                $(this).parents('.expandable').toggleClass('expandable-is-open');
            });

            $('.form-filters .popover').addClass('popover-is-hidden');
            $('.form-filters > .form-element > label').on('click touchstart', function (e) {
                e.stopPropagation();
                e.preventDefault();

                var isHidden = $(this).parents('.form-element').find('.popover').hasClass('popover-is-hidden');
                $('.popover').addClass('popover-is-hidden');

                if (isHidden) {
                  $(this).parents('.form-element').find('.popover').removeClass('popover-is-hidden');
                }
            });
            $('.popover').on('click touchstart', function (e) {
                e.stopPropagation();
            });
            $('body').on('click touchstart', function (e) {
                $('.popover').addClass('popover-is-hidden');
            });

            if ($('.findit-related-programs .node-program').length > 2) {
                $('.findit-related-programs .expandable').removeClass('expandable-is-open');
            }

            if ($('.findit-related-events .node-event').length > 2) {
                $('.findit-related-events .expandable').removeClass('expandable-is-open');
            }

            $('.slide-with-style-slider').bind('slide', function (e, ui) {
                var labels = settings.slider['edit-findit-age'].textvalues;
                var minLabel = labels[ui.values[0]];
                var maxLabel = labels[ui.values[1]];
                $('#age-range').text(minLabel + '—' + maxLabel);
            });

            // Detect Internet Explorer.
            if (window.navigator.userAgent.indexOf("MSIE ") > 0 || !!navigator.userAgent.match(/Trident.*rv\:11\./)) {
                $('body').addClass('ie');
            }
        }
    };

})(jQuery);
