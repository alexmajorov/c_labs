#!/bin/bash

gcc -std=c99 -Werror -Wall -Wextra -Wpedantic -Wvla -c --coverage main.c
gcc -std=c99 -Werror -Wall -Wextra -Wpedantic -Wvla -c --coverage my_string.c
gcc -o app.exe --coverage main.o my_string.o

./app.exe

rc=$?
echo "returned code ${rc}"

gcov -r -f main.c my_string.c

