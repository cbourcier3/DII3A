#include "actions.h"
#include <stdio.h>
#define MAX_PLAY_ACTION 12

char play_actions[] = {
    ACTION_DASH_L,
    ACTION_DASH_L,
    ACTION_DASH_L,
    ACTION_DASH_L,
    ACTION_DASH_L,
    ACTION_DASH_L,
    ACTION_DASH_L,
    ACTION_DASH_L,
    ACTION_DASH_L,
    ACTION_DASH_L,
    ACTION_DASH_L,
    ACTION_MOVE_D
};

char get_action()
{
    static int i = 0;
    char ret_val = 0;

    ret_val = play_actions[i];
    i++;
    if (i >= MAX_PLAY_ACTION)
    {
        i = 0;
    } 
    return (ret_val);
}