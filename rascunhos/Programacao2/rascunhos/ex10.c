#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int linhas, linhas2;
    int colunas, colunas2;
    //int aux, i, j;
    //int X;

    void multiplicar(int linhas, int colunas, int linhas2, int colunas2, int matriz[linhas][colunas], int matriz2[linhas2][colunas2]);

    printf("\n\nDigite a quantidade de linhas da matriz 1: ");
    scanf("%d", &linhas);

    printf("\n\nDigite a quantidade de colunas da matriz 1: ");
    scanf("%d", &colunas);

    printf("\n\nDigite a quantidade de linhas da matriz 2: ");
    scanf("%d", &linhas2);

    printf("\n\nDigite a quantidade de colunas da matriz 2: ");
    scanf("%d", &colunas2);

    int matriz[linhas][colunas];
    int matriz2[linhas2][colunas2];
    //int matriz3[linhas][colunas2];

    if(colunas != linhas2)
    {
        printf("\n\nNao eh possivel multiplicar\n");
        exit(0);

    }

    srand(time(NULL));

    printf("\n\n");

    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            matriz[i][j] = rand() % 10;
            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    for(int i = 0; i < linhas2; i++)
    {
        for(int j = 0; j < colunas2; j++)
        {
            matriz2[i][j] = rand() % 10;
            printf("%d", matriz2[i][j]);
        }
        printf("\n");
    }

    multiplicar(linhas, colunas, linhas2, colunas2, matriz, matriz2);

    /*for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas2; j++)
        {

            matriz3[i][j] = 0;
            for(X = 0; X < linhas2; X++)
            {
                aux += matriz[i][X] * matriz2[X][j];
            matriz3[i][j] = aux;
            aux = 0;
            }
        }
    }

    printf("\n\n");

    printf("Matriz gerada da multiplicação: (matriz1 * matriz2) \n\n");

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas2; j++)
            printf("%6.d", matriz3[i][j]);
        printf("\n\n");
    }

    printf("\n");*/

    return 0;
}

/*void multiplicar(int linhas, int colunas, int linhas2, int colunas2, int matriz[linhas][colunas], int matriz2[linhas2][colunas2])
{
    int i;
    int j;
    int aux;
    int X;

    int matriz3[linhas][colunas2];

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas2; j++)
        {

            matriz3[i][j] = 0;
            for(X = 0; X < linhas2; X++)
            {
                aux += matriz[i][X] * matriz2[X][j];
            matriz3[i][j] = aux;
            aux = 0;
            }
        }
    }

    printf("\n\n");

    printf("Matriz gerada da multiplicação: (matriz1 * matriz2) \n\n");

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas2; j++)
            printf("%6.d", matriz3[i][j]);
        printf("\n\n");
    }

    printf("\n");

}*/
