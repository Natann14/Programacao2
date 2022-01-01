/*
 * Instrucoes para compilar:
 *   $gcc ex17.c -o ex17.x -Wall
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
 *      $astlye -A1 -s4 -k3 -xj -SCNeUpv ex17.c
 */

/* ---------------------------------------------------------------------- */
/* includes */

//ESSE Ã‰ O .C

#include <stdio.h> /* Standard I/O functions */
#include <stdlib.h> /* Miscellaneous functions (rand, malloc, srand)*/
#include <getopt.h> /* get options from system argc/argv */
#include <string.h> /* Strings functions definitions */
#include "ex17.h" /* To be created for this template if needed */

/* To include assert.h for diagnostics, do it after #define DEBUG bellow */
/* #include <time.h> */ /* Time and date functions */
/* #include <math.h> */ /* Mathematics functions */
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
/* #include <stdint.h> */ /* Integer types and sizes */
/* #include <inttypes.h> */ /* Macros for integer types */
/* #include <ncurses.h> */ /* Screen handling and optimisation functions */
/* #include <libintl.h> */ /* Internationalization / translation */
/* #include <locale.h> */ /* MACROS LC_ for location specific settings */
/* #include <allegro.h> */ /* A game library for graphics, sounds, etc. */
/* #include <SWI-Prolog.h> */ /* Prolog integration with C */
/* #include "libeco.h" */ /* I/O, Math, Sound, Color, Portable Linux/Windows */

/* ---------------------------------------------------------------------- */
/* definitions */

#ifndef VERSION /* gcc -DVERSION="0.1.160612.142628" */
#define VERSION "20181202.204804" /**< Version Number (string) */
#endif

/* Debug */
#ifndef DEBUG /* gcc -DDEBUG=1 */
#define DEBUG 0 /**< Activate/deactivate debug mode */
#endif

#if DEBUG==0
#define NDEBUG
#endif
/* #include <assert.h> */ /* Verify assumptions with assert. Turn off with #define NDEBUG */ 

/** @brief Debug message if DEBUG on */
#define IFDEBUG(M) if(DEBUG) fprintf(stderr, "[DEBUG file:%s line:%d]: " M "\n", __FILE__, __LINE__); else {;}

/* limits */
#define SBUFF 256 /**< String buffer */

/* ---------------------------------------------------------------------- */
/* globals */

static int verb = 0; /*< verbose level, global within the file */

/* ---------------------------------------------------------------------- */
/* prototypes */

void help(void); /* print some help */
void copyr(void); /* print version and copyright information */
void ex17_init(void); /* global initialization function */

/* ---------------------------------------------------------------------- */
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
 * the developer, iggc!!
 *
 * @param[in] argc Argument counter
 * @param[in] argv Argument strings (argument values)
 *
 * @retval 0 If succeed (EXIT_SUCCESS).
 * @retval 1 Or another error code if failed.
 *
 * @par Example
 * @code
 *    $./ex17 -h
 * @endcode
 *
 * @warning   Be carefull with...
 * @bug There is a bug with...
 * @todo Need to do...
 * @note You can read more about it at <<a href="http://www.upe.br">www.upe.br</a>>
 * @author 
 * @version 20181202.204804
 * @date 2018-12-02
 *
 */


/* ---------------------------------------------------------------------- */
/* ex11 - AFND to AFD */
int main(int argc, char *argv[])
{
    int opt; /* return from getopt() */
    FILE *arq = NULL;
    char sfile[SBUFF]; 
    char data[SBUFF];
    // quint_t *q = NULL;
    //t_quintupla *q;
    printf("Use uma das flags para realizar uma operacao. A flag -h eh a de ajuda.\n");
    IFDEBUG("Starting optarg loop...");

    /* getopt() configured options:
     *        -h  help
     *        -V  version
     *        -v  verbose
     */
    opterr = 0;
    while((opt = getopt(argc, argv, "vhVf:m:n:")) != EOF)
    {
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'V':
                copyr();
                break;
            case 'v':
                verb++;
                break;
            case 'n':
                //strcpy(sfile, optarg);
                //arq = fopen(sfile, "r");
                // pegaEntrada(q,arq); 
            case 'm':
                arq = fopen(optarg,"r");
                // montar_afnd(arq);
                break;


            case 'f':
                strcpy(sfile, optarg);
                arq = fopen(sfile, "r"); /* Ponteiro leitor do arquivo em txt */
                if(arq == NULL)
                {
                    printf("Erro ao abrir o arquivo\n");
                    exit(1);
                }
                while(!feof(arq)) /* percorre todo o arquivo */
                {
                    fgets(data, SBUFF, arq); /* pegar a linha atual */
                    printf("%s\n", data);
                }
                fclose(arq);
                printf("Arquivo aberto com sucesso\n");
                ex11(optarg);
                break;

            case '?':
            default:
                printf("Type\n\t$man %s\nor\n\t$%s -h\nfor help.\n\n", argv[0], argv[0]);
                return EXIT_FAILURE;
        }
    }
    if(verb)
        printf("Verbose level set at: %d\n", verb);

    /* ex17_init(); */ /* initialization function */

    return EXIT_SUCCESS;
}

