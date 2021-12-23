#!/bin/sh
current_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
cd "$current_path"
gcc ./cat_fetch.c -o cat-fetch
sudo mv ./cat-fetch /bin/
