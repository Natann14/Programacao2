/*****************************************************************************
 *   exN.c                                    Version 20180714.101818        *
 *                                                                           *
 *   Calculadora Polonesa usando Pilhas                                      *
 *   Copyright (C) 2016-2018    by Ruben Carlo Benante                       *
 *****************************************************************************
 *   This program is free software; you can redistribute it and/or modify    *
 *   it under the terms of the GNU General Public License as published by    *
 *   the Free Software Foundation; either version 2 of the License.          *
 *                                                                           *
 *   This program is distributed in the hope that it will be useful,         *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *   GNU General Public License for more details.                            *
 *                                                                           *
 *   You should have received a copy of the GNU General Public License       *
 *   along with this program; if not, write to the                           *
 *   Free Software Foundation, Inc.,                                         *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.               *
 *****************************************************************************
 *   To contact the author, please write to:                                 *
 *   Ruben Carlo Benante                                                     *
 *   Email: rcb@beco.cc                                                      *
 *   Webpage: www.beco.cc                                                    *
 *   Phone: +55 (81) 3184-7555                                               *
 *****************************************************************************/

/* ------------------------------------------------------------------------- */
/**
 * @file exN.c
 * @ingroup GroupUnique
 * @brief Brief description
 * @details This program really do a nice job as a template, and template only!
 * @version 20160908.182830
 * @date 2016-09-08
 * @author Ruben Carlo Benante <<rcb@beco.cc>>
 * @par Webpage
 * <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @copyright (c) 2016 GNU GPL v2
 * @note This program is free software: you can redistribute it
 * and/or modify it under the terms of the
 * GNU General Public License as published by
 * the Free Software Foundation version 2 of the License.
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program.
 * If not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place - Suite 330, Boston, MA. 02111-1307, USA.
 * Or read it online at <<http://www.gnu.org/licenses/>>.
 *
 *
 * @todo Now that you have the template, hands on! Programme!
 * @warning Be carefull not to lose your mind in small things.
 * @bug This file right now does nothing usefull
 *
 */

/*
 * Instrucoes para compilar:
 *   $gcc exN.c -o exN.x -Wall
 *        -Wextra -ansi -pedantic-errors -g -O0 -DDEBUG=1 -DVERSION="0.1.160612.142044"
 *   ou preferencialmente inclua um makefile e use:
 *   $make
 *
 * Modelo de indentacao:
 * Estilo: --style=allman ou -A1
 *
 * Opcoes: -A1 -s4 -k3 -xj -SCNeUpv
 *
 *  * No vi use:
 *      :% !astyle -A1 -s4 -k3 -xj -SCNeUpv
 *  * No linux:
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv exN.c
 */

/* ------------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include "ex7.h" /* To be created for this template if needed */

/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
#include <string.h>  /* Strings functions definitions */
/* #include <dlfcn.h> */ /* Dynamic library */
/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <unistd.h> */ /* UNIX standard function */
/* #include <limits.h> */ /* Various C limits */
/* #include <ctype.h> */ /* Character functions */
/* #include <errno.h> */ /* Error number codes errno */
/* #include <signal.h> */ /* Signal processing */
/* #include <stdarg.h> */ /* Functions with variable arguments */
/* #include <pthread.h> */ /* Parallel programming with threads */
/* #include <fcntl.h> */ /* File control definitions */
/* #include <termios.h> */ /* Terminal I/O definitions POSIX */
/* #include <sys/stat.h> */ /* File status and information */
/* #include <float.h> */ /* Float constants to help portability */
/* #include <setjmp.h> */ /* Bypass standard function calls and return */
/* #include <stddef.h> */ /* Various types and MACROS */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

/* ------------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This is the main event of the evening
 * @details Ladies and Gentleman... It's tiiiime!
 * Fightiiiiing at the blue corner,
 * he, who has compiled more C code than any other adversary in the history,
 * he, who has developed UNIX and Linux, and is an inspiration to maaany languages
 * and compilers, the GNU C Compiler, GCC!
 * Fightiiiiing at the red corner, the challenger, in his first fight, lacking of any
 * valid experience but angrily, blindly, and no doubtfully, will try to
 * compile this program without errors. He, the student, the apprentice,
 * the developer, beco!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./exN -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
/*typedef struct no
{
    float valor;
    struct no *proximo;
}No;*/


/* ------------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "exN", "Brief description");
    printf("\nUsage: %s [-h|-v]\n", "exN");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-V,  --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ------------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "exN", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ------------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written in
 * multiple lines
 *
 * @pre You need to call foo() before calling this function
 *
 * @param[in] i Input parameter that does bla
 * @param[out] o Parameter that outputs ble
 * @param[in,out] z The @a z variable is used as input and output
 *
 * @retval 0 Returned when bli
 * @retval 1 Error code: function returned blo
 *
 * @par Example
 * @code
 *    if(x == funcexample(i, o, z))
 *       printf("And that is it\n");
 * @endcode
 *
 * @return Void
 *
 * @warning Be carefull with blu
 * @todo Need to implement it. Its empty now. This doxygen tags are overwhelming.
 * Mandatory tags are: ingroup, brief, details, param, return, author and date.
 * The others are optional.
 *
 * @deprecated This function will be deactivated in version +11
 * @see help()
 * @see copyr()
 * @bug There is a bug with x greater than y
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 *
 * @author Ruben Carlo Benante
 * @version 20160908.182830
 * @date 2016-09-08
 * @copyright Use this tag only if not the same as the whole file
 *
 */