void ex11(char *optarg)
{
    unsigned i;
    char alfabeto[27]={"abcdefghijklmnopqrstuvwxyz"},vetor_alf[SBUFF]={0}; /*vetores para receber entradas especificas*/
    FILE *file = fopen(optarg,"r");
    char linha[SBUFF][10]={0}, vetor_estf[SBUFF],auxestf[SBUFF],vetor_con[SBUFF];
    int p , j, a = 0, normal=0;
    t_quintupla q;
    opterr =0;

    q.F=NULL;
    q.D=NULL;

    normal=1;
    if(verb)
        printf("Verbose level set at: %d\n", verb);

    printf("-------------QUINTUPLA-AFND--------------\n\n");

    if(normal == 1)
    {
        if(file == NULL)
        {
            printf("Erro ao abrir o arquivo\n");
            exit(1);
        }

        while(fgets(linha[a], 10, file) != NULL) /* laco que atribui cada linha a um vetor de strings */
            a++;

        /* ------------------------------------ N ESTADOS -------------------------------------- */
        q.K=atoi(linha[1]);
        printf("K = %u \n\n",q.K);

        /* ------------------------------------ ALFABETO -------------------------------------- */
        q.A=linha[3][0];

        for(j=0;j<SBUFF;j++)
        {
            vetor_alf[j]=alfabeto[j];
            if(q.A==alfabeto[j])
                break;
        }
        printf("A = %c \n\n",q.A);
        /* ------------------------------------ ESTADO INICIAL -------------------------------------- */
        q.S=atoi(linha[5]);
        printf("S = %u \n\n",q.S);

        /* ------------------------------------ ESTADOS FINAIS -------------------------------------- */
        memset(vetor_estf, 0, SBUFF);
        quebra_vetores(linha[7],vetor_estf);

        for(i=0;i<strlen(vetor_estf);i++)
        {
            auxestf[0]=vetor_estf[i];
            inserir_estados_finais(&q.F,atoi(auxestf));
        }

        /* imprimir_estados(q.F); */
        printf("\n");

        /* ------------------------------------ CONEXOES -------------------------------------- */
        j=10;
        p=-1;

        do
        {
            quebra_vetores(linha[j],vetor_con);

            inserir_delta(&q.D,vetor_con);

            j++;
            p++;

        }while(strlen(linha[j]) != 0);

        /* imprimir_delta(q.D); */
    }

    gera_nova_quintupla(q,vetor_alf);

    return ;
}

void gera_nova_quintupla(t_quintupla  q , char *vet_alf)
{
    t_lprinc *lista_simultaneos=NULL, *lista_nova=NULL, *aux_nova=NULL;;
    t_ll *p0 = NULL;
    t_lft *novas_transicoes = NULL;
    unsigned short int i=0,j=0,k=0;
    int indice;

    /* os simultaneos do estado inicial sao adicionados a nova lista porque ele sempre sera o P0 da nova quintupla */
    lista_simultaneos=acha_simultaneos(q.D,q.K);
    p0 = buscar_principal(lista_simultaneos,q.S);
    inserir_na_principal(&lista_nova,i,p0);
    inserir_na_principal(&aux_nova,i,p0);
    aux_nova=lista_nova;

    while(lista_nova!=NULL)
    {
        for(k=0;k<strlen(vet_alf);k++)
        {
            /* se a minha gera estado retornar um novo estado igual a qualquer um da na nova lista, ele nao eh inserido, apenas a transicao*/
            if(ja_faz_parte(aux_nova,gera_estado(q.D,lista_nova->simul,vet_alf[k],lista_simultaneos)))
            {
                indice=buscar_indice(aux_nova,gera_estado(q.D,lista_nova->simul,vet_alf[k],lista_simultaneos));
                inserir_outro_delta(&novas_transicoes,i,vet_alf[k],indice);
            }
            else
            {
                j++;

                if(gera_estado(q.D,lista_nova->simul,vet_alf[k],lista_simultaneos)!=NULL)
                {
                    inserir_na_principal(&aux_nova,j,gera_estado(q.D,lista_nova->simul,vet_alf[k],lista_simultaneos));
                    inserir_outro_delta(&novas_transicoes,i,vet_alf[k],j);
                }
                else
                    j--;
            }
        }
        i++;
        lista_nova=lista_nova->prox;
    }

    printf("-------------QUINTUPLA-AFD--------------\n\n");

    printf("ALFABETO:\n");
    for(k=0;k<strlen(vet_alf);k++)
        printf("-%c\n",vet_alf[k]);
    printf("\n");

    printf("ESTADO INICIAL: P0\n\n");

    printf("NOVOS ESTADOS: \n");
    imprimir_principal(aux_nova);
    printf("\n");

    printf("NOVAS TRANSICOES: \n");
    imprimir_delta(novas_transicoes);
    printf("\n");

    printf("ESTADOS FINAIS: \n");
    imprimir_novos_finais(aux_nova,q.F);

    printf("---------------------------------------\n\n");

    salva_saida11_no_txt(novas_transicoes, vet_alf, q.F);

    return;
}

