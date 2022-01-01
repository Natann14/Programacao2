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
    void numeros_aleatorios(void);
    numeros_aleatorios();


    return 0;
}
/*void numeros_aleatorios(void)
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
*/




