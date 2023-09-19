#include <stdio.h>
typedef short TypeEntier;

TypeEntier factorielle(TypeEntier n){
    int k=1;

    for(int i=1 ; i<=n ; i++){
        k= k*i;
    }
    return k;
}

int main(void){
    int n;
    printf("Saisir l'entier n:");
    scanf("%d", &n);
    printf("%d",factorielle(n));
    

}


