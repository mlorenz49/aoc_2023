#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

int main()
{
    char *filename = "input.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    // read one character at a time and
    // display it to the output
    char line[256];
    int line_int;

    int calories_elf = 0;
    int max_cals = 0;

    while (fgets(line, sizeof(line), fp))

        if (strcmp(line, "\n") != 0)
        {
            line_int = atoi(line);
            calories_elf += line_int;
            // printf("%i\n", line_int);
        }
        else
        {
            if (calories_elf > max_cals)
            {
                max_cals = calories_elf;
            }
            calories_elf = 0;
        }

    // close the file
    fclose(fp);

    printf("%i\n", max_cals);

    return 0;
}
