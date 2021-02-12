#include "alloc.h"
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define UPPER 25000
#define LOWER 10000

unsigned long int total_mem = 0;

int main(){
    printf("To test the heap!\n");
    srand(time(0));
    int i=1;
    while(i > 0){
        printf("Iter: [%d]\n", i);
        int M = (rand() % (UPPER - LOWER + 1)) + LOWER;
        printf("\tSize of array: %d\n", M);
        int *A = (int*) myalloc(M*sizeof(int),&total_mem);
        if(A == NULL){
            printf("\tAllocation Failed\n");
            break;
        }
        printf("\tAddress of A[0]  : %u\n", A);
        printf("\tAddress of A[M-1]: %u\n", &(A[M-1]));
        myfree(A,&total_mem,M*sizeof(A[0]));
        i++;
    }
    printf("The loop was executed: %d times\n", i);
}