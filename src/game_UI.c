#include "game_UI.h"
#include <stdio.h>

#include "globals.h"
#include "gen_util.h"

// Prompts
char * promptGameMenu = ""
char promptGameMenuFormatted[256];
char *promptGameShop =
    "Byron's Bike Shop\n"
    "1: Placeholder\n"
    "2: Placeholder\n"
    "\n9: Exit\n";


// Print Functions
void formatStatsToString(const PlayerStats *player, char *buffer, unsigned int size)
{
    snprintf(buffer, size, "Balance: $%.2lf\nFavors: %d\n\n", player->dollars, player->favors);
    // add a check for size of numbers; make a function that writes numbers with 'k', 'm', etc.

    /*
    printf("Balance: $%.2lf\n", player->dollars);
    printf("Favors:  %d\n\n", player->favors);
    ****
    printf("$ Mult:  %.2fx\n", player.dollarRate);
    printf("F Mult:  %.2fx\n\n", player.favorRate);
    */

    return;
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