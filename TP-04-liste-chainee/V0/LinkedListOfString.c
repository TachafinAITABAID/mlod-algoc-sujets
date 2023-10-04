// gcc -W -Wall -std=c99 linkedList.c linkedListOfString.c -o linkedListOfString 

// valgrind -leak-check=yes --leak-check=full
//--show-leak-kinds=all --show-reachable=no ./linkedListOfString

#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void afficheElement( Element e){
    printf("%s",(char*)e);

}

void detruireElement( Element e){

}

bool equalsElement(Element e1,Element e2){
    return (char *)e1 == (char *) e2;
}
void main(){

    Liste l, p;

	l = NULL;
	printf("estVide(l) = %s\n",estVide(l)?"TRUE":"FALSE");

	l = ajoutTete(" !",l);
	l = ajoutTete(" !",l);
	l = ajoutTete(" !",l);
	l = ajoutTete(" !",l);
	l = ajoutTete(" !",l);
	l = ajoutTete(" !",l);
	l = ajoutTete(" ABAID",l);
	l = ajoutTete(" AIT",l);
	l = ajoutTete("Tachafin",l);

	afficheListe_i(l);
    ajoutFin_r(" MPSI",l);
	afficheListe_i(l);

	ajoutFin_r(" MP",l);
	afficheListe_i(l);

	p = cherche_i("PC",l);
	printf("cherche_i(200) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	p = cherche_i(" AIT",l);
	if(estVide(p))
		printf("cherche_i(AIT) : [ERREUR] pas trouve \n");
	else {
		printf("cherche_i(AIT) : trouve ");
		afficheElement(p->val);
		printf("\n");
	}

	p = cherche_r(" ABAID",l);
	printf("cherche_r( ABAID) : %s\n",estVide(p)?"pas trouve":"[ERREUR] trouve !!!");

	

	printf("retirePremier_i(!)   : ");
	l = retirePremier_i(" !",l);
	afficheListe_r(l);

	printf("retirePremier_i(!)   : ");
	l = retirePremier_i(" !",l);
	afficheListe_r(l);

	printf("retirePremier_i(!) : ");
	l = retirePremier_i(" !",l);
	afficheListe_r(l);

	printf("retirePremier_r(!)   : ");
	l = retirePremier_r(" !",l);
	afficheListe_r(l);



	detruire_r(l);

}