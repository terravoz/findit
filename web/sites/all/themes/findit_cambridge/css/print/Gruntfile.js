module.exports = function (grunt) {
    grunt.initConfig({
        sass: {
          dev: {
            options: {
              style: 'compact'
            },
            files: {
              'css/printstyle.css': 'sass/printstyle.scss'
            }
          }
        },
        connect: {
            preview: {
                options: {
                    base: ['./'],
                    port: 9000,
                    hostname: 'localhost',
                    keepalive: false,
                    livereload: 35729,
                    open: 'http://0.0.0.0:9000/'
                }
            }
        },
        watch: {
            templates: {
                files: [
                  '*.html',
                  'sass/**/*.scss',
                ],
                tasks: ['sass:dev']
            },
            livereload: {
                options: {
                    livereload: '<%= connect.preview.options.livereload %>'
                },
                files: ['css/**.*']
            }
        }
    });

    grunt.loadNpmTasks('grunt-contrib-connect');
    grunt.loadNpmTasks('grunt-contrib-watch');
    grunt.loadNpmTasks('grunt-sass');
    grunt.registerTask('default',['sass:dev','connect:preview','watch']);
};
