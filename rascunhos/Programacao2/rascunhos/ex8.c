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
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(void)
{
    int numeros[500];
    int numeros2[500];
    int i = 0, j = 0;
    int igualdade;

    void bubble_sort(int numeros[]);

    srand(time(NULL));

    do
    {
        igualdade = 0;
        numeros[i] = rand() % 500;
        for(j = 0; j < i; j++)
        {
            if(numeros[j] == numeros[i])
                igualdade = 1;
        }
        if(igualdade == 0)
            i++;
    }
    while(i < 500);

    printf("\n\n");

    printf("\nVetor que sera ordenado pelo Bublle sort e pelo Insetion Sort:\n\n");

    for(i = 0; i < 500; i++)
        printf("%4d| ", numeros[i]);


    printf("\n\n");

    for(i = 0; i < 500; i++)
        numeros2[i] = numeros[i];

    /*printf("\n\nVetor ordenado pelo outro sort:\n\n");

    for(i = 0; i < 500; i++)
        printf("%4d| ", numeros2[i]);*/


    //printf("\n\n");

    bubble_sort(numeros);

    //insertion sort

     int k = 0;
     int n = 500;
     j = 0;
     int aux;
     int trocas = 0;
     int comparacoes = 0;

   for (k = 1; k <= n - 1; k++){
      //printf("\n[%d] ", k);

      aux = numeros2[k];
      j = k - 1;
      while (j >= 0 && aux < numeros2[j]) {
          comparacoes++;
         //printf("%d, ", j);

         numeros2[j+1] = numeros2[j];
         j--;
      }

      numeros2[j+1] = aux;
      trocas++;
   }

    printf("------------------------------------------------------------------------------------------------------");

    printf("\n\nCASO MEDIO (VETOR ALEATORIO COLOCADO EM ORDEM CRESCENTE) usando Insertion Sort:\n\n");

    for(i = 0; i < 500; i++)
        printf("%4d", numeros2[i]);

    printf("\n\n");

    printf("\n\nComparacoes: %d             Trocas: %d\n\n", comparacoes, trocas);

     k = 0;
     n = 500;
     j = 0;
     aux = 0;
     trocas = 0;
     comparacoes = 0;

   for (k = 1; k <= n - 1; k++){
      //printf("\n[%d] ", k);

      aux = numeros2[k];
      j = k - 1;
      while (j >= 0 && aux > numeros2[j]) {
          comparacoes++;
         //printf("%d, ", j);

         numeros2[j+1] = numeros2[j];
         j--;
      }

      numeros2[j+1] = aux;
      trocas++;
   }

    printf("------------------------------------------------------------------------------------------------------");

    printf("\n\nMELHOR CASO (VETOR EM ORDEM CRESCENTE COLOCADO EM ORDEM DECRESCENTE) usando Insertion Sort:\n\n");

    for(i = 0; i < 500; i++)
        printf("%4d", numeros2[i]);

    printf("\n\n");

    printf("\n\nComparacoes: %d             Trocas: %d\n\n", comparacoes, trocas);

     k = 0;
     n = 500;
     j = 0;
     aux = 0;
     trocas = 0;
     comparacoes = 0;

   for (k = 1; k <= n - 1; k++){
      //printf("\n[%d] ", k);

      aux = numeros2[k];
      j = k - 1;
      while (j >= 0 && aux < numeros2[j]) {
          comparacoes++;
         //printf("%d, ", j);

         numeros2[j+1] = numeros2[j];
         j--;
      }

      numeros2[j+1] = aux;
      trocas++;
   }

    printf("------------------------------------------------------------------------------------------------------");

    printf("\n\nPIOR CASO (VETOR EM ORDEM DECRESCENTE COLOCADO EM ORDEM CRESCENTE) usando Insertion Sort:\n\n");

    for(i = 0; i < 500; i++)
        printf("%4d", numeros2[i]);

    printf("\n\n");

    printf("\n\nComparacoes: %d             Trocas: %d\n\n", comparacoes, trocas);

    return 0;
}

void bubble_sort(int numeros[])
{
    int contador = 0;
    int aux = 0;
    int i = 0;
    int comparacoes = 0;
    int trocas = 0;

    // Algoritmo de ordenação Bubblesort:
    for(contador = 1; contador < 500; contador++)
    {
        for(i = 0; i < 500 - 1; i++)
        {
            comparacoes++;
            if(numeros[i] > numeros[i + 1])
            {
                aux = numeros[i];
                numeros[i] = numeros[i + 1];
                numeros[i + 1] = aux;
                trocas++;
            }
        }
    }
    //Fim do algoritmo Bubble sort

    printf("\n\nCASO MEDIO (VETOR ALEATORIO COLOCADO EM ORDEM CRESCENTE) usando Bubble Sort:\n\n");

    for(i = 0; i < 500; i++)
        printf("%4d", numeros[i]);

    printf("\n\n");

    printf("\n\nComparacoes: %d             Trocas: %d\n\n", comparacoes, trocas);

    printf("------------------------------------------------------------------------------------------------------");

//Ordem decrescente melhor caso usando Bubble Sort

    contador = 0;
    aux = 0;
    i = 0;
    comparacoes = 0;
    trocas = 0;

    for(contador = 1; contador < 500; contador++)
    {
        for(i = 0; i < 500 - 1; i++)
        {
            comparacoes++;
            if(numeros[i] < numeros[i + 1])
            {
                aux = numeros[i];
                numeros[i] = numeros[i + 1];
                numeros[i + 1] = aux;
                trocas++;
            }
        }
    }

    printf("\n\nMELHOR CASO (VETOR EM ORDEM CRESCENTE COLOCADO EM ORDEM DECRESCENTE) usando Bubble Sort:\n\n");

    for(i = 0; i < 500; i++)
        printf("%4d", numeros[i]);

    printf("\n\n");

    printf("\n\nComparacoes: %d             Trocas: %d\n\n", comparacoes, trocas);

    printf("------------------------------------------------------------------------------------------------------");

//Voltando para ordem crescente usando Bubble sort

    contador = 0;
    aux = 0;
    i = 0;
    comparacoes = 0;
    trocas = 0;

    for(contador = 1; contador < 500; contador++)
    {
        for(i = 0; i < 500 - 1; i++)
        {
            comparacoes++;
            if(numeros[i] > numeros[i + 1])
            {
                aux = numeros[i];
                numeros[i] = numeros[i + 1];
                numeros[i + 1] = aux;
                trocas++;
            }
        }
    }
    printf("\n\nPIOR CASO (VETOR EM ORDEM DECRESCENTE COLOCADO EM ORDEM CRESCENTE) usando Bubble Sort:\n\n");

    for(i = 0; i < 500; i++)
        printf("%4d", numeros[i]);

    printf("\n\n");

    printf("\n\nComparacoes: %d             Trocas: %d\n\n", comparacoes, trocas);

}
