#include "globals.h"
#include <stdio.h>

// Constants
const int RESET = 0;
const int EXIT = 9;

// Global Variables
int userInput = 0;
int lineBreakLen = 20;
int userSave = 1;

// Gameplay Data
/*  Distance is measured in miles * 100; 100 distance = 1 miles */
PlayerStats p1 =
{0.0f, 0,
{1, 100, 10, 100},
{
    {1.0f, 0.25f},
    {1.0f, 0.06f},
    {0.3f, 0.5f}
}
};
int dayCount = 0;
