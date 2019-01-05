#include "actions.h"
#include <stdio.h>
#define MAX_PLAY_ACTION 20
unsigned int i = 0;
char play_actions[] = {
    ACTION_MOVE_L,
    ACTION_DASH_D,
    ACTION_SPLASH
};

char get_action()
{
    char ret_val = play_actions[i];
    if (i + 1 < sizeof(play_actions))
    {
        i++;
    }
    else{
        i=0;
    }
    return (ret_val);
}
