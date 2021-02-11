#include<stdio.h>

int main(){
    int a, b;
    printf("Enter two numbers: \n");
    printf("1. ");
    scanf("%d", &a); // haha, forgot to add &a for their address operator
    printf("2. ");
    scanf("%d", &b);
    printf("Sum: %d", a+b);
    return 0;
}