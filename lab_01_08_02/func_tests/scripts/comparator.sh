#!/bin/bash

if [ "$(grep -Eo "Result: .*" "$1")" = "$(grep -Eo "Result: .*" "$2")" ]; then
    exit 0
else
    exit 1
fi
