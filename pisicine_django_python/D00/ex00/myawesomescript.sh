#!/bin/sh

if [ $1 ]; then
curl -lsi $1 | grep ocation | cut -c11-
fi
