#include<stdio.h>
#include<stdlib.h>
#include "que.h"

struct queue newQ(){
    struct queue q;
    q.front = NULL;
    q.rear = NULL; // remember for normal var "." & for pointer "->"
    return q;
}

int isEmptyQ(struct queue q){
    if(q.front == NULL){
        return 1;
    }
    else return 0;
}

struct queue delQ(struct queue q){
    int status = isEmptyQ(q);
    if(status == 1){
        printf("Queue is empty cannot delete anything!\n");
    }
    else{
        struct node* temp = q.front;
        q.front = (q.front)->next;
        free(temp);
    }
    return q;
}

int front(struct queue q){
    int status = isEmptyQ(q);
    if(status == 1){
        printf("The queue is empty!\n");
        return -1;
    }
    else{
        int ele = (q.front)->element;
        return ele;
    }
}

struct queue addQ(struct queue q, int ele){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->element = ele;
    newNode->next = NULL;
    int status = isEmptyQ(q);
    if(status == 1){
        q.front = q.rear = newNode;
    }
    else{
        q.rear->next = newNode;
        q.rear = q.rear->next;
    }
    return q;
}

int lengthQ(struct queue q){
    struct node* temp = q.front;
    int len = 0;
    int status = isEmptyQ(q);
    if(status == 1) return len;
    else{
        do{
            len++;
            temp = temp->next;
        } while (temp != NULL);
    }
    return len;
}

void printQ(struct queue q){
    int status = isEmptyQ(q);
    if(status == 1) printf("Queue empty\n");
    else{
        struct node* temp = q.front;
        do{
            printf("Element: %d\n", temp->element);
            temp = temp->next;
        }while(temp != NULL);
    }
}