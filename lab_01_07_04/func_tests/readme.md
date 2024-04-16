# Тесты для Лабораторной работы №01

## Входные данные
Действительные: значение x, точность e

## Выходные данные
Действительные: s(x), f(x), вычисленное с заданной точностью e, абсолютная погрешность, относительная погрешность

## Позитивные тесты
- 01 - низкая точность, x равен нулю
- 02 - низкая точность, x стремится к 1
- 03 - низкая точность, x стремится к -1
- 04 - высокая точность, x равен нулю
- 05 - высокая точность, x стремится к 1
- 06 - высокая точность, x стремится к -1
- 07 - положительный x
- 08 - отрицательный x 

## Негативные тесты
- 01 - пустой файл
- 02 - x >= 1
- 03 - x >= -1
- 04 - e <= 0
- 05 - e > 1
- 06 - буква вместо x
- 07 - буква вместо e
- 08 - неверное количество чисел