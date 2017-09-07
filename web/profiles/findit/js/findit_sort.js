(function ($) {
    Drupal.behaviors.findit_sort = {
        attach: function (context) {
            $('#findit_custom_search_sort').on('change', function() {
                var url = window.location.protocol + '//' + window.location.host + window.location.pathname;
                if (this.value == 'search_api_relevance') {
                    $.query.SET('sort','search_api_relevance').SET('order', 'desc');
                }
                else if (this.value == 'title_asc') {
                    $.query.SET('sort','title').SET('order', 'asc');
                }
                else {
                    $.query.SET('sort','title').SET('order', 'desc');
                }

                var query = $.query.toString();
                window.location.href = url+query;
            })
        }
    }
})(jQuery);
