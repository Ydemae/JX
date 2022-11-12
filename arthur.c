#include <stdio.h>
int a, b;
int Tab2[50][2] = {{20, 10}, {15, 70}, {12, 5}};

void creerplateau(int *ligne, int *colonne)
{
    do
    {
        printf("Donner le nombre de lignes du plateau. \n");
        scanf("%d", &(*ligne));
        printf("Donner le nombre de colonnes du plateau. \n");
        scanf("%d", &(*colonne));
    } while (*ligne % 2 == 0 || *colonne % 2 == 0 || *ligne > 7 || ligne < 3 || *colonne > 7 || *colonne < 3);
}

int effacerTab(int *tab[7][7])
{
    for (int i = 0; i <= 6; i++)
        for (int j = 0; j <= 6; j++)
        {
            tab[i][j] = 0;
        }
    return 0;
}

char getpseudo(int numJoueur, char pseudo[])
{
    printf("Quel est votre pseudo joueur %d? \n", numJoueur);
    scanf("%s", pseudo);
    return pseudo;
}

int verifieCase(int tab[7][7], int ligneCible, int columnCible)
{
    if (tab[ligneCible][columnCible] != 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void tour(int nbTour, int *tab[7][7], int ligne, int colonne, char pseudoJ1[], char pseudoJ2[])
{
    int ligneCible, colonneCible;
    for (int i = 1; i <= 2; i++)
    {
        afficheTab(tab, ligne, colonne);
        printf("Tour du joueur %d \n", i);
        do
        {
            printf("Sur quelle ligne voulez vous placer votre jeton?");
            scanf("%d", &ligneCible);
            printf("Dans quelle colonne voulez-vous placer votre jeton?");
            scanf("%d", &colonneCible);
            ligneCible--;
            colonneCible--;
        } while (tab[ligneCible][colonneCible] != 0 || ligneCible < 0 || ligneCible > ligne - 1 || colonneCible > colonne - 1 || colonneCible < 0);
        if (i == 1)
        {
            tab[ligneCible][colonneCible] = nbTour;
        }
        else
        {
            tab[ligneCible][colonneCible] = -nbTour;
        }
    }
}

int afficheTab(int tab[][7], int ligne, int column)
{
    for (int compteLigne = -1; compteLigne < ligne; compteLigne++)
    {
        if (compteLigne == -1)
        {
            for (int i = 0; i <= column; i++)
            {
                printf(" %3d", i);
            }
            printf("\n");
        }
        else
        {
            for (int compteColonne = 0; compteColonne < column; compteColonne++)
            {
                if (compteColonne == 0)
                {
                    printf(" %3d||", compteLigne + 1);
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

int afficheScore(int tab[][2], int nbParties, char pseudoJ1[], char pseudoJ2[])
{

    int totalJ1 = 0, totalJ2 = 0;
    char *vainqueur[30];
    for (int i = 0; i < nbParties; i++)
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
        printf("Partie %d\nResultat : %d contre %d.\nVainqueur : %s \n", i + 1, tab[i][0], tab[i][1], *vainqueur);
        if (i < nbParties)
        {
            totalJ1 += tab[i][0];
            totalJ2 += tab[i][1];
        }
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
        *vainqueur = "Tout le monde ! C'est une egalite !";
    }
    printf("Total de %s : %d\nTotal de %s : %d\nVainqueur Global : %s", pseudoJ1, totalJ1, pseudoJ2, totalJ2, *vainqueur);
    return 0;
}

int NouvellePartie(int EnJeu)
{
    do
    {
        printf("Souhaitez vous continuer a jouer? (0 si non, 1 si oui)");
        scanf("%d", EnJeu);
    } while (EnJeu != 1 && EnJeu != 0);
    return EnJeu;
}

/*void finPartie(int tab[7][7], int ligne, int colonne)
{
    for (int i; i < ligne; i++)
        for (int j; j < colonne; j++)
        {
            if (tab[i][j] == 0)
            {

            }
        }
}*/

int main()
{

    int plateauJeu[7][7], enJeu = 1, ligne, colonne, nbParties = 0;
    char pseudoJ1[30], pseudoJ2[30];
    getpseudo(1, pseudoJ1);
    getpseudo(2, pseudoJ2);
    while (enJeu == 1)
    {
        nbParties += 1;
        effacerTab(plateauJeu);
        creerplateau(&ligne, &colonne);
        for (int i = 1; i < ligne * colonne / 2 - 1; i++)
        {
            tour(i, plateauJeu, ligne, colonne, pseudoJ1, pseudoJ2);
        }
        NouvellePartie(enJeu);
    }
    return 0;
}