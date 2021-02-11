#include "linkedlist.h"
#include<stdlib.h>
#include<stdio.h>
#define ERROR -69420

void insertFirst(struct linkedList *head, int ele){
    struct node* gen = (struct node* ) malloc(sizeof(struct node));
    gen->element = ele;
    gen->next = head->first;

    head->first = gen;
    head->count++;
}
// exercise: to implement
struct node *deleteFirst(struct linkedList *head){
    struct node* temp = head->first;
    head->first = temp->next; // imp to point to head->first
    head->count--;
    return temp;
}

void printList(struct linkedList *head){
    struct node* curr = head->first;

    while(curr != NULL){
        printf("\n[");
        printf("ele: %d]", curr->element);
        curr = curr->next;
    }
}
// exercise: to implement
int search(struct linkedList *head, int ele){
    int status = 0;
    struct node* curr = head->first;
    int i=1;
    while(curr != NULL){
        printf("Searching [%d/%d] ... \n", i++, head->count);
        if(curr->element == ele){
            printf("\t %d founded", ele);
            status = 1;
            break;
        }
        curr = curr->next;
    }
    return status;
}

struct node *deleteEle(struct linkedList *head, int ele){
    struct node* curr = head->first;
    struct node* error = (struct node*) malloc(sizeof(struct node));
    struct node *predecessor = (struct node *)malloc(sizeof(struct node));
    predecessor->next = curr;
    error->element = ERROR;
    error->next = NULL;
    int i=1;
    while(curr != NULL){
        printf("Searching [%d/%d] ... \n", i++, head->count);
        if(curr->element == ele){
            printf("Element Found! ");
            predecessor->next = curr->next;
            head->count--;
            printf("Element successfully deleted!\n");
            return curr;
        }
        else{
            predecessor = curr;
            curr = curr->next;
        }        
    }
    return error;
}