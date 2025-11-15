#include "game_logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "globals.h"
#include "game_UI.h"
#include "gen_util.h"

void change_stats_additive(PlayerStats *player, PlayerStats change)
{
    player->dollars += change.dollars;
    player->favors += change.favors;
    player->dollarRate += change.dollarRate;
    player->favorRate += change.favorRate;
}

void change_stats_multiplicative(PlayerStats *player, PlayerStats change)
{
    player->dollars *= change.dollars;
    player->favors *= change.favors;
    player->dollarRate *= change.dollarRate;
    player->favorRate *= change.favorRate;
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

// Calculates in integers (cents), then converts to dollars
float dollar_RNG(PlayerStats player)
{
    int initialDollars = 0;
    float dollarsEarned = 0;

    initialDollars = basic_RNG(nano_seed(), 100, 300);
    dollarsEarned = player.dollarRate * (initialDollars / 100.0f);

    return dollarsEarned;
}

// Chooses a random # (1-99) * 100 and checks if it is less than favorRate * 10^4
int favor_RNG(PlayerStats player)
{
    int favorsEarned, favorRNG, favorChance;
    favorsEarned = favorRNG = favorChance = 0;
    
    favorRNG = 100 * basic_RNG(nano_seed(), 1, 100);
    favorChance = (int)((player.favorRate * 100.0f) * 100.0f);
    if (favorRNG < favorChance)
    {
        favorsEarned++;
    }

    return favorsEarned;
}

PlayerStats biking_RNG(int iterations, PlayerStats player)
{
    lineBreak(lineBreakLen);
    
    PlayerStats change = {0.0f, 0, 0.0f, 0.0f};
    
    for (int i = 0; i < iterations; i++)
    {
        change.dollars += dollar_RNG(player);
        change.favors += favor_RNG(player); 
    }
    
    return change;
}