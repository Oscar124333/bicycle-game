#ifndef ui_h
#define ui_h

// Header Constants
const int RESET = 0;
const int EXIT = 9;
#define CASE_EXIT 0

// Globals
int lineBreakLen = 20;
int inStatus = 0;

bool user_saves(void) // Currently, '1' is the only correct choice.
{
    lineBreak(lineBreakLen);

    do
    {
        do
        {
            printf("Please choose your save.\n");
            printf("\n==> ");
            inStatus = inputHandler(&userSave);

            lineBreak(lineBreakLen);
        } while (inStatus != 1);
        
        if (userSave == 1)
        {
            printf("Successfully selected save #%d.\n", userSave);
            return true;
        }
        else
        {
            printf("Save not found.\n");
        }
    } while (true);
}

int main_options(void)
{
    int m_opScreen = 0;

    enum Options{
        OPTIONS,
        LINEBREAKLEN,
        PLACEHOLDER
    };

    do
    {
        switch (m_opScreen)
        {
            case OPTIONS:
                do
                {
                    lineBreak(lineBreakLen);

                    printf("Options\n");
                    printf("1: Linebreak Length\n2: Placeholder\n\n9: Exit\n\n");
                    printf("==> ");
                    inStatus = inputHandler(&m_opScreen);
                } while (inStatus != 1);
                break;
                case LINEBREAKLEN:
                do
                {
                    lineBreak(lineBreakLen);
                    
                    printf("Default LineBreak Length: 20\nPlease enter your desired length\n");
                    printf("==> ");
                    inStatus = inputHandler(&lineBreakLen);
                } while (inStatus != 1);

                printf("\nLineBreak Length set to %d.\n", lineBreakLen);

                m_opScreen = OPTIONS;
                break;
            case PLACEHOLDER:
                m_opScreen = OPTIONS;
                break;
            case CASE_EXIT:
                break;
            default:
                m_opScreen = OPTIONS;
                break;
        }
    } while (m_opScreen != EXIT);

    return RESET;
}

int main_info(void)
{
    int m_inScreen = 0;
    
    enum Info{
        INFO,
        H2P,
        LORE
    };

    do
    {
        switch (m_inScreen)
        {
            case INFO: 
                do
                {
                    lineBreak(lineBreakLen);
                    
                    printf("Information\n");
                    printf("1: How to Play\n2: Lore\n\n9: Exit\n\n");
                    printf("==> ");
                    inStatus = inputHandler(&m_inScreen);
                } while (inStatus != 1);

                break;
            case H2P:
                do
                {
                    do
                    {
                        lineBreak(lineBreakLen);

                        printf("How to Play WIP\n");
                        printf("\n9: Exit\n\n");
                        printf("==> ");
                        inStatus = inputHandler(&m_inScreen);
                    } while (inStatus != 1);
                } while (m_inScreen != EXIT);

                m_inScreen = INFO;
                break;
            case LORE:
            do
                {
                    do
                    {
                        lineBreak(lineBreakLen);
                        printf("Lore WIP\n");
                        printf("\n9: Exit\n\n");
                        printf("==> ");
                        inStatus = inputHandler(&m_inScreen);
                    } while (inStatus != 1);
                } while (m_inScreen != EXIT);

                m_inScreen = INFO;
                break;
            default:
                m_inScreen = INFO;
                break;
        }
    } while (m_inScreen != EXIT);
    
    return RESET;
}

int main_credits(void)
{
    int m_crScreen = 0;

    enum Credits{
        CREDITS,
        PLACEHOLDER
    };
    
    do
    {
        switch (m_crScreen)
        {
            case CREDITS:
                do
                {
                    lineBreak(lineBreakLen);
                    
                    printf("Credits WIP\n");
                    printf("\n9: Exit\n\n");
                    printf("==> ");
                    inStatus = inputHandler(&m_crScreen);
                } while (inStatus != 1);
                break;
            case PLACEHOLDER:
                m_crScreen = CREDITS;
                break;
            case CASE_EXIT:
                break;
            default:
                m_crScreen = CREDITS;
                break;
        }
    } while (m_crScreen != EXIT);
    
    return RESET;
}

int game_overview(void)
{
    int g_ovScreen = 0;

    enum game_options{
        OVERVIEW,
        GO2SCHOOL,
        SHOP,
        SKILLS,
        ITERATE
    };

    lineBreak(lineBreakLen);

    printf("You wake up. It's day %d.\n", dayCount);

    do
    {
        switch (g_ovScreen)
        {
            case OVERVIEW:
                do
                {
                    lineBreak(lineBreakLen);

                    if (true)
                    {
                        displayStats(p1);
                    }

                    printf("Day %d.\n", dayCount);
                    printf("1: Bike to School\n2: Shop\n3: Skills\n4: Iterate\n\n9: Exit\n\n");
                    printf("==> ");
                    inStatus = inputHandler(&g_ovScreen);
                } while (inStatus != 1);
                break;
            case GO2SCHOOL:
                g_ovScreen = bike_manual();
                break;
            case SHOP:
            case SKILLS:
            case ITERATE:
                g_ovScreen = OVERVIEW;
                break;
            default:
                g_ovScreen = OVERVIEW;
                break;
        }
    } while (g_ovScreen != EXIT);

    return RESET;
}

void displayStats(PlayerStats player)
{
    printf("Balance: $%.2lf\n", player.dBal);
    printf("Favors:  %d\n", player.fBal);
    printf("$ Mult:  %.2fx\n", player.dollarRate);
    printf("F Mult:  %.2fx\n\n", player.favorRate);
}

#endif
