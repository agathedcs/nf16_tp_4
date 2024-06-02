#include <stdio.h>
#include <stdlib.h>
#include "tp4.h"

int main()
{
    T_Arbre abr = NULL;
    abr = insererElement(abr, 10);
    abr = insererElement (abr, 11);
    abr = insererElement (abr, 20);
    abr = insererElement (abr, 13);
    abr = insererElement(abr, 12);
    afficherSommet(abr);
    return 0;
}
