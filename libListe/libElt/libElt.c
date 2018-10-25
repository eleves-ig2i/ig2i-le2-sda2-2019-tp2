/**
 * \file libElt.c
 * \include "libElt.h"
 * \author Nathan Salez
 * \brief code source des fonctions du TAD utilisé pour les listes chaînées.
 * \note le type utilisé actuellement est : int
 * \version 1.1
 * \date 18/09/2018
 */
#include "libElt.h"

void saisirElt(elt_t *e)
{
    assert( e != NULL );
    scanf("%d",e);
}


void rangerElt(elt_t* d, const elt_t* s)
{
    assert( d != NULL && s != NULL);
    *d = *s;
}


void afficherElt(const elt_t* e)
{
    assert( e != NULL);
    printf(" ----> %d",*e);
}
