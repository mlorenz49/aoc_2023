#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <cs50.h>

//Prototype
int total_cals(int array[]);

int main()
{
    char *filename = "input.txt";
    FILE *fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("Error: could not open file %s", filename);
        return 1;
    }

    char line[256];
    int line_int;

    int calories_elf = 0;
    int max_cals[3];

    max_cals[0] = 0;
    max_cals[1] = 0;
    max_cals[2] = 0;

    while (fgets(line, sizeof(line), fp))

        if (strcmp(line, "\n") != 0)
        {
            line_int = atoi(line);
            calories_elf += line_int;
            // printf("%i\n", line_int);
        }
        else
        {
            for (int i = 0; i < 3; i++)
            {
                if (calories_elf > max_cals[i])
                {
                    max_cals[i] = calories_elf;
                    calories_elf = 0;
                    continue;
                }
            }

            calories_elf = 0;

        }

    // close the file
    fclose(fp);

    printf("total calories: %i\n", total_cals(max_cals));

    return 0;
}

int total_cals(int array[])
{
    int sum = 0;

    for (int n = 0; n < 3; n++)
    {
        sum += array[n];
        printf("%i\n", array[n]);
    }
    return sum;
}
