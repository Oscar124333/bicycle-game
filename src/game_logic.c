#include "game_logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "globals.h"
#include "game_UI.h"
#include "gen_util.h"

void change_stats_additive(PlayerStats *player, PlayerStats change)
{
    player->dollars += change.dollars;
    player->favors += change.favors;
    /*
    player->dollarRate += change.dollarRate;
    player->favorRate += change.favorRate;
    */
}

void change_stats_multiplicative(PlayerStats *player, PlayerStats change)
{
    player->dollars *= change.dollars;
    player->favors *= change.favors;
    /*
    player->dollarRate *= change.dollarRate;
    player->favorRate *= change.favorRate;
    */
}

/****************
*   RNG stuff
****************/

unsigned int nano_seed(void)
{
    struct timespec seed;
    if (clock_gettime(CLOCK_MONOTONIC, &seed) == -1)
    {
        perror("clock_gettime error");
    }
    unsigned int seedOut = (unsigned int)(seed.tv_sec ^ seed.tv_nsec);
    return seedOut;
}

int basic_RNG(unsigned int seed, int rangeStart, int rangeEnd)
{
    int output = 0;
    srand(seed);
    output = (rand() % (rangeEnd - rangeStart)) + rangeStart;
    return output;
}

float dollar_RNG(BasicOperands dollars)
{
    // Calculates in integers (cents), then converts to dollars
    float dollarsEarned = 0;

    int minDollars = (int) (dollars.base * 100.0f);
    // double maxDollarsFormula = (-3007 / (dollars.base + 30.05)) + 100;
    double maxDollarsFormula = sqrt(dollars.base * 2.3f);
    int maxDollars = (int) ((maxDollarsFormula + dollars.base) * 100.0f); 
    dollarsEarned = basic_RNG(nano_seed(), minDollars, maxDollars);

    dollarsEarned *= dollars.mult / 100.0f;

    return dollarsEarned;
}

int favor_RNG(BasicOperands favors)
{
    // Chooses a random # (1-99) and checks if it is less than favor.base * 100
    int favorsEarned = 0;
    
    int favorRNG = basic_RNG(nano_seed(), 1, 100);
    int favorChance = (int)(favors.base * 100.0f);
    if (favorRNG < favorChance)
    {
        favorsEarned++;
    }

    favorsEarned *= favors.mult;

    return favorsEarned;
}

PlayerStats biking_RNG(int iterations, PlayerStats player)
{
    lineBreak(lineBreakLen);
    
    PlayerStats change = {0};
    
    for (int i = 0; i < iterations; i++)
    {
        change.dollars += dollar_RNG(player.arithValues.dollars);
        change.favors += favor_RNG(player.arithValues.favors); 
    }
    
    return change;
}