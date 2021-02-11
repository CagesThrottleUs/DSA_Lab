/*  File: new_test.c    */

#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("[0]: %s", argv[0]);
    printf("\n%d", argc); //expected output: 3
    return 0;
}