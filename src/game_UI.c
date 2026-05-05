#include "game_UI.h"
#include <stdio.h>

#include "globals.h"
#include "gen_util.h"

// Prompts
int promptDayCountSize = 11;   // "Day ####.\n"    
char *promptGameMenu =
    "1: Bike to School\n"
    "2: Shop\n"
    "3: Skills\n"
    "4: Home\n"
    "5: Iterate\n"
    "\n9: Exit\n\n";

// Prompts SHOP
char *promptGameShopMenu =
    "Byron's Bike Shop\n"
    "1: Bicycles\n"
    "2: Placeholder\n"
    "\n9: Exit\n";

char *promptGameShopBIKE =
    "Bicycles In Stock\n"
    "1: one\n"
    "2: two\n"
    "3: three\n"
    "4: four\n"
    "5: five\n"
    "\n9: Exit\n";


// Print Functions
void formatStatsToString(char *buffer, unsigned int size, const PlayerStats *player)
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