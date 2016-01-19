(function () {
    Drupal.behaviors.findit_cambridge = {
        attach: function () {
            var toggle = document.getElementById('main-menu-toggle');
            toggle.onclick = function (e) {
                var container = document.querySelector('.l-container');
                container.classList.toggle('l-container-with-main-menu');
            };
        }
    };
})();
