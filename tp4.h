//
// Created by Arthur Maugée on 21/05/2024.
//

#ifndef TP4_TP3_H
#define TP4_TP3_H

#include <stdlib.h>
#include <stdlib.h>

typedef struct T_Sommet T_Sommet;
typedef T_Sommet *T_Arbre;
struct T_Sommet{
    int inf;
    int sup;
    T_Sommet * Lson;
    T_Sommet * Rson;
};

T_Sommet *creerSommer(int element);
int empty_abr(T_Arbre abr);
T_Sommet *rechercherElement(T_Arbre abr, int element);
void afficher_intervalle(T_Sommet som);
void afficherSommet(T_Arbre abr);
void afficherElements(T_Arbre abr);

#endif //TP4_TP3_H
