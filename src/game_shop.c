#include "game_shop.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "globals.h"
#include "game_logic.h"
#include "game_UI.h"
#include "gen_util.h"

int shop_overview(void)
{
    int screen = 0;

    enum game_options
    {
        OVERVIEW,
        BICYCLES
    };

    do
    {
        switch (screen)
        {
        case OVERVIEW:
            inputPrompt(&screen, promptGameShopMenu);
            break;
        case BICYCLES:
            inputPrompt(&screen, promptGameShopBIKE);
            switch (screen)
            {
            case 1:
                printf("Sucessfully bought!\n +10 Speed");
                screen = OVERVIEW;
                break;
            default:
                screen = OVERVIEW;
                break;
            }
            break;
        default:
            screen = OVERVIEW;
            break;
        }
        
    } while (screen != RESET);

    lineBreak(lineBreakLen);
    return RESET;
}