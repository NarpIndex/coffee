#!/bin/bash

sudo rm -rf /usr/bin/csh
sudo sed -i '\|^/usr/bin/csh$|d' /etc/shells
