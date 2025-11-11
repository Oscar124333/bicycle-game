#ifndef menuUTIL_H
#define menuUTIL_H

#include "globals.h"

// Saves
bool does_save_exist(int inSave);

int save_handler(void);

// Main Funcs
int main_options(void);

int main_info(void);

int main_credits(void);

void displayStats(PlayerStats player);

#endif