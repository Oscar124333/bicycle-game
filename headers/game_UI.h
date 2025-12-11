#ifndef gameUI_H
#define gameUI_H

#include "globals.h"

extern char *promptGameMenu;
extern char *promptGameShop;

void formatStats(const PlayerStats *player, char *buffer, unsigned int size);
void displayBiking_RNG(PlayerStats change);

#endif