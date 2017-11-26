/*programme jeu_de_nim

//---------------------------PROCEDURES ET FONCTIONS-----------------------------
//BUT:Enregistrer le nom des joueur.
//ENTREE: Deux chaines de caractères.
//SORTIE: Deux chaines de caractères remplies.
PROCEDURE pseudo12(var nom1:CHAINE var nom2:CHAINE)
DEBUT
	REPETER
		ECRIRE("JOUEUR 1 ENTREZ VOTRE NOM")
		LIRE(nom1)
	JUSQUA (LONGUEUR(nom1)>0) ET (LONGUEUR(nom1)<10)
	REPETER
		ECRIRE('JOUEUR 2 ENTREZ VOTRE NOM')
		LIRE(nom2)
	JUSQUA (LONGUEUR(nom2)>0) ET (LONGUEUR(nom2)<10)
FINPROCEDURE

//-------------------------------------------------------------------------------
//BUT:Choisir un joueur qui jouera en premier au hasard.
//ENTREE:Une chaine de caractère du nom du joueur et du joueur 2.
//SORTIE:Une des deux chaines de caractères précédente.
FONCTION premier(var joueur:CHAINE nom1:CHAINE nom2:CHAINE):CHAINE
var
	i:ENTIER
DEBUT
	i<-random(2)+1
	SI i=1 ALORS
		joueur<-nom1
	SINON
	joueur<-nom2
	FINSI
	premier<-joueur
FINFONCTION

//-------------------------------------------------------------------------------
//BUT: Réaliser le tour de jeux du joueur courant.
//ENTREE: la chaine de caractère du joueur actuel et de l'ia,l'entier du nombre d'allumettes restantes.
//SORTIE: L'ENTIER d'allumettes restantes, l'ENTIER saisie par l'utilisateur.
PROCEDURE tourjoueur(nom1:CHAINE nom2: CHAINE var choix:ENTIER var joueur:CHAINE var allumette:ENTIER var allumax:ENTIER)
var
	i:ENTIER
DEBUT
	ECRIRE(joueur & " combien d''allumettes souhaitez-vous enlever ?")
	SI allumette-3<0 ALORS //s'il reste moins de 3 allumettes on affiche le nombre d'allumettes possible à enlever(allumax).
		allumax<-allumette
		ECRIRE("Choisissez un nombre entre 1 et "& allumax &".")
		ECRIRE("Il reste "& allumette & " allumettes.")
		REPETER
			LIRE(choix)
		JUSQUA (choix < allumax + 1) ET (choix > 0)
	SINON //s'il reste plus de 3 allumettes le joueur courant peux en retirer entre 1 et 3.
		ECRIRE("Choisissez un nombre entre 1 et 3.")
		ECRIRE("Il reste "& allumette &" allumettes.")
		REPETER
			LIRE(choix)
		JUSQUA (choix < 4) ET (choix > 0)
	FINSI
	allumette<-allumette-choix //on soustait le choix du joueur à allumette.
	SI allumette>0 ALORS //on change le tour de joueur
		SI joueur= nom1 ALORS
			joueur<-nom2
		SINON SI joueur=nom2 ALORS
			joueur<-nom1
		FINSI
	FINSI
FINPROCEDURE
//--------------------------FIN PROCEDURE ET FONCTION------------------------

//-------------------------------DEBUT PROGRAMME-----------------------------
var
	allumette,allumax,choix:ENTIER
	nom1,nom2,joueur:CHAINE
DEBUT
	allumette<-21

	ECRIRE("JEU DE NIM")
	pseudo12(nom1,nom2)//les joueurs rentrent leurs pseudo
	joueur<-premier(joueur,nom1,nom2)//on choisi qui commence à jouer.
	ECRIRE("le premier joueur sera : "& joueur)
//--------------------------------BOUCLE DE JEU------------------------------
	REPETER
		tourjoueur(nom1,nom2,choix,joueur,allumette,allumax) //tour de jeu
	JUSQUA allumette =0 // quand il n'y a plus d'allumette le jeu est finit.
//----------------------------FIN DE BOUCLE DE JEU---------------------------
	ECRIRE(joueur& " a perdu.")
FIN.
//------------------------------- FIN PROGRAMME------------------------------
*/


//-------------------------------DEBUT PROGRAMME-----------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LGMAX 250
#define NBMAX 2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//---------------------------------PROTOTYPE---------------------------------

void pseudo12(char nom1[LGMAX]);
char premier(char joueur[LGMAX],char nom1[LGMAX], char nom2[LGMAX]);
void tourjoueur(char nom1[LGMAX],char nom2[LGMAX],int *choix,char joueur[LGMAX],int *allumette,int *allumax);
void changeTour(char joueur[LGMAX],char nom1[LGMAX],char nom2[LGMAX],int *allumette);


//-------------------------------FIN PROTOTYPE-------------------------------

