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


int dollar_RNG(PlayerStats player)
{
    int dollarsEarned = (int)((rand() % (300 - 100)) + 100) / 100.0f
    dollarsEarned *= player.dollarRate;
    return dollarsEarned;
}

int favor_RNG(PlayerStats player)
{
    int favorsEarned = 0;
    int favorRNG = 100 * (rand() % (100 - 1) + 1);
    int favorChance = (int)(player.favorRate * 100.0f) * 100.0f;

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
        srand(time(NULL));
        // Calculates in integers (cents), then converts to dollars
        change.dollars += dollar_RNG(player);
    
        change.favors += favor_RNG(player); 
    }
    
    return change;
}