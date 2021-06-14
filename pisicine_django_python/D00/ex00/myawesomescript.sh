#!/bin/sh

if [ $1 ]; then
curl -Ls -o /dev/null -w %{url_effective}'\n' $1
fi