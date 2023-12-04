#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int check_str(char int_spelled[], char arr[]);

int main()
{   // open the file
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

    char arr[9][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"}; //oneight twone threeight fiveight sevenine eightwo eighthree
    char numbers[9] = {1,2,3,4,5,6,7,8,9};
    //char str[2] = "\0"; /* gives {\0, \0} -> a means for us to store the current chr in an array*/
    char int_spelled[100];  //initiate array where chrs are gping to be stored after each loop (e.g. t,th,thr,thre,three)
    int n = 0;  //used to determine at which position to add current chr inside of the array at posiiton n
    int int_spelled_int; // binary saying if current int_spelled is in the array arr{"one"..} = 1 or not = 0

    do
    {
        // Taking input single character at a time
        char c = fgetc(fp); //get the current chr

        if (c != '\n'){
            //check if spelled out int is present
            //str[0] = c; // add current chr to beginning of array
            int_spelled[n] = c;
            int_spelled[n + 1 ] = '\0'; //strings are arrays of chrs which have null at the end
            printf("int_spelled: %s\n",int_spelled);

            // loop thorugh the written numbers in arr and see if current string is present in there
            for (int d=0; d < 9; d++){

                int_spelled_int = check_str(int_spelled, arr[d]);

                if ((int_spelled_int != 0) & (i == 0)){
                    first_digit = numbers[d] + 48;
                    printf("first digit: %i\n", first_digit);
                    i++;
                    n = -1;
                }
                else if (int_spelled_int != 0){
                    last_digit = numbers[d] + 48;
                    printf("last digit: %i\n", last_digit);
                    i++;
                    n = -1;
                }
            }

            if (isdigit(c) & (i == 0)){
                first_digit = c;
                printf("first digit: %i\n", first_digit);
                i++;
                n = -1;
            }
            else if (isdigit(c)){
                last_digit = c;
                printf("last digit: %i\n", last_digit);
                i++;
                n = -1;
            }

            n++;
            printf("%i\n", n);
        }

        else {

            if (i == 1){
                last_digit = first_digit;
            }

            char calib_ar[10] = {first_digit,last_digit};
            calib = atoi(calib_ar); //convert integers on the form of ascii code to int
            printf("calib: %i\n", calib); //callibration value we get for the line
            calib_sum += calib; //add calibration value of the line to total callibration value
            printf("callib_sum: %i\n", calib_sum);

            // reset for next line
            i = 0;
            first_digit = 0;
            last_digit = 0;
            n = 0;
        }

        // Checking for end of file
        if (feof(fp))
            break ;

    }  while(1);

    //printf("%i", calib_sum);

    fclose(fp);

    return 0;
}


int check_str(char int_spelled[], char arr[]){
    int int_spelled_len = strlen(int_spelled);

    char last_three[4];
    char last_four[5];
    char last_five[6];

    int q = 0;
    for (q=3; q >= 0; q --){
        last_three[3 - q] = int_spelled[(int_spelled_len - q)];
        last_three[3] = '\0';
    }
    for (q=4; q >= 0; q --){
        last_four[4 - q] = int_spelled[(int_spelled_len - q)];
        last_four[4] = '\0';
    }
    for (q=5; q >= 0; q --){
        last_five[5 - q] = int_spelled[(int_spelled_len - q)];
        last_five[5] = '\0';
    }

    if (strcmp(last_three, arr) == 0) {
            printf("success\n");
            return 1;
    }
    else if (strcmp(last_four, arr) == 0){
            printf("success\n");
            return 1;
    }
    else if (strcmp(last_five, arr) == 0){
            printf("success: %s\n", last_five);
            return 1;
    }
    else{
        return 0;
    }

}
