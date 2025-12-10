#ifndef gameUI_H
#define gameUI_H

#include "globals.h"

extern char *promptGameMenu;
extern char *promptGameShop;

void displayStats(const PlayerStats *player);
void displayBiking_RNG(PlayerStats change);

#endif