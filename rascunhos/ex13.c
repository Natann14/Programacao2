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
#include <string.h>
#include <errno.h>
#include <error.h>

extern int errno;

int in();

int main(void)
{
    FILE *file;
    for(int i = 0; i<=134;i++)
        printf("Strerror(%d): %s\n",i, strerror(i));
    printf("ENOSYS: %s\n", strerror(in()));

    file = fopen("file.txt","r");
    if(!file)
    {
        printf("Errno: %d\n", errno);
        perror("Perror");
        error(0, errno,"Error");
    }
    return EXIT_SUCCESS;
}


int in()
{
    return ENOSYS;
}

