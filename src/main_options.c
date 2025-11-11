#include <stdio.h>
#include "main_options.h"

#include "globals.h"

void change_lineBreak(int settingInput)
{
    lineBreakLen = settingInput;
    printf("\nLineBreak Length set to %d.\n", lineBreakLen);
    return;
}
