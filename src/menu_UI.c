#include <stdio.h>
#include <stdbool.h>
#include "menu_UI.h"

#include "globals.h"
#include "gen_util.h"
#include "menu_util.h"

// General
void displayStats(PlayerStats player)
{
    printf("Balance: $%.2lf\n", player.dBal);
    printf("Favors:  %d\n", player.fBal);
    printf("$ Mult:  %.2fx\n", player.dollarRate);
    printf("F Mult:  %.2fx\n\n", player.favorRate);
}

//

// main_options
char *promptOptions =
"Options\n"
"1: Linebreak Length\n"
"2: Placeholder\n"
"\n9: Exit\n\n"
"==> ";

char *promptLineBreakSetting =
"Default Linebreak Length: 20\n"
"Please enter your desired length\n\n"
"==> ";

// main_info
char *promptInfo =
"Information\n"
"1: How to Play\n"
"2: Lore\n"
"\n9: Exit\n\n"
"==> ";

char *promptH2P =
"How to play WIP\n"
"wasdwasdwasd\n"
"\n9: Exit\n\n"
"==> ";

char *promptLore =
"Lore WIP\n"
"\n9: Exit\n\n"
"==> ";

// main_credits
char *promptCredits =
    "Credits WIP\n"
    "\n9: Exit\n\n"
    "==> ";