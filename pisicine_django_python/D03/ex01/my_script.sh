#!/bin/sh

pip3 --version

pip3 install --log my_install.log -t local_lib -U git+https://github.com/jaraco/path > pip3.log && python3 my_program.py

# -U is used to uprade the package to the latest version
# -t local_lib is used to choose the directory for the installion
# > is used to redirect the output of the installion
# "&&"" is used to run the program only if path.py is correctly installed
# --log to print the log in my_install.log