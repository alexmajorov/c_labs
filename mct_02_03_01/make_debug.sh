#!/bin/bash

gcc -c main.c -std=c99 -Werror -Wextra -Wpedantic -Wvla -Wall --coverage -g3
gcc -c cars.c -std=c99 -Werror -Wextra -Wpedantic -Wvla -Wall --coverage -g3 -D_XOPEN_SOURCE=500
gcc -o app.exe --coverage main.o cars.o
