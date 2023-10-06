#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


// constructs a new (empty) list
List *list_create(void) {
    List *l = malloc(sizeof(List));
    l->first = l->last = NULL;
    return l;
}

// counts the items on a list
size_t list_count(const List *list) {
    size_t count = 0;

    ListNode *p=list->first;
    while(p!=NULL) {
        count++;
        p=p->next;
    }

    return count;
}

// inserts item_data at *end* of a list
void list_addlast(List *list, data_t item_data) {
    ListNode *new_node = malloc(sizeof(ListNode));
    new_node->data = item_data;
    new_node->next = NULL;

    if (list->last == NULL) {
        list->first = list->last = new_node;
    } else {
        list->last->next = new_node;
        list->last = new_node;
    }

}

// removes the item from *end* of the list and returns its value
data_t list_rmlast(List *list) {
    data_t valeur_supp = list->last->data;
    ListNode *precedent = NULL;
    ListNode *actuel = list->first;
    if (actuel == list->last) { // on regarde si la liste contient un seul élément
        free(actuel);
        list->first = list->last = NULL;
    } else {
        while (actuel->next != NULL) { // on parcourt la liste jusqu'à trouver le dernier élément
            precedent = actuel;
            actuel = actuel->next;
        }
        free(actuel); // on supp le dernier elément qui ets un ListNode
        list->last = precedent; // on effectue les modif sur la liste 
        precedent->next = NULL; // comme le prev ets le denrier element de la liste il n'a pas de next
    }

    return valeur_supp;
}

void list_print(List *list) {
    ListNode *current = list->first;

    printf("Liste : ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}



int main(void) {

    List *l = list_create();

    assert(list_count(l)==0);

    list_addlast(l,10);
    list_addlast(l,20);
    list_addlast(l,30);
    list_addlast(l,40);

    assert(list_count(l)==4);

    list_print(l);

    data_t t =  list_rmlast(l);

    assert(t==40);
    list_print(l);

    return 0;
}