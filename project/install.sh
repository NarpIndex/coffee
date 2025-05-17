#!/bin/bash

sudo ln -sf /usr/bitey/software/coffee/bin/csh /usr/bin/csh
grep -qxF "/usr/bin/csh" /etc/shells || echo "/usr/bin/csh" | sudo tee -a /etc/shells
