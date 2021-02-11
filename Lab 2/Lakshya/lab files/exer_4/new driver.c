#include<stdio.h>
#include<stdlib.h>
#include "stack.h"
// #include "linkedlist.h"

int main(int argc, char* argv[]){
    FILE* fileptr = fopen(argv[1], "r");
    struct linkedList *head = (struct linkedList *)malloc(sizeof(struct linkedList));
    head->count = 0;
    head->first = NULL;
    printf("Pushing elements from %s\n", argv[1]);
    while (!feof(fileptr)){
        int temp;
        fscanf(fileptr, "%d", &temp);
        printf("Read element: %d\n", temp);
        push(head, temp);
    }
    printf("Popping elements one by one\n");
    struct node* curr = head->first;
    while(curr != NULL){
        pop(head);
        curr = curr->next;
    }
}