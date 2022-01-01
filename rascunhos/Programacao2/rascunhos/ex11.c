#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "libsnsds.h"

int main(void)
{
    int linhas, linhas2;
    int colunas, colunas2;

    int vetor[100] = {0};
    int vetor1[100] ={0};
    int i=0;
    int j=0;
    int k=0;
    int flag=0;
    int igualdade;

    void multiplicar(int linhas, int colunas, int linhas2, int colunas2, int matriz[linhas][colunas], int matriz2[linhas2][colunas2]);

    srand(time(NULL));

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

    do
    {
        igualdade = 0;
        vetor[i] = rand() % 100;
        for(j=0; j<i; j++)
        {
            if(vetor[j] == vetor[i])
                igualdade = 1;
        }
        if(igualdade == 0)
        {
            i++;
        }
    }
    while(i<100);

    i=0;
    j=0;

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)
        {
            for(k = 0; k < (linhas * colunas); k++)
            {
                matriz[i][k] = vetor[k];

                //printf("Valores passados para a  matriz são %d\n", matriz[i][k]);

                if(k == (linhas * colunas) -1)
                {
                    flag = 1;
                    break;
                }
            }

            if(flag)
                break;
        }
        if(flag)
            break;
    }

    igualdade=0;
    i=0;
    j=0;

     do
    {
        igualdade = 0;
        vetor1[i] = rand() % 100;
        for(j=0; j<i; j++)
        {
            if(vetor1[j] == vetor1[i])
                igualdade = 1;
        }
        if(igualdade == 0)
        {
            i++;
        }
    }
    while(i<100);


    i=0;
    j=0;

    for(i = 0; i < linhas2; i++)
    {
        for(j = 0; j < colunas2; j++)
        {
            for(k = 0; k < (linhas2 * colunas2); k++)
            {
                matriz2[i][k] = vetor1[k];

                //printf("Valores passados para a  matriz são %d\n", matriz[i][k]);

                if(k == (linhas2 * colunas2) - 1)
                {
                    flag = 1;
                    break;
                }
            }

            if(flag)
                break;
        }
        if(flag)
            break;
    }

    printf("\n--------------------MATRIZ 1--------------------\n");

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas; j++)

            printf("%2d ", matriz[i][j]);

        printf("\n");
    }

    printf("\n--------------------MATRIZ 2--------------------\n");

     for(i = 0; i < linhas2; i++)
    {
        for(j = 0; j < colunas2; j++)

            printf("%2d ", matriz2[i][j]);

        printf("\n");
    }

      multiplicar(linhas, colunas, linhas2, colunas2, matriz, matriz2);

    printf("\n");
 
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

    printf("----------Matriz gerada da multiplicação: (matriz1 * matriz2)----------\n\n");

    for(i = 0; i < linhas; i++)
    {
        for(j = 0; j < colunas2; j++)
            printf("%6d", matriz3[i][j]);
        printf("\n\n");
    }

    printf("\n");

}*/
 
