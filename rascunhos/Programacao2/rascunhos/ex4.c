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
#include<string.h>

int main(void)
{
    char palavra1[50];
    char palavra2[50];
    int valor; //variavel usada para receber valor da funcao strcmp

    printf("\nDigite a primeira palavra: ");
    fgets(palavra1,50,stdin);

    palavra1[strlen(palavra1)-1] = '\0';

    printf("\nDigite a segunda palavra: ");
    fgets(palavra2,50,stdin);

    palavra2[strlen(palavra2)-1] = '\0';

    valor = strcmp(palavra1,palavra2);

    if(valor == 0)
    {
        printf("\nAs palavras sao iguais\n");
        exit(0);
    }

    void prefixo(char palavra1[], char palavra2[]);
    prefixo(palavra1, palavra2);


    return 0;
}
/*void prefixo(char palavra1[], char palavra2[])
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
void sufixo(char palavra1[], char palavra2[])
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
void subpalavra(char palavra1[], char palavra2[])
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
void concatenacao(char palavra1[], char palavra2[])
{
    
    strcat(palavra1,palavra2);
    printf("\nConcatencao das strings: %s\n", palavra1);
    printf("\n\n");

}*/

















