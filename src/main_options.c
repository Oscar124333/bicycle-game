#include "main_options.h"
#include <stdio.h>

#include "globals.h"

void change_lineBreak(int settingInput)
{
    lineBreakLen = settingInput;
    printf("\nLinebreak Length set to %d.\n", lineBreakLen);
    return;
}
