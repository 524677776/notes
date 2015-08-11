### nginx configuration

server {

    listen    80;
    server_name phalcon.local.com;

    index index.php index.html index.htm;
    set $root_path '/var/www/html/invo/public';

    root $root_path;

    try_files $uri $uri/ @rewrite;

    location @rewrite {
        rewrite ^/(.*)$ /index.php?_url=/$1;
    }

    location ~ \.php$ {
        fastcgi_pass unix:/run/php5-fpm.sock;
        fastcgi_index  index.php;
        fastcgi_param SCRIPT_FILENAME $request_filename;
        fastcgi_param REQUEST_URI $uri?$args;
        include        fastcgi_params;
    }

    location ~*^/(css|img|js|flv|swf|download)/(.+)$ {
        root $root_path;
    }

    location ~ /\.ht {
        deny all;
    }
}
