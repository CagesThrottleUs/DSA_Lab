#include "linkedlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void insert(struct linkedList *ls, int ele, unsigned long int *total_mem){
    struct node *block = (struct node*) myalloc(sizeof(struct node), total_mem);
    if(block == NULL){
        printf("Allocation unsuccessful! abort\n");
    }
    else{
        block->element = ele;
        block->next = ls->head;
        ls->head = block;
    }
}

unsigned int length(struct linkedList *ls){
    struct node *curr = ls->head;
    int length = 0;
    while(curr != NULL){
        curr = curr->next;
        length++;
    }
    return length;
}

void deleteFirst(struct linkedList *ls, unsigned long int *total_mem){
    if(ls->head == NULL){
        printf("List is empty! abort\n");
    }
    else{
        struct node *temp = ls->head;
        ls->head = ls->head->next;
        myfree(temp, total_mem, sizeof(struct node));
    }
}

struct linkedList *createList(int n, unsigned long int *total_mem, FILE *f){
    srand(time(0));
    
    printf("Attempting to create the linked list\n");
    struct linkedList *ls = (struct linkedList*) myalloc(sizeof(struct linkedList), total_mem);
    ls->head = NULL;
    if(ls == NULL){
        printf("\tLinked list cannot be created! abort\n");
        return ls;
    }
    
    printf("Attempting to create a temporary array\n");
    int *arr = (int*) myalloc(sizeof(int)*n, total_mem);
    if(arr == NULL){
        printf("\tRandom array could not be allocated! abort\n");
        return NULL;
    }

    fprintf(f, "\n\nThe Linear List\n\n");
    for(int i=0; i<n; i++){
        printf("Creating node [%d/%d]:\n", i+1, n);
        arr[i] = rand(); // give some random value
        insert(ls, arr[i], total_mem);
        fprintf(f, "\tLinearElement value: %d\n", arr[i]);
    }
    myfree(arr, total_mem, sizeof(int)*n);
    return ls;
}