#!/bin/bash

gcc -c main.c -std=c99 -Werror -Wextra -Wpedantic -Wvla -Wall
gcc -c cars.c -std=c99 -Werror -Wextra -Wpedantic -Wvla -Wall -D_XOPEN_SOURCE=500
gcc -o app.exe main.o cars.o
 
