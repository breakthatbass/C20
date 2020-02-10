#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int main(int argc, char *argv[])
{

    char *die; // variable to hold the dice
    int rolls, modifier;

    if (argc < 2) // quit the program if there are no args
    {
        printf("Usage: ./main dice-type\n");
        return 1;
    }

    die = argv[1];
    rolls = 1;
    modifier = 0;

    // assign variables if args are given
    if (argc == 3)
    {
        rolls = atoi(argv[2]);
    }
    if (argc == 4)
    {
        rolls = atoi(argv[2]);
        modifier = atoi(argv[3]);
    }

    printf("%i\n", check_die(die));

}