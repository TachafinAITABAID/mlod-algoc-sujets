#include "liste-chainee.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return l == NULL;
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste NouvelleListe = (Liste)malloc(sizeof(Cellule));
	NouvelleListe->val=v;
	NouvelleListe->suiv=NULL;
	return NouvelleListe;
}

// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {
	Liste nouvelleliste=creer(v);
	nouvelleliste->suiv =l;
	return nouvelleliste;
}


void afficheElement(Element e) {
	printf("%i ", e);
}

// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	Liste actuel= l;
	while(actuel != NULL){
		afficheElement(actuel->val);
		actuel = (actuel->suiv);
	}
	printf("\n");
}

// version recursive
void afficheListe_r(Liste l) {
	
	if (l!=NULL){
		afficheElement(l->val);
		afficheListe_r(l->suiv);		
	}
	else{
		printf("\n");
	}

}

//void detruireElement(Element e) {
//}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	while (l!= NULL){
		Liste temp = l->suiv;
		free(l);
		l=temp;
	}	
}

// version récursive
void detruire_r(Liste l) {
	if ( l!= NULL){
		detruire_r(l->suiv);
		free(l);
	}
}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste nouvelleCellule= creer(v);
	if (l==NULL){
		return nouvelleCellule;
	}
	else {
		Liste actuel=l;
		while (actuel->suiv!=NULL){
			actuel=actuel->suiv;
		}
	actuel->suiv=nouvelleCellule;
	return l;
	}
}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	if(l==NULL){
		return creer(v);
	}
	else{
		l->suiv =ajoutFin_r(v, l->suiv);
		return l;
	}
}

// compare deux elements
bool equalsElement(Element e1, Element e2){
	return e1 == e2;
}

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	Liste actuel=l;
	while(actuel!=NULL){
		if (equalsElement(actuel->val,v)){
			return actuel;
		}
		actuel=actuel->suiv;
	}
	return NULL;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if (l==NULL){
		return NULL;
	}
	else if (equalsElement(l->val,v)){
		return l;	
	}
	else{
		return cherche_r(v,l->suiv);
	}
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
Liste courant = l;
    Liste precedent = NULL;

    while (courant != NULL) {
        if (courant->val == v) {
            if (precedent == NULL) {
                // Si l'élément à retirer est en tête de liste
                Liste temp = l;
                l = l->suiv;
                free(temp);
                return l;
            } else {
                precedent->suiv = courant->suiv;
                free(courant);
                return l;
            }
        }
        precedent = courant;
        courant = courant->suiv;
    }

    // Si l'élément n'a pas été trouvé, retourne la liste inchangée
    return l;
}

// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if (l == NULL) {
        return NULL;
    }
    if (l->val == v) {
        Liste temp = l->suiv;
        free(l);
        return temp;
    }
    l->suiv = retirePremier_r(v, l->suiv);
    return l;
}


void afficheEnvers_r(Liste l){
	if (l != NULL) {
        afficheEnvers_r(l->suiv); 
        afficheElement(l->val);   
	}
	
}



