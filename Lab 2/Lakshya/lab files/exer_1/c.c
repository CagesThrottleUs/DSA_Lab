#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[]){
    printf("Total number of command-line args: %d\n", argc);
    for(int i=0; i<argc; i++){
        printf("[%d] string_val: %s\n", i, argv[i]);
        printf("[%d] int_value : %d\n", i, atoi(argv[i]));
    }
    return 0;
}