/* funcao que identifica qual lista (dentro da principal - t_lprinc  *a) eh igual a uma lista qualquer (t_ll *b)*/
int buscar_indice(t_lprinc  *a, t_ll *b)
{
    while(a!=NULL)
    {
        if(compara_listas(a->simul, b))
            return a->indice;
        a=a->prox;
    }
    return -1;
}

/* funcao que identifica e imprime os novos estados finais (sendo todos os novos estados que tenham como conteudo os antigos estados finais)*/
void imprimir_novos_finais(t_lprinc  *cabeca, t_lef *x)
{
    t_lprinc  *pl=cabeca;
    t_lprinc  *plant=pl;
    t_ll *sim=pl->simul;

    while(x!=NULL)
    {
        pl=plant;
        pl->simul=sim;

        while(pl!=NULL)
        {

            while(pl->simul!=NULL)
            {
                if(pl->simul->fi==x->f)
                    printf("-P%u\n",pl->indice);

                pl->simul=pl->simul->prox;
            }
            pl=pl->prox;
        }
        x=x->prox;
    }

    return;
}

t_ll *gera_estado(t_lft *deltas,t_ll *estado ,char letra,t_lprinc *simultaneos)
{
    t_ll *est_novo=NULL,*aux=NULL;
    unsigned short int k=0;

    while(estado!=NULL)
    {
        if(busca_trans(deltas,estado->fi,letra)!=(unsigned short int)-1)
            inserir_na_listinha(&aux,busca_trans(deltas,estado->fi,letra));
        k++;
        estado=estado->prox;
    }
    while(aux!=NULL)
    {
        uniao_simultaneos(&est_novo,buscar_principal(simultaneos,aux->fi));
        aux=aux->prox;
    }

    return est_novo;
}

/* ve se uma listinha eh identica a alguma lista da principal */
bool ja_faz_parte(t_lprinc *a,t_ll *b)
{
    while(a!=NULL)
    {
        if(compara_listas(a->simul, b))
            return true;
        a=a->prox;
    }
    return false;
}

/* retorna o tamanho de uma lista */
int tamanho(t_ll *x)
{
    int cont=0;

    while(x!=NULL)
    {
        cont++;
        x=x->prox;
    }

    return cont;
}

bool compara_listas(t_ll *a,t_ll *b)
{
    int c;
    t_ll *auxb=b;

    if(tamanho(a)!=tamanho(b))
        return false;

    while (a != NULL)
    {
        b=auxb;
        c=0;
        while (b != NULL)
        {
            if (a->fi == b->fi)
                c++;

            b = b->prox;
        }
        a = a->prox;
        if(c!=1)
            return false;
    }

    return (a == NULL && b == NULL && c==1);
}

t_ll *buscar_principal(t_lprinc  *cabeca, unsigned short int x)
{
    t_lprinc  *pl=cabeca;

    while(pl!=NULL)
    {
        if(pl->indice==x)
            return  pl->simul;
        pl=pl->prox;
    }
    return  NULL;
}

void limpar(t_lft **lista)//Remove todos os nM-CM-3s da Lista
{
    t_lft *p;

    if(*lista == NULL)
    {
        printf("\nLista Vazia\n");
    }
    else
    {
        while(*lista!=NULL)
        {
            p = *lista;
            *lista = (*lista)->prox;
            free(p);
        }
    }

    return;
}

