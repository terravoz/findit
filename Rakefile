# See https://labs.agaric.com/redmine/projects/find-it-cambridge/wiki#New-server
# for details on ssh host settings. If you need your key added, please contact:
# jhandfield@cambridgema.gov Justin Handfield

ENVIRONMENTS = {
  "dev" => {
    "host" => "vlad@simone.mayfirst.org",
    "path" => "/var/local/drupal/findit/web",
    "backups" => "/tmp",
  },
  "stage" => {
    "host" => "finditvm",
    "path" => "/var/www/fic_stage/htdocs",
    "drush" => "/home/agaric/bin/drush",
    "backups" => "/tmp",
  },
  "live" => {
    "host" => "finditvm",
    "path" => "/var/www/fic/htdocs",
    "drush" => "/home/agaric/bin/drush",
    "backups" => "/tmp",
  },
  "legacy-stage" => {
    "host" => "fic@statedec-webserver.cloudapp.net",
    "path" => "/home/fic/www_stage/htdocs",
    "backups" => "/tmp",
  },
  "legacy-live" => {
    "host" => "fic@statedec-webserver.cloudapp.net",
    "path" => "/home/fic/www/htdocs",
    "backups" => "/tmp",
  },
}
TAGNAMES = %w(stable)
DRUPAL = "web"
PROFILE = "findit"
BUILDDIR = "/tmp/build"
