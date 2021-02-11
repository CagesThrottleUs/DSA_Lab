#include<stdio.h>
#include<stdlib.h>
#include "linkedlist.h"

int main(int argc, char* argv[]){
    FILE* fileptr = fopen(argv[1], "r");
    struct linkedList* head = (struct linkedList*) malloc(sizeof(struct linkedList));
    head->count = 0;
    head->first = NULL;
    while(!feof(fileptr)){
        int temp;
        fscanf(fileptr, "%d", &temp);
        insertFirst(head, temp);
    }
    fclose(fileptr);
    printf("List now is:");
    printList(head);
    printf("\nDeleting the first element!\n");
    deleteFirst(head);
    printf("List now is:");
    printList(head);

    // print list to a file
    fileptr = fopen("outputList.txt", "w");
    struct node* curr = head->first;
    while(curr != NULL){
        fprintf(fileptr, "%d\n", curr->element);
        curr = curr->next;
    }
    fclose(fileptr);
    return 0;
}