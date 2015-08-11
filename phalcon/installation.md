# install #
env ubuntu

## requirements ##

php5-dev   
libpcre3-dev   
gcc  
make   
php5-mysql  

## compilation ##

git clone --depth=1 git://github.com/phalcon/cphalcon.git  
cd cphalcon/build   
sudo ./install   

## configuration ##

*add a file called 30-phalcon.ini in /etc/php5/config.d/*   
extension=phalcon.so   

and then restart php5-fpm  nginx

## check installation ##
php -m 
or phpinfo() 
or print_r(get_loaded_extensions());

