#include <stdio.h>
#include <stdlib.h>
#include "alloc.h"

void *myalloc(int size, unsigned long int *total_mem){
    void *ptr = malloc(size);
    if (ptr != NULL){
        printf("\tAllocation successfull! ");
        *total_mem += size;
        printf("\tTotal heap mem: %lu\n", *total_mem);
    }
    return ptr;
}

void myfree(void *ptr, unsigned long int *total_mem, unsigned long int mem){
    printf("\tFreeing the allocated space! ");
    free(ptr);
    *total_mem -= mem;
    printf("\tTotal heap mem: %lu\n", *total_mem);
}