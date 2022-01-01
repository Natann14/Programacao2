/***************************************************************************
 *   exN.h                                 Version 20210512.104607         *
 *   AFND, AFD and ER                                                      *
 *                                                                         *
 *   Converte de tudo: AFD, AFND e ER                                      *
 *   Copyright (C) 2016-2021         by Ruben Carlo Benante                *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License.        *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************
 *   To contact the author, please write to:                               *
 *   Ruben Carlo Benante                                                   *
 *   Email: rcb@beco.cc                                                    *
 *   Webpage: www.beco.cc                                                  *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * \file automax.h
 * \ingroup GroupUnique
 * \brief Converte AFD, AFND e ER
 * \details This program really do a nice job as a template, and template only!
 * \version 20160618.013412
 * \date 2016-06-18
 * \author Ruben Carlo Benante <<rcb@beco.cc>>
 * \par Webpage
 * <<a href="www.beco.cc">www.beco.cc</a>>
 * \copyright (c) 2016 GNU GPL v2
 * \note This program is free software: you can redistribute it
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
 * \todo Now that you have the template, hands on! Programme!
 * \warning Be carefull not to lose your mind in small things.
 * \bug This file right now does nothing usefull
 *
 */

#ifndef _EXALL_H
#define _EXALL_H

/* ---------------------------------------------------------------------- */
/* includes */

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */

/* #include <malloc.h> */ /* Dynamic memory allocation */
/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
#include <string.h>  /* Strings functions definitions */
/* #include <dlfcn.h> */ /* Dynamic library */
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

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20210512.104607" /**< Version Number */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
#include <assert.h> /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 512 /**< String buffer */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /**< verbose level, global within the file */
int counter = 0;
int qlabel = 0;
int qmax = 0;
int simpos = 0;
int state = 0;

/* estrutura padrao para autômatos */
struct automato
{
    unsigned short int K; /* conjunto de estados */
    char A; /* conjunto alfabeto */
    unsigned short int S; /* estado inicial */
    struct final *F; /* conjunto de estados finais */
    struct delta *D; /*conjunto de funções */
};

/* estrutura para armazenar valores de equivalencia para o novo estado */
struct estados
{
    unsigned short int label;
    unsigned short int size;
    struct final *L; /* nos aproveitamos da estutura 'final' mas isto nao é uma lista de estados finais. */
    struct estados *prox;
};

/* estrutura para o conjunto 'estados finais' dos autômatos */
struct final
{
    unsigned short int value; /* inteiro representando o número do(s) estado(s) final(is) */
    struct final *prox; /* ponteiro para guiar a lista */
};

/* estrutura para o conjunto 'delta' dos autômatos */
struct delta
{
    unsigned short int Ei; /* inteiro representando o estado inicial desta funçao */
    char Le[SBUFF]; /* char representando uma letra do alfabeto, argumento da funçao */
    unsigned short int Ef; /* inteiro representando o estado final desta funçao */
    struct delta *prox; /* ponteiro para guiar a lista */
};

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /**< Prints help information and exit */
void copyr(void); /**< Prints copyright information and exit */
void automax_init(void);  /**< Initializes some operations before start */
void automax_update(void); /**< Updates values during program cycle */
int funcexample(int i, int *o, int *z); /* just an example with complete doxygen fields */


void afdtoer(void);
void afndtoafd(void);
void checkstring(char entrada[SBUFF]);
void ertoafnd(void);
void conversaoafder(struct automato *afd); 
void defineState(struct delta *afndD);
void fileer(char sfile[SBUFF]);
void printAuto(struct automato *autom);
int fileafnd(char sfile[SBUFF]);
int fileafd(char sfile[SBUFF]);
void simplificarvazios(char expressao[SBUFF]);
struct automato *checksizeE(struct automato *afd);
struct automato *conversao(struct automato *afnd);
struct automato *criarQuintupla(char entrada[SBUFF]);
struct automato *criarUnidade(char letra[SBUFF]); /* Funçao para criar uma transiçao entre dois estados ao ler uma letra. */
struct automato *freeAuto(struct automato *quintupla);
struct automato *novosestadosauxiliares(struct automato *afd); /* Cria dois novos estados, um de partida e um de chegada, para auxliar na esclusao dos demais */
struct automato *novosFinais(struct automato *afnd);
struct automato *processoDeEquivalencia(struct automato *afnd);
struct automato *readsuser(void);
struct automato *removerImpossiveis(struct automato *afnd);
struct automato *removerVazios(struct automato *afnd);
struct delta *addStringToD(unsigned short int val1, char le[SBUFF], unsigned short int val2, struct delta *afndD);
struct delta *addToD(unsigned short int val1, char le, unsigned short int val2, struct delta *afndD);
struct delta *copiarDelta(struct delta *destino, struct delta *origem);
struct delta *freeD(struct delta *vec);
struct delta *kleene(char er[SBUFF], unsigned short int target, struct delta *afdD);
struct delta *redirecionarDelta(unsigned short int oldEi, unsigned short int oldEf, struct delta *afndD);
struct delta *removeDelta(int pos, struct delta *afndD);
struct delta *removeRepeticoes(struct delta *afndD);
struct delta *substituirDelta(unsigned short int oldEi, char oldLe, unsigned short int novoestado, struct delta *afndD);
struct delta *substituirEf(unsigned short intx, char y[SBUFF], unsigned short int z, struct delta *afdD);
struct delta *organizar(struct delta *afndD);
struct estados *freeEstados(struct estados *lista);
struct estados *findlabel(struct estados *lista, unsigned short int x);
struct final *addToF(unsigned short int val1, struct final *afndF);
struct final *freeF(struct final *vec);
struct final *readsF(char string[SBUFF], struct final *lista);
struct final *removeFinal(unsigned short int oldE, struct final *afndF);
void conversaoerafnd(char entrada[SBUFF]);
void simplificarvazios(char expressao[SBUFF]); 
void simplificar(char expressao[SBUFF]);
const char *simplificarparenteses(char expressao[SBUFF]);


char alfabeto(struct delta *aux);

unsigned short int checksize(struct final *lista);

#endif /* NOT def _EXALL_H */

/* ---------------------------------------------------------------------- */
/* vi: set ai et ts=4 sw=4 tw=0 wm=0 fo=croql : C config for Vim modeline */
/* Template by Dr. Beco <rcb at beco dot cc> Version 20160615.020326      */

