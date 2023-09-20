#include <stdio.h>


enum Mois {
    janvier=1,
    fevrier, 
    mars,
    avril,
    mai,
    juin,
    juillet,
    aout,
    septembre,
    octobre,
    novembre,
    decembre
};

struct date {
    int jour;
    enum Mois mois; 
    int annee;

};

void initialiseDate(struct date *d){
    printf("entrez la date (jour/mois/annee) :");
    scanf("%hu %d %hu, &(d->jour),(int *)&d->mois, &d->annee );

}
void afficheDate( struct date *d){
    printf("Date : %d / %d / %d \n", &d->jour,(int )&d->mois, &d->annee);
}

int main(void){
    enum Mois mois_de_l_annee=janvier;
    printf("%u", mois_de_l_annee);
    struct date d;
    initialiseDate(&d);
    afficheDate(&d);
}


