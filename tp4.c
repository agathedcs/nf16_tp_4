#include <stdlib.h>
#include <stdio.h>
#include "tp4.h"

T_Sommet *creerSommet(int element){
    T_Sommet *sommet = malloc(sizeof(T_Sommet));
    sommet->inf = element;
    sommet->sup = element;
    sommet->Lson = NULL;
    sommet->Rson = NULL;
    return sommet;
}

int empty_abr(T_Arbre abr){
    if (abr == NULL) {
        return 1;
    }else{
        return 0;
    }
}

T_Sommet *rechercherElement(T_Arbre abr, int element){
    if (empty_abr(abr) == 0){
        printf("L'arbre est vide, le sommet n'a donc pas été trouvé ...\n");
    }
    else{
        T_Sommet  *current = abr;
        //Recherche en profondeur dans l'arbre
        while(current != NULL){
            if (element < current->inf){
                current = current->Lson;
            }
            else if (element > current->sup){
                current = current->Rson;
            }
            //Cas ou le sommet est dans l'intervalle du sommet actuel
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
            return NULL;
        }
    }
}

//Affiche tout les sommets présent dans un intervalle
void afficher_intervalle(T_Sommet som){
    int inf = som.inf;
    int sup = som.sup;
    for (inf;inf<=sup;inf++){
        printf("[%d] ",inf);
    }
}

//Fonction récursive qui affiche tout les sommets sous formes d'intervalle
void afficherSommet(T_Arbre abr,int retour_ligne){
    if (abr != NULL){
        if (abr->inf == abr->sup){
            printf("[%d] ",abr->inf);
        }
        else {
            printf("[%d:%d] ", abr->inf, abr->sup);
        }
        afficherSommet(abr->Lson,0);
        afficherSommet(abr->Rson,0);
        if (retour_ligne){
            printf("\n");
        }
    }
}

//Fonction récursive qui affiche tout les éléments dans un abre dans l'ordre croissant
void afficherElements(T_Arbre abr,int retour_ligne){
    if (abr != NULL){
        afficher_intervalle(*abr);
        afficherElements(abr->Lson,0);
        afficherElements(abr->Rson,0);
        if (retour_ligne){
            printf("\n");
        }
    }
}

// Fonction qui ajoute un élement a l'arbre
T_Arbre insererElement (T_Arbre abr, int element){
    if (abr == NULL)
        //Creer un arbre avec l'élement en racine de l'arbre
        return creerSommet(element);

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

T_Arbre insererElements(T_Arbre abr, int nb_elements) {
    int count = 0;
    int element;
    while (count < nb_elements) {
        printf("Elément : ");
        if (scanf("%d", &element) == 1) {  // Vérifiez si l'entrée est un entier
            viderBuffer();  // Vider le buffer après scanf pour éviter les boucles infinies
            T_Sommet *som = rechercherElement_messageless(abr,element);
            if (som == NULL) {
                abr = insererElement(abr, element);
                count++;
            } else {
                printf("L'élément [%d] existe déjà.\n", element);
            }
        } else {
            printf("Entrée invalide, veuillez entrer un entier.\n");
            viderBuffer();  // Vider le buffer pour éviter les boucles infinies
        }
    }
    return abr;
}

T_Sommet* minimum(T_Arbre abr) {
    //trouve le minimum des sommets de l'arbre de racine abr = intervalle ayant la plus petite borne inferieure
    T_Sommet* sommet = abr;
    while (sommet->Lson != NULL)
        sommet = sommet->Lson;
    return sommet;
}

T_Arbre supprimerElement(T_Arbre abr, int element){
    if (abr == NULL)
        return NULL;
    if (element< abr->inf)
        abr->Lson = supprimerElement(abr->Lson, element);
    else if (element > abr->sup)
        abr->Rson = supprimerElement(abr->Rson, element);
    else {
        //on a trouve l'element
        if (abr->sup == abr->inf){
            //le sommet ne contient qu'un element donc on supprime ce sommet
            if (abr->Lson == NULL && abr->Rson == NULL){
                free(abr);
                return NULL;
            }
            else if (abr->Lson == NULL){
                T_Sommet* tmp = abr->Rson;
                free(abr);
                return tmp;
            }
            else if (abr->Rson == NULL){
                T_Sommet* tmp = abr->Lson;
                free(abr);
                return tmp;
            }
            else {
                T_Sommet* tmp = minimum(abr->Rson);
                abr->inf = tmp->inf;
                abr->sup = tmp->sup;
                abr->Rson = supprimerElement(abr->Rson, tmp->inf);
                //on supprime le sommet et on le remplace par le sommet ayant la plus petite borne inferieure
            }
        }
        else if (element == abr->inf)
            abr->inf++;
        else if (element == abr->sup)
            abr->sup++;
        else {
            //la supression de l'element creer 2 nouveaux intervales
            T_Sommet* nv = creerSommer(abr->inf);
            nv->sup = element - 1;
            nv->Lson = abr->Lson;
            abr->Lson = NULL;
            nv->Rson = abr;
            abr->inf = element + 1;
            return nv;
        }
    }
    return abr;
}

int Taille_Memoire(T_Arbre abr){
    if (abr == NULL){
        return 0;
    }
    else{
        return sizeof(T_Sommet) + Taille_Memoire(abr->Rson)+ Taille_Memoire(abr->Lson);
    }
}

//Vide la mémoire
void empty_abr_memory(T_Arbre abr){
    if(abr == NULL){
        return;
    }
    empty_abr(abr->Lson);
    empty_abr(abr->Rson);
    free(abr);
    return;

}

void viderBuffer()
{
    int c = 0;
    while (c != '\n' && c != EOF)
    {
        c = getchar();
    }
}
