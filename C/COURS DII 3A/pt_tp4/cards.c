#include "type_cards.h"
#include <stdlib.h>
#include <stdio.h>

void display_hand(t_card *head){
    t_card *ptr = head;
    while (ptr->next != NULL){
        printf("couleur:%d valeur:%d \n",ptr->color, ptr->value);
        ptr = ptr->next;
    }
}
t_card * create_deck(){
    t_card * ptr_head = NULL;
    ptr_head = malloc(sizeof(t_card));
    t_card * ptr_card = ptr_head;
    for(int i =0;i<MAX_COLOR;i++){
        for(int j=0;j<MAX_VAL;j++){
            ptr_head->color=i;
            ptr_head->value=j;
            ptr_head->next = malloc(sizeof(t_card));
            ptr_head=ptr_head->next;
        }
    }
    //display_hand(ptr_card);
    return ptr_card;
}
void dispatch_2p(t_card *deck,t_card **hand_p1, t_card **hand_p2){
    t_card * ptr_chaine = deck;
    t_card ** ptr_p1 = hand_p1;
    t_card ** ptr_p2 = hand_p2;
    int compteur=0;
    while (compteur<16)
    {
        ptr_p1->next = ptr_chaine;
        ptr_p1 = ptr_p1->next;
        ptr_chaine = ptr_chaine->next;
        ptr_p2->next = ptr_chaine;
        ptr_p2 = ptr_p2->next;
        ptr_chaine = ptr_chaine->next;
        compteur++;
    }
    //ptr_p1 = ptr_p1Init;
    //ptr_p2 = ptr_p2Init;
}
