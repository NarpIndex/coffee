#!/bin/bash

sudo rm -rf /usr/bin/csh
if grep -qxF "/usr/bin/csh" /etc/shells; then
    sudo sed -i '\|^/usr/bin/csh$|d' /etc/shells
fi