int main()
{
//--------------------------------INITIALISATION-----------------------------
    srand(time(NULL));
    int allumette=21;
    int allumax=0;
    int choix=0;
    char nom1[LGMAX]={"\0"};
    char nom2[LGMAX]="IA";
    char joueur[LGMAX]={"\0"};

//------------------------------FIN INITIALISATION---------------------------

    puts("JEU DE NIM");
    pseudo12(nom1);//les joueurs rentrent leurs pseudo
    joueur[LGMAX]=premier(joueur,nom1,nom2);//on choisi qui commence à jouer.
    printf("le premier joueur sera : %s",joueur);

//--------------------------------BOUCLE DE JEU------------------------------
    do{
        tourjoueur(nom1,nom2,&choix,joueur,&allumette,&allumax); //tour de jeu
        changeTour(joueur,nom1,nom2,&allumette);
    }
    while (allumette >0); // tans qu'il y a au moins une allumette le jeu continue
//----------------------------FIN DE BOUCLE DE JEU---------------------------
	printf(" %s a perdu.",joueur);

    return 0;
}
//------------------------------- FIN PROGRAMME------------------------------

//---------------------------PROCEDURES ET FONCTIONS-------------------------

//BUT:Enregistrer le nom des joueur.
//ENTREE: Deux chaines de caractères.
//SORTIE: Deux chaines de caractères remplies.

void pseudo12(char nom1[LGMAX]){
	do
    {
        puts("JOUEUR 1 ENTREZ VOTRE NOM");
		gets(nom1);
	}
	while ((strlen(nom1)==0) || (strlen(nom1)>15));
}
//-------------------------------------------------------------------------------
//BUT:Choisir un joueur qui jouera en premier au hasard.
//ENTREE:Une chaine de caractère du nom du joueur et du joueur 2.
//SORTIE:Une des deux chaines de caractères précédente.

char premier(char joueur[LGMAX],char nom1[LGMAX], char nom2[LGMAX]){

	int i=0;
	i= (rand()%NBMAX+1);

	if(i==1){
        strcpy(joueur,nom1);
	}

	else {
        strcpy(joueur,nom2);
	}

	return joueur[LGMAX];
}

//-------------------------------------------------------------------------------
//BUT: Réaliser le tour de jeux du joueur courant.
//ENTREE: la chaine de caractère du joueur actuel et de l'ia,l'entier du nombre d'allumettes restantes.
//SORTIE: L'ENTIER d'allumettes restantes, l'ENTIER saisie par l'utilisateur.

void tourjoueur(char nom1[LGMAX],char nom2[LGMAX],int *choix,char joueur[LGMAX],int *allumette,int *allumax){

    if (strcmp(joueur,nom1)==0){

        printf("%c combien d'allumettes souhaitez-vous enlever ?",joueur[LGMAX]);

        if(*allumette-3<0){ //s'il reste moins de 3 allumettes on affiche le nombre d'allumettes possible à enlever(allumax).

            *allumax=*allumette;
            printf("Choisissez un nombre entre 1 et %d .\n",*allumax);
            printf("Il reste %d allumettes.\n",*allumette);

            do
            {
                fflush(stdin);
                scanf("%d",choix);
            }

            while ((*choix > *allumax + 1) || (*choix < 0));
        }

        else{ //s'il reste plus de 3 allumettes le joueur courant peux en retirer entre 1 et 3.

            puts("Choisissez un nombre entre 1 et 3.\n");
            printf("Il reste %d allumettes.\n",*allumette);

            do
            {
                fflush(stdin);
                scanf("%d",choix);
            }

            while ((*choix > 3) || (*choix < 0));
        }
        *allumette=(*allumette-*choix); //on soustait le choix du joueur à allumette.
    }
    else
    {
        if (((*allumette-1) %4==0) && (*allumette-3>=0)){

                fflush(stdin);
                *choix=rand()%3+1;
        }
        else{
                fflush(stdin);
                *allumax=*allumette;
                *choix=(rand()%*allumax+1);
            }
        *allumette=(*allumette-*choix);
    }
}

//-------------------------------------------------------------------------------
//BUT: Réaliser le tour de jeux du joueur courant.
//ENTREE: la chaine de caractère du joueur actuel et de l'ia,l'entier du nombre d'allumettes restantes.
//SORTIE: L'ENTIER d'allumettes restantes, l'ENTIER saisie par l'utilisateur.

void changeTour(char joueur[LGMAX],char nom1[LGMAX],char nom2[LGMAX],int *allumette){
	if (*allumette>0){ //on change le tour de joueur
		if (strcmp(joueur,nom1)==0){
                fflush(stdin);
                strcpy(joueur,nom2);
        }

		else {
                fflush(stdin);
                strcpy(joueur,nom1);
        }

	}
}
//------------------------FIN PROCEDURES ET FONCTIONS------------------------
