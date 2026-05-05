#include "game_shop_util.h"
#include <stdio.h>

#include "globals.h"
#include "game_UI.h"
#include "gen_util.h"
#include "game_shop_bicycle.h"


void print_bike_stock(Bicycle *bikeStock, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("Bike %d\n", bikeStock[i].type);
        printf("%-7s %d\n", "HP:", bikeStock[i].HP);
        printf("%-7s %d\n", "Speed:", bikeStock[i].speed);
        printf("%-7s %d\n", "Weight:", bikeStock[i].weight);
        printf("%-7s %d\n", "Cost:", bikeStock[i].value);
    }
}

void purchase_modifier(PlayerStats *playerInfo, Bicycle bikeProduct)
{
    playerInfo->dollars -= bikeProduct.value;
    playerInfo->bike = bikeProduct;
    
    return;
}

bool purchase_bike(PlayerStats *playerInfo, Bicycle bikeProduct)
{
    if (playerInfo->dollars < bikeProduct.value)
    {
        return false;
    }

    purchase_modifier(playerInfo, bikeProduct);

    return true;
}