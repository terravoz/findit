#!/usr/bin/env bash
export DEBIAN_FRONTEND=noninteractive
apt-get update
apt-get -y upgrade
apt-get -y install \
	rake \
	ruby-sass \
	rubygems-integration
apt-get -y autoremove

cp -r /vagrant/provisioning/etc/* /etc/
chmod -R u+w /vagrant/web/sites/default
cp /vagrant/provisioning/settings.php /vagrant/web/sites/default/

php5enmod -s cli vagrant

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

# Disable the system's default virtual host.
if [ -L /etc/apache2/sites-enabled/000-default.conf ]; then
	a2dissite 000-default
fi

# Enable the drupal website as the default virtual host.
if [ ! -L /etc/apache2/sites-enabled/drupal.conf ]; then
	a2ensite drupal
fi

service apache2 restart

# Install phpunit.
if [ ! -e /usr/local/bin/phpunit ]; then
	wget -q https://phar.phpunit.de/phpunit.phar
	chmod +x phpunit.phar
	mv phpunit.phar /usr/local/bin/phpunit
fi;
