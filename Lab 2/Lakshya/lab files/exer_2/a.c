#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[0]){
    if(argc != 3){
        printf("Error! enter only two file names!");
        exit(2);
    }

    printf("File name entered are %s and %s\n", argv[1], argv[2]);
    // to read from argv[1] and write into argv[2]
    // we have to copy the content
    FILE* read = fopen(argv[1], "r");
    FILE* write = fopen(argv[2], "w");

    if(read == NULL || write == NULL){
        printf("Error in opening file!");
        exit(1);
    }

    char temp[250];
    do{
        fscanf(read, "%s", temp);
        fprintf(write, "%s ", temp);
    }while(!feof(read));

    fclose(read);
    fclose(write);

    printf("File successfully copied and pasted!\n");

    return 0;
}