/**
 * \file testLibListe.c
 * \author Nathan Salez
 * \brief Code source des fonctions de test de la bibliothèque libListe
 * \version 1.1
 * \date 20/09/2018
 */
#include "testLibListe.h"



int main(void)
{
    atexit(epilogue);

    // Inserer une fonction de test ici.
#if (0)
    nbrEltsListe_test();
    afficherListe_test();
    insererEltTeteListe_test();
    insererEltQueueListe_test();
    supprimerDernierElementListe_test();
    supprimerPremierElementListe_test();
    libererListe_test();
    copierListe_test();
    estMembre_test();
    occurenceValeur_test();
    insererEltListeOrdonnee_test();
    supprimerElementListe_test();
    trouverMinListe_test();
#endif

    return 0;
}



/********* FONCTIONS DE TEST *********/


void afficherListe_test()
{
    printf("Test de afficherListe\n--------------------------\n");
    liste_t maListe = NULL;

    printf("La liste est initialisée, on tente l'affichage :\n");
    afficherListe(maListe);

    printf("\nOn ajoute 2 éléments. On a l'affichage suivant :\n");
    maListe = insererEltTeteListe(5,maListe);
    maListe = insererEltTeteListe(4,maListe);
    afficherListe(maListe);
}

// Valide
void insererEltTeteListe_test()
{
    printf("Test de insererEltTeteListe\n--------------------------\n");
    liste_t maListe = NULL;

    printf("La liste est initialisée, on ajoute 5 éléments.\n");
    maListe = insererEltTeteListe(5,maListe);
    maListe = insererEltTeteListe(4,maListe);
    maListe = insererEltTeteListe(3,maListe);
    maListe = insererEltTeteListe(2,maListe);
    maListe = insererEltTeteListe(1,maListe);
    afficherListe(maListe);

}


void insererEltQueueListe_test()
{
    printf("Test de insererEltQueueListe\n--------------------------\n");
    liste_t maListe = NULL;
    maListe = insererEltTeteListe(5,maListe);
    maListe = insererEltTeteListe(4,maListe);
    maListe = insererEltTeteListe(3,maListe);
    maListe = insererEltTeteListe(2,maListe);
    maListe = insererEltTeteListe(1,maListe);
    printf("La liste a été initialisée, affichage :\n");
    afficherListe(maListe);

    printf("\nOn ajoute 6 en fin de liste, affichage :\n");
    maListe = insererEltQueueListe(6,maListe);
    afficherListe(maListe);
}


void nbrEltsListe_test()
{
    printf("Test de nbrEltListe\n--------------------------\n");
    liste_t maListe = NULL;
    printf("On a initialisé la liste, il y a %u éléments dans cette liste.\n",nbrEltsListe(maListe));
    maListe = insererEltTeteListe(5,maListe);
    maListe = insererEltTeteListe(4,maListe);
    maListe = insererEltTeteListe(3,maListe);
    maListe = insererEltTeteListe(2,maListe);
    maListe = insererEltTeteListe(1,maListe);
    printf("On a inséré des éléments en tête de liste, affichage :\n");
    afficherListe(maListe);
    printf("\nIl y a %u éléments dans cette liste.",nbrEltsListe(maListe));

}


void supprimerDernierElementListe_test()
{
    printf("Test de supprimerDernierElementListe\n--------------------------\n");
    liste_t maListe = NULL;
    maListe = insererEltTeteListe(3,maListe);
    maListe = insererEltTeteListe(2,maListe);
    maListe = insererEltTeteListe(1,maListe);

    printf("La liste a été initialisée, affichage :\n");
    afficherListe(maListe);

    printf("\nOn supprime le dernier élément, affichage :\n");
    supprimerDernierElementListe(maListe);
    afficherListe(maListe);

    printf("\nOn supprime le dernier élément, affichage :\n");
    maListe = supprimerDernierElementListe(maListe);
    afficherListe(maListe);

    printf("\nOn supprime le dernier élément, affichage :\n");
    maListe = supprimerDernierElementListe(maListe);
    afficherListe(maListe);
}


void libererListe_test()
{
    printf("Test de libererListe\n--------------------------\n");
    liste_t maListe = NULL;
    maListe = insererEltTeteListe(5,maListe);
    maListe = insererEltTeteListe(4,maListe);
    maListe = insererEltTeteListe(3,maListe);
    maListe = insererEltTeteListe(2,maListe);
    maListe = insererEltTeteListe(1,maListe);
    printf("La liste a été initialisée, affichage :\n");
    afficherListe(maListe);

    printf("\nOn supprime tous les éléments de la liste, affichage :\n");
    maListe = libererListe(maListe);
    afficherListe(maListe);
}


void copierListe_test()
{
    printf("Test de copierListe\n--------------------------\n");
    liste_t maListe = NULL;
    maListe = insererEltTeteListe(5,maListe);
    maListe = insererEltTeteListe(4,maListe);
    maListe = insererEltTeteListe(3,maListe);
    maListe = insererEltTeteListe(2,maListe);
    maListe = insererEltTeteListe(1,maListe);
    printf("La liste 1 a été initialisée, affichage :\n");
    afficherListe(maListe);

    printf("\nOn initialise maListe dans liste2, affichage :\n");
    liste_t liste2 = copierListe(maListe);
    afficherListe(liste2);
    printf("\nListe 1 :\n");
    afficherListe(maListe);

    printf("\nOn change liste2 en ajoutant un élément en tête de liste, affichage :\n");
    liste2 = insererEltTeteListe(6,liste2);
    afficherListe(liste2);
    printf("\nListe 1 :\n");
    afficherListe(maListe);

}


