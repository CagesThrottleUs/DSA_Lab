#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "cycle.h"

int createCycle(struct linkedList *ls, FILE* f){
    srand(time(0));
    
    if (length(ls) == 0){
        printf("Please fill up the list first!\n");
        return -2;
    }
    int toss = rand() % 2;
    // 0 is linear and 1 is cyclic
    if(toss != 0){
        fprintf(f, "\n\nThe Cyclic List\n\n");
        if (length(ls) == 1){
            printf("The list is too small (size:1), please enter more elements\n");
            return -1;
        }
        else{
            int r = rand() % (length(ls) - 1) + 1;
            printf("Node value selected: %d\n", r);
            struct node *curr = ls->head;
            struct node *gen = ls->head;
            int i = 1;
            while (curr->next != NULL){
                if (i == r){
                    i++;
                    gen = curr;
                    fprintf(f, "The last CycleElement connects here\n");
                    fprintf(f, "|\n");
                    fprintf(f, "--> ");
                    fprintf(f, "CycleElement value: %d\n", curr->element);
                    curr = curr->next;
                }
                else{
                    i++;
                    fprintf(f, "\tCycleElement value: %d\n", curr->element);
                    curr = curr->next;
                }
            }
            curr->next = gen;
            fprintf(f, "\tCycleElement value: %d\n", curr->element);
            return r;
        }
    }
    return 0;
}

/*  function: distance()
    @param:
        linkedList
        a node (assumed to be in the list)
    @return:
        0 if the node is = head
        else distance away from head
    @desc:
        calculates the distance between the
        linkedList head and that to node pointer.
*/
int distance(struct linkedList *ls, struct node *ptr){
    struct node *curr = ls->head;
    int distance = 0;
    // ptr cannot be outside of list because of the implementation
    while(curr != ptr){
        curr = curr->next;
        distance++;
    }
    return distance;
}

int testCyclic(struct linkedList *ls){
    int status = 0; // linear, 1 cyclic
    if (ls->head == NULL){
        printf("List is empty! Cyclic test is indeterminate.\n");
        return status;
    }
    else if(ls->head->next == NULL){
        printf("List has only one element! It's a linear list\n");
        return status;
    }
    else{
        struct node *hare = ls->head;
        struct node *tort = ls->head;
        while(hare != NULL && hare->next != NULL){
            int hd = distance(ls, hare);
            int td = distance(ls, tort);
            if(td != 0 && hd <= td){
                status = 1;
                break;
            }
            tort = tort->next;
            hare = hare->next;
            hare = hare->next;
        }
    }
    return status;
}

void makeCircularList(struct linkedList *ls, int status, unsigned long int *total_mem, FILE *f){
    if(status == 0){
        if(length(ls) == 0){
            printf("Empty List! Cannot make it circular\n");
        }
        else if(length(ls) == 1){
            printf("Singleton List! Cannot make it circular\n");
        }
        else{
            struct node *curr = ls->head;
            fprintf(f, "\n\nThe Circular List\n\n");
            fprintf(f, "The last CircularElement connects here\n");
            fprintf(f, "|\n");
            fprintf(f, "--> ");
            fprintf(f, "CircularElement value: %d\n", curr->element);
            for(int i=1; i<length(ls); i++){
                curr = curr->next;
                fprintf(f, "\tCircularElement value: %d\n", curr->element);
            }
            curr->next = ls->head;
            fprintf(f, "\tCircularElement value: %d\n", curr->element);
        }
    }
    else{
        struct node *curr = ls->head->next;
        int dis[2] = {distance(ls, curr), 0};
        fprintf(f, "\n\nThe Circular List\n\n");
        while(dis[0] > dis[1]){
            dis[1] = dis[0];
            curr = curr->next;
            dis[0] = distance(ls, curr);
        }
        for(int i=0; i<dis[0]; i++){
            deleteFirst(ls, total_mem);
        }
        curr = ls->head;
        fprintf(f, "The last CircularElement connects here\n");
        fprintf(f, "|\n");
        fprintf(f, "--> ");
        fprintf(f, "CircularElement value: %d\n", curr->element);
        curr = curr->next;
        for (int i = dis[0]; i < dis[1]; i++){
            fprintf(f, "\tCircularElement value: %d\n", curr->element);
            curr = curr->next;
        }
    }
}