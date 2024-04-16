#!/bin/bash

gcc -c main.c -std=c99 -Wall -Werror -Wfloat-equal -Wfloat-conversion -Wextra -Wpedantic -Wvla -O0 -ggdb --debug --coverage
gcc -o app.exe main.o --coverage
