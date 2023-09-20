#include <stdio.h>

void echangeContenu(int *a,int *b){
    int vartemp;
    vartemp =*a;
    *a=*b;
    *b= vartemp;
}

int main(void){
    int a=10;
    int b=20;
    printf("%i %i \n",a,b);
    echangeContenu(&a,&b);
    printf("%i %i \n",a,b);
    return 0;
}