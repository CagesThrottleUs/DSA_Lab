#include<stdio.h>

int main(int argc, char* argv[]){
    printf("Total number of command line args: %d\n", argc);
    for(int i=0; i<argc; i++){
        printf("[%d]: %s\n", i, argv[i]);
    }
    return 0;
}