#include <stdio.h>
void creerJeu(int tab[7][7], int *L, int *C)
{
    do
    {
        printf("Entrez le nimbre de lignes de la grille : ");
        scanf("%d", &(*L));
        printf("Entrez le nimbre de lignes de la grille : ");
        scanf("%d", &(*C));
        getchar();
    } while ((*L < 3 || 7 < *L) || (*C < 3 || 7 < *C) || (*L % 2 == 0) || (*C % 2 == 0));
}
int main()
{
    int machin[7][7], *L = 10, *C = 1;
    printf("%d + %d \n", L, C);
    creerJeu(machin, L, C);
    printf("%d + %d", L, C);
}