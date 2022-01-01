/* *********************************************************************** *
 *    PROGRAM_NAME, VERSION                                                 *
 *    BRIEF_DESCRIPTION                                                     *
 *                                                                          *
 *  Copyright (C) 2021 by Silas Natanael Silva De Souza                     *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *  To contact the author, please write to:                                 *
 *  Name: Silas Natanael Silva De Souza <snss@poli.br>                      *
 *  Webpage: http://beco.poli.br/~username                                  *
 *  Phone: (81) 98361-9055                                                  *
 * ************************************************************************ *
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct tempNo
{
    float valor;
    int coluna;
    struct tempNo *prox;
} NO;

typedef NO *PONT;

typedef struct
{
    PONT *A;
    int linhas;
    int colunas;
} MATRIZ;

void iniciarMatriz(MATRIZ *m, int lin, int col)
{
    int i;
    m->linhas = lin;
    m->colunas = col;
    m->A = (PONT *) malloc(lin * sizeof(PONT));

    for(i = 0; i < lin; i++)
        m->A[i] = NULL;
}

bool atribuiMatriz(MATRIZ *m, int lin, int col, float val)
{
    if(lin < 0 || lin >= m->linhas || col < 0 || col >= m->colunas)
        return false;

    PONT ant = NULL;
    PONT atual = m->A[lin];

    while(atual != NULL && atual->coluna < col)
    {
        ant = atual;
        atual = atual->prox;
    }

    if(atual != NULL && atual->coluna == col)
    {
        if(val == 0)
        {
            if(ant == NULL) m->A[lin] = atual->prox;
            else ant->prox = atual->prox;
            free(atual);
        }
        else
            atual->valor = val;
    }
    else
    {
        PONT novo = (PONT) malloc(sizeof(NO));
        novo->coluna = col;
        novo->valor = val;
        novo->prox = atual;

        if(ant == NULL)
            m->A[lin] = novo;
        else
            ant->prox = novo;
    }

    return true;
}

float valorMatriz(MATRIZ *m, int lin, int col)
{
    if(lin < 0 || lin >= m->linhas || col < 0 || col >= m->colunas)
        return 0;

    PONT atual = m->A[lin];
    while(atual != NULL && atual->coluna < col)
        atual = atual->prox;

    if(atual != NULL && atual->coluna == col)
        return atual->valor;

    return 0;
}

void printMatriz(MATRIZ *m, int lin, int col)
{
    int i, j;

    printf("\n");
    for(i = 0; i < lin; i++)
    {
        for(j = 0; j < col; j++)
            printf("%2.0f  ", valorMatriz(m, i, j));
        printf("\n");
    }
}
MATRIZ *criarMatriz(int linhas, int colunas)
{
    MATRIZ *matriz = (MATRIZ *)malloc(sizeof(MATRIZ));
    int linha = 0, coluna = 0, valor = 0;
    int end = 0;
    char comando = ' ';
    int qtd = 0;

    iniciarMatriz(matriz, linhas, colunas);

    while(end != 1)
    {
        printf("\nQuer inserir um valor? [s/n]\n");
        scanf(" %c", &comando);

        if(comando == 'n')
            end = 1;

        if(qtd == (linhas * colunas) - 1)
            end = 1;

        if(comando == 's')
        {
            printf("\n Qual linha e coluna voce quer inserir o valor? linhas (de 0 a %i) e colunas (de 0 a %i)\n", (linhas - 1), (colunas - 1));
            scanf("%d %d", &linha, &coluna);

            if(linha >= linhas || linha < 0 || coluna >= colunas || coluna < 0)
            {
                printf("\nInsira um valor valido\n");
                return NULL;
            }

            printf("\nQual valor vc quer inserir na linha %d coluna  %d\n", linha, coluna);
            scanf("%d", &valor);

            atribuiMatriz(matriz, linha, coluna, valor);

            qtd++;
        }
    }

    return matriz;
}

MATRIZ *multiplicacao(MATRIZ *matriz1, MATRIZ *matriz2, int linhasMatriz1, int colunasMatriz1, int linhasMatriz2, int colunasMatriz2)
{
    MATRIZ *matriz = (MATRIZ *)malloc(sizeof(MATRIZ));
    int i, j, k;
    int teste;

    if(colunasMatriz1 != linhasMatriz2)
    {
        printf("\nAs matrizes nao podem ser multiplicadas\n");
        return NULL;
    }

    iniciarMatriz(matriz, linhasMatriz1, colunasMatriz2);

    for(i = 0; i < linhasMatriz1; i++)
    {
        for(j = 0; j < colunasMatriz2; j++)
        {
            teste = 0;

            for(k = 0; k < colunasMatriz1; k++)
                teste += (valorMatriz(matriz1, i, k) * valorMatriz(matriz2, k, j));

            atribuiMatriz(matriz, i, j, teste);
        }
    }

    return matriz;
}

int main(void)
{
    MATRIZ *matriz1;
    int linhasMatriz1, colunasMatriz1;
    MATRIZ *matriz2;
    int linhasMatriz2, colunasMatriz2;

    MATRIZ *matrizMultiplicada;

    printf("\nQuantas linhas vai ter a primeira matriz?\n");
    scanf("%d", &linhasMatriz1);

    printf("\nQuantas colunas vai ter a primeira matriz?\n");
    scanf("%d", &colunasMatriz1);

    matriz1 = criarMatriz(linhasMatriz1, colunasMatriz1);

    if(matriz1 != NULL)
    {

        printf("\n");
        printf("MATRIZ 1 \n");
        printMatriz(matriz1, linhasMatriz1, colunasMatriz1);
        printf("\n");

        printf("\nQuantas linhas vai ter a segunda matriz?\n");
        scanf("%d", &linhasMatriz2);

        printf("\nQuantas colunas vai ter a segunda matriz?\n");
        scanf("%d", &colunasMatriz2);

        matriz2 = criarMatriz(linhasMatriz2, colunasMatriz2);
    }

    if(matriz1 != NULL && matriz2 != NULL)
    {

        printf("\n");
        printf("MATRIZ 2 \n");
        printMatriz(matriz2, linhasMatriz2, colunasMatriz2);
        printf("\n");
        printf("------------------------------------------------------------- MATRIZ MULTIPLICADA ---------------------------------------------------------------------------\n");

        matrizMultiplicada = multiplicacao(matriz1, matriz2, linhasMatriz1, colunasMatriz1, linhasMatriz2, colunasMatriz2);

        if(matrizMultiplicada != NULL)
            printMatriz(matrizMultiplicada, linhasMatriz1, colunasMatriz2);
        printf("\n");
    }

    return 0;
}


