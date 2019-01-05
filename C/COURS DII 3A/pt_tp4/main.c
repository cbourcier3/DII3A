#include "cards.h"
#include <stdlib.h>

int main() {

    t_card *deck = create_deck();
    t_card *p1 = NULL;
    t_card *p2 = NULL;

    
    dispatch_2p(deck,&p1,&p2);
    printf("\npremiere main trie comme nimporte nawak\n");
    display_hand(p1);
    printf("deuxieme main trie comme nimporte nawak\n");
    display_hand(p2);

    return 0;
}

