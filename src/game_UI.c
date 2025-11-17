#include "game_UI.h"
#include <stdio.h>

#include "globals.h"
#include "gen_util.h"

// Prompts
char *promptGameMenu = "hmmmm";

// Print Functions
void displayStats(const PlayerStats *player)
{
    printf("Balance: $%.2lf\n", player->dollars);
    printf("Favors:  %d\n\n", player->favors);
    /*
    printf("$ Mult:  %.2fx\n", player.dollarRate);
    printf("F Mult:  %.2fx\n\n", player.favorRate);
    */
}

void displayBiking_RNG(PlayerStats change)
{
    float waitTime = 0.5f;

    wait(waitTime);
    printf("biking...\n");
    wait(waitTime);
    printf("earned %.2f dollars!\n", change.dollars);
    if (change.favors > 0)
    {
        printf("earned %d favors!\n", change.favors);
    }
    wait(waitTime);
}