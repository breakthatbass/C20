#include "helpers.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h> 

#define MAX 6

typedef struct
{
    char *d;
    int v;
}
dice;


int check_die(char *die, int rolls, int modifier)
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
        if (strcmp(dices[i].d, die) == 0)
        {
            die_val = &dices[i].v;
        }
    }
    
    if (die_val == 0)
    {
        printf("Not a valid die\n");
        printf("Valid Dice:\n");
        for (int i = 0; i < MAX; i++)
        {
            printf("%s\n", dices[i].d);
            return 1;
        }
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
        // int cast = randint(die);
        int cast = (rand() % (die - 1 + 1)) + 1;

        // print info about rolls if there is a modifier
        if (modifier != 0 && cast != 20 && cast != 1)
        {
            printf("Base cast is %i\n", cast);
            printf("Modifier is %i\n", modifier);
        }

        // account for crit hit and misses while rolling a d20
        if (cast == 20)
        {
            printf("Roll %i is 20! Ciritical hit!\n", i);
        } 
        else if (cast == 1 && die == 20)
        {
            printf("Roll %i is 1. Critical miss! Dangit!\n", i);
        }
        // if the modifer makes the roll go below 1, print 1
        else if (cast + (modifier) < 1)
        {
            printf("Roll %i is 1\n", i);
        }
        // otherwise just do the  math and print the value
        else if (modifier != 0)
        {
            printf("Roll %i is %i\n", i, cast + (modifier));
        }
        else
        {
            printf("Roll %i is %i\n", i, cast);
        }
        printf("----------------\n");
    }
}