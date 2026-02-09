#ifndef gameUI_H
#define gameUI_H

#include "globals.h"

extern int promptDayCountSize;
extern char *promptGameMenu;
extern char *promptGameShop;

void formatStatsToString(char *buffer, unsigned int size, const PlayerStats *player);
void displayBiking_RNG(PlayerStats change);

#endif