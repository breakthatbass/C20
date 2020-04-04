#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

int main(int argc, char *argv[])
{

    char *die; // variable to hold the dice
    int rolls, modifier;

    if (argc < 2) // quit the program if there are no args
    {
        printf("\n");
        printf("\033[1m\033[31m"); // print in red bold
        printf("Usage:");
        printf("\033[0m");
        printf(" ./dice\n");
        printf("\n");
        printf("Optional Arguments:\n");
        printf("\033[1m\033[32m"); // print in green bold
        printf("number-of-rolls\n");
        printf("modifier\n");
        printf("\033[0m");
        printf("\n");
        return 1;
    }

    die = argv[1];
    rolls = 1; // by default amount of rolls is 1
    modifier = 0; // by default there is no modifier

    // assign rolls var if second arg is provided
    if (argc == 3)
    {
        rolls = atoi(argv[2]);
    }
    if (argc == 4) // assign rolls and mod var if two additional args are given
    {
        rolls = atoi(argv[2]);
        modifier = atoi(argv[3]);
    }

    // take the input string for the die and set its value to new_die
    int new_die = check_die(die);

    // take the die value, amount of rolls, and modifier and roll
    roll_dice(new_die, rolls, modifier);
    //return 0;

}
