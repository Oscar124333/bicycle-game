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

PlayerStats biking_RNG(int iterations)
{
    lineBreak(lineBreakLen);

    PlayerStats change = {0.0f, 0, 0.0f, 0.0f};

    for (int i = 0; i < iterations; i++)
    {
        srand(time(NULL));
        // Calculates in integers (cents), then converts to dollars
        change.dollars += (int)((rand() % (300 - 100)) + 100) / 100.0f;
    }
    
    return change;
}