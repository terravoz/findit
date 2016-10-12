(function ($) {
    Drupal.behaviors.findit_search = {
        attach: function (context, settings) {
            var $min = $('[name=' + settings.select_pair.min + ']');
            var $max = $('[name=' + settings.select_pair.max + ']');

            $min.on('change', function () {
                $max.find('option').slice(0, this.selectedIndex).prop('disabled', true);
                $max.find('option').slice(this.selectedIndex).prop('disabled', false);
            });

            $max.on('change', function () {
                $min.find('option').slice(this.selectedIndex + 1).prop('disabled', true);
                $min.find('option').slice(0, this.selectedIndex + 1).prop('disabled', false);
            });

            $max.trigger('change');
            $min.trigger('change');
        }
    }
})(jQuery);
