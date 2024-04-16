#ifndef _CARS_H_
#define _CARS_H_
#define STR_LEN 80

#include <stdio.h>

struct car
{
	char mark[STR_LEN];
	char number[STR_LEN];
	double fuel;
	double mass;
};


void add_entry(FILE *f, struct car *entry);
void get_value(FILE *f, struct car *value, size_t index);
void set_value(FILE *f, struct car *value, size_t index);
void sort_by_mark(FILE *f);
void sort_by_number(FILE *f);
void sort_by_mass(FILE *f);
void sort_by_fuel(FILE *f);
int print_file(FILE *f);
void delete_my_cars(FILE *f);
void add_renos(FILE *f);





#endif
