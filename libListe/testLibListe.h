/**
 * \file testLibListe.h
 * \brief Déclaration des fonctions de test de la bibliothèque libListe.
 * \author Nathan Salez
 * \version 1.0
 * \date 19/09/2018
 */

#ifndef SDA2_TP2_SALEZ_NATHAN_TESTLIBLISTE_H
#define SDA2_TP2_SALEZ_NATHAN_TESTLIBLISTE_H

#include <string.h>
#include <math.h>
#include <time.h>
#include <stdlib.h>

#include "libListe.h"

#include <sys/types.h>
#include <sys/timeb.h>

#if defined (_WIN32)
#include <windows.h>
#pragma comment(lib, "Ws2_32.lib")
//#elif defined (__unix__)
#else
#define  __unix__
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#endif


#if defined (_MSC_VER)
/*
 *	Slection du niveau le plus lev d'affichage des messages
 *	d'avertissement
 */
#pragma warning( push, 4 )

/*
 *	Dsactivation de l'affichage des messages d'avertissement lis 
 *	l'utilisation de fonctions dprcies par Visual C++ car remplaées
 *	par des fonctions spcifiques plus sres mais non standards
 */
#pragma warning( disable : 4996 )
#endif
/* ------------------------------------------------------------------------ */
/*		C O N S T A N T E S   &   P R O T O T Y P E S						*/
/* ------------------------------------------------------------------------ */
#define MAXLEN          256

/**
 *  \fn void epilogue(void)
 *  \brief      Squelette pour acceuillir un programme quelconcque
 *              avec excution de la fonction epilogue  la fin du
 *              programme
 *  \author     Samir El Khattabi
 *  \date       10 Octobre 2005
 *  \version    1.0
 *  \remark	Le code source a été transféré ici, pour améliorer la lisibilité du programme principal.
 */
void epilogue(void)
{
    static const char * jour[] = {
            "Dimanche", "Lundi", "Mardi", "Mercredi",
            "Jeudi", "Vendredi", "Samedi"};

    static const char * mois[] = {
            "Janvier", "Fevrier", "Mars"     , "Avril"  , "Mai"     , "Juin"    ,
            "Juillet", "Aout"   , "Septembre", "Octobre", "Novembre", "Decembre",
    };

    time_t ltime;
    struct tm * today;
    char userName[MAXLEN + 1] = "";
    char hostName[MAXLEN + 1] = "";
    unsigned long name_len = MAXLEN + 1;

#if defined (_WIN32)
    WSADATA wsaData;
#endif

    struct hostent * pHostEntry;
    struct in_addr *pinAddr;

#if defined (_WIN32)
    WSAStartup(MAKEWORD(2,2), &wsaData);
#endif

    /*	Nom de l'utilisateur   					                			*/
#if defined (_WIN32)
    GetUserName(userName, &name_len);
#elif defined (__unix__)
    getlogin_r(userName,name_len);
#endif
    printf("\n%-9.9s ", userName);

    /*	Nom de l'ordinateur   								                */
    gethostname(hostName, MAXLEN);

    /* Nom réseau et adresse IP de l'ordinateur								*/
    pHostEntry = gethostbyname(hostName);
    if (pHostEntry != NULL)
    {
        printf("%-13.10s ", pHostEntry->h_name);
        pinAddr = ((struct in_addr *)pHostEntry->h_addr_list[0]);
        if (pinAddr != NULL)
            printf("%s ", inet_ntoa(*pinAddr));
    }

    /*	Date et heure														*/
    tzset();
    time(&ltime);
    today = localtime(&ltime);
    printf("%9s %d %s %4d a %dh %dmn %ds\n",
           jour[today->tm_wday], today->tm_mday,
           mois[today->tm_mon], today->tm_year + 1900,
           today->tm_hour, today->tm_min, today->tm_sec);

#if defined (_WIN32)
    WSACleanup();
#endif
}
/****************************** FIN FONCTION EPILOGUE ******************************/

int main(void);

/********* FONCTIONS DE TEST *********/
void insererEltTeteListe_test();
void afficherListe_test();
void insererEltQueueListe_test();
void nbrEltsListe_test();
void supprimerDernierElementListe_test();
void libererListe_test();
void copierListe_test();
void supprimerPremierElementListe_test();
void estMembre_test();
void occurenceValeur_test();
void supprimerElementListe_test();
void insererEltListeOrdonnee_test();
void trouverMinListe_test();



#endif // SDA2_TP2_SALEZ_NATHAN_TESTLIBLISTE_H

