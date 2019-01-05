#include <stdlib.h>
#include <SDL2/SDL.h>
#include "player.h"
#include "param.h"

int start_pos_x[] = {25, 25, 75, 75};
int start_pos_y[] = {25, 75, 25, 75};

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void player_init(t_player* p_player, uint8_t num)
{
    p_player->id = num + 1;
    p_player->color = 0;
    p_player->x = start_pos_x[num];
    p_player->y = start_pos_y[num];
    p_player->data = NULL;
    p_player->credits = CREDITS;
    p_player->count = 0;
}

