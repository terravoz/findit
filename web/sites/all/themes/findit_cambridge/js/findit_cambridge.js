(function () {
    Drupal.behaviors.findit_cambridge = {
        attach: function () {
            var toggle = document.getElementById('main-menu-toggle');
            toggle.onclick = function (e) {
                var body = document.querySelector('body');
                body.classList.toggle('main-menu-is-active');
            };
        }
    };
})();
