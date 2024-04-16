#!/bin/bash

file_app_args=""
if [ $# -gt 2 ]; then
    file_app_args="../data/${3}"
fi
if [ -n "${USE_VALGRIND}" ]; then
    eval "valgrind ../../app.exe ${file_app_args} < $1 > results.txt"
else
    eval "../../app.exe ${file_app_args} < $1 > results.txt" 
fi
if ./comparator.sh "$2" ./results.txt; then
    exit 0;
else
    exit 1;
fi
