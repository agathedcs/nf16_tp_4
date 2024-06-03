#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"
#include "tp4.c"

int main()
{
    char choix[7];
    int nb_elements, element;
    T_Arbre abr = NULL;
    while (1){  //Permet de boucler à l'infini
        printf("Entrez votre choix :\n\t"
               "1 : Creer un arbre vide\n\t"
               "2 : Construire un arbre de N elements\n\t"
               "3 : Ajouter un element\n\t"
               "4 : Afficher tout les sommets\n\t"
               "5 : Afficher tout les éléments\n\t"
               "6 : Supprimer un élément\n\t"
               "7 : Afficher la taille en mémoire\n\t"
               "8 : Quitter\n");
        fgets(choix, sizeof(choix), stdin);
        int choix_entier = atoi(choix);  //convertion de choix en entier
        switch(choix_entier){
            case 1:
                if(abr != NULL){
                    empty_abr_memory(abr);
                    printf("L'arbre a été vidé\n");
                    abr = NULL;
                }
                else{
                    printf("L'arbre est déja vide\n");
                }
                break;

            case 2:
                printf("Création d'un arbre en cours...\nVeuillez rentrez le nombre d'élements que vous voulez ajoutez :\n");
                scanf("%d",&nb_elements);
                abr = insererElements(abr,nb_elements);
                printf("Création effectué avec succès !\n");
                break;

            case 3:
                printf("Rentrez l'élément à ajouter :\n");
                scanf("%d",&element);
                if (rechercherElement_messageless(abr,element) == NULL){
                    abr = insererElement(abr,element);
                    printf("Elément ajouté avec succès !\n");
                }
                else{
                    printf("L'élément existe déjà\n");
                }

                break;

            case 4:
                if(empty_abr(abr)){
                    printf("Arbre vide.\n");
                }
                else{
                    printf("Sommets du graphe :\n");
                    afficherSommet(abr,1);
                }

                break;

            case 5:
                printf("Eléments du graphe :\n");
                afficherElements(abr,1);
                break;
            
            case 6:
                if(empty_abr(abr))
                    printf("L'arbre est vide, il n'y a rien à supprimer.\n");
                else {
                    printf("Rentrez l'élément à supprimer :\n");
                    scanf("%d",&element);
                    if (rechercherElement_messageless(abr,element) == NULL)
                        printf("L'element n'existe pas dans l'arbre. \n");
                    else {
                        abr = supprimerElement(abr, element);
                        printf("Elément supprimé avec succès !\n")
                    }
                }
                break;
            
            case 7:
                printf("La taille en mémoire de l'arbre est égale à %zu bytes\n", Taille_Memoire(abr));
                break;

            case 8:
                empty_abr_memory(abr);
                printf("Sortie du programme\n");
                exit(0);
                break;

            default:
                printf("La valeur n'est pas accepté, Réeassayez\n");
        }
        printf("Entrez pour continuer .\n");
        viderBuffer();
    }
}
