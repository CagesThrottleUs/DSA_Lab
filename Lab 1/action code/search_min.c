#include <stdio.h>

int search(int arr[], int n)
{
    int i;
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("Inside function min=%d\n", min);
    return min;
}