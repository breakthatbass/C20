#include "helpers.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX 6

// create struct to store the dice and values
typedef struct
{
    char *d;
    int v;
}
dice;

int check_die(char *die)
{
    int *die_val = 0; // variable to determine whether the input is in struct
    dice dices[MAX];

    // store the key value pairs for dice and their values
    dices[0].d = "d4";
    dices[0].v = 4;
    dices[1].d = "d6";
    dices[1].v = 6;
    dices[2].d = "d8";
    dices[2].v = 8;
    dices[3].d = "d10";
    dices[3].v = 10;
    dices[4].d = "d12";
    dices[4].v = 12;
    dices[5].d = "d20";
    dices[5].v = 20;

    for (int i = 0; i < MAX; i++)
    {
        // if argv[1] == any of the dice in the struct...
        if (strcmp(dices[i].d, die) == 0)
        {
            die_val = &dices[i].v;
        }
    }
    // if argv[1] don't match any dice in struct...
    if (die_val == 0)
    {
        // print the valid dice arguments and exit program
        printf("\033[0;34m");
        printf("Not a valid die\n");
        printf("\033[0m");
        printf("\033[0;32m");
        printf("Valid Dice:\n");
        printf("\033[0m");
        for (int i = 0; i < MAX; i++)
        {
            printf("%s\n", dices[i].d);
        }
        exit(1);
    }

    return *die_val;
}

void roll_dice(int die, int rolls, int modifier)
{

    printf("----------------\n");
    // roll dice as many times as requested
    srand(time(0));
    for (int i = 1; i <= rolls; i++)
    {
        // Kepp track of crit to use to not show base and modifier if they are implemented
        bool crit = false;
        // int cast = randint(die);
        int cast = (rand() % (die - 1 + 1)) + 1;

        if (cast == 20){ // critical hit true
            crit = true;
        }
        if (cast == 1 && die == 20){ // critical miss true
            crit = true;
        }

        // print info about rolls if there is a modifier
        if (modifier != 0 && crit == false)
        {
            printf("Base cast is %i\n", cast);
            printf("Modifier is %i\n", modifier);
        }

        // account for crit hit and misses while rolling a d20
        if (cast == 20)
        {
            printf("\033[1m\033[32m"); // print in green bold
            printf("Roll %i is 20! Ciritical hit!\n", i);
            printf("\033[0m");
        }
        else if (cast == 1 && die == 20)
        {
            printf("\033[1m\033[31m"); // print in red bold
            printf("Roll %i is 1. Critical miss! Dangit!\n", i);
            printf("\033[0m");
        }
        // if the modifer makes the roll go below 1, print 1
        else if (cast + (modifier) < 1)
        {
            printf("\033[36m");
            printf("Roll %i is 1\n", i);
            printf("\033[0m");
        }
        // otherwise just do the  math and print the value
        else if (modifier != 0)
        {
            printf("\033[36m");
            printf("Roll %i is %i\n", i, cast + (modifier));
            printf("\033[0m");
        }
        else // just print the rolls with no info if no additional args are inputted
        {
            printf("\033[36m");
            printf("Roll %i is %i\n", i, cast);
            printf("\033[0m");
        }
        printf("----------------\n");
        // reset crit tracker
        crit = false;
    }
}
