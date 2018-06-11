#!/usr/bin/env bash
export DEBIAN_FRONTEND=noninteractive
apt-get update
apt-get -y upgrade
apt-get -y install \
	apache2 \
	composer \
	git \
	mysql-server \
	openjdk-8-jre-headless \
	php-apcu \
	php-cli \
	php-curl \
	php-fpm \
	php-gd \
	php-mbstring \
	php-mysql \
	php-xdebug \
	php-xml \
	rake \
	vim-nox
apt-get -y autoremove

if ! service --status-all | grep -Fq 'solr'; then
	cd /opt
	wget http://archive.apache.org/dist/lucene/solr/6.6.4/solr-6.6.4.tgz
	tar xzf solr-6.6.4.tgz solr-6.6.4/bin/install_solr_service.sh --strip-components=2
	bash install_solr_service.sh solr-6.6.4.tgz
	sudo -u solr /opt/solr/bin/solr create -c drupal -n data_driven_schema_configs
	cp /vagrant/web/sites/all/modules/contrib/search_api_solr/solr-conf/6.x/* /var/solr/data/drupal/conf/
	cd -
fi

cp -r /vagrant/provisioning/etc/* /etc/
chmod -R u+w /vagrant/web/sites/default
cp /vagrant/provisioning/settings.php /vagrant/web/sites/default/

phpenmod vagrant

/vagrant/vendor/bin/phpcs --config-set installed_paths /vagrant/vendor/drupal/coder/coder_sniffer
/vagrant/vendor/bin/phpcs --config-set default_standard Drupal

# Create a local file folder inside the VM and symlink drupal's public file
# folder to updload files through the UI.
export FILES=/var/local/drupal
if [ ! -d $FILES ]; then
	mkdir -p $FILES
fi
chown -R www-data:staff $FILES
chmod -R g+w $FILES

if [ ! -d ~/.drush ]; then
	mkdir -p ~/.drush
	cp -r /vagrant/drush/*  ~/.drush/
fi

if [ ! -L /vagrant/web/sites/default/files ]; then
	ln -s $FILES /vagrant/web/sites/default/files
fi

# Create the database.
if [ ! -d /var/lib/mysql/drupal ]; then
	mysqladmin -u root create drupal
	mysql -e "GRANT ALL ON drupal.* TO drupal@localhost IDENTIFIED BY 'drupal'"
fi

# Enable the required web server modules
if [ ! -L /etc/apache2/mods-enabled/rewrite.load ]; then
        a2enmod rewrite
fi

if [ ! -L /etc/apache2/mods-enabled/proxy.load ]; then
        a2enmod proxy
fi

if [ ! -L /etc/apache2/mods-enabled/proxy_fcgi.load ]; then
        a2enmod proxy_fcgi
fi

# Disable the system's default virtual host.
if [ -L /etc/apache2/sites-enabled/000-default.conf ]; then
	a2dissite 000-default
fi

# Enable the drupal website as the default virtual host.
if [ ! -L /etc/apache2/sites-enabled/drupal.conf ]; then
	a2ensite drupal
fi

if ! grep -q PATH /home/vagrant/.bashrc; then
	echo 'export PATH=$PATH:/vagrant/vendor/bin' >> /home/vagrant/.bashrc
fi

adduser vagrant adm
adduser vagrant staff

service php7.0-fpm restart
service apache2 restart
service solr restart
