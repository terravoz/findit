(function ($) {
    var findKey = function (value, options) {
        for (var key in options) {
            if (options.hasOwnProperty(key) && options[key] === value) {
                return key;
            }
        }
    };

    Drupal.behaviors.findit_svg = {
        attach: function (context, settings) {
            var $select = $('svg + select');
            var baseClass = $('[data-term]', context).attr('class').baseVal;
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
                    $(this).attr('class').baseVal = baseClass;
                });

                if (multiple) {
                    var selected = $(this).val() || [];
                } else {
                    var selected = [$(this).val()];
                }

                for (var i = 0; i < selected.length; i++) {
                    var $element = $('[data-term="' + options[selected[i]] + '"]');
                    if ($element.length) {
                        $element.attr('class').baseVal += ' is-selected';
                    }
                }
            }).change();
        }
    };
})(jQuery);