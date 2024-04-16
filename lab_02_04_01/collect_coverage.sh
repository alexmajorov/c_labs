#!/bin/bash

cd func_tests/scripts || exit 1
./func_tests.sh > /dev/null 2>&1
cd ../..
gcov main.c
