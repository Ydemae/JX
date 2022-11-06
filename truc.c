// C program to store temperature of two cities of a week and display it.
#include <stdio.h>
int CITY = 2;
int WEEK = 7;
int Tab[6][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
int main()
{

    // Using nested loop to store values in a 2d array

    printf("\nDisplaying values: \n\n");

    // Using nested loop to display vlues of a 2d array
    for (int i = 0; i < 6; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            printf("City %d, Day %d = %d\n", i + 1, j + 1, Tab[i][j]);
        }
    }
    return 0;
}