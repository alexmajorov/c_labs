#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include "cars.h"


int print_file(FILE *f)
{
	fseek(f, 0, SEEK_END);
	size_t number_of_elements = ftell(f) / sizeof(struct car);
	struct car entry;
	for (size_t i = 0; i < number_of_elements; ++i)
	{
		get_value(f, &entry, i);
		printf("%s %s %lf %lf\n", entry.mark, entry.number, entry.fuel, entry.mass);
	}
	return EXIT_SUCCESS;
}

void add_entry(FILE *f, struct car *entry)
{
	size_t index = ftell(f);
	fseek(f, 0, SEEK_END);
	fwrite(entry, sizeof(struct car), 1, f);
	fseek(f, index, SEEK_SET);
}

void get_value(FILE *f, struct car *value, size_t index)
{
	fseek(f, index * sizeof(struct car), SEEK_SET);
	fread(value, sizeof(struct car), 1, f);
}

void set_value(FILE *f, struct car *value, size_t index)
{
	fseek(f, index * sizeof(struct car), SEEK_SET);
	fwrite(value, sizeof(struct car), 1, f);    
}

void sort_by_mark(FILE *f)
{
	fseek(f, 0, SEEK_END);
	size_t number_of_elements = ftell(f) / sizeof(struct car);
	struct car car1, car2;
	for (size_t i = 0; i < number_of_elements - 1; ++i)
		for (size_t j = 0; j < number_of_elements - i - 1; ++j)
        {
            get_value(f, &car1, j);
            get_value(f, &car2, j + 1);
            if (strcmp(car1.mark, car2.mark) > 0)
            {
                set_value(f, &car1, j + 1);
                set_value(f, &car2, j);
            }            
        }
}

void sort_by_number(FILE *f)
{
	fseek(f, 0, SEEK_END);
	size_t number_of_elements = ftell(f) / sizeof(struct car);
	struct car car1, car2;
	for (size_t i = 0; i < number_of_elements - 1; ++i)
		for (size_t j = 0; j < number_of_elements - i - 1; ++j)
        {
            get_value(f, &car1, j);
            get_value(f, &car2, j + 1);
            if (strcmp(car1.number, car2.number) > 0)
            {
                set_value(f, &car1, j + 1);
                set_value(f, &car2, j);
            }            
        }
}

void sort_by_mass(FILE *f)
{
    fseek(f, 0, SEEK_END);
    size_t number_of_elements = ftell(f) / sizeof(struct car);
    struct car car1, car2;
    for (size_t i = 0; i < number_of_elements - 1; ++i)
        for (size_t j = 0; j < number_of_elements - i - 1; ++j)
        {
            get_value(f, &car1, j);
            get_value(f, &car2, j + 1);
            if (car1.mass > car2.mass)
            {
                set_value(f, &car1, j + 1);
                set_value(f, &car2, j);
            }            
        }
}


void sort_by_fuel(FILE *f)
{
	fseek(f, 0, SEEK_END);
	size_t number_of_elements = ftell(f) / sizeof(struct car);
	struct car car1, car2;
	for (size_t i = 0; i < number_of_elements - 1; ++i)
		for (size_t j = 0; j < number_of_elements - i - 1; ++j)
        {
            get_value(f, &car1, j);
            get_value(f, &car2, j + 1);
            if (car1.fuel > car2.fuel)
            {
                set_value(f, &car1, j + 1);
                set_value(f, &car2, j);
            }            
        }
}

void delete_my_cars(FILE *f)
{
    fseek(f, 0, SEEK_END);
    size_t old_number_of_elements = ftell(f) / sizeof(struct car);
    size_t new_number_of_elements = 0;
    struct car entry;
    
    for (size_t i = 0; i < old_number_of_elements; ++i)
    {
        get_value(f, &entry, i);
        if (entry.fuel > 10.0)
        {
            set_value(f, &entry, new_number_of_elements);
            new_number_of_elements++;
        }
    }
    ftruncate(fileno(f), new_number_of_elements * sizeof(struct car));
}

void insert_entry(FILE *f, struct car *value, size_t index)
{
    struct car entry;
    strncpy(entry.mark, "0", STR_LEN);
    strncpy(entry.number, "0", STR_LEN);
    entry.mass = 0.0;
    entry.fuel = 0.0;
    add_entry(f, &entry);
    struct car current;
    fseek(f, 0, SEEK_END);
    size_t number_of_elements = ftell(f) / sizeof(struct car);
    for (size_t i = number_of_elements - 1; i > index; --i)
    {
        get_value(f, &current, i - 1);
        set_value(f, &current, i);
    }
    set_value(f, value, index);
}

void add_renos(FILE *f)
{
    fseek(f, 0, SEEK_END);
    size_t number_of_elements = ftell(f) / sizeof(struct car);
    struct car entry;
    strncpy(entry.mark, "Рено", STR_LEN);
    strncpy(entry.number, "0000", STR_LEN);
    entry.mass = 0.0;
    entry.fuel = 0.0;
    size_t i = 0;
    struct car current;
    while (i < number_of_elements)
    {
        get_value(f, &current, i);
        if (strcmp(current.mark, "жигули") == 0)
        {
            insert_entry(f, &entry, i + 1);
            number_of_elements++;
        }
        ++i;
    }
}
