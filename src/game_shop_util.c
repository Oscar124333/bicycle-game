#include "game_shop_util.h"
#include <stdio.h>

#include "globals.h"
#include "game_logic.h"
#include "game_UI.h"
#include "gen_util.h"

void print_bike_stock(Bicycle bikeProduct, )
{
    printf("")
}

void purchase_modifier(playerStats *playerInfo, Bicycle bikeProduct)
{
    playerInfo->bike->dollars - bikeProduct.value;
    playerInfo->bike = bikeProduct;
    
    return;
}

bool purchase_bike(PlayerStats *playerInfo, Bicycle bikeProduct)
{
    if (playerInfo->dollars < bicyclePrice)
    {
        return false;
    }

    purchase_modifier(playerInfo, bikeProduct)

    return true;
}