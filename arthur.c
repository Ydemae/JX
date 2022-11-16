#include <stdio.h>

void afficheRegles()
{   
    char veutAfficheRegles;
    printf("Bienvenue,\nvous etes en train de jouer au JeuX edition AT mais peut etre que c'est votre premiere fois, souhaitez vous voir les regles du jeu? (repondre O pour oui N pour non)");
    scanf("%c", &veutAfficheRegles);
    if(veutAfficheRegles == 'O' || veutAfficheRegles == 'o') printf("Ce jeu se joue a deux et se deroule sur un plateau defini par un nombre de ligne et de colonnes impair comme celui ci :\n\e[0;32m0    1   2   3\e[0m\n\e[0;32m1\e[0m||  0|   0|   0|\n\e[0;32m2\e[0m||  0|   0|   0|\n\e[0;32m3\e[0m||  0|   0|   0|\nVous devrez placer des jetons numerotes en fonction du tour actuel, partant donc de 1.\nVous devrez evidemment faire attention a cibler une case qui figure dans le tableau et a ne pas tenter de poser de jeton sur un jeton deja en jeu, ceci etant contraire aux regles.\nCes erreurs vous renverraient ce message d'erreur \e[7;31mveuillez saisir une case valide\e[0m .\nLe gagnant du jeu est determine en fonction du dernier 0 en jeu. En effet, toutes les cases autour de ce 0 seront comptabilisees dans le score d'un des deux joueurs, c'est ce qui donne une dimension plus strategique a ce jeu, vous permettant de retirer des conditions de victoire a votre adversaire. Nous esperons que cette breve explication vous aura ete utile mais rien n'est mieux qu'une partie pour comprendre le fonctionnement du jeu, nous vous souhaitons donc bon jeu, \e[1;33mHave Fun !\e[0m\n");
}

void creerplateau(int *ligne, int *colonne)
{
    do
    {
        printf("Donner le nombre de lignes du plateau, ce nombre doit etre impair. \n");
        scanf("%d", &(*ligne));
        printf("Donner le nombre de colonnes du plateau, ce nombre doit etre impair. \n");
        scanf("%d", &(*colonne));
    } while (*ligne % 2 == 0 || *colonne % 2 == 0 || *ligne > 7 || *ligne < 3 || *colonne > 7 || *colonne < 3);
}

int effacerTab(int tab[7][7])
{
    for (int i = 0; i <= 6; i++)
        for (int j = 0; j <= 6; j++)
        {
            tab[i][j] = 0;
        }
    return 0;
}

char * getpseudo(int numJoueur, char pseudo[])
{
    printf("Quel est votre pseudo joueur %d? \n", numJoueur);
    scanf("%s", pseudo);
    return pseudo;
}

int afficheTab(int tab[7][7], int ligne, int colonne)
{
    for (int compteLigne = -1; compteLigne < ligne; compteLigne++)
    {
        if (compteLigne == -1)
        {
            for (int i = 0; i <= colonne; i++)
            {
                printf("\e[0;32m %3d\e[0m", i);
            }
            printf("\n");
        }
        else
        {
            for (int compteColonne = 0; compteColonne < colonne; compteColonne++)
            {
                if (compteColonne == 0)
                {
                    printf("\e[0;32m %3d\e[0m||", compteLigne + 1);
                }
                if (tab[compteLigne][compteColonne] > 0)
                {
                    printf("\e[1;34m%3d\e[0m|", tab[compteLigne][compteColonne]);
                }
                else if (tab[compteLigne][compteColonne] < 0)
                {
                    printf("\e[1;31m%3d\e[0m|", abs(tab[compteLigne][compteColonne]));
                }
                else
                {
                    printf("\e[1;29m%3d\e[0m|", tab[compteLigne][compteColonne]);
                }
            }
            printf("\n");
        }
    }
    return 0;
}

void tour(int nbTour, int tab[7][7], int ligne, int colonne, int firstPlayer)
{
    int ligneCible, colonneCible;
    if (firstPlayer == 1)
    {
        for (int i = 1; i <= 2; i++)
        {
            printf("Tour du joueur %d \n", i);
            do
            {
                printf("Sur quelle ligne voulez vous placer votre jeton? ");
                scanf("%d", &ligneCible);
                printf("Dans quelle colonne voulez-vous placer votre jeton? ");
                scanf("%d", &colonneCible);
                ligneCible--;
                colonneCible--;
                if (tab[ligneCible][colonneCible] != 0 || ligneCible < 0 || ligneCible > ligne - 1 || colonneCible > colonne - 1 || colonneCible < 0) printf("\n\e[7;31mveuillez saisir une case valide\e[0m\n");
            } while (tab[ligneCible][colonneCible] != 0 || ligneCible < 0 || ligneCible > ligne - 1 || colonneCible > colonne - 1 || colonneCible < 0);
            if (i == 1)
            {
                tab[ligneCible][colonneCible] = nbTour;
            }
            else
            {
                tab[ligneCible][colonneCible] = -nbTour;
            }
            afficheTab(tab, ligne, colonne);
        }
    }
    else
    {
        for (int i = 2; i >= 1; i--)
        {
            printf("Tour du joueur %d \n", i);
            do
            {
                printf("Sur quelle ligne voulez vous placer votre jeton?");
                scanf("%d", &ligneCible);
                printf("Dans quelle colonne voulez-vous placer votre jeton?");
                scanf("%d", &colonneCible);
                ligneCible--;
                colonneCible--;
                if (tab[ligneCible][colonneCible] != 0 || ligneCible < 0 || ligneCible > ligne - 1 || colonneCible > colonne - 1 || colonneCible < 0) printf("\n\e[7;31mveuillez saisir une case valide\e[0m\n");
            } while (tab[ligneCible][colonneCible] != 0 || ligneCible < 0 || ligneCible > ligne - 1 || colonneCible > colonne - 1 || colonneCible < 0);
            if (i == 1)
            {
                tab[ligneCible][colonneCible] = nbTour;
            }
            else
            {
                tab[ligneCible][colonneCible] = -nbTour;
            }
            afficheTab(tab, ligne, colonne);
        }
    }
}

