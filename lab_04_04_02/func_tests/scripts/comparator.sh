#!/bin/bash

if [ "$(grep -Eo "[+-]?([0-9]*[.])?[0-9]+" "$1")" = "$(grep -Eo "[+-]?([0-9]*[.])?[0-9]+" "$2")" ]; then
 exit 0
else
 exit 1
fi