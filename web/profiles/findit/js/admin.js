(function ($) {
  Drupal.behaviors.findit = {
    attach: function (context) {
      $('.field-name-field-program-categories .form-checkboxes label').once().each( function(index) {
        var label = $(this).text();

        if (!( /^-/.test(label))) {
          $(this).siblings('input').remove();
        }
        else {
          $(this).text(label.replace(/-*/, ''));
        }
      });

      // Detect Internet Explorer.
      if (window.navigator.userAgent.indexOf("MSIE ") > 0 || !!navigator.userAgent.match(/Trident.*rv\:11\./)) {
        $('body').addClass('ie');
      }
    }
  }
})(jQuery);
