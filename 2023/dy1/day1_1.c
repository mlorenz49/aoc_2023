#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

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

    int first_digit;
    int last_digit;
    int calib;
    int calib_sum = 0;
    int i = 0;

    do
    {
        // Taking input single character at a time
        char c = fgetc(fp);

        if (c != '\n'){

            if (isdigit(c) & (i == 0)){
                first_digit = c;
                i++;
            }
            else if (isdigit(c)){
                last_digit = c;
                i++;
            }
        }

        else {

            if (i == 1){
                last_digit = first_digit;
            }

            char calib_ar[10] = {first_digit,last_digit};
            calib = atoi(calib_ar);
            calib_sum += calib;

            // reset for next line
            i = 0;
            first_digit = 0;
            last_digit = 0;
        }

        // Checking for end of file
        if (feof(fp))
            break ;

        printf("%c", c);
    }  while(1);

    printf("%i", calib_sum);

    // close the file
    fclose(fp);

    return 0;
}
