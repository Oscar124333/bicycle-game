#ifndef game_shop_util_H
#define game_shop_util_H

#include "game_logic.c"
#include <stdbool.h>

void purchase_modifier(playerStats *playerInfo, Bicycle bikeProduct);
bool purchase_bike(PlayerStats *playerInfo, Bicycle bikeProduct);

#endif