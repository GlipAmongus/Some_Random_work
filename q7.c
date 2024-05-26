#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool flag = true;
    int output[512];

    FILE *fptr;
    fptr = fopen("Collatz.csv", "w+"); //creates/opens file in cmake-build-debug folder
    if (!fptr)
        perror("fopen");

    //Initialize original row
    for(int i = 2; i <= 512; i++)
        output[i-2] = i;

    while(flag == true) //Until no numbers other than 1 found
    {
        flag = false;
        for(int i = 2; i <= 512; i++)
        {
            //display row
            if(i != 512)
                fprintf(fptr, "%d, ", output[i-2]);
            else //end of row
                fprintf(fptr,"%d", output[i-2]);

            if(output[i-2] != 1)
            {
                if(output[i-2] % 2 == 0) //even case
                {
                    output[i-2] /= 2;
                    flag = true;
                }
                else //odd case
                {
                    output[i-2] = (3 * output[i-2]) + 1;
                    flag = true;
                }
            }
        }
        fprintf(fptr, "\n");
    }

    exit(0);
}