(function ($, Drupal) {
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
            $('.form-filters > .form-element > label, .findit-sort .findit-sort-title').on('click touchstart', function (e) {
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

            // Toggle calendar view display.
            $('.calendar-nav-pager-toggle-display').click(function (e) {
                e.preventDefault();
                $(this).children('a').text(function(i, text) {
                    return text === Drupal.t("Table View") ? Drupal.t("List View") : Drupal.t("Table View");
                });
                $('.calendar').toggleClass('calendar-grid-view');
            });

            // Equal height columns.
            var equalHeight = function (container) {

                var currentTallest = 0,
                    currentRowStart = 0,
                    rowDivs = new Array(),
                    $el,
                    topPosition = 0;
                $(container).each(function () {
                    $el = $(this);
                    $($el).height('auto');
                    topPostion = $el.position().top;

                    if (currentRowStart != topPostion) {
                        for (currentDiv = 0 ; currentDiv < rowDivs.length ; currentDiv++) {
                            rowDivs[currentDiv].height(currentTallest);
                        }
                        rowDivs.length = 0; // empty the array
                        currentRowStart = topPostion;
                        currentTallest = $el.height();
                        rowDivs.push($el);
                    } else {
                        rowDivs.push($el);
                        currentTallest = (currentTallest < $el.height()) ? ($el.height()) : (currentTallest);
                    }
                    for (currentDiv = 0 ; currentDiv < rowDivs.length ; currentDiv++) {
                        rowDivs[currentDiv].height(currentTallest);
                    }
                });
            };

            // Make callouts on homepage equal heights.
            $(window).load(function () {
                equalHeight('.findit-highlights .node-callout, .findit-hero .node-callout');
            });
            $(window).resize(function () {
                equalHeight('.findit-highlights .node-callout, .findit-hero .node-callout');
            });

            // Detect Internet Explorer.
            if (window.navigator.userAgent.indexOf("MSIE ") > 0 || !!navigator.userAgent.match(/Trident.*rv\:11\./)) {
                $('body').addClass('ie');
            }
        }
    };

})(jQuery, Drupal);
