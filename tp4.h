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

//Question 1
T_Sommet *creerSommet(int element);

//Question 2
T_Arbre insererElement (T_Arbre abr, int element);
T_Arbre insererElements (T_Arbre abr, int nb_elements);

//Question 3
T_Sommet *rechercherElement(T_Arbre abr, int element);
T_Sommet *rechercherElement_messageless(T_Arbre abr, int element);

//Question 4
void afficherSommet(T_Arbre abr,int retour_ligne);
void parcours_infixe(T_Arbre abr,int retour_ligne);

//Question 5
void afficherElements(T_Arbre abr,int retour_ligne);

//Question 6
T_Sommet* minimum(T_Arbre abr);
T_Arbre supprimerElement(T_Arbre abr, int element);

//Question 7
int Taille_Memoire(T_Arbre abr);

//Annexe
//Fonction qui permet de vérifier si l'arbre est vide, retourne 1 si vrai, sinon 0
int empty_abr(T_Arbre abr);

//Affiche un sommet sous la forme [X] si non intervalle, sinon [inf:sup]
void afficher_intervalle(T_Sommet som);

//Affiche le sommet et son fils droit et gauche
void afficher_fils(T_Sommet som);

//
void afficher_sommet_affichage(T_Sommet som);

void viderBuffer();

//Vide la mémoire de toutes les données de l'arbre
void empty_abr_memory(T_Arbre abr);

#endif //TP4_GIT_TP4_H
