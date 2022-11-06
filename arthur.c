#include <stdio.h>
int a, b;
int Tab[7][7] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
int Tab2[50][2] = {{20, 10}, {15, 70}, {12, 5}};

void afficheTab(int tab[][7], int ligne, int column)
{
    /*int i, j;
    // partie affichage des colonnes
    for (i = 0; i < b; i++)
    {
        if (i == b - 1)
        {
            printf("%d", i + 1);
        }
        // empêche le print de "|" à la fin de la ligne pour ne pas répéter le caractère deux fois
        else if (i == 0)
        {
            printf("|%d|", i + 1);
        }
        // entoure le premier élément de "|"
        else
        {
            printf("%d|", i + 1);
        }
        // affiche les numéro de collonne entre le début et la fin du tableau
    }*/
    // partie affichage des lignes
    /*for (i = 0; i < (a * b) + 1; i++)
    {
        if (i % b == 0)
        {
            printf("|%d\n", (i / b));
        }

        if (i != (a * b))
        {
            printf("|%d", tab[i]);
        }
        // affiche les lignes du tableau, la condition empêche l'affichage d'un élément en dehors du tableau
    }*/
    for (int compteLigne = -1; compteLigne < ligne; compteLigne++)
    {
        if (compteLigne == -1)
        {
            for (int i = 0; i <= column; i++)
            {
                printf(" %d", i);
            }
            printf("\n");
        }
        else
        {
            for (int compteColonne = 0; compteColonne < column; compteColonne++)
            {
                if (compteColonne == 0)
                {
                    printf(" %d||", compteLigne + 1);
                }
                printf("%d|", tab[compteLigne][compteColonne]);
            }
            printf("\n");
        }
        /*if (compteLigne == 0)
        {
            printf("%d||", compteLigne);
            for (int z = 1; z <= column; z++)
            {
                printf("%d|", z);
            }
            printf("\n");
        }
        else
        {
            printf("%d||", compteLigne);
        }*/
    }
}

void afficheScore(int tab[][2], int nbParties, char pseudoJ1[], char pseudoJ2[])
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
    /*int i, totalJ1, totalJ2;
    char *vainqueur[30];
    for (i = 0; i < nbParties * 2; i = i + 2)
    {
        if (tab[i] < tab[i + 1])
        {
            *vainqueur = pseudoJ2;
        }
        else if (tab[i] > tab[i + 1])
        {
            *vainqueur = pseudoJ1;
        }
        else
        {
            *vainqueur = "Les deux ! C'est une egalite !";
        }
        printf("Partie %d\nResultat : %d contre %d.\nVainqueur : %s \n", i / 2 + 1, tab[i], tab[i + 1], *vainqueur);
        if (i != nbParties * 2 - 2)
        {
            totalJ1 = totalJ1 + tab[i];
            totalJ2 = totalJ2 + tab[i + 1];
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
    printf("Total du joueur 1 : %d\nTotal du joueur 2 : %d\nVainqueur Global : %s", totalJ1, totalJ2, *vainqueur);*/
}
void main()
{
    afficheTab(Tab, 6, 3);
    afficheScore(Tab2, 3, "Arthur", "Thomas");
}