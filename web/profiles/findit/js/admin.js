(function ($) {
  Drupal.behaviors.findit = {
    attach: function (context) {
      $('.field-name-field-program-categories .form-checkboxes label').each( function(index) {
        var label = $( this ).text();

        if ( !( /^-/.test( label ) ) ) {
          $( this ).siblings( 'input' ).remove();
        }
        else {
          $( this ).text( label.replace( /-*/, '' ) );
        }
      });
    }
  }
})(jQuery);
