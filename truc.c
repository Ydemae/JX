#include <stdio.h>
void afficheRegles()
{
    printf("Bienvenue,\nvous etes en train de jouer au JeuX edtition AT mais peut etre que c'est votre premiere fois, c'est pour cela que nous allons vous presenter les regles. Ce jeu se joue a deux et se deroule sur un plateau defini par un nombre de ligne et de colonnes impair comme celui ci :\n\e[0;32m0    1   2   3\e[0m\n\e[0;32m1\e[0m||  0|   0|   0|\n\e[0;32m2\e[0m||  0|   0|   0|\n\e[0;32m3\e[0m||  0|   0|   0|\nVous devrez placer des jetons numerotes en fonction du tour actuel, partant donc de 1.\nVous devrez evidemment faire attention a cibler une case qui figure dans le tableau et a ne pas tenter de poser de jeton sur un jeton deja en jeu, ceci etant contraire aux regles.\nCes erreurs vous renverraient ce message d'erreur \e[7;31mveuillez saisir une case valide\e[0m .\nLe gagnant du jeu est determine en fonction du dernier 0 en jeu. En effet, toutes les cases autour de ce 0 seront comptabilisees dans le score d'un des deux joueurs, c'est ce qui donne une dimension plus strategique a ce jeu, vous permettant de retirer des conditions de victoire a votre adversaire. Nous esperons que cette breve explication vous aura ete utile mais rien n'est mieux qu'une partie pour comprendre le fonctionnement du jeu, nous vous souhaitons donc bon jeu, \e[1;33mHave Fun !\e[0m");
}
int main()
{
    afficheRegles();
}