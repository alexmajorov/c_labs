#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cars.h"


int main(int argc, char **argv)
{
    if (argc < 3)
        return EXIT_FAILURE;
    char *command = argv[2];
    char *file_name = argv[1];
    FILE *f = fopen(file_name, "r+b");
    if (f == NULL)
        return EXIT_FAILURE;
    if (strcmp(command, "add") == 0)
    {
        // ./app.exe file_name add mark number fuel mass 
        if (argc != 7)
            return EXIT_FAILURE;
        char *mark = argv[3];
        char *number = argv[4];
        double fuel = atof(argv[5]);
        double mass = atof(argv[6]);
        struct car entry;
        strncpy(entry.mark, mark, STR_LEN);
        strncpy(entry.number, number, STR_LEN);
        entry.fuel = fuel;
        entry.mass = mass;
        add_entry(f, &entry);
    }
    else if (strcmp(command, "srtmark") == 0)
    {
        if (argc != 3)
        {
            fclose(f);
            return EXIT_FAILURE;
        }
        sort_by_mark(f);
    }
    else if (strcmp(command, "srtnum") == 0)
    {
        if (argc != 3)
        {
            fclose(f);
            return EXIT_FAILURE;
        }
        sort_by_number(f);
    }
    else if (strcmp(command, "srtmass") == 0)
    {
        if (argc != 3)
        {
            fclose(f);
            return EXIT_FAILURE;
        }
        sort_by_mass(f);
    }
    else if (strcmp(command, "srtfuel") == 0)
    {
        if (argc != 3)
        {
            fclose(f);
            return EXIT_FAILURE;
        }
        sort_by_fuel(f);
    }
    else if (strcmp(command, "delmycars") == 0)
        delete_my_cars(f);
    else if (strcmp(command, "addrenos") == 0)
        add_renos(f);
    
    
    print_file(f);
    
        
    fclose(f);
    return EXIT_SUCCESS;
}
