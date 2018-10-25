/**
 * \file testLibElt.c
 * \author Nathan Salez
 * \brief Code source des fonctions de test de la bibliothèque libPile
 * \version 1.1
 * \date 18/09/2018
 */
#include "testLibElt.h"




int main(void)
{
    atexit(epilogue);
    testAfficherElt();
    
#if (0)
    testAfficherElt();
    testRangerElt();
    testSaisieElt();
#endif

    return 0;
}


void testSaisieElt()
{
    printf("Test de saisirElt()\n");
    printf("Premier test : elt_t\n");
    elt_t pasDerreur;
    printf("Veuillez saisir un nombre : ");
    saisirElt(&pasDerreur);
    printf("Nombre saisi : %d\n\n",pasDerreur);
    
    printf("Deuxième test : elt_t* (avec allocation)\n");
    elt_t * pasDerreurDeux = (elt_t*)malloc(sizeof(elt_t));
    assert(pasDerreurDeux != NULL);
    printf("Veuillez saisir un nombre : ");
    saisirElt(pasDerreurDeux);
    printf("Nombre saisi : %d\n\n",*pasDerreurDeux);
    
    printf("Troisième test : elt_t* (sans allocation => erreur)\n");
    elt_t * erreur = NULL;
    printf("Veuillez saisir un nombre : ");
    saisirElt(erreur);
    printf("Nombre saisi : %d\n\n",*erreur);
}



void testRangerElt()
{
    printf("Test de ranger()\n");
    elt_t test1a=2, test1b=3;
    
    elt_t* test2a=NULL;
    elt_t* test2b=(elt_t*)malloc(sizeof(elt_t));
    *test2b = 5;
    
    printf("Premier test : test1a = %d && test1b = %d\n",test1a,test1b);
    rangerElt(&test1a,&test1b);
    printf("Résultats : test1a = %d && test1b = %d\n\n",test1a,test1b);
    
    printf("Deuxième test : test2a = NULL, *test2b = %d",*test2b);
    rangerElt(test2a,test2b);
}



void testAfficherElt()
{
    printf("Test de afficherElt()\n");
    elt_t test1 = 2;
    elt_t *test2 = (elt_t *)malloc(sizeof(elt_t));
    *test2 = 0;
    elt_t *test3 = NULL;
    
    printf("Premier test : elt_t\n");
    afficherElt(&test1);
    
    printf("Deuxième test : elt_t* (avec allocation)\n");
    afficherElt(test2);
    
    printf("Troisième test : elt_t* (sans allocation => erreur)\n");
    afficherElt(test3);


}



    
    
    
    

