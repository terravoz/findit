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
    "host" => "agaric@Finditcambridgev2.eastus.cloudapp.azure.com",
    "path" => "/var/www/fic_stage/htdocs/",
    "drush" => "/home/agaric/bin/drush",
    "backups" => "/tmp",
  },
  "live" => {
    "host" => "agaric@Finditcambridgev2.eastus.cloudapp.azure.com",
    "path" => "/var/www/fic/htdocs/",
    "backups" => "/tmp",
  },
}
TAGNAMES = %w(stable)
DRUPAL = "web"
PROFILE = "findit"
BUILDDIR = "/tmp/build"
