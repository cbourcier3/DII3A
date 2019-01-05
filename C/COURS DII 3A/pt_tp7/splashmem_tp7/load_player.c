#include "world.h"
#include <dlfcn.h>
#include <stdio.h>

/* ------------------------------------------------------------------------- */
/*                                                                           */
/* ------------------------------------------------------------------------- */
void load_players(int argc, char *argv[])
{
    int i = 0;
    for (i = 0; i < MAX_PLAYERS; i++)
    {
        players[i]->so_handle = dlopen(argv[i+1], RTLD_LAZY);
        if (!players[i]->so_handle)
        {
            /* fail to load the library */
            fprintf(stderr, "Error open so: %s\n", dlerror());
            exit(EXIT_FAILURE);
        }

        players[i]->get_action = dlsym(players[i]->so_handle, "get_action");
        if (!players[i]->get_action)
        {
            /* no such symbol */
            fprintf(stderr, "Error: %s\n", dlerror());
            dlclose(players[i]->so_handle);
            exit(EXIT_FAILURE);
        }
    }
}