#include <stdio.h>

int main()
{

    int matA[100][100], matB[100][100], matC[100][100];
    int m, n, p;

    printf("Vnesi broj na redovi na prvata matrica, koloni na prvata a redovi na vtorata i koloni na vtorata matrica\n");
    scanf("%d %d %d", &m, &n, &p);

    printf("Vnesi gi elementite na prvata matrica\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matA[i][j]);
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d\t", matA[i][j]);
        }

        printf("\n");
    }

    printf("Vnesi gi elementite na vtorata matrica\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            scanf("%d", &matB[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("%d\t", matB[i][j]);
        }

        printf("\n");
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {

            for (int k = 0; k < n; k++)
            {
                matC[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    printf("Konecnata matrica e:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            printf("%d\t", matC[i][j]);
        }
        printf("\n");
    }

    return 0;
}