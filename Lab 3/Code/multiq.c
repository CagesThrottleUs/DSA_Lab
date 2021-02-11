#include "multiq.h"
#include<stdio.h>
#include<stdlib.h>

struct multiq *createMQ(struct multiq* mq, int num){
    for(int i=0; i<num; i++){
        (mq + i)->priority = i+1;
        (mq + i)->q = newQ();
    }
    return mq;
}

int sizeMQbyPriority(struct multiq *mq, int priority){
    return lengthQ((mq + priority - 1)->q);
}

int sizeMQ(struct multiq *mq, int size_of_arr){
    int total_len = 0;
    for (int i = 0; i < size_of_arr; i++){
        total_len += sizeMQbyPriority(mq, i + 1);
    }
    return total_len;
}

struct queue getQueueFromMQ(struct multiq *mq, int priority){
    return (mq + priority - 1)->q;
}

struct multiq *addMQ(struct multiq *mq, struct task t){
    (mq + t.priority -1)->q = addQ((mq + t.priority-1)->q, t.tid);
    return mq;
}

struct task nextMQ(struct multiq *mq, int highest_priority){
    struct task t;
    t.priority = highest_priority;
    t.tid = front((mq + highest_priority - 1)->q);
    return t;
}

struct multiq *delNextMQ(struct multiq *mq, int highest_priority){
    (mq + highest_priority - 1)->q = delQ((mq + highest_priority - 1)->q);
    return mq;
}

int isEmptyMQ(struct multiq *mq, int size){
    int status = 1; // true initially
    for(int i=0; i<size; i++){
        status = isEmptyQ((mq + i)->q);
        if (status == 0) break;
    }
    return status;
}

void print(struct multiq *mq, int size){
    for(int i=0; i<size; i++){
        printf("For priority queue [%d]:\n", (mq+i)->priority);
        printQ((mq+i)->q);
    }
}