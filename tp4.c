#include <stdlib.h>
#include <stdio.h>
#include "tp4.h"

T_Sommet *creerSommer(int element){
    T_Sommet *sommet = malloc(sizeof(T_Sommet));
    sommet->inf = element;
    sommet->sup = element;
    sommet->Lson = NULL;
    sommet->Rson = NULL;
    return sommet;
}

int empty_abr(T_Arbre abr){
    if (abr == NULL) {
        return 0;
    }else{
        return 1;
    }
}

T_Sommet *rechercherElement(T_Arbre abr, int element){
    if (empty_abr(abr)){
        printf("L'arbre est vide, le sommet n'a donc pas �t� trouv� ...\n");
    }
    else{
        T_Sommet  *current = abr;
        while(current != NULL){
            if (element < current->inf){
                current = current->Lson;
            }
            else if (element > current->sup){
                current = current->Rson;
            }
            else {
                return current;
            }
        }
        if (current == NULL){
            printf("Le sommet n'existe dans aucun intervalle ...\n");
            return 0;
        }
    }
}

T_Sommet *rechercherElement_messageless(T_Arbre abr, int element){
    if (empty_abr(abr)){
        return 0;
    }
    else{
        T_Sommet  *current = abr;
        while(current != NULL){
            if (element < current->inf){
                current = current->Lson;
            }
            else if (element > current->sup){
                current = current->Rson;
            }
            else {
                return current;
            }
        }
        if (current == NULL){
            return 0;
        }
    }
}

void afficher_intervalle(T_Sommet som){
    int inf = som.inf;
    int sup = som.sup;
    for (inf;inf<=sup;inf++){
        printf("[%d] ",inf);
    }
}

void afficherSommet(T_Arbre abr){
    if (abr != NULL){
        printf("[%d:%d] ",abr->inf,abr->sup);
        afficherSommet(abr->Lson);
        afficherSommet(abr->Rson);
    }
}

void afficherElements(T_Arbre abr){
    if (abr != NULL){
        afficher_intervalle(*abr);
        afficherElements(abr->Lson);
        afficherElements(abr->Rson);
    }
}


T_Arbre insererElement (T_Arbre abr, int element){
    if (abr == NULL)
        return creerSommer(element);

    if (abr->sup + 1 < element)
        abr->Rson = insererElement(abr->Rson, element);
    else if (element + 1 < abr->inf)
        abr->Lson = insererElement(abr->Lson, element);
    else {
        if (element == abr->sup + 1)
            abr->sup = element;
        else if (element + 1 == abr->inf)
            abr->inf = element;

        T_Sommet* tmp = abr;
        T_Sommet* dinf = abr->Lson;
        while (dinf != NULL && (dinf->sup + 1) != abr->inf){
            tmp = dinf;
            dinf = dinf->Rson;
        }
        if (dinf != NULL){
            abr->inf = dinf->inf;
            if (tmp == abr)
                tmp->Lson = dinf->Lson;
            else
                tmp->Rson = dinf->Lson;
            free(dinf);
        }
        else {
            tmp = abr;
            T_Sommet* dsup = abr->Rson;
            while (dsup != NULL && (abr->sup + 1) != dsup->inf){
                tmp = dsup;
                dsup = dsup->Lson;
            }
            if (dsup != NULL){
                abr->sup = dsup->sup;
                if (tmp == abr)
                    tmp->Rson = dsup->Rson;
                else
                    tmp->Lson = dsup->Rson;
                free(dsup);
            }
        }

    }
    return abr;
}