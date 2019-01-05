
#include "actions.h"
#include "player.h"
#include "param.h"
#include "world.h"

#define  DASH_LENGTH 8

static void (*pf_actions[ACTION_NUMBER])(t_player* p_player) = {0};

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_still(t_player *p_player)
{
    p_player->credits--;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_move_l(t_player *p_player)
{
    p_player->x = (p_player->x == 0) ? MAP_SIZE - 1 : p_player->x - 1;
    p_player->credits--;
#ifdef DEBUG
    printf("ml%d\n", p_player->x);
#endif
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_move_r(t_player *p_player)
{
    p_player->x = (p_player->x == MAP_SIZE-1) ? 0 : p_player->x + 1;
    p_player->credits--;
#ifdef DEBUG
    printf("mr%d\n", p_player->x);
#endif 
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_move_u(t_player *p_player)
{
    p_player->y = (p_player->y == 0) ? MAP_SIZE - 1 : p_player->y - 1;
    p_player->credits--;
#ifdef DEBUG
    printf("mu%d\n", p_player->y);
#endif
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_move_d(t_player *p_player)
{
    p_player->y = (p_player->y == MAP_SIZE - 1) ? 0 : p_player->y + 1;
    p_player->credits--;
#ifdef DEBUG
    printf("md%d\n", p_player->y);
#endif
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_dash_l(t_player *p_player)
{
    int i = 0;
    for (i = 0 ; i < DASH_LENGTH; i++)
    {
        p_player->x = (p_player->x == 0) ? MAP_SIZE - 1 : p_player->x - 1;
        world_paint_spot(p_player->x, p_player->y, p_player->id);
    }
#ifdef DEBUG
    printf("dl%d\n", p_player->x);
#endif
    p_player->credits-= 10;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_dash_r(t_player *p_player)
{
    int i = 0;
    for (i = 0 ; i < DASH_LENGTH; i++)
    {
        p_player->x = (p_player->x == MAP_SIZE-1) ? 0 : p_player->x + 1;
        world_paint_spot(p_player->x, p_player->y, p_player->id);
    }
#ifdef DEBUG
    printf("dl%d\n", p_player->x);
#endif
    p_player->credits-= 10;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_dash_u(t_player *p_player)
{
    int i = 0;
    for (i = 0 ; i < DASH_LENGTH; i++)
    {
        p_player->y = (p_player->y == 0) ? MAP_SIZE - 1 : p_player->y - 1;
        world_paint_spot(p_player->x, p_player->y, p_player->id);
    }
#ifdef DEBUG
    printf("du%d\n", p_player->y);
#endif
    p_player->credits-= 10;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_dash_d(t_player *p_player)
{
    int i = 0;
    for (i = 0 ; i < DASH_LENGTH; i++)
    {
        p_player->y = (p_player->y == MAP_SIZE - 1) ? 0 : p_player->y + 1;
        world_paint_spot(p_player->x, p_player->y, p_player->id);
    }
#ifdef DEBUG
    printf("dd%d\n", p_player->y);
#endif
    p_player->credits -= 10;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_teleport_l(t_player *p_player)
{
    int pos = p_player->x - 8;
    p_player->x = (pos < 0) ? MAP_SIZE + pos : pos;
    p_player->credits -= 4 ;
#ifdef DEBUG
    printf("tl%d\n", p_player->x);
#endif
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_teleport_r(t_player *p_player)
{
    p_player->x = p_player->x + 8;
    p_player->x = (p_player->x > MAP_SIZE - 1) ? p_player->x % MAP_SIZE : p_player->x;
    p_player->credits -= 4 ;
#ifdef DEBUG
    printf("tr%d\n", p_player->x);
#endif
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_teleport_u(t_player *p_player)
{
    /*
    p_player->y = p_player->y - 8;
    p_player->y = (p_player->y > MAP_SIZE) ? p_player->y % MAP_SIZE : p_player->y;
    */

    int pos = p_player->y - 8;
    p_player->y = (pos < 0) ? MAP_SIZE + pos : pos;
    p_player->credits -= 4 ;
#ifdef DEBUG
    printf("tu%d\n", p_player->y);
#endif
    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_teleport_d(t_player *p_player)
{
    p_player->y = p_player->y + 8;
    p_player->y = (p_player->y > MAP_SIZE-1) ? p_player->y % MAP_SIZE : p_player->y;
    p_player->credits -= 4 ;
#ifdef DEBUG
    printf("td%d\n", p_player->y);
#endif

    world_paint_spot(p_player->x, p_player->y, p_player->id);
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_splash(t_player *p_player)
{
    unsigned int max_y = (p_player->y == MAP_SIZE -1) ? 0 : p_player->y + 1;
    unsigned int max_x = (p_player->x == MAP_SIZE -1) ? 0 : p_player->x + 1;

    unsigned int min_y = (p_player->y == 0) ? MAP_SIZE -1 : p_player->y - 1;
    unsigned int min_x = (p_player->x == 0) ? MAP_SIZE -1 : p_player->x - 1;    

    world_paint_spot(max_x,       p_player->y, p_player->id);
    world_paint_spot(max_x,       max_y,       p_player->id);
    world_paint_spot(p_player->x, max_y,       p_player->id);
    world_paint_spot(min_x,       p_player->y, p_player->id);
    world_paint_spot(min_x,       min_y,       p_player->id);
    world_paint_spot(p_player->x, min_y,       p_player->id);
    world_paint_spot(min_x,       max_y,       p_player->id);
    world_paint_spot(max_x,       min_y,       p_player->id);

}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void action_bomb(t_player *p_player)
{

}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void actions_init(void)
{
    pf_actions[ACTION_STILL] =  action_still;
    pf_actions[ACTION_MOVE_L] = action_move_l;
    pf_actions[ACTION_MOVE_R] = action_move_r;
    pf_actions[ACTION_MOVE_U] = action_move_u;
    pf_actions[ACTION_MOVE_D] = action_move_d;
    pf_actions[ACTION_DASH_L] = action_dash_l;
    pf_actions[ACTION_DASH_R] = action_dash_r;
    pf_actions[ACTION_DASH_U] = action_dash_u;
    pf_actions[ACTION_DASH_D] = action_dash_d;
    pf_actions[ACTION_TELEPORT_L] = action_teleport_l;
    pf_actions[ACTION_TELEPORT_R] = action_teleport_r;
    pf_actions[ACTION_TELEPORT_U] = action_teleport_u;
    pf_actions[ACTION_TELEPORT_D] = action_teleport_d;
    pf_actions[ACTION_SPLASH] = action_splash;
    pf_actions[ACTION_BOMB] = action_bomb;
}

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void actions_do(t_player *p_player, enum action act_id)
{
    pf_actions[act_id](p_player);
}
