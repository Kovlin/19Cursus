#!/bin/sh

if [ $1 ]; then
curl -Ls -o /dev/null -w %{url_effective} $1
fi