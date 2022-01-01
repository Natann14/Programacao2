/***************************************************************************
 *   automax.c                                 Version 20210512.104607         *
 *                                                                         *
 *   Converte AFD, AFND e ER                                               *
 *   Copyright (C) 2016-2021    by Ruben Carlo Benante                     *
 ***************************************************************************
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation version 2 of the License.               *
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
 *   Webpage: http://www.beco.cc                                           *
 *   Phone: +55 (81) 3184-7555                                             *
 ***************************************************************************/

/* ---------------------------------------------------------------------- */
/**
 * @file automax.c
 * @ingroup GroupUnique
 * @brief Converte AFD, AFND e ER
 * @details This program really do a nice job as a template, and template only!
 * @version 20160618.013215
 * @date 2016-06-18
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

/* ---------------------------------------------------------------------- */
/* includes, definitions, etc., that cannot be in exN.h */

#include "automax.h" /* To be created for this template if needed */

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
 * @version 20210512.104607
 * @date 2016-06-18
 *
 */
int main(int argc, char *argv[])
{
    int opt;

    IFDEBUG("Starting optarg loop...");

    opterr = 0;
    int tipoconv1 = 0;
    //int tipoconv2 = 0;
    //int tipoconv3 = 0;
    int flag_arquivo = 0;
    char arqentra[SBUFF] = "";

    while((opt = getopt(argc, argv, "vhVf:nde")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'v':
                verb++;
                break;
            case 'n':
                tipoconv1 = 1;
                break;
            case 'd':
                tipoconv1 = 1;
                break;
            case 'e':
                tipoconv1 = 1;
                break;
            case 'f':
                strncpy(arqentra, optarg, SBUFF);
                flag_arquivo = 1;
                break;
            case '?':
            default:
                help();
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);
    
    if(!tipoconv1)
    {
        printf("\nDigite obrigatoriamente -n, -d ou -e.\n");
        exit(1);
    }


    if(flag_arquivo)
    {
        fileafnd(arqentra);
        fileafd(arqentra);
        fileer(arqentra);
    }

    afndtoafd();
    afdtoer();
    ertoafnd();

    automax_init(); /* initialization function */


    return EXIT_SUCCESS;
}
/* Write your functions here... */

void afdtoer(void)
{

   // printf("# # # [ AFD -> ER ] # # #\n");
   // printf("# Voce deve digitar os dados de uma AFND conforme requisitado.\n");
   // printf("# Ao finalizar com algum dos campos que oferecem multiplas opcões de entrada,\n# aperte 'enter' com uma linha vazia para prosseguir.\n");


    struct automato *afd = NULL;

    afd = readsuser();

    conversaoafder(afd);

    exit(EXIT_SUCCESS);
}

void afndtoafd(void)
{

    struct automato *afnd = NULL;

    afnd = readsuser();

    afnd = conversao(afnd);
    freeAuto(afnd);

    exit(EXIT_SUCCESS);
}
void checkstring(char entrada[SBUFF])
{
    int i = 0;
    while(entrada[i] > 32)
    {
        if((entrada[i] < 97) || (entrada[i] > 122)) /* ou seja, se nao for uma letra minuscula */
            if((entrada[i] != 124) && (entrada[i] != 40) && (entrada[i] != 41) && (entrada[i] != 42) && (entrada[i] != 46)) /* se nao for operadores | ( ) * . */
                if(entrada[i] != 69) /* se nao for caractere vazio 'E' */
                {
                    printf("\nO caractere \"%c\" (ASCII Dec %d) digitado eh invalido neste programa.\n", entrada[i], entrada[i]);
                    exit(-1);
                }
        i++;
    }
}

void ertoafnd(void)
{
    char entrada[SBUFF]; /* armazena toda string que compõe a expressao regular */

    while(1)
    {
        fgets(entrada, sizeof(entrada), stdin);
        if(entrada[0] != '#')
            break;
    }
    checkstring(entrada);
    printf("\n");
    conversaoerafnd(entrada);

    exit(EXIT_SUCCESS);
}

void conversaoafder(struct automato *afd)
{
    state = -1;
    afd = novosestadosauxiliares(afd);
    afd = checksizeE(afd);
    struct delta *headdelta = afd->D;
    unsigned short int target,
             numeroestados = afd->K;

    while(numeroestados > 2)
    {
        // O primeiro estado a ser excluido eh definido por 'target', mas ele nao pode ser estado de partida ou chegada
        target = afd->D->Ei;
        while(target == afd->S)
        {
            afd->D = afd->D->prox;
            target = afd->D->Ei;
        }
        afd->D = headdelta;

        // Este loop identifica se 'target' possui estrela de kleene e, caso afirmativo, exclui estas transicões enquanto copia a respectiva ER para outros estados
        while(afd->D != NULL)
        {
            if((afd->D->Ei == target) && (afd->D->Ef == target))
            {
                headdelta = kleene(afd->D->Le, afd->D->Ei, headdelta); // Caso: Estrela de Kleene
                break;
            }
            afd->D = afd->D->prox;
        }
        afd->D = headdelta;

        // Substituiremos 'target' por sua(s) ER equivalente(s)
        while(afd->D != NULL)
        {
            if(afd->D->Ei == target)
            {
                headdelta = substituirEf(afd->D->Ei, afd->D->Le, afd->D->Ef, headdelta);
                afd->D = headdelta;
            }
            else
                afd->D = afd->D->prox;
        }
        afd->D = headdelta;

        // Apagaremos transicões cujo ef = 'target'
        struct delta *ant = NULL;
        while(afd->D != NULL)
        {
            if(afd->D->Ef == target)
            {
                if(ant == NULL)
                {
                    struct delta *temp = afd->D;
                    headdelta = afd->D->prox;
                    afd->D = headdelta;
                    free(temp);
                }
                else
                {
                    struct delta *temp = afd->D;
                    ant->prox = afd->D->prox;
                    afd->D = ant;
                    free(temp);
                }
            }

            ant = afd->D;
            afd->D = afd->D->prox;
        }
        afd->D = headdelta;

        numeroestados--;
    }

    // A Conversao foi finalizada mas ha algumas transicões "inicio" E "fim" que precisam convergir
    char expressaoregular[SBUFF] = "\0";
    strcat(expressaoregular, afd->D->Le);
    afd->D = afd->D->prox;
    while(afd->D != NULL)
    {
        strcat(expressaoregular, "|");
        strcat(expressaoregular, afd->D->Le);
        afd->D = afd->D->prox;
    }
    afd->D = headdelta;

    simplificar(expressaoregular);

    freeAuto(afd);
}

void conversaoerafnd(char entrada[SBUFF])
{
    struct automato *afnd = NULL; // Declaramos a nova quintupla.
    afnd = criarQuintupla(entrada);
    afnd -> A = alfabeto(afnd -> D);

    printAuto(afnd);

    freeAuto(afnd);

    exit(EXIT_SUCCESS);
}

void defineState(struct delta *afndD)
{
    struct delta *head = afndD;

    while(afndD != NULL)
    {
        if(afndD -> Ei > state)
            state = (int)afndD -> Ei;
        if(afndD -> Ef > state)
            state = (int)afndD -> Ef;

        afndD = afndD -> prox;
    }

    qmax = state;

    afndD = head;
}

void entradainvalida(void)
{
    printf("Algum caractere digitado nao eh valido para este programa.\n");
    printf("Para obter mais informacões, consulte a ajuda do programa em:\n");
    printf("\t$./automax.x -h\n");

    exit(-1);
}

void fileer(char sfile[SBUFF])
{

    //    Ler arquivo.

    char entrada[SBUFF]; // armazena toda string que compõe a expressao regular

    FILE *dados;
    dados = fopen(sfile, "r");
    if(dados == NULL)
    {
        printf("O arquivo nao foi encontrado.\n");
        exit(-1);
    }

    while(1)
    {
        fgets(entrada, sizeof(entrada), dados);
        if(entrada[0] != '#')
            break;
    }

    conversaoerafnd(entrada);
}

void printAuto(struct automato *autom)
{
    printf("#K\n%hu\n", autom -> K);
    printf("#A\n%c\n", autom -> A);
    printf("#S\n%hu\n", autom -> S);

	struct final *tempF = autom -> F;
    struct delta *tempD = autom -> D;

    printf("#F\n");
    while(1)
	{
		printf("%hu", tempF -> value);
		
		if(tempF -> prox == NULL)
        {
            printf("\n");
            break;
        }
		else
        {
            printf(" ");
            tempF = tempF -> prox;
        }
    }

	printf("#D\n");
    while(1)
    {
        printf("%hu ", tempD -> Ei);
        printf("%c ", tempD -> Le[0]);
        printf("%hu\n", tempD -> Ef);
	
		if(tempD -> prox == NULL)
            break;
        else
            tempD = tempD -> prox;
    }
 
    printf("\n");

    return;
}

char alfabeto(struct delta *aux)
{
    char alfa = 0;

    struct delta *tempD = aux;

    while(1)
    {
        if((tempD -> Le[0]) > alfa)
            alfa = (int)tempD->Le[0];

        if(tempD -> prox != NULL)
            tempD = tempD -> prox;
        else
            break;
    }

    tempD = aux;
    return alfa;
}

unsigned short int checksize(struct final *lista)
{
	
	unsigned short int tamanho = 0;
    struct final *head = lista;

	while(lista != NULL)
    {
        tamanho = tamanho + 1;
        lista = lista -> prox;
    }
	
	lista = head;
    return tamanho;
}

int fileafd(char sfile[SBUFF])
{
	struct automato *afd = (struct automato *)malloc(sizeof(struct automato));
    afd->F = NULL;
    afd->D = NULL;

	FILE *dados;
    dados = fopen(sfile, "r");
    if(dados == NULL)
    {
        printf("O arquivo nao foi encontrado.\n");
        exit(-1);
    } 
    
    int entrada = 0;
    unsigned short int val1, val2;
    char str[SBUFF], le;

    
        while(fgets(str, sizeof(str), dados))
        {
            if(str[0] == 35)
            {
                entrada++;
                continue;
            }
            
            switch(entrada)
            {
                case 1:
                    sscanf(str, "%hu", &afd -> K);
                    break;

                case 2:
                    sscanf(str, "%c", &afd->A);
					break;

                case 3:
					sscanf(str, "%hu", &afd->S);
                    break;

                case 4:
                    afd->F = readsF(str, afd->F);
					break;
        
                case 5:
                    sscanf(str, "%hu %c %hu", &val1, &le, &val2);
                afd -> D = addToD(val1, le, val2, afd -> D);
                    break;
            }
        }
        
	if(dados)
        fclose(dados);

    conversaoafder(afd);

    exit(EXIT_SUCCESS);
}

int fileafnd(char sfile[SBUFF])
{
    struct automato *afnd = (struct automato *)malloc(sizeof(struct automato));
    afnd -> F = NULL;
    afnd -> D = NULL;

    FILE *dados;
    dados = fopen(sfile, "r");
    if(dados == NULL)
    {
        printf("O arquivo nao foi encontrado.\n");
        exit(-1);
    }

    int entrada = 0;
    unsigned short int val1, val2;
    char str[SBUFF],
    le;

    while(fgets(str, sizeof(str), dados))
    {
        if(str[0] == 35)
        {
            entrada++;
            continue;
        }

        switch(entrada)
        {
            case 1:
                sscanf(str, "%hu", &afnd -> K);
                break;

            case 2:
                sscanf(str, "%c", &afnd -> A);
                break;

            case 3:
                sscanf(str, "%hu", &afnd -> S);
                break;

            case 4:
                afnd -> F = readsF(str, afnd -> F);
                break;

            case 5:
                sscanf(str, "%hu %c %hu", &val1, &le, &val2);
                afnd -> D = addToD(val1, le, val2, afnd -> D);
                break;
        }
    }

    if(dados)
        fclose(dados);

    afnd = conversao(afnd);

    freeAuto(afnd);
    exit(EXIT_SUCCESS);
}

int checknovoestado(struct estados *temp, struct estados *novosestados)
{
    struct final *pontheadtemp = temp -> L;

    struct estados *headnovosestados = novosestados;
    int tamanho = temp -> size;
    int flagsize = 0;

    if(novosestados == NULL)
        return 1;

    while(novosestados != NULL)
    {
        if(temp -> size == novosestados -> size)
            flagsize = 1;

        novosestados = novosestados -> prox;
    }

    novosestados = headnovosestados;

    if(flagsize == 0)
    {
        return 1;
    }

    while(novosestados != NULL)
    {
        while(temp -> L != NULL)
        {
            struct final *pontnovos = novosestados -> L;

            while(novosestados -> L != NULL)
            {
                if(temp -> L -> value == novosestados -> L -> value)
                    tamanho--;

                novosestados -> L = novosestados -> L -> prox;
            }

            novosestados -> L = pontnovos;
            temp -> L = temp -> L -> prox;
        }

        temp -> L = pontheadtemp;
        if(tamanho == 0)
        {
            qlabel = novosestados -> label;
            break;
        }
        else
        {
            novosestados = novosestados -> prox;
            tamanho = temp -> size;
        }
    }

    novosestados = headnovosestados;

    if(tamanho == 0)
    {
        temp -> L = pontheadtemp;
        return 0;
    }

    temp -> L = pontheadtemp;

    return 1;
}

void simplificar(char expressao[SBUFF])
{
    simpos = 0;
    simplificarparenteses(expressao);
    //simpos = 0;
    simplificarvazios(expressao);
}

const char *simplificarparenteses(char expressao[SBUFF])
{
    int c1, c2, opcao = 0, flag = 1;

    while(expressao[simpos] > 32)
    {
        opcao = 99;

        if(expressao[simpos] == 40)  // (
            opcao = 0;

        if(expressao[simpos] == 41)  // )
            opcao = 1;

        if(expressao[simpos] == 124)  // |
            opcao = 2;

        switch(opcao)
        {
            case 0:
                c1 = simpos; // salva a posicao do parentese abrindo "("
                simpos++;
                simplificarparenteses(expressao);

                if(expressao[simpos] != 41)
                {
                    c2 = c1;
                    while(expressao[c2] > 32)
                    {
                        expressao[c2] = expressao[c2 + 1];
                        c2++;
                    }
                    simpos = simpos - 1;
                }
                else
                {
                    simpos++;
                }
                break;

            case 1:
                if(flag)  
                {
                    if(expressao[simpos + 1] == 42)
                    {
                        if(expressao[simpos - 2] == 40)
                        {
                            c2 = simpos;
                            while(expressao[c2] > 32)
                            {
                                expressao[c2] = expressao[c2 + 1];
                                c2++;
                            }
                            simpos = simpos - 1;
                            return expressao;
                        }
                        else
                            return expressao;
                    }
                    else
                    {
                        c2 = simpos;
                        while(expressao[c2] > 32)
                        {
                            expressao[c2] = expressao[c2 + 1];
                            c2++;
                        }
                        simpos = simpos - 1;
                        return expressao;
                    }
                }
                else
                    return expressao;
                break;

            case 2:
                flag = 0;
                simpos++;
                break;

            default:
                simpos++;
                break;
        }
    }

    return expressao;
}

void simplificarvazios(char expressao[SBUFF])
{
    int c1;
    while(expressao[simpos] > 32)
    {
        if(expressao[simpos] == 69)
        {
            // Encontramos um caractere vazio 'E'. precisamos analisar o que vem antes e depois dele para saber se ele pode ser excluido. Casos onde nao podemos excluir o caractere vazio: quando este nao segue ou eh seguido por um sinal de concatenacao "."
            if((expressao[simpos - 1] > 32) && (expressao[simpos + 1] > 32))
            {
                // Caso onde o caractere vazio nem eh o primeiro caractere da expressao regular nem o último
                if((expressao[simpos - 1] == 46) && (expressao[simpos + 1] == 46))
                {
                    // Caso: (#).E.(#) - apagaremos tres caracteres
                    c1 = simpos - 1;
                    while(expressao[c1] > 32)
                    {
                        expressao[c1] = expressao[c1 + 2];
                        c1++;
                    }
                    expressao[c1 - 1] = 0;
                    expressao[c1 - 2] = 0;
                }
                else
                    if(expressao[simpos + 1] == 46)
                    {
                        // Caso: (E.(#) - apagaremos dois caracteres
                        c1 = simpos;
                        while(expressao[c1] > 32)
                        {
                            expressao[c1] = expressao[c1 + 2];
                            c1++;
                        }
                        expressao[c1 - 1] = 0;
                        expressao[c1 - 2] = 0;
                    }
                    else
                        if(expressao[simpos - 1] == 46)
                        {
                            // Caso: (#).E) - apagaremos dois caracteres
                            c1 = simpos - 1;
                            while(expressao[c1] > 32)
                            {
                                expressao[c1] = expressao[c1 + 2];
                                c1++;
                            }
                            expressao[c1 - 1] = 0;
                            expressao[c1 - 2] = 0;
                        }
            }
            else
            {
                if(expressao[simpos + 1] == 46)
                {
                    // Caso: E.(#) - apagaremos dois caracteres
                    c1 = simpos;
                    while(expressao[c1] > 32)
                    {
                        expressao[c1] = expressao[c1 + 2];
                        c1++;
                    }
                    expressao[c1 - 1] = 0;
                    expressao[c1 - 2] = 0;
                }
                else
                    if(expressao[simpos - 1] == 46)
                    {
                        // Caso: (#).E - apagaremos dois caracteres
                        c1 = simpos - 1;
                        while(expressao[c1] > 32)
                        {
                            expressao[c1] = expressao[c1 + 2];
                            c1++;
                        }
                        expressao[c1 - 1] = 0;
                        expressao[c1 - 2] = 0;
                    }
            }
        }
        else
            simpos++;
    }

    printf("%s\n", expressao);
}

struct automato *checksizeE(struct automato *afd)
{
    unsigned short int count = 0; // contador de estados no autômato
    int i = 0; // indice para legenda de cada estado
    struct delta *headdelta = afd -> D;

    defineState(afd -> D);

    while(i <= qmax)
    {
        while(afd -> D != NULL)
        {
            if((afd -> D -> Ei == i) || (afd -> D -> Ef == i))
            {
                count++;
                break;
            }
            afd -> D = afd -> D -> prox;
        }

        i++;
        afd -> D = headdelta;
    }

    afd -> K = count;

    return afd;
}

struct automato *conversao(struct automato *afnd)
{
    defineState(afnd -> D);
    afnd = removerVazios(afnd);
    afnd = processoDeEquivalencia(afnd);
    afnd = removerImpossiveis(afnd);
    afnd -> D = organizar(afnd -> D);
    afnd = checksizeE(afnd);

    printAuto(afnd);

    return afnd;
}

struct automato *criarQuintupla(char entrada[SBUFF]) // Cabeca para ler a string de entrada.
{
    struct automato *afnd = NULL;
    struct automato *temp_afnd = NULL;

    while((entrada[counter] > 32) && (entrada[counter] != 41))
    {
        int opcao;

        if(((entrada[counter] >= 97) && (entrada[counter] <= 122)) || (entrada[counter] == 69))     // Letra
            opcao = 0;

        if(entrada[counter] == 40) // Parentese abrindo
            opcao = 1;

        if(entrada[counter] == 46) // Concatenacao
            opcao = 2;

        if(entrada[counter] == 124) // Uniao
            opcao = 3;

        if(entrada[counter] == 42) // Estrela de Kleene
            opcao = 4;

        switch(opcao)
        {
            case 0:
                // Letra
                afnd = criarUnidade(entrada);
                break;

            case 1:
                // Parenteses
                counter++;
                if(afnd == NULL)
                    afnd = criarQuintupla(entrada);
                else
                    temp_afnd = criarQuintupla(entrada);
                break;

            case 2:
                // Concatenacao
                counter++;
                temp_afnd = criarUnidade(entrada);

                // Agora a concatenacao propriamente dita.
                // O fim de afnd eh conectado ao inicio de temp_afnd por um caractere vazio 'E'.

                // Caractere vazio concatenando ambos autômatos.
                afnd -> D = addToD(afnd -> F -> value, 'E', temp_afnd -> S, afnd -> D);
                // copiar funcões de temp_afnd:
                copiarDelta(afnd -> D, temp_afnd -> D);
                afnd -> K = afnd -> K + temp_afnd -> K;
                struct final *freeff = afnd->F;
                afnd -> F = temp_afnd -> F;
                free(freeff);
                break;

            case 3:
                // Uniao
                counter++;
                temp_afnd = criarQuintupla(entrada);

                // Agora a uniao propriamente dita.
                // Ambos autômatos possuirao o mesmo inicio e fim.

                // copiar funcões de temp_afnd:
                afnd -> D = copiarDelta(afnd -> D, temp_afnd -> D);

                state++;

                afnd -> D = addToD(state, 'E', afnd -> S, afnd -> D);
                afnd -> D = addToD(state, 'E', temp_afnd -> S, afnd -> D);

                state++;
                afnd -> D = addToD(afnd -> F -> value, 'E', state, afnd -> D);
                afnd -> D = addToD(temp_afnd -> F -> value, 'E', state, afnd -> D);
                afnd -> K = afnd -> K + (temp_afnd -> K) + 2;

                afnd -> S = state - 1;
                afnd -> F -> value = state;
                break;

            case 4:
                // Estrela de Kleene

                state++;
                afnd -> D = addToD(afnd -> F -> value, 'E', afnd -> S, afnd -> D);
                afnd -> D = addToD(state, 'E', afnd -> S, afnd -> D);
                afnd -> D = addToD(state, 'E', state + 1, afnd -> D);
                afnd -> S = state;
                state++;
                afnd -> D = addToD(afnd -> F -> value, 'E', state, afnd -> D);

                afnd -> K += 2;
                afnd -> F -> value = state;

                counter++;
                break;
        }
    }

    if(entrada[counter] == 41)
        counter++;

    return afnd;
}

struct automato *criarUnidade(char letra[SBUFF])
{
    struct automato *aux;

    if(((letra[counter] >= 97) && (letra[counter] <= 122)) || (letra[counter] == 69))
    {
        aux = (struct automato *)malloc(sizeof(struct automato));
        state++;
        aux -> F = NULL;
        aux -> D = NULL;

        aux -> S = state;
        state++;
        aux -> F = addToF(state, aux -> F);

        aux -> D = addToD(aux -> S, letra[counter], aux -> F -> value, aux -> D);
        aux -> K = 2;

        counter++;
    }
	else
    {
        counter++;
        aux = criarQuintupla(letra);
    }

    return aux;
}

struct automato *freeAuto(struct automato *quintupla)
{
    freeF(quintupla -> F);
    freeD(quintupla -> D);

    free(quintupla -> F);
    free(quintupla -> D);

    quintupla->F = NULL;
    quintupla->D = NULL;

    free(quintupla);

    return NULL;
}


// Cria dois novos estados, um de partida e um de chegada, para auxliar na esclusao dos demais
struct automato *novosestadosauxiliares(struct automato *afd)
{
    struct final *headfinal = afd->F;

    defineState(afd->D);
    state++;
    unsigned short int novoinicio = state;
    state++;
    unsigned short int novofim = state;

    while(afd->F != NULL)
    {
        afd->D = addToD(afd->F->value, 'E', novofim, afd->D);
        afd->F = afd->F->prox;
    }

    afd->D = addToD(novoinicio, 'E', afd->S, afd->D);

    afd->K += 2;

    afd->F = headfinal;
    freeF(afd->F);
    free(afd->F);
    afd->F = NULL;
    afd->F = addToF(novofim, afd->F);

    afd->S = novoinicio;

    return afd;
}

struct automato *novosFinais(struct automato *afnd)
{
    struct final *headfinal = afnd -> F;
    struct delta *headdelta = afnd -> D;

    while(afnd -> F != NULL)
    {
        while(afnd -> D != NULL)
        {
            if((afnd -> D -> Le[0] == 'E') && (afnd -> D -> Ef == afnd -> F -> value))
                headfinal = addToF(afnd -> D -> Ei, headfinal);

            afnd -> D = afnd -> D -> prox;
        }

        afnd -> D = headdelta;
        afnd -> F = afnd -> F -> prox;
    }

    afnd -> F = headfinal;
    afnd -> D = headdelta;
    return afnd;
}

struct automato *processoDeEquivalencia(struct automato *afnd)
{
	struct delta *headdelta = afnd -> D;
    struct delta *ant = NULL;
    struct final *headfinal = afnd -> F;
    struct estados *novosestados = NULL;

	unsigned short int ei, ef;
    int opcao, flag;
    char le;

	
	while(afnd -> D -> prox != NULL)
    {
        struct delta *pont = afnd -> D -> prox;
        struct estados *temp = malloc(sizeof(struct estados));
        temp -> L = NULL;
        temp -> prox = NULL;
        temp -> size = 0;
        ei = afnd -> D -> Ei;
        le = afnd -> D -> Le[0];
        ef = afnd -> D -> Ef;
        flag = 0;


        while(pont != NULL)
        {
            if((ei == pont -> Ei) && (le == pont -> Le[0]))
            {
				flag = 1;

                if(ef <= qmax)
                    temp -> L = addToF(ef, temp -> L);
                else
				{
                    struct estados *headnovos = novosestados;
					struct final *headnovosfinal = novosestados -> L;

					novosestados = findlabel(novosestados, ef);
					
                    while(novosestados -> L != NULL)
                    {
                        temp -> L = addToF(novosestados -> L -> value, temp -> L);
                        novosestados -> L = novosestados -> L -> prox;
                    }
					
					novosestados -> L = headnovosfinal;
                    novosestados = headnovos;

                 }
  
                 if(pont -> Ef <= qmax)
                     temp -> L = addToF(pont -> Ef, temp -> L);
                 
                 else
				 {
			     
                     struct estados *headnovos = novosestados;
    				 struct final *headnovosfinal = novosestados -> L;
                    
                     novosestados = findlabel(novosestados, pont -> Ef);
                  
                     while(novosestados -> L != NULL)
                     {
                        temp -> L = addToF(novosestados -> L -> value, temp -> L);
                        novosestados -> L = novosestados -> L -> prox;
                     }

                     novosestados -> L = headnovosfinal;
                     novosestados = headnovos;                      
                 }
            }


            pont = pont -> prox;

        }
    
        if(flag)
        {
            temp -> size = checksize(temp -> L);
            opcao = checknovoestado(temp, novosestados);

            switch(opcao)
            {
                case 0:
                    freeEstados(temp);

                    struct estados *headnovos = novosestados;
                    novosestados = findlabel(novosestados, qlabel);

                    headdelta = substituirDelta(ei, le, qlabel, headdelta);
                    headdelta = removeRepeticoes(headdelta);

                    novosestados = headnovos;
                    break;

                 case 1:
                    if(novosestados != NULL)
                    {
                        struct estados *headnovosestados = novosestados;
                        state++;
                        temp -> label = state;

                        while(novosestados -> prox != NULL)
                            novosestados = novosestados -> prox;

                        novosestados -> prox = temp;
                        novosestados = headnovosestados;
                    }
                    else
                    {
                        state++;
                        temp -> label = state;
                        novosestados = temp;
                    }
                    
                    struct delta *tempdelta = headdelta;
                    struct final *backtemp = temp -> L;
                    while(temp -> L != NULL)
                    {
                        while(headdelta != NULL)
                        {
                            if(headdelta -> Ei == temp -> L -> value)
                                headdelta = addToD(temp -> label, headdelta -> Le[0], headdelta -> Ef, headdelta);

                            headdelta = headdelta -> prox;
                        }


                        struct final *afndfinal = afnd -> F;

                        while(afnd -> F != NULL)
                        {
                            if(temp -> L -> value == afnd -> F -> value)
                                afndfinal = addToF(temp -> label, afndfinal);

                            afnd -> F = afnd -> F -> prox;
                        }
                        afnd -> F = afndfinal;

                        headdelta = tempdelta;
                        temp -> L = temp -> L -> prox;
                    }
                    temp -> L = backtemp;

                    headdelta = substituirDelta(ei, le, state, headdelta);
                    headdelta = removeRepeticoes(headdelta);

                    break;
            }

         }
         else
             freeEstados(temp);

         ant = afnd -> D;
         afnd -> D = afnd -> D -> prox;
         ant -> prox = afnd -> D;

         if(afnd -> D == NULL)
             break;
    }

    if(novosestados != NULL)
        freeEstados(novosestados);

    afnd -> F = headfinal;
    afnd -> D = headdelta;
    
    return afnd;

}

struct automato *readsuser(void)
{
    int entrada = 1;
    unsigned short int val1, val2; 
    char str[121],
         le; 

    struct automato *afnd = (struct automato *)malloc(sizeof(struct automato));
    afnd -> F = NULL;
    afnd -> D = NULL;

    while(1)
    {

        switch(entrada)
        {
            case 1:

                while(1)
                {
                    fgets(str, sizeof(str), stdin);
                    if((str[0] >= 48) && (str[0] <= 57))
                    {
                        sscanf(str, "%hu", &afnd -> K);
                        entrada++;
                        break;
                    }
                    else
                    {
                        if(str[0] == 35)
                        {}
                        else
                            entradainvalida();
                    }
                }
                break;

            case 2:

                while(1)
                {
                    fgets(str, sizeof(str), stdin);
                    if((str[0] >= 97) && (str[0] <= 122))
                    {
                        sscanf(str, "%c", &afnd -> A);
                        entrada++;
                        break;
                    }
                    else
                        if(str[0] == 35)
                        {}
                        else
                            entradainvalida();
                }
                break;

            case 3:
                while(1)
                {
                    fgets(str, sizeof(str), stdin);
                    if((str[0] >= 48) && (str[0] <= 57))
                    {
                        sscanf(str, "%hu", &afnd -> S);

                        entrada++;
                        break;
                    }
                    else
                        if(str[0] == 35)
                        {}
                        else
                            entradainvalida();
                }

                break;

            case 4:
                while(1)
                {
                    fgets(str, sizeof(str), stdin);

                    if((str[0] >= 48) && (str[0] <= 57))
                    {
                        afnd -> F = readsF(str, afnd -> F);


                        entrada++;
                        break;
                    }
                    else
                        if(str[0] == 35)
                        {}
                        else
                            entradainvalida();
                }

                break;

            case 5:
                while(1)
                {
                    fgets(str, sizeof(str), stdin);
                    if((str[0] >= 48) && (str[0] <= 57))
                    {
                        sscanf(str, "%hu %c %hu", &val1, &le, &val2);
                        afnd -> D = addToD(val1, le, val2, afnd -> D);
                    }
                    else
                        if(str[0] == 35)
                        {
                        }
                        else
                        {
                            if(str[0] <= 32)
                            {
                                entrada++;
                                break;
                            }
                            else
                                entradainvalida();
                        }
                }
                break;

            case 6:
                return afnd;
                break;
        }

    }

    return afnd;
}

struct automato *removerImpossiveis(struct automato *afnd)
{
    int flag = 0;
    struct delta *headdelta = afnd -> D;
    struct delta *ant = NULL;
    unsigned short int target;

    while(afnd -> D != NULL)
    {
        flag = 0;
        target = afnd -> D -> Ei;
        while(target == afnd -> S)
        {
            afnd -> D = afnd -> D -> prox;
            target = afnd -> D -> Ei;
        }
        struct delta *temp = headdelta;
        while(temp != NULL)
        {
            if((temp -> Ei != target) && (temp -> Ef == target))
            {
                flag = 1;
                break;
            }
            temp = temp -> prox;
        }
        if(!flag)
        {
            afnd -> F = removeFinal(afnd -> D -> Ei, afnd -> F);
            if(ant == NULL)
            {
                struct delta *apagar = afnd -> D;
                headdelta = afnd -> D -> prox;
                afnd -> D = headdelta;
                free(apagar);
            }
            else
            {
                struct delta *apagar = afnd -> D;
                ant -> prox = afnd -> D -> prox;
                afnd -> D = afnd -> D -> prox;
                free(apagar);
            }
        }
        else
        {
            ant = afnd -> D;
            afnd -> D = afnd -> D -> prox;
        }
    }
    afnd -> D = headdelta;

    struct final *headfinal = afnd -> F;

    while(afnd -> F != NULL)
    {
        target = afnd -> F -> value;
        flag = 0;
        while(afnd -> D != NULL)
        {
            if(afnd -> D -> Ef == target)
            {
                flag = 1;
                break;
            }
            afnd -> D = afnd -> D -> prox;
        }
        afnd -> D = headdelta;

        if(!flag)
        {
            afnd -> F = afnd -> F -> prox;
            headfinal = removeFinal(target, headfinal);
        }
        else
            afnd -> F = afnd -> F -> prox;
    }

    afnd -> F = headfinal;
    return afnd;
}

struct automato *removerVazios(struct automato *afnd)
{
    struct delta *head = afnd -> D;
    int pos = 1,
        inicio = 0;

    afnd = novosFinais(afnd);

    while(afnd -> D != NULL)
    {
        if(afnd -> D -> Le[0] == 'E')
        {
            unsigned short int oldEi = afnd -> D -> Ei,
                               oldEf = afnd -> D -> Ef;

            head = removeDelta(pos, head);

            head = redirecionarDelta(oldEi, oldEf, head);

            inicio = 1;
        }

        switch(inicio)
        {
            case 0:
                pos++;
                afnd -> D = afnd -> D -> prox;
                break;
            case 1:
                afnd -> D = head; 
                pos = 1;
                inicio = 0;
                break;
        }

    }

    head = removeRepeticoes(head);

    afnd -> D = head;
    return afnd;
}

struct delta *addStringToD(unsigned short int val1, char le[SBUFF], unsigned short int val2, struct delta *afndD)
{
    struct delta *aux = malloc(sizeof(struct delta));

    struct delta *deltahead = afndD;

    aux->prox = NULL;
    aux->Ei = val1;
    aux->Ef = val2;

    for(int i = 0; i < SBUFF; i++)
        aux->Le[i] = le[i];

    if(afndD == NULL)
    {
        deltahead = aux;
    }
    else
    {
        struct delta *deltaant = NULL;
        while(afndD != NULL)
        {
            deltaant = afndD;
            afndD = afndD->prox;
        }

        afndD = aux;
        deltaant->prox = afndD;
        afndD->prox = NULL;
    }

    return deltahead;
}

struct delta *addToD(unsigned short int val1, char le, unsigned short int val2, struct delta *afndD)
{
    struct delta *aux = malloc(sizeof(struct delta));

    struct delta *deltahead = afndD;

    for(int i = 0; i < SBUFF; i++)
        aux -> Le[i] = '\0';

    aux -> prox = NULL;
    aux -> Ei = val1;
    aux -> Le[0] = le;
    aux -> Ef = val2;

    if(afndD == NULL)
    {
        deltahead = aux;
    }
    else
    {
        struct delta *deltaant = NULL;
        while(afndD != NULL)
        {
            deltaant = afndD;
            afndD = afndD -> prox;
        }

        afndD = aux;
        deltaant -> prox = afndD;
        afndD -> prox = NULL;
    }

    return deltahead;
}

struct delta *copiarDelta(struct delta *destino, struct delta *origem)
{
    struct delta *deltahead = destino;

    while(destino -> prox != NULL)
        destino = destino -> prox;

    destino -> prox = origem;

    return deltahead;
}

struct delta *freeD(struct delta *vec)
{
    if(vec == NULL)
        return NULL;

    if(vec -> prox != NULL)
    {
        freeD(vec -> prox);
        free(vec->prox);
        vec -> prox = NULL;
    }

    return vec;
}

struct delta *kleene(char er[SBUFF], unsigned short int target, struct delta *afdD)
{
    struct delta *headdelta = afdD;
    struct delta *ant = NULL;
    char star[SBUFF] = "(";
    char aux[SBUFF] = "\0";

    strcat(star, er);

    while(afdD != NULL)
    {
        if((afdD->Ei == target) && (afdD->Ef == target) && (afdD->Le != er))
        {
            strcat(star, "|");
            strcat(star, afdD->Le);
        }

        afdD = afdD->prox;
    }
    afdD = headdelta;

    strcat(star, ")*");

    while(afdD != NULL)
    {
        if((afdD->Ei == target) && (afdD->Ef == target))
        {
            if(ant == NULL)
            {
                struct delta *temp = afdD;
                headdelta = afdD->prox;
                afdD = headdelta;
                free(temp);
            }
            else
            {
                struct delta *temp = afdD;
                ant->prox = afdD->prox;
                afdD = ant;
                free(temp);
                ant = afdD;
                afdD = afdD->prox;
            }
        }
        else
        {
            ant = afdD;
            afdD = afdD->prox;
        }
    }
    afdD = headdelta;

    while(afdD != NULL)
    {
        if((afdD->Ei == target))
        {
            for(int i = 0; i < SBUFF; i++)
                aux[i] = 0;

            strcat(aux, star);
            strcat(aux, ".");
            strcat(aux, "(");
            strcat(aux, afdD->Le);
            strcat(aux, ")");

            for(int i = 0; i < SBUFF; i++)
                afdD->Le[i] = 0;

            strcpy(afdD->Le, aux);
        }
        afdD = afdD->prox;
    }

    afdD = headdelta;
    return headdelta;
}

struct delta *redirecionarDelta(unsigned short int oldEi, unsigned short int oldEf, struct delta *afndD)
{
    struct delta *head = afndD;
    struct delta *temp = NULL;
    struct delta *ant = NULL;
    unsigned short int ef;
    char le;

    while(afndD != NULL)
    {
        if(afndD -> Ei == oldEf)
        {
            le = afndD -> Le[0];
            ef = afndD -> Ef;

            temp = addToD(oldEi, le, ef, temp);
        }
        ant = afndD;
        afndD = afndD -> prox;
        ant -> prox = afndD;
    }

    ant -> prox = temp;

    return head;
}

struct delta *removeDelta(int pos, struct delta *afndD)
{
    struct delta *head = afndD;
    struct delta *ant = NULL;
    int i;

    for(i = 1; i < pos; i++)
    {
        ant = afndD;
        afndD = afndD -> prox;
    }

    struct delta *temp = afndD;

    if(ant == NULL)
        head = head -> prox;
    else
        ant -> prox = afndD -> prox;

    free(temp);

    return head;
}

struct delta *removeRepeticoes(struct delta *afndD)
{
    struct delta *head = afndD;
    struct delta *pont = NULL;

    unsigned short int ei, ef;
    char le;
    int pos = 1,
        pospont = pos + 1,
        inicio = 0;

    while(afndD -> prox != NULL)
    {
        ei = afndD -> Ei;
        le = afndD -> Le[0];
        ef = afndD -> Ef;
        pont = afndD -> prox;

        while(pont != NULL)
        {
            if((pont -> Ei == ei) && (pont -> Ef == ef) && (pont -> Le[0] == le))
            {
                head = removeDelta(pospont, head);
                inicio = 1;
                break;
            }
            else
            {
                pospont++;
                pont = pont -> prox;
            }
        }

        switch(inicio)
        {
            case 0:
                pos++;
                pospont = pos + 1;
                afndD = afndD -> prox;
                break;

            case 1:
                afndD = head; // volta ao inicio
                pos = 1;
                pospont = pos + 1;
                inicio = 0;
                break;
        }
    }

    afndD = head;
    return afndD;
}

struct delta *substituirDelta(unsigned short int oldEi, char oldLe, unsigned short int novoestado, struct delta *afndD)
{
    struct delta *head = afndD;

    while(afndD != NULL)
    {
        if((afndD -> Ei == oldEi) && (afndD -> Le[0] == oldLe))
            afndD -> Ef = novoestado;

        afndD = afndD -> prox;
    }

    return head;
}

struct delta *substituirEf(unsigned short int x, char y[SBUFF], unsigned short int z, struct delta *afdD)
{
    char aux[SBUFF] = "\0";
    // Seja x o estado que desejamos excluir, buscaremos casos onde ele eh estado final de uma transicao
    struct delta *headdelta = afdD;
    struct delta *ant = NULL;
    struct delta *temp = NULL;
    struct delta *headtemp = NULL;

    while(afdD != NULL)
    {
        if(afdD->Ef == x)
        {
            for(int i = 0; i < SBUFF; i++)
                aux[i] = 0;

            strcat(aux, "(");
            strcat(aux, afdD->Le);
            strcat(aux, ").(");
            strcat(aux, y);
            strcat(aux, ")");
            headdelta = addStringToD(afdD->Ei, aux, z, headdelta);
            ant = afdD;
            afdD = afdD->prox;
        }
        else
            if((afdD->Ei == x) && (afdD->Le == y))
            {
                // Neste caso encontramos a propria transicao que estamos realizando as substituicões, portanto iremos apaga-la
                if(ant == NULL)
                {
                    if(temp == NULL)
                    {
                        temp = afdD;
                        headtemp = temp;
                    }
                    else
                    {
                        temp->prox = afdD;
                        temp = temp->prox;
                    }
                    headdelta = afdD->prox;
                    afdD = headdelta;
                    temp->prox = NULL;
                }
                else
                {
                    if(temp == NULL)
                    {
                        temp = afdD;
                        headtemp = temp;
                    }
                    else
                    {
                        temp->prox = afdD;
                        temp = temp->prox;
                    }
                    ant->prox = afdD->prox;
                    afdD = ant;
                    ant = afdD;
                    afdD = afdD->prox;
                    temp->prox = NULL;
                }
            }
            else
            {
                ant = afdD;
                afdD = afdD->prox;
            }
    }
    afdD = headdelta;

    freeD(headtemp);
    free(headtemp);
    headtemp = NULL;

    return headdelta;
}

struct delta *organizar(struct delta *afndD)
{
    struct delta *headdelta = afndD;
    struct delta *prox = NULL;
    struct delta *ant = NULL;
    struct delta *temp = NULL;
    struct delta *tempprox = NULL;

    while(afndD -> prox != NULL)
    {
        prox = afndD -> prox;
        if(afndD -> Ei > prox -> Ei)
        {
            if(ant == NULL)
            {
                temp = afndD;
                tempprox = prox -> prox;
                headdelta = prox;
                prox -> prox = temp;
                temp -> prox = tempprox;
                afndD = headdelta;
            }
            else
            {
                temp = afndD;
                tempprox = prox -> prox;
                ant -> prox = prox;
                prox -> prox = temp;
                temp -> prox = tempprox;
                afndD = headdelta;
            }
        }
        else
            if(afndD -> Ei == prox -> Ei)
            {
                if(afndD -> Le[0] > prox -> Le[0])
                {
                    if(ant == NULL)
                    {
                        temp = afndD;
                        tempprox = prox -> prox;
                        headdelta = prox;
                        prox -> prox = temp;
                        temp -> prox = tempprox;
                        afndD = headdelta;
                    }
                    else
                    {
                        temp = afndD;
                        tempprox = prox -> prox;
                        ant -> prox = prox;
                        prox -> prox = temp;
                        temp -> prox = tempprox;
                        afndD = headdelta;
                    }
                }
                else
                    if(afndD -> Le[0] == prox -> Le[0])
                    {
                        if(afndD -> Ef > prox -> Ef)
                        {
                            if(ant == NULL)
                            {
                                temp = afndD;
                                tempprox = prox -> prox;
                                headdelta = prox;
                                prox -> prox = temp;
                                temp -> prox = tempprox;
                                afndD = headdelta;
                            }
                            else
                            {
                                temp = afndD;
                                tempprox = prox -> prox;
                                ant -> prox = prox;
                                prox -> prox = temp;
                                temp -> prox = tempprox;
                                afndD = headdelta;
                            }
                        }
                        else
                        {
                            ant = afndD;
                            afndD = afndD -> prox;
                        }
                    }
                    else
                    {
                        ant = afndD;
                        afndD = afndD -> prox;
                    }
            }
            else
            {
                ant = afndD;
                afndD = afndD -> prox;
            }
    }

    afndD = headdelta;
    return headdelta;
}

struct estados *freeEstados(struct estados *lista)
{
    if(lista -> prox != NULL)
    {
        freeEstados(lista -> prox);
        lista -> prox = NULL;

        freeF(lista -> L);

        free(lista -> L);

        lista -> L = NULL;
    }
    else
    {
        freeF(lista -> L);

        free(lista -> L);

        lista -> L = NULL;
    }

    free(lista);
    return NULL;
}

struct estados *findlabel(struct estados *lista, unsigned short int x)
{
    while(lista -> label != x)
        lista = lista -> prox;

    return lista;
}

struct final *addToF(unsigned short int val1, struct final *afndF)
{
    struct final *aux = malloc(sizeof(struct final));

    struct final *finalhead = afndF;
    struct final *finalant = NULL;

    aux -> value = val1;
    aux -> prox = NULL;

    // Caso a lista de estados finais esteja vazia, o primeiro estado eh armazenado prontamente.
    if(afndF == NULL)
        finalhead = aux;
    else
    {
        // Caso a lista de estados finais nao esteja vazia, utilizamos a variavel auxiliar para armazenar um novo estado final na lista.
        while(afndF != NULL)
        {
            if(afndF -> value == val1) // Se o estado ja existir na lista, entao nao adiciona
            {
                free(aux);
                finalant = afndF;
                return finalhead;
            }
			else
            {
                finalant = afndF;
                afndF = afndF -> prox;
                finalant -> prox = afndF;
            }
        }

        afndF = aux;
        finalant -> prox = afndF;
    }

    return finalhead;
}

struct final *freeF(struct final *vec)
{
    if(vec == NULL)
        return NULL;

    if(vec -> prox != NULL)
    {
        freeF(vec -> prox);
        free(vec->prox);
        vec->prox = NULL;
    }

    return vec;
}

// Funcao que le uma linha de valores para lugares finais e transforma em diversos valores
struct final *readsF(char string[SBUFF], struct final *lista)
{
    int i = 0, // contador do loop while que roda toda string
        isftemp = 0, // ajuda a indicar se ftemp eh maior que 10
        caso = 0;

    unsigned short int ftemp ; // valor final temporario que sera movido a lista

    while(string[i] >= 32)
    {
        if((string[i] >= 48) && (string[i] <= 57))
            caso = 1 ;

        if(string[i] == 32)
            caso = 2;

        switch(caso)
        {
            case 1 :
                if(isftemp)
                {
                    string[i] -= 48;
                    ftemp = ftemp * 10;
                    ftemp += string[i];
                }
                else
                {
                    string[i] -= 48;
                    ftemp = string[i];
                    isftemp = 1;
                }
                break ;
            case 2 :
                lista = addToF(ftemp, lista);
                isftemp = 0;
                break ;
        }

        i++ ;
    }

    if(isftemp)
        lista = addToF(ftemp, lista);

    return lista;
}

struct final *removeFinal(unsigned short int oldE, struct final *afndF)
{
    struct final *head = afndF;
    struct final *ant = NULL;

    while(afndF != NULL)
    {
        if(afndF -> value == oldE)
        {
            struct final *temp = afndF;

            if(ant == NULL)
            {
                head = afndF ->prox;
                head = addToF(state, head);
                free(temp);
            }
            else
            {
                ant ->prox = afndF ->prox;
                ant = addToF(state, ant);
                free(temp);
            }
            break ;
        }

        ant = afndF;
        afndF = afndF ->prox;
    }

    afndF = head;
    return afndF ;
}


/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints help information and exit
 * @details Prints help information (usually called by opt -h)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160618.013215
 * @date 2016-06-18
 *
 */
void help(void)
{
    IFDEBUG("help()");
    printf("%s - %s\n", "Automax", "Converte AFD, AFND e ER");
    printf("\nUsage: %s [-h|-v]\n", "Automax");
    printf("\nOptions:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-c,  --copyright, --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-f, --file\n\t\tSet the input filename.\n");
    /* add more options here */
    printf("\t-n, --nfa\n\t\tA entrada de dados é uma quíntupla de um AFND que será convertido para AFD.\n");
    printf("\t-e, --re\n\t\tA entrada de dados é uma quíntupla de um AFD que será convertido para uma ER.\n");
    printf("\t-d, --dfa\n\t\tA entrada de dados é uma _string_ de uma ER que será convertida em um AFND..\n");
    /*
    * -n : a entrada de dados é uma quíntupla de um AFND que será convertido para AFD.
    * -d : a entrada de dados é uma quíntupla de um AFD que será convertido para uma ER.
    * -e : a entrada de dados é uma _string_ de uma ER que será convertida em um AFND.
    */
    printf("\nExit status:\n\t0 if ok.\n\t1 some error occurred.\n");
    printf("\nTodo:\n\tLong options not implemented yet.\n");
    printf("\nAuthor:\n\tWritten by %s <%s>\n\n", "Ruben Carlo Benante", "rcb@beco.cc");
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief Prints version and copyright information and exit
 * @details Prints version and copyright information (usually called by opt -V)
 * @return Void
 * @author Ruben Carlo Benante
 * @version 20160618.013215
 * @date 2016-06-18
 *
 */
void copyr(void)
{
    IFDEBUG("copyr()");
    printf("%s - Version %s\n", "Automax", VERSION);
    printf("\nCopyright (C) %d %s <%s>, GNU GPL version 2 <http://gnu.org/licenses/gpl.html>. This  is  free  software: you are free to change and redistribute it. There is NO WARRANTY, to the extent permitted by law. USE IT AS IT IS. The author takes no responsability to any damage this software may inflige in your data.\n\n", 2016, "Ruben Carlo Benante", "rcb@beco.cc");
    if(verb > 3) printf("copyr(): Verbose: %d\n", verb); /* -vvvv */
    exit(EXIT_FAILURE);
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function initializes some operations before start
 * @details Details to be written
 * @return Void
 * @todo Need to implement it. Its empty now.
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 *
 */
void automax_init(void)
{
    IFDEBUG("automax_init()");
    /* initialization */
    return;
}

/* ---------------------------------------------------------------------- */
/**
 * @ingroup GroupUnique
 * @brief This function does bla bla bla
 * @details It works by doing first a bla, followed by two bla's, giving
 * bla bla bla
 *
 * @pre You need to call foo() before calling this function
 *
 * @param[in] i Input parameter that does bla
 * @param[out] o Parameter that outputs ble
 * @param[in,out] z The @a z variable is used as input and output
 *
 * @return The returned value @a r means rhit
 * @retval 0 Returned when bli
 * @retval 1 Error code: function returned blo
 *
 * @par Example
 * @code
 *    if(x==funcexample(i, o, z))
 *       printf("And that is it\n");
 * @endcode
 *
 * @warning   Be carefull with blu
 * @deprecated This function will be deactivated in version +33
 * @see help()
 * @see copyr()
 * @bug There is a bug with x greater than y
 * @todo Need to change its output format to conform POSIX
 * @note You can read more about it at <<a href="http://www.beco.cc">www.beco.cc</a>>
 * @author Ruben Carlo Benante
 * @version 20160520.000202
 * @date 2016-05-20
 * @copyright Only if not the same as the whole file
 *
 */
int funcexample(int i, int *o, int *z)
{
    IFDEBUG("funcexample()");
    i += *z;
    *o = (*z)++;
    return i - 4;
}


/* ------------------------------------------------------------------ */
/* C config for Vim modeline                                          */
/* vi: set ai cin et ts=4 sw=4 tw=0 wm=0 fo=croqltn :                 */
/* Template by Dr. Beco <rcb at beco dot cc>  Version 20160614.152950 */

