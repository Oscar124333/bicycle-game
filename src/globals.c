#include "globals.h"
#include <stdio.h>

// Constants
const int RESET = 0;
const int EXIT = 9;
const int NULLTERMSPACE = 1;

// Global Variables
int userInput = 0;
int lineBreakLen = 20;
int userSave = 1;

// Gameplay Data
/*  Distance is measured in miles * 100; 100 distance = 1 miles */
PlayerStats p1 =
{0.0f, 0,               // dollars, favors (balances)
{0, 100, 10, 100, 5},      // bicycle: type, HP, speed, weight, value
{                   // stats: multiplier, base chance
    {1.0f, 0.25f},      // dollars
    {1.0f, 0.06f},      // favors
    {0.3f, 0.5f}        // accidents (0.3 * 0.5 = 0.15 = 15%)
}
};
int dayCount = 0;
