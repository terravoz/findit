(function ($) {
    var findKey = function (value, options) {
        for (var key in options) {
            if (options.hasOwnProperty(key) && options[key] === value) {
                return key;
            }
        }
    };

    var getClassFromSVG = function ($element) {
        if ($element.attr('class').baseVal) {
            return $element.attr('class').baseVal;
        } else {
            return $element.attr('class');
        }
    };

    var setClassOnSVG = function ($element, className) {
        if ($element.attr('class').baseVal) {
            $element.attr('class').baseVal = className;
        } else {
            $element.attr('class', className);
        }
    };

    Drupal.behaviors.findit_svg = {
        attach: function (context, settings) {
            var $select = $('svg + select');
            var baseClass = getClassFromSVG($('[data-term]', context));
            var options = {};

            $select.find('option').each(function () {
                options[this.value] = this.textContent;
            });

            var multiple = $select.attr('multiple');

            $('svg', context).click(function () {
                $select.val(null).change();
            });

            $('[data-term]', context).click(function (e) {
                e.stopPropagation();
                if (multiple) {
                    var values = $select.val() || [];
                    var newValue = findKey($(this).data('term'), options);
                    var index = values.indexOf(newValue);

                    if (index > -1) {
                        delete values[index];
                    } else {
                        values.push(newValue);
                    }

                    $select.val(values).change();

                } else {
                    $select.val(findKey($(this).data('term'), options)).change();
                }
            });

            $select.change(function (e) {
                $('[data-term]', context).each(function () {
                    setClassOnSVG($(this), baseClass);
                });

                if (multiple) {
                    var selected = $(this).val() || [];
                } else {
                    var selected = [$(this).val()];
                }

                if ($('.map > ul').length === 0) {
                    $('.map').append($('<ul class="map-selection"></ul>'));
                }

                $('.map > ul').empty();

                for (var i = 0; i < selected.length; i++) {
                    $('[data-term="' + options[selected[i]] + '"]').each(function () {
                        setClassOnSVG($(this), baseClass + ' is-selected');
                    });

                    if (i < 4) {
                        $('.map > ul', context).append($('<li>' + options[selected[i]] + '</li>'));
                    } else if (i === 4) {
                        $('.map > ul', context).append($('<li>…</li>'));
                    }

                }
            }).change();
        }
    };
})(jQuery);