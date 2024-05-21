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
        printf("L'arbre est vide, le sommet n'a donc pas été trouvé ...\n");
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

int *rechercherElement_test(T_Arbre abr, int element){
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
                return 1;
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
    if (empty_abr(abr) == 0){
        printf("[%d:%d] ",abr->inf,abr->sup);
        afficherSommet(abr->Lson);
        afficherSommet(abr->Rson);
    }
}

void afficherElements(T_Arbre abr){
    if (empty_abr(abr) == 0){
        afficher_intervalle(*abr);
        afficherElements(abr->Lson);
        afficherElements(abr->Rson);
    }
}

T_Arbre insererElement (T_arbre abr, int element){
    if (rechercherElement_test(abr, element))
        throw "L'element existe deja.";
    if (abr != NULL) {
        T_Sommet *tmp1 = abr;
        while ((element + 1)< tmp->inf && tmp1->Lson != NULL){
            tmp1 = tmp1->Lson;
        }
        T_Sommet *tmp2 = tmp1;
        while ((tmp->sup + 1) < element && tmp->Rson != NULL){
            tmp2 = tmp2->Rson;
        }


        if (element+1 == tmp->inf){
            if (tmp->Lson->sup + 1 ==element){
                T_Sommet *tmp2 = tmp->Lson;
                tmp->inf = tmp2->inf;
                tmp->Lson = tmp2->Lson;
                //dans cette configuration,
            }
        }

    }

}
