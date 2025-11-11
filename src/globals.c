#include <stdio.h>

#include "globals.h"

// Constants
const int RESET = 0;
const int EXIT = 9;

// Global Variables
int userInput = 0;
int lineBreakLen = 20;
int userSave = 1;

// Gameplay Data
/*  Distance is measured in miles * 10; 100 distance = 10 miles */
Bicycle bike1 = {0, 100, 10, 0.3f};
PlayerStats p1 = {0.0f, 0, 1.0f, 0.11f};
int dayCount = 0;
