#!/usr/bin/env bash
export DEBIAN_FRONTEND=noninteractive
apt-get update
apt-get -y upgrade
apt-get -y install \
	apache2 \
	drush \
        git \
        mysql-server \
	php-codesniffer \
        php5-apcu \
        php5-cli \
        php5-curl \
        php5-fpm \
        php5-gd \
        php5-mysql \
        php5-xdebug \
        rake \
        vim-nox
apt-get -y autoremove

cp -r /vagrant/provisioning/etc/* /etc/
chmod -R u+w /vagrant/web/sites/default
cp /vagrant/provisioning/settings.php /vagrant/web/sites/default/

php5enmod vagrant
phpcs --config-set default_standard /vagrant/web/sites/all/modules/contrib/coder/coder_sniffer/Drupal/

# Create a local file folder inside the VM and symlink drupal's public file
# folder to updload files through the UI.
export FILES=/var/local/drupal
if [ ! -d $FILES ]; then
	mkdir -p $FILES
fi
chown -R www-data:staff $FILES
chmod -R g+w $FILES

if [ ! -L /vagrant/web/sites/default/files ]; then
	ln -s $FILES /vagrant/web/sites/default/files
fi

# Create the database.
if [ ! -d /var/lib/mysql/drupal ]; then
	mysqladmin -u root create drupal
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

service php5-fpm restart
service apache2 restart

# Install phpunit.
if [ ! -e /usr/local/bin/phpunit ]; then
	wget -q https://phar.phpunit.de/phpunit.phar
	chmod +x phpunit.phar
	mv phpunit.phar /usr/local/bin/phpunit
fi;
