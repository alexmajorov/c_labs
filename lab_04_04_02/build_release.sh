#!/bin/bash

gcc -c main.c -std=c99 -Wall -Werror -Wfloat-conversion -Wfloat-equal -Wpedantic -Wextra -Wno-unused-result -Wvla -O2
gcc -o app.exe main.o