void  imprimir_estados(t_lef *cabeca)
{
    t_lef *pl=cabeca;

    while(pl!=NULL)
    {
        printf("%u->",pl->f);
        pl=pl->prox;
    }
    printf("NULL\n");
}

t_ll *buscar(t_ll  *cabeca, unsigned short int x)
{
    t_ll  *pl=cabeca;

    while(pl!=NULL)
    {
        if(pl->fi==x)
            return  pl;
        pl=pl->prox;
    }
    return  NULL;
}

/* Descricao: A funcao insere os estados simultaneos em sua repectiva lista
 *  *  * Entrada: Quintupla do Automato
 *   *   * Saida: Lista de estados simultaneos */

t_lprinc *acha_simultaneos(t_lft *cabeca,unsigned short int nes)
{
    unsigned short int aux=0;
    t_lprinc *sm=NULL;
    t_ll  *ls,*lista=NULL,*ax=NULL;
    t_lft *pl=cabeca;

    while(aux<nes)
    {
        inserir_na_listinha(&lista,aux);
        ls = lista;
        while(ls!= NULL)
        {
            while(pl!=NULL)
            {
                if(pl->ei==ls->fi && pl->le== 'E')
                {
                    ax=buscar(lista, pl->ef);
                    if(ax==NULL)
                        inserir_na_listinha(&lista,pl->ef);
                }

                pl=pl->prox;
            }
            ls = ls->prox;
            pl=cabeca;
        }
        inserir_na_principal(&sm,aux,lista);
        lista=NULL;
        aux++;
    }
    printf("\nEstados / Simultaneos\n");
    imprimir_principal(sm);
    printf("Retornou\n");

    return sm;
}

void  imprimir_delta(t_lft  *cabeca)
{
    t_lft *pl=cabeca;

    while(pl!=NULL)
    {
        printf("%u->%c->%u\n",pl->ei,pl->le,pl->ef);
        pl=pl->prox;
    }

    printf("NULL\n");
}

/* ---------------------------------------------------------------------- */
void inserir_delta(t_lft **cabeca, char *x)
{
    t_lft  *pl=*cabeca;
    t_lft  *plant=NULL;
    char aux[2];

    while(pl!=NULL)
    {
        plant=pl;
        pl=pl->prox;
    }

    pl=malloc(sizeof(t_lft));

    aux[0]=x[0];
    pl->ei=atoi(aux);
    pl->le=x[1];
    aux[0]=x[2];
    pl->ef=atoi(aux);

    pl->prox=NULL;

    if(plant!=NULL)
        plant->prox=pl;
    else
        *cabeca=pl;
}

/* ---------------------------------------------------------------------- */
void inserir_estados_finais(t_lef **cabeca,unsigned short int ini)
{
    t_lef  *pl=*cabeca;
    t_lef  *plant=NULL;

    while(pl!=NULL)
    {
        plant=pl;
        pl=pl->prox;
    }

    pl=malloc(sizeof(t_lef));

    pl->f=ini;
    pl->prox=NULL;

    if(plant!=NULL)
        plant->prox=pl;
    else
        *cabeca=pl;
}

/* ---------------------------------------------------------------------- */
void quebra_vetores(char *a, char *vetor)
{
    unsigned i=0;
    char *aux_geral;
    char aux_a[SBUFF];

    aux_geral = strtok(a," ");
    strcpy(aux_a,aux_geral);

    while(aux_geral!= NULL)
    {
        if(aux_geral != NULL)
            strcpy(aux_a,aux_geral);
        vetor[i]=aux_a[0];
        aux_geral = strtok(NULL," ");
        i++;
    }
}

/* ---------------------------------------------------------------------- */
unsigned short int busca_trans(t_lft *cabeca,unsigned short int qinic,char alfb)
{
    t_lft *pl=cabeca;

    while(pl!=NULL)
    {
        if(pl->ei==qinic && pl->le==alfb)
            return pl->ef;
        pl=pl->prox;
    }

    return -1;
}

/* ---------------------------------------------------------------------- */
void inserir_na_listinha(t_ll **cabeca, unsigned short int fin)
{
    t_ll  *pl=*cabeca;
    t_ll  *plant=NULL;

    while(pl!=NULL)
    {
        plant=pl;
        pl=pl->prox;
    }

    pl=malloc(sizeof(t_ll));

    pl->fi=fin;
    pl->prox=NULL;

    if(plant!=NULL)
        plant->prox=pl;
    else
        *cabeca=pl;
}

