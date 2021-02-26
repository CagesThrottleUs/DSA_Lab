#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define COMMON_SIZE 10

typedef struct{
    unsigned long long cardNumber;
    char bankCode[6];
    int expMonth;
    int expYear;
    char fname[6];
    char lname[6];
} bankInfo;

/*  function: openFile
    @return:
        File pointer
    @params:
        int argc
        char *argv[]
    @desc:
        custom function to open files
        and perform checks.
*/
FILE *openFile(int argc, char *argv[]);

/*  function: readFile
    @return:
        total size of arr affected.
    @params:
        file pointer
        bankInfo array
        init_size of array
    @read:
        just reads the values from file
        and insert them to the bank array
*/
bankInfo *readFile(FILE *f, bankInfo *b, int *size);

int main(int argc, char *argv[]){ // Find the time taken for operation
    clock_t start, end;
    start = clock();

    FILE *fp = openFile(argc, argv);
    if(fp == NULL){
        printf("Terminating execution! Error Code: 1\n");
        return 1;
    }
    bankInfo *arr = (bankInfo*) malloc(sizeof(bankInfo)*COMMON_SIZE);
    int arrSize = COMMON_SIZE; // tells about total number of elements in arr
    arr = readFile(fp, arr, &arrSize);
    fclose(fp);

    end = clock();
    double diff = (double) (end - start) / CLOCKS_PER_SEC;

    FILE *metadata = fopen(argv[2], "a");
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);

    fprintf(metadata, "Time: %s", asctime(info));
    fprintf(metadata, "\tFor %d data: \n", arrSize);
    fprintf(metadata, "\tTime taken: %.8lf seconds\n", diff);
    fprintf(metadata, "\tTotal array size: %u bytes\n", sizeof(bankInfo)*arrSize);
    fclose(metadata);
    
    free(arr);
    return 0;
}

FILE *openFile(int argc,char *argv[]){
    if(argc != 3){
        printf("Please enter the proper number of inputs!\n");
        return NULL;
    }
    return fopen(argv[1], "r");
}

/*  function: insert()
    @return:
        none
    @params:
        bankInfo array
        bankInfo ele
        current hold size of arr
    @desc:
        describes how the element are 
        going to be inserted to array
*/
void insert(bankInfo *b, bankInfo ele, int current_size){
    // Here we have to just keep on adding at the end.
    b[current_size] = ele;
}

/*  function: populateEle
    @return:
        the populated element
    @params:
        buffer string
    @desc:
        using the buffer string populate
        the element of bankInfo.
*/
bankInfo populateEle(char *buffer){
    bankInfo temp;
    char *token;

    token = strtok(buffer, "\",/");
    temp.cardNumber = atoll(token);

    token = strtok(NULL, "\",/");
    strcpy(temp.bankCode, token);

    token = strtok(NULL, "\",/");
    temp.expMonth = atoi(token);
    token = strtok(NULL, "\",/");
    temp.expYear = atoi(token);

    token = strtok(NULL, "\",/");

    strcpy(temp.fname, token);

    token = strtok(NULL, "\",/");

    strcpy(temp.lname, token);

    return temp;
}

bankInfo *readFile(FILE *f, bankInfo *b, int *size){
    char *buffer;
    size_t buffSize = 44;
    buffer = (char*) malloc(sizeof(char)*buffSize);
    int total_iter = 0;

    while(!feof(f)){
        if(total_iter == *size){
            (*size) *= COMMON_SIZE;
            b = realloc(b, sizeof(bankInfo)*(*size)); 
            if(b == NULL){
                printf("Reallocation Failed!\n");
                return NULL;
            }
        }
        fscanf(f, "%s", buffer);
        bankInfo temp = populateEle(buffer);
        insert(b, temp, total_iter);
        total_iter++;
    }
    return b;
}