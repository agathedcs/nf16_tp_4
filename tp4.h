#ifndef TP4_H_INCLUDED
#define TP4_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct Sommet T_Sommet;
struct Sommet {
    int inf;
    int sup;
    T_Sommet* Lson;
    T_Sommet* Rson;
};
typedef T_Sommet* T_Arbre;

T_Sommet *creerSommer(int element);
T_Arbre insererElement (T_Arbre abr, int element);
int empty_abr(T_Arbre abr);
T_Sommet *rechercherElement(T_Arbre abr, int element);
T_Sommet *rechercherElement_messageless(T_Arbre abr, int element);
void afficher_intervalle(T_Sommet som);
void afficherSommet(T_Arbre abr);
void afficherElements(T_Arbre abr);

#endif // TP4_H_INCLUDED