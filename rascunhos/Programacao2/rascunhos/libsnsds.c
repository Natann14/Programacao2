
/*------------------------------*/
//includes
#ifndef libsnsds_h
    #include"libsnsds.h"
#endif
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<allegro.h>
/*-------------------------------*/

/*---------------------------------------------------------------------------*/

//Funcao do ex1.c
void normalizar_x(void)
{
    float maximo = 0, minimo = 0, x= 0;
    float normalizador = 0;

    printf("\nDigite o valor de X: \n");
    scanf("%f", &x);

    printf("\nDigite o valor maximo: \n");
    scanf("%f", &maximo);

    printf("\nDigite o valor minimo: \n");
    scanf("%f", &minimo);

    if(minimo > maximo)
    {
        printf("\nNao eh possivel realizar a operacao matematica\n");
        exit(0);
    }

    normalizador = (x - minimo)/(maximo - minimo);

    printf("\nValor normalizado: %f\n\n", normalizador);

}
/*-------------------------------------------------------------------------------*/

//Funcao do ex2.c
void numeros_aleatorios(void)
{
    int numeros[20] = {0};
    int i=0;
    int j=0;
    int igualdade;
    srand(time(NULL));

    do
    {
        igualdade = 0;
        numeros[i] = rand() % 50;
        for(j=0; j<i; j++)
        {
            if(numeros[j] == numeros[i])
                igualdade = 1;
        }
        if(igualdade == 0)
        {
            i++;
        }
    }
    while(i<20);

    printf("\n");

    for(i=0; i<20; i++)
    {
        printf("%i, ", numeros[i]);
    }

    printf("\n\n");

}

/*---------------------------------------------------------------------------------*/

//Funcoes do ex4.c

void prefixo(char palavra1[], char palavra2[]) //prefixo
{
    int retorno;

    retorno = strncmp(palavra1,palavra2,2);

    if(retorno == 0)
    {
        printf("\nAs palavras tem o mesmo prefixo\n");
    }
    else
    {
        printf("\nNao tem o mesmo prefixo\n");
    }

    void sufixo(char palavra1[], char palavra2[]);
    sufixo(palavra1, palavra2);

}
void sufixo(char palavra1[], char palavra2[]) //sufixo
{
    int i=0, aux=0, fim=0;
    int tamanho1, tamanho2, retornar=0;
    char destino1[50], destino2[50];

    tamanho1 = strlen(palavra1);
    tamanho2 = strlen(palavra2);

    strcpy(destino1,palavra1);
    strcpy(destino2,palavra2);

    fim = tamanho1-1;
    for(i=0; i<tamanho1/2; i++)
    {
        aux = destino1[i];
        destino1[i] = destino1[fim];
        destino1[fim] = aux;
        fim--;
    }

    i=0;
    aux=0;
    fim=0;

    fim = tamanho2-1;
    for(i=0; i<tamanho2/2; i++)
    {
        aux = destino2[i];
        destino2[i] = destino2[fim];
        destino2[fim] = aux;
        fim--;
    }

    retornar = strncmp(destino1, destino2,2);

    if(retornar == 0)
    {
        printf("\nAs palavras tem o mesmo sufixo\n");
    }
    else
    {
        printf("\nNao tem o mesmo sufixo\n");
    }

    void subpalavra(char palavra1[], char palavra2[]);
    subpalavra(palavra1,palavra2);

}
void subpalavra(char palavra1[], char palavra2[]) //subpalavra
{
    char *resultado;

    resultado = strstr(palavra1,palavra2);

    if(resultado)
    {
        printf("\nA segunda string eh substring da primeira\n");
    }
    else
    {
        printf("\nA segunda string nao eh substring da primeira\n");
    }

    void concatenacao(char palavra1[], char palavra2[]);
    concatenacao(palavra1,palavra2);

}
void concatenacao(char palavra1[], char palavra2[]) //concatenacao
{

    strcat(palavra1,palavra2);
    printf("\nConcatencao das strings: %s\n", palavra1);
    printf("\n\n");

}


/*---------------------------------------------------------------------------------*/

//Funcao do ex9.c

void inverter(char vetor[], int inicio, int fim)
{
    int auxiliar;
    if(inicio<fim)
    {
        auxiliar = vetor[inicio];
        vetor[inicio] = vetor[fim];
        vetor[fim] = auxiliar;
        inverter(vetor, inicio + 1, fim - 1);
    }

}

/*---------------------------------------------------------------------------------*/

//funcao do ex10.c

void multiplicar(int linhas, int colunas, int linhas2, int colunas2, int matriz[linhas][colunas], int matriz2[linhas2][colunas2])
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

}
/*----------------------------------------------------------------------------------*/
//funcao do ex11.c

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
