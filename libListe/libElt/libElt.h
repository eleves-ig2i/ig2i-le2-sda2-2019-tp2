/**
 * \file libElt.h
 * \author Nathan Salez
 * \brief déclaration des fonctions et du TAD utilisé pour les listes chaînées.
 * \note le type utilisé actuellement est : int
 * \version 1.1
 * \date 18/09/2018
 */

#ifndef TP2_LIBELT_H
#define TP2_LIBELT_H

#include <stdio.h>
#include <assert.h>

typedef int elt_t;

#define ELT_HB (-1024)

/**
 * \fn void saisirElt(elt_t* e)
 * \param e pointeur sur un elt_t, qui ne vaut pas NULL
 * \brief Saisie d'un élément (ici un int)
 * \attention e ne doit pas être égal à NULL
 * \author Nathan Salez
 * \version 1.0
 * \date 13/09/2018
 */
void saisirElt(elt_t* e);


/**
 * \fn void rangerElt(elt_t* d, const elt_t* s)
 * \param d pointeur sur un elt_t, valeur changée après affectation.
 * \param s un elt_t, sa valeur reste inchangée.
 * \brief Affectation de s vers d
 * \attention d et s ne doivent pas être égaux à NULL
 * \author Nathan Salez
 * \version 1.1
 * \date 18/09/2018
 */
void rangerElt(elt_t* d, const elt_t* s);


/**
 * \fn void afficherElt(const elt_t* e)
 * \param e pointeur sur un elt_t, dont la valeur est affichée.
 * \brief Affichage de *e sur la sortie standard.
 * \attention e ne doit pas être égal à NULL
 * \author Nathan Salez
 * \version 1.1
 * \date 18/09/2018
 */
void afficherElt(const elt_t* e);


/******************* FONCTIONS DE TEST *******************/
void testSaisieElt();
void testRanger();
void testAfficherElt();

int main(void);



#endif //TP2_LIBELT_H
