#ifndef game_shop_util_H
#define game_shop_util_H

#include <stdbool.h>
#include "globals.h"

void print_bike_stock(Bicycle *bikeStock, int length);

void purchase_modifier(PlayerStats *playerInfo, Bicycle bikeProduct);
bool purchase_bike(PlayerStats *playerInfo, Bicycle bikeProduct);

#endif