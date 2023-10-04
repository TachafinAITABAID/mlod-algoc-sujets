#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#pragma once
#include <stdbool.h>

typedef void* Element;
struct cellule_s {
    Element val;
    struct cellule_s* suiv;
};
typedef struct cellule_s Cellule;
typedef Cellule* Liste;

Liste creer(Element v);
Liste ajoutTete(Element v, Liste l);
void afficheListe_i(Liste l);

bool estVide(Liste l);
extern void afficheElement(Element e);
void afficheListe_r(Liste l);
extern bool equalsElement(Element e1, Element e2);
extern void detruireElement(Element e);

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l);

// version récursive
void detruire_r(Liste l);

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l);

// version recursive
Liste ajoutFin_r(Element v, Liste l);

// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l);

// version récursive
Liste cherche_r(Element v,Liste l);

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l);

// version recursive
Liste retirePremier_r(Element v, Liste l);


void afficheEnvers_r(Liste l);
#endif