/*

	Code en c pour le cours d'OpenclassRooms

	Jeu de Plus ou Moins amelioré

	Auteur : raphchar

*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>



int main()
{
	// Définition des variables
	int const MIN = 1;				// On définit le minimum pour pas avoir à le faire dans chaque condition if
	int nombreInconnu = 0;			// On définit le nombre inconnu
	int tentatives = 0;				// On définit le nombre de tentatives de l'utilisateur
	int nombreDeCoups = 10;			// L'utilisateur a 10 chances pour trouver le nombre inconnu
	int niveau = 0;					// Variable qui va donner le niveau du jeu
	int coups = 0;					// Variable qui va compter le nombre de coup du joeur
	int Jouer = 1;					// Variable qui force la partie à ce dérouler
	
	// Boucle de jeu qui se stoppe si l'utilisateur souhaite arrêter de jouer
	while (Jouer == 1)
	{
		// Menu qui demande le niveau
		printf("Bonjour, vous allez commencer une partie de Plus ou Moins.\n\n");
		printf("Trois niveaux de jeu sont disponibles \n \
		1. Niveau 1 : le nombre à trouver est entre 1 et 100 \n \
		2. Niveau 2 : le nombre à trouver est entre 1 et 1000 \n \
		3. Niveau 3 : le nombre à trouver est entre 1 et 10 000. \n\n");
		printf("Quel est le niveau auquel vous voulez vous mesurer ? ");
		scanf("%d", &niveau);

		// Génération du nombre aléatoire en fonction du niveau
		srand(time(NULL));
		if (niveau == 1)
		{
			int MAX = 100;
			nombreInconnu = (rand() % (MAX - MIN + 1)) + MIN;
		}
		else if (niveau == 2)
		{
			int MAX = 1000;
			nombreInconnu = (rand() % (MAX - MIN + 1)) + MIN;
		}
		else 
		{
			int MAX = 10000;
			nombreInconnu = (rand() % (MAX - MIN + 1)) + MIN;
		}

		// Corps du jeu de Plus ou Moins
		while (tentatives != nombreInconnu)
		{
			// On demande a l'utilisateur de rentrer un nombre
			printf("Quel est le nombre ? ");
			scanf("%d", &tentatives);

			if (tentatives < nombreInconnu)
			{
				printf("C'est plus.\n");
				coups = coups + 1;
			}
			else if (tentatives > nombreInconnu)
			{
				printf("C'est moins.\n");
				coups = coups + 1;
			}
			else
			{
				printf("C'est le bon nombre ! C'est gagné !!\n");
				printf("Vous avez trouvé le nombre en %d coups.\n\n", coups);
			}

		}

		// On demande si l'utilisateur souhaite rejouer
		int choixRejouer = 0;			// Variable qui stock le choix de l'utilisateur s'il veut rejouer ou non
		printf("Vous avez terminé la partie de Plus ou Moins.\n");
		printf("Souhaitez-vous rejouer : 1. Oui 2.Non.\n");
		printf("Votre choix : ");
		scanf("%d", &choixRejouer);

		if (choixRejouer == 1)
		{
			Jouer = 1;
			coups = 0;	//On remet le compteur de coups à 0
		}
		else
		{
			printf("Merci d'avoir jouer avec nous.\n");
			Jouer = 0;
		}
	}

	

	return 0;
}