/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief valida a equacao
 * @details valida a string da equacao aceitando apenas numeros, 4 operacoes e espaco
 * @return int : verdadeiro ou falso. Retorna verdadeiro se ok, falso e errno=EINVAL se argumento invalido
 * @author Nome do autor da funcao
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
void valida(char vetor[])
{
	int i=0;

    while(vetor[i] != '\0')
    {
        if((vetor[i] >= 'a' && vetor[i] <= 'z') || (vetor[i] >= 'A' && vetor[i] <= 'Z'))
        {
            printf("\n\nErro, existem letras no meio da espressao\n\n");
            exit(0);
        }
        i++;
    }
    
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief remove elemento
 * @details remove elemento do topo da pilha e retorna um struct com a informacao
 * @return int : o elemento removido
 * @author Nome do autor da funcao
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
/*info_t *pop(pilha_t **p)
{
    ;
}*/
/*------------------------------------------------------------------------*/

//funcao empilhar

No* empilhar(No *pilha, float num)
{
    No *novo = malloc(sizeof(No));

    if(novo)
    {
        novo->valor = num;
        novo->proximo = pilha;
        return novo;
    }
    else
    {
        printf("\nErro ao alocar memoria\n");
    }
    return NULL;
}
/*------------------------------------------------------------------------*/

//funcao desempilhar
 
No* desempilhar(No **pilha)
{
    No *remover = NULL;

    if(*pilha)
    {
        remover = *pilha;
        *pilha = remover->proximo;
    }
    else
    {
        printf("\npilha vazia\n");
    }
    return remover;
}

/* ---------------------------------------------------------------------- */
float operacao(float a, float b, char x)
{
    switch(x)
    {
        case '+':
            return a + b;
            break;

        case '/':
            return a / b;
            break;

        case '*':
            return a * b;
            break;

        case '-':
            return a - b;
            break;

        default:
            return 0.0;
    }
}

/* ---------------------------------------------------------------------- */

float resolver(char x[])
{
    char *pt;
    float num;
    No *n1, *n2, *pilha = NULL;

    pt = strtok(x, " ");
    while(pt)
    {
        if(pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*')
        {
            n1 = desempilhar(&pilha);
            n2 = desempilhar(&pilha);
            num = operacao(n2->valor, n1->valor, pt[0]);
            pilha = empilhar(pilha, num);
            free(n1);
            free(n2);
        }
        else
        {
            num = strtol(pt, NULL, 10);
            pilha = empilhar(pilha,num);
        }

        pt = strtok(NULL, " ");
    }
        n1 = desempilhar(&pilha);
        num = n1->valor;
        free(n1);
        return num;
}        

/**
 * @ingroup GroupUnique
 * @brief insere elemento no topo 
 * @details insere elemento info_t no topo da pilha pilha_t
 * @return void 
 * @author Nome do autor da funcao
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
/*void push(pilha_t **p, info_t i)
{
    ;
}*/

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief testa se pilha vazia
 * @details retorna verdadeiro se a pilha estiver vazia
 * @return int : verdadeiro ou falso
 * @author Nome do autor da funcao
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
/*int empty(pilha_t *p)
{
    ;
}*/

/* ---------------------------------------------------------------------- */

/**
 * @ingroup GroupUnique
 * @brief limpa a memoria utilizada
 * @details limpa a memoria utilizada para terminar o programa com pilha vazia, apagando todos nodos alocados
 * @return void
 * @author Nome do autor da funcao
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
/*void clean(pilha_t **p)
{
    ;
}*/

/* ---------------------------------------------------------------------- */

/**
 * @ingroup GroupUnique
 * @brief Total de elementos
 * @details Retorna o total de elementos na pilha 
 * @return int : total  
 * @author Nome do autor da funcao
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
/*int size(pilha_t *p)
{
    ;
}*/

/* ---------------------------------------------------------------------- */

/**
 * @ingroup GroupUnique
 * @brief Olha o primeiro elemento 
 * @details Consulta elemento no topo, sem remove-lo. Se pilha vazia, retorna 0 e errno=EFAULT, endereço ruim. Se houver elemento, retorna os dados em info_t
 * @return int : o elemento consultado, ou 0 e errno=EFAULT para erro
 * @author Nome do autor da funcao
 * @version 20160908.182830
 * @date 2016-09-08
 *
 */
/*info_t *top(pilha_t *p)
{
    ;
}

*/


int main(void)
{
        char vetor[50]; //{"5 3 2 + * 4 / 6 -"};

    printf("\n\nInsira os dados que serao calculados: ");
    scanf("%[^\n]", vetor);

    /*while(vetor[i] != '\0')
    {
        if((vetor[i] >= 'a' && vetor[i] <= 'z') || (vetor[i] >= 'A' && vetor[i] <= 'Z'))
        {
            printf("\n\nErro, existem letras no meio da espressao\n\n");
            exit(0);
        }
        i++;
    }*/

    void valida(char vetor[]);
    valida(vetor);

    printf("\n\nResultado da expressao: %f\n\n", resolver(vetor));

        return EXIT_SUCCESS;
}


/* ------------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline    */
/* Template by Dr. Beco <rcb at beco dot cc>       Version 20180716.101436   */

