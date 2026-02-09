#ifndef gameLOGIC_H
#define gameLOGIC_H

#include <stdbool.h>

#include "globals.h"

void change_stats_additive(PlayerStats *player, PlayerStats change);

void change_stats_multiplicative(PlayerStats *player, PlayerStats change);

int basic_RNG(unsigned int seed, int rangeEnd, int rangeStart);

unsigned int nano_seed(void);

float dollar_RNG(BasicOperands player);

int favor_RNG(BasicOperands player);

PlayerStats biking_RNG(int iterations, PlayerStats player);
int go_to_school(bool iterationState, PlayerStats *player);

#endif