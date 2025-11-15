#ifndef gameLOGIC_H
#define gameLOGIC_H

#include "globals.h"

void change_stats_additive(PlayerStats *player, PlayerStats change);
void change_stats_multiplicative(PlayerStats *player, PlayerStats change);
PlayerStats biking_RNG(int iterations);

#endif