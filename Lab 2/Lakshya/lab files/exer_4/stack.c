#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void push(struct linkedList *head, int ele){
    insertFirst(head, ele);
}

void pop(struct linkedList *head){
    struct node* ele = deleteFirst(head);
    printf("Element: %d popped\n", ele->element);
}