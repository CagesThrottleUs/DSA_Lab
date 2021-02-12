/*  this is the main file for the rest of the exercise
    create a structure that holds total_mem and filename
*/
#include<stdio.h>
#include "cycle.h"
#include<sys/time.h>

int main(int argc, char *argv[]){
    struct timeval start, end;
    gettimeofday(&start, NULL);
    // list content storage
    if(argc != 3){
        printf("Not the required number of command line arguments! (=3)\n");
        return 1;
    }
    printf("Please enter a large number (N): ");
    int n;
    scanf("%d", &n);

    unsigned long int total_mem = 0;
    FILE *f = fopen(argv[1], "a");
    FILE *listStore = fopen(argv[2], "w");
    printf("The files are: %s and %s\n", argv[1], argv[2]);

    struct linkedList *ls = createList(n, &total_mem, listStore);
    if(ls == NULL){
        printf("Aborting operation! \n");
        return 2;
    }

    printf("Printing the current linear list in %s! \n", argv[2]); 

    printf("Now we attempt to create a cycle!\n");
    int node = createCycle(ls, listStore);

    int status = testCyclic(ls);
    
    if(status == 0)
        printf("The list has remained linear! Please find the list value in %s.\n", argv[2]);
    else
        printf("The list now is a cyclic, updated %s\n", argv[2]);

    printf("Now we attempt to make the list Circular\n");
    makeCircularList(ls, status, &total_mem, listStore);

    printf("The list is now circular, updated %s\n", argv[2]);

    gettimeofday(&end, NULL);

    long seconds = (end.tv_sec - start.tv_sec);
    long micros = (end.tv_usec - start.tv_usec);
    micros = seconds*100000 - micros;

    if(node == -2){
        fprintf(f, "Value of n: %d", n);
        fprintf(f, "\nLinear Empty list");
        fprintf(f, "\nTotal heap memory after main() call: %lu\n", total_mem);
        fprintf(f, "Total time for execution: %d.%d seconds\n\n", seconds, micros);
    }
    else if(node == -1){
        fprintf(f, "Value of n: %d", n);
        fprintf(f, "\nLinear Singleton list");
        fprintf(f, "\nTotal heap memory after main() call: %lu\n", total_mem);
        fprintf(f, "Total time for execution: %d.%d seconds\n\n", seconds, micros);
    }
    else if(node == 0){
        fprintf(f, "Value of n: %d", n);
        fprintf(f, "\nLinear list");
        fprintf(f, "\nTotal heap memory after main() call: %lu\n", total_mem);
        fprintf(f, "Total time for execution: %d.%d seconds\n\n", seconds, micros);
    }
    else{
        fprintf(f, "Value of n: %d", n);
        fprintf(f, "\nCyclical list with node value: %d", node);
        fprintf(f, "\nTotal heap memory after main() call: %lu\n", total_mem);
        fprintf(f, "Total time for execution: %d.%d seconds\n\n", seconds, micros);
    }
    fclose(f);
    fclose(listStore);
    return 0;
}