#include <stdlib.h>
#include <stdio.h>

#include "world.h"
#include "param.h"
#include "player.h"
#include "actions.h"

uint8_t mapmem[MAP_SIZE * MAP_SIZE] = {0};
t_player* players[MAX_PLAYERS] = {0};

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void world_create_players()
{
    int i = 0;

    for (i = 0; i < MAX_PLAYERS; i++)
    {
        players[i] = (t_player*) malloc(sizeof(t_player));
        player_init(players[i], i);
        world_paint_spot(players[i]->x, players[i]->y, players[i]->id);
    }
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void world_do_player_action(t_player *p_player)
{
    if (p_player->credits > 0)
    {
        enum action act_id = ACTION_STILL;

        act_id = p_player->get_action();
        actions_do(p_player, act_id);
    }
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void world_paint_spot(uint32_t x, uint32_t y, uint32_t num)
{
    uint32_t pos = y * MAP_SIZE + x;
    mapmem[pos] = num;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void world_get_winner(char *argc[])
{
    int i = 0; 

    for (i = 0; i < SPOT_NUM; i++)
    {
        if (mapmem[i] > 0) {
            players[ mapmem[i]-1 ]->count++;
        }
    }

    for (i = 0; i < MAX_PLAYERS; i++)
    {
        printf("[%s] player %d: %d\n", argc[1+i],players[i]->id, players[i]->count);
    }
}