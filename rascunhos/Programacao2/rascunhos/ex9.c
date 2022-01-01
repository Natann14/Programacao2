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
    void inverter(char vetor[], int inicio, int fim);

    char vetor[20];

    printf("\n\nDigite uma palavra ou sequencia de letras e numeros: ");
    scanf("%s", vetor);

    int tamanho=0;

    tamanho = strlen(vetor);

    printf("\n\nO vetor que sera invertido eh: %s", vetor);

    inverter(vetor, 0, tamanho-1);

    printf("\n\nO vetor invertido eh: ");

    for(int i = 0; i<tamanho; i++)
    {
        printf("%c", vetor[i]);
    }

    printf("\n\n");

    return 0;
}
/*void inverter(char vetor[], int inicio, int fim)
{
    int auxiliar;
    if(inicio<fim)
    {
        auxiliar = vetor[inicio];
        vetor[inicio] = vetor[fim];
        vetor[fim] = auxiliar;
        inverter(vetor, inicio + 1, fim - 1);
    }

}*/
