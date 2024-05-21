//
// Created by Arthur Maugée on 21/05/2024.
//
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