/* ---------------------------------------------------------------------- */
void inserir_na_principal(t_lprinc **cabeca, unsigned short int fin, t_ll *lista)
{
    t_lprinc  *pl=*cabeca;
    t_lprinc  *plant=NULL;
    t_ll *listinha=lista;

    while(pl!=NULL)
    {
        plant=pl;
        pl=pl->prox;
    }

    pl=malloc(sizeof(t_lprinc));

    pl->indice=fin;
    pl->simul=NULL;
    while(listinha!=NULL)
    {
        /* printf("(%u)",listinha->fi); */
        inserir_na_listinha(&pl->simul,listinha->fi);
        listinha=listinha->prox;
    }

    pl->prox=NULL;

    if(plant!=NULL)
        plant->prox=pl;
    else
        *cabeca=pl;
}

void uniao_simultaneos(t_ll **cabeca, t_ll *lista)
{
    t_ll *ax=NULL;
    t_ll *listinha=lista;

    while(listinha!=NULL)
    {
        ax=buscar(*cabeca, listinha->fi);
        if(ax==NULL)
            inserir_na_listinha(cabeca,listinha->fi);
        listinha=listinha->prox;
    }
}

void inserir_outro_delta(t_lft **cabeca, unsigned short int i, char a, unsigned short int f)
{
    t_lft  *pl=*cabeca;
    t_lft  *plant=NULL;

    while(pl!=NULL)
    {
        plant=pl;
        pl=pl->prox;
    }

    pl=malloc(sizeof(t_lft));

    pl->ei=i;
    pl->le=a;
    pl->ef=f;

    pl->prox=NULL;

    if(plant!=NULL)
        plant->prox=pl;
    else
        *cabeca=pl;
}

void  imprimir_principal(t_lprinc *cabeca)
{
    t_lprinc *pl=cabeca;

    while(pl!=NULL)
    {
        printf("P%u: ",pl->indice);
        imprimir_listinha(pl->simul);
        pl=pl->prox;
    }
    printf("NULL\n");
}

void  imprimir_listinha(t_ll  *cabeca)
{
    t_ll *pl=cabeca;

    while(pl!=NULL)
    {
        printf("%u->",pl->fi);
        pl=pl->prox;
    }
    printf("NULL\n");
}

void salva_saida11_no_txt(t_lft *cabeca, char *vet_alf, t_lef *x)
{
    FILE *file;
    file = fopen("saida11.txt", "w");
    
    fprintf(file, "#K\n");
    t_lft *pa = cabeca;
    int maior = 0;
    while(pa != NULL)
    {
        if(pa->ei > maior)
            maior = pa->ei;
        if(pa->ef > maior)
            maior = pa->ef;
        pa=pa->prox;
    }
    fprintf(file, "%i\n", maior);


    fprintf(file, "#A\n");
    int i = strlen(vet_alf);
    char alf = vet_alf[i-1];
    fprintf(file, "%c\n", alf);


    fprintf(file, "#S\n0\n");

    fprintf(file, "#F\n");
    t_lef *fin = x;
    while(fin != NULL)
    {
        fprintf(file, "%u\n", fin->f);
        fin = fin->prox;
    }
    fprintf(file, "2\n");
    fprintf(file, "\n");

    fprintf(file, "#D\n");
    t_lft *pl = cabeca;
    while(pl != NULL)
    {
        fprintf(file, "%u %c %u\n", pl->ei, pl->le, pl->ef);
        pl=pl->prox;
    }

    fclose(file);
}

/* ---------------------------------------------------------------------- */

void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "ex17", "Conversao de AFND para AFD, de AFD para ER, e de ER para AFND.");
    printf("\nUsage: %s [-h|-v]\n", "ex17");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-f,  --include file\n\t\tUse the command './ex17.x -f file' to pass the 'file' arq (with the automatum data) to the program.\n");
    printf("\t-V,  --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    /* add more options here */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthors:\n\tWritten by :\n");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Iago Gade Gusmao Carrazzoni
 * @version 20181202.204804
 * @date 2018-12-02
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "ex17", VERSION);
    printf("\nCopyright (C) %d, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2018);
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    printf("\t\t %s <%s>\n", "", "");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
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
 * @note You can read more about it at <<a href="http://www.upe.br">www.upe.br</a>>
 *
 * @author  * @version 20181202.204804
 * @date 2018-12-02
 * @copyright Use this tag only if not the same as the whole file
 *
 */
void ex17_init(void)
{
    IFDEBUG("ex17_init()");
    /* initialization */
    return;
}

