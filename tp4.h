//
// Created by Arthur Maugée on 02/06/2024.
//

#ifndef TP4_GIT_TP4_H
#define TP4_GIT_TP4_H

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

T_Sommet *creerSommet(int element);
T_Arbre insererElement (T_Arbre abr, int element);
T_Arbre insererElements (T_Arbre abr, int nb_elements);
int empty_abr(T_Arbre abr);
T_Sommet *rechercherElement(T_Arbre abr, int element);
T_Sommet *rechercherElement_messageless(T_Arbre abr, int element);
void afficher_intervalle(T_Sommet som);
void afficherSommet(T_Arbre abr,int retour_ligne);
void afficherElements(T_Arbre abr,int retour_ligne);
int Taille_Memoire(T_Arbre abr);
void viderBuffer();
void empty_abr_memory(T_Arbre abr);

#endif //TP4_GIT_TP4_H
