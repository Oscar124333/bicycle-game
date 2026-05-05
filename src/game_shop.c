#include "game_shop.h"
#include <stdio.h>

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
            screen = bicycle_shop();
            break;
        default:
            screen = OVERVIEW;
            break;
        }
        
    } while (screen != RESET);

    lineBreak(lineBreakLen);
    return RESET;
}