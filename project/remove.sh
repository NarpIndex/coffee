#!/bin/bash

sudo rm -rf /usr/bin/csh
sudo rm -rf /usr/bin/coffee
sudo rm -rf /usr/bin/reader
if grep -qxF "/usr/bin/csh" /etc/shells; then
    sudo sed -i '\|^/usr/bin/csh$|d' /etc/shells
fi

