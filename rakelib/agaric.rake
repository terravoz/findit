require 'date'
require 'rake/clean'

CLEAN.include("#{BUILDDIR}")

ENVIRONMENTS.keys.each do |env|
  settings_source = "#{BUILDDIR}/#{env}/#{DRUPAL}/sites/default/#{env}.settings.php"
  settings_target = "#{BUILDDIR}/#{env}/#{DRUPAL}/sites/default/settings.php"

  release_host = ENVIRONMENTS[env]["host"]
  release_path = ENVIRONMENTS[env]["path"]
  release_backups = ENVIRONMENTS[env]["backups"]
  release_tag = ENVIRONMENTS[env]["tag"]

  build_env = "build_#{env}".to_sym
  upload_env = "upload_#{env}".to_sym
  deploy_env = "deploy_#{env}".to_sym

  file "#{BUILDDIR}/#{env}" => :clean do
    commit = release_tag ? release_tag : 'HEAD'
    mkdir_p "#{BUILDDIR}/#{env}"
    sh "git archive #{commit} #{DRUPAL} | tar -x -C #{BUILDDIR}/#{env}"
  end

  file settings_target => settings_source do
    cp settings_source, settings_target
  end

  build_version = "#{BUILDDIR}/#{env}/#{DRUPAL}/BUILD_VERSION.txt"

  file build_version do
    sh "git describe --always --long #{release_tag} > #{build_version}"
  end

  desc "Build the #{env} environment."
  task build_env => [:clean, "#{BUILDDIR}/#{env}", settings_target, build_version]

  desc "Upload #{env} environment to the configured host."
  task upload_env => build_env do
    sh "ssh #{release_host} '([ -d #{release_path} ] || mkdir -p #{release_path})'"
    rsync_options = "-rz --stats --exclude sites/default/files/ --exclude config.rb --exclude sass/ --exclude .sass-cache/ --delete"
    rsync_source = "#{BUILDDIR}/#{env}/#{DRUPAL}/"
    rsync_target = "#{release_host}:#{release_path}"
    sh "rsync #{rsync_options} #{rsync_source} #{rsync_target}"
  end

  db_backup_task = "db_backup_#{env}".to_sym
  task db_backup_task do
    file = "#{release_backups}/backup-#{DateTime.now}.sql"
    sh "ssh #{release_host} 'drush -r #{release_path} sql-dump > #{file}'"
  end

  db_drop_tables_task = "db_drop_tables_#{env}".to_sym
  task db_drop_tables_task => db_backup_task do
    sh "ssh #{release_host} drush -y -r #{release_path} sql-drop"
  end

  desc "Deploy the #{env} environment to the configured host."
  task deploy_env => [db_backup_task, upload_env] do
    files_path = "#{release_path}/sites/default/files"
    commands = [
      "([ -d #{files_path} ] || mkdir #{files_path})",
      "drush -y -r #{release_path} updatedb",
      "drush -y -r #{release_path} cc all",
    ].join(" && ")
    sh "ssh #{release_host} '#{commands}'"
  end

  file_sync_task = "file_sync_#{env}_to_local".to_sym
  desc "Sync files from #{env} to local environment."
  task file_sync_task do
    sh "rsync -rz --stats --exclude styles --exclude css --exclude js --delete \
      #{release_host}:#{release_path}/sites/default/files/ \
      #{DRUPAL}/sites/default/files/"
  end

  db_sync_task = "db_sync_#{env}_to_local".to_sym
  desc "Sync database from #{env} to local environment."
  task db_sync_task do
    drupal_root = "#{Dir.getwd()}/#{DRUPAL}"
    sh "drush -y -r #{drupal_root} sql-drop"
    sh "ssh -C #{release_host} drush -r #{release_path} \
      sql-dump --structure-tables-key=common | drush -r #{drupal_root} sql-cli"
  end

  ENVIRONMENTS.keys.each do |e|
    unless e == env then
      from_host = ENVIRONMENTS[e][0]
      from_path = ENVIRONMENTS[e][1]

      file_sync_task = "file_sync_#{e}_to_#{env}".to_sym
      desc "Sync files from #{e} to #{env} environment."
      task file_sync_task do
        sh "ssh -A #{from_host} rsync -rz --stats --exclude styles \
          --exclude css --exclude js #{from_path}/sites/default/files/ \
          --delete #{release_host}:#{release_path}/sites/default/files/"
      end

      db_sync_task = "db_sync_#{e}_to_#{env}".to_sym
      desc "Sync database from #{e} to #{env} environment."
      task db_sync_task => db_drop_tables_task do
        sh "ssh -C #{from_host} drush -r #{from_path} \
          sql-dump --structure-tables-key=common | \
          ssh -C #{release_host} drush -r #{release_path} sql-cli"
      end
    end
  end

  desc "Build all environments."
  task :default => build_env
end

TAGNAMES.each do |tagname|
  desc "Tag a commit with #{tagname}."
  task "tag_#{tagname}".to_sym do
    sh "git fetch --tags"
    num = `git tag`.scan(Regexp.new(tagname + "-")).size + 1
    sh "git tag -am '#{tagname.upcase} Release #{num}' #{tagname}-#{num}"
    sh "git tag -afm 'Current #{tagname.upcase} Release' #{tagname}"
    sh "git push origin :refs/tags/#{tagname}"
    sh "git push origin --tags"
  end
end

task :sniff do
  files = ["web/profiles/#{PROFILE}", 'web/sites/all/modules/custom'].join(' ')
  extensions = ['module', 'profile', 'install', 'inc', 'php'].join(',')
  sh "phpcs --extensions=#{extensions} #{files}"
end

namespace :tests do

  desc "Run integration tests."
  task "integration" do
    sh "phpunit --process-isolation --bootstrap=tests/bootstrap.php tests/integration"
  end

end

if defined? PROFILE
  desc "Delete and re-install a site from its installation profile."
  task "site_install" do
    sh "drush -y site-install #{PROFILE}"
  end
end
