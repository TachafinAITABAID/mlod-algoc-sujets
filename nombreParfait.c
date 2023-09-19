#include <stdio.h>

int estNombreParfait(int n){
    int sommeDiviseurs =1;
    for ( int i=2 ; i<=n/2 ; i++){
        if (n % i == 0){
            sommeDiviseurs +=i;
        }
    }
    return sommeDiviseurs==n;

    
}

int main(){
    int N;
    printf("Entrer un entier positif N:");
    scanf("%d", &N);

    for (int i=0;i<=N;i++){
        if(estNombreParfait(i)){
            printf("%d\n", i);
        }
        
    }
    return 0;
}