#include<stdio.h>

int main(){
    int var = 20;
    int* ip = NULL; // declare pointers as NULL
    ip = &var;

    printf("Address of var is %x\n", &var);
    printf("Address stored in ip %x\n", ip);
    printf("Value of *ip is: %d\n", *ip);

    return 0;
}