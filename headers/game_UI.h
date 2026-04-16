#ifndef gameUI_H
#define gameUI_H

#include "globals.h"

extern int promptDayCountSize;
extern char *promptGameMenu;
// SHOP
extern char *promptGameShop;
extern char *promptGameShopMenu;
extern char *promptGameShopBIKE;

void formatStatsToString(char *buffer, unsigned int size, const PlayerStats *player);
void displayBiking_RNG(PlayerStats change);

#endif