int afficheScore(int tab[][2], int nbParties, char pseudoJ1[], char pseudoJ2[])
{

    int totalJ1 = 0, totalJ2 = 0;
    char *vainqueur[30];
    for (int i = 0; i <= nbParties; i++)
    {
        if (tab[i][0] < tab[i][1])
        {
            *vainqueur = pseudoJ2;
        }
        else if (tab[i][0] > tab[i][1])
        {
            *vainqueur = pseudoJ1;
        }
        else
        {
            *vainqueur = "Les deux ! C'est une egalite !";
        }
        printf("Partie %d\nResultat : \e[1;34m%d\e[0m contre \e[1;31m%d\e[0m.\nVainqueur : %s \n", i + 1, tab[i][0], tab[i][1], *vainqueur);
        totalJ1 += tab[i][0];
        totalJ2 += tab[i][1];
    }
    if (totalJ1 > totalJ2)
    {
        *vainqueur = pseudoJ1;
    }
    else if (totalJ2 > totalJ1)
    {
        *vainqueur = pseudoJ2;
    }
    else
    {
        *vainqueur = "\e[1;32mTout le monde ! C'est une egalite !\e[0m";
    }
    printf("\nTotal de \e[1;34m %s \e[0m: %d\nTotal de \e[1;31m%s\e[0m : %d\nVainqueur Global : %s\n", pseudoJ1, totalJ1, pseudoJ2, totalJ2, *vainqueur);
    return 0;
}

int NouvellePartie(int *EnJeu)
{
    do
    {
        printf("Souhaitez vous continuer a jouer? (0 si non, 1 si oui) ");
        scanf("%d", &(*EnJeu));
    } while (*EnJeu != 1 && *EnJeu != 0);
    return 0;
}

void comptePoints(int tab[7][7], int ligne, int colonne, int score[][2], int nbParties)
{
    int ligneLastCase, colonneLastCase, compteLigne, compteColonne, scoreJ1 = 0, scoreJ2 = 0;
    for (compteLigne = 0; compteLigne < ligne; compteLigne++)
        for (compteColonne = 0; compteColonne < colonne; compteColonne++)
        {
            if (tab[compteLigne][compteColonne] == 0)
            {
                ligneLastCase = compteLigne;
                colonneLastCase = compteColonne;
                break;
            }
        }
    for (compteColonne = colonneLastCase - 1; compteColonne <= colonneLastCase + 1; compteColonne++)
        for (compteLigne = ligneLastCase - 1; compteLigne <= ligneLastCase + 1; compteLigne++)
        {
            if (compteColonne >= 0 && compteColonne < colonne && compteLigne >= 0 && compteLigne < ligne)
            {
                if (tab[compteLigne][compteColonne] < 0)
                {
                    scoreJ2 += abs(tab[compteLigne][compteColonne]);
                }
                else if (tab[compteLigne][compteColonne] > 0)
                {
                    scoreJ1 += tab[compteLigne][compteColonne];
                }
            }
        }
    score[nbParties][0] = scoreJ1;
    score[nbParties][1] = scoreJ2;
}

int main()
{

    int plateauJeu[7][7], enJeu = 1, ligne, colonne, nbPartie = 0, scoreTotal[50][2], firstPlayer = 1;
    char pseudoJ1[30], pseudoJ2[30];
    afficheRegles();
    getpseudo(1, pseudoJ1);
    getpseudo(2, pseudoJ2);
    while (enJeu == 1)
    {
        effacerTab(plateauJeu);
        creerplateau(&ligne, &colonne);
        afficheTab(plateauJeu, ligne, colonne);
        for (int i = 1; i <= ligne * colonne / 2; i++)
        {
            tour(i, plateauJeu, ligne, colonne, firstPlayer);
        }
        comptePoints(plateauJeu, ligne, colonne, scoreTotal, nbPartie);
        afficheScore(scoreTotal, nbPartie, pseudoJ1, pseudoJ2);
        NouvellePartie(&enJeu);
        firstPlayer = firstPlayer == 1 ? 2 : 1;
        nbPartie += 1;
    }
    return 0;
}