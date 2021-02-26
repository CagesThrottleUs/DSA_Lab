#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ORIGINAL_SIZE 10

int main(int argc, char *argv[]){
    if(argc != 3){
        printf("Enter the proper number of command line args!\n");
        return 1;
    }
    FILE *f = fopen(argv[1], "r");
    if(f == NULL){
        printf("File cannot be opened!\n");
        return 2;
    }
    char *token = strtok(argv[2], ".");
    int file_len = atoi(token);
    FILE *write = fopen(argv[2], "w");
    if(file_len == 0 || file_len % ORIGINAL_SIZE != 0){
        printf("Enter the correct file name to generate!");
        return 3;
    }
    else if(write == NULL){
        printf("File cannot be opened!\n");
        return 2;
    }
    char buffer[44];
    char store[ORIGINAL_SIZE][45];
    int i =0;
    while (!feof(f)){
        fscanf(f, "%s", buffer);
        printf("%s\n", buffer);
        strcpy(store[i++], buffer);
        strcat(store[i-1], "\0");
    }
    for(int i=0; i<ORIGINAL_SIZE; i++)
        printf("%d: %s\n",i, store[i]);

    for(int j=0; j<file_len; j++){
        i = j % ORIGINAL_SIZE;
        int x = fprintf(write, "%s\n", store[i]);
        printf("%d\n", x);
    }
    fclose(f);
    fclose(write);
    return 0;
}