void supprimerPremierElementListe_test()
{
    printf("Test de supprimerPremierElementListe\n--------------------------\n");
    liste_t maListe = NULL;
    maListe = insererEltTeteListe(4,maListe);
    maListe = insererEltTeteListe(3,maListe);
    maListe = insererEltTeteListe(2,maListe);
    maListe = insererEltTeteListe(1,maListe);

    printf("La liste a été initialisée, affichage :\n");
    afficherListe(maListe);

    printf("\nOn supprime le premier élément, affichage :\n");
    maListe = supprimerPremierElementListe(maListe);
    afficherListe(maListe);

    printf("\nOn supprime le premier élément, affichage :\n");
    maListe = supprimerPremierElementListe(maListe);
    afficherListe(maListe);

    printf("\nOn supprime le premier élément, affichage :\n");
    maListe = supprimerPremierElementListe(maListe);
    afficherListe(maListe);
}


void estMembre_test()
{
    printf("Test de estMembre\n--------------------------\n");
    liste_t maListe = NULL;

    printf("\nLa liste est vide, on cherche la valeur 6 dans la liste, résultat : %d\n", estMembre(maListe,6));

    maListe = insererEltTeteListe(5,maListe);
    maListe = insererEltTeteListe(4,maListe);
    maListe = insererEltTeteListe(3,maListe);
    maListe = insererEltTeteListe(2,maListe);
    maListe = insererEltTeteListe(1,maListe);
    printf("La liste a été remplie, affichage :\n");
    afficherListe(maListe);

    printf("\nOn cherche la valeur 6 dans la liste, résultat : %d\n", estMembre(maListe,6));
    printf("On cherche la valeur 3 dans la liste, résultat : %d\n", estMembre(maListe,3));
}


void occurenceValeur_test()
{
    printf("Test de occurenceValeur\n--------------------------\n");
    liste_t maListe = NULL;
    maListe = insererEltTeteListe(2,maListe);
    maListe = insererEltTeteListe(2,maListe);
    maListe = insererEltTeteListe(3,maListe);
    maListe = insererEltTeteListe(2,maListe);
    maListe = insererEltTeteListe(1,maListe);
    printf("La liste a été initialisée, affichage :\n");
    afficherListe(maListe);

    printf("\n");
    for(int i =0; i<4;i++)
    {
        printf("Nombre d'occurences de la valeur %d dans la liste : %u\n",i,occurenceValeur(maListe,i));
    }
}


void insererEltListeOrdonnee_test()
{
    printf("Test de insererEltOrdonneeListe\n--------------------------\n");
    liste_t maListe = NULL;
    printf("On insère un 1er élément dans la liste pour illustrer le 1er cas, affichage :\n");
    maListe = insererEltListeOrdonnee(3,maListe);
    afficherListe(maListe);

    printf("\n\nOn insère un 2e élément dans la liste pour illustrer le 2e cas, affichage :\n");
    maListe = insererEltListeOrdonnee(1,maListe);
    afficherListe(maListe);

    printf("\n\nOn insère un 3e élément dans la liste pour illustrer le 3e cas, affichage :\n");
    maListe = insererEltListeOrdonnee(4,maListe);
    afficherListe(maListe);

    printf("\n\nOn insère un 4e élément dans la liste pour illustrer le 4e cas, affichage :\n");
    maListe = insererEltListeOrdonnee(5,maListe);
    afficherListe(maListe);

    printf("\n\nOn insère un 5e élément dans la liste, affichage :\n");
    maListe = insererEltListeOrdonnee(10,maListe);
    afficherListe(maListe);
}



void supprimerElementListe_test()
{
    printf("Test de supprimerElementListe\n--------------------------\n");
    liste_t maListe = NULL;
    maListe = insererEltTeteListe(4,maListe);
    maListe = insererEltTeteListe(2,maListe);
    maListe = insererEltTeteListe(2,maListe);
    maListe = insererEltTeteListe(3,maListe);
    maListe = insererEltTeteListe(2,maListe);
    maListe = insererEltTeteListe(1,maListe);
    printf("La liste a été initialisée, affichage :\n");
    afficherListe(maListe);

    printf("\nOn supprime les 2, affichage :\n");
    maListe = supprimerElementListe(2,maListe);
    afficherListe(maListe);
}


void trouverMinListe_test()
{
    printf("Test de trouverMinListe\n--------------------------\n");
    liste_t maListe = NULL;
    maListe = insererEltQueueListe(5,maListe);
    maListe = insererEltQueueListe(-1,maListe);
    maListe = insererEltQueueListe(3,maListe);
    maListe = insererEltQueueListe(2,maListe);
    maListe = insererEltQueueListe(6,maListe);
    printf("La liste a été remplie, affichage :\n");
    afficherListe(maListe);

    printf("\nValeur minimale de la liste : %d\n",trouverMinListe(maListe));

}
