#include "game_shop_bicycle.h"

#include <stdio.h>

#include "globals.h"
#include "game_logic.h"
#include "game_UI.h"
#include "gen_util.h"
#include "game_shop_util.h"

Bicycle shopStock[] =
    {   // type, HP, speed, weight, value (cost)
        {1, 110, 13, 105, 75},
        {2, 30, 18, 70, 150},
        {3, 135, 15, 125, 150},
        {4, 125, 16, 95, 400},
        {5, 150, 20, 90, 1000}
    };

int bicycle_shop(void)
{

    int screen = 0;
    int userInput = 0;

    enum game_shop_bicycle
    {
        OVERVIEW,
        BIKE1,
        BIKE2,
        BIKE3,
        BIKE4,
        BIKE5
    };

    do
    {
        switch (screen)
        {
        case OVERVIEW:
            // void print_bike_stock(shopStock, sizeof(shopStock)/shopStock[0])
            inputPrompt(&screen, promptGameShopBIKE);
            break;
        case BIKE1:
            inputPrompt(&userInput, "Would you like to purchase?\n1: Yes\n2: No\n9: Exit");
            if (userInput == 1 && purchase_bike(&p1, shopStock[BIKE1-1]))
            {
                printf("Sucessfully bought BIKE1!\n");
            }
            else
            {
                printf("Insufficient funds.\n");
            }
            
            screen = OVERVIEW;
            break;
        case BIKE2:
            printf("Sucessfully bought BIKE2!\n");
            screen = OVERVIEW;
            break;
        case BIKE3:
            printf("Sucessfully bought BIKE3!\n");
            screen = OVERVIEW;
            break;
        case BIKE4:
            printf("Sucessfully bought BIKE4!\n");
            screen = OVERVIEW;
            break;
        default:
            screen = OVERVIEW;
            break;
        }
        
    } while (screen != RESET);

    lineBreak(lineBreakLen);
    return RESET;
}