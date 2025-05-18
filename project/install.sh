#!/bin/bash

sudo ln -sf /usr/bitey/software/coffee/bin/csh /usr/bin/csh
sudo ln -sf /usr/bitey/software/coffee/bin/coffee /usr/bin/coffee
sudo ln -sf /usr/bitey/software/coffee/bin/reader /usr/bin/reader
grep -qxF "/usr/bin/csh" /etc/shells || echo "/usr/bin/csh" | sudo tee -a /etc/shells
