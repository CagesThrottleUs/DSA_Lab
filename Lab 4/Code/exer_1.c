#include<stdio.h>

int bits = 10;

void p(int n);
void g();
void h();
void d();

int main(){
    printf("To understand stack memory...");
    printf("\n\n One needs to understand that:\n");
    printf("\tLocal Variables are automatically allocated when function is called.\n");
    printf("\tThey are also automatically deallocated when the function call is over.\n");
    printf("\tThat's why they are called Automatic Variables.");
    // Now change the order
    printf("\nGlobal variable location: %u\n", &bits);
    p(0);
    g();
    d();
    h();
    return 0;
}

void p(int n){
    printf("Inside p()\n");
    int pilani = 25;
    printf("\taddress of n: %u\n", &n);
    p(n+1);
}

void g(){
    printf("Inside g()\n");
    int goa = 25;
    printf("\taddress of goa: %u\n", &goa);
    d();
}

void h(){
    printf("Inside h()\n");
    int hyd = 25;
    printf("\taddress of hyd: %u\n", &hyd);
}

void d(){
    printf("Inside d()\n");
    int dub = 25;
    printf("\taddress of dub: %u\n", &dub);
    h();
}

