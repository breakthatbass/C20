#include "helpers.h"
#include <stdio.h>
#include <string.h>

#define MAX 7

typedef struct
{
    char *d;
    int v;
}
dice;


int check_die(char *die)
{
    int die_val = 0; // variable to determine whether the input is in struct
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
            die_val = dices[i].v;
            return die_val;
        }
    }
    
    if (die_val == 0)
    {
        printf("Not a valid die\n");
        printf("Valid Dice:\n");
        for (int i = 0; i < MAX; i++)
        {
            printf("%s\n", dices[i].d);
        }
    }
    return 0;
}