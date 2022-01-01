
#include "er.h" /* To be created for this template if needed */


int main(int argc, char *argv[])
{
    int opt;

    opterr = 0;
    while((opt = getopt(argc, argv, "vhVnde")) != EOF)
        switch(opt)
        {
            case 'h':
                help();
                break;
            case 'v':
                verb++;
                break;
            case 'd':
                if(argv[2] != NULL)
                {
                    // Foi acionada a flag -f. argv[3] deve conter o nome do arquivo a ser lido.
                    if(argv[3] == NULL)
                    {
                       // help();
                        return EXIT_FAILURE;
                    }
                    else
                        fileafd(argv[3]);
                }
                else
                    afdtoer();
                break;
            case '?':
            default:
                help();
                return EXIT_FAILURE;
        }

    if(verb)
        printf("Verbose level set at: %d\n", verb);

    auto2_init(); /* initialization function */


    return EXIT_SUCCESS;
}

void afdtoer(void)
{



    struct automato *afd = NULL;

    afd = readsuser();

    conversaoafder(afd);

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
    printf("\t$./ex7.x -h\n");

    exit(-1);
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

    //    Ler arquivo.

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


    int entrada = 0; // Variavel para identificar quais dados estao sendo lidos;
    // 1 para K; 2 para A; 3 para S; 4 para F; 5 para D.
    unsigned short int val1, val2; // variaveis para receber valores de entrada.
    char str[SBUFF],               // 'str' armazena a string de uma linha do arquivo de entrada.
         le;                        // 'le' recebe tipos char no conjunto delta de funcões.

    // 'fgets' le cada linha do arquivo e armazena a string em 'str'.
    while(fgets(str, sizeof(str), dados))
    {
        // Se a linha do arquivo comeca com um # (valor 35), entao a linha nao fica armazenada em nossa struct. O contador 'entrada' nos informa se estamos lendo valores de K, A, S, F ou D conforme explicado acima.
        if(str[0] == 35)
        {
            entrada++;
            continue;
        }

        switch(entrada)
        {
            // Leitura dos valores de K:
            case 1:
                sscanf(str, "%hu", &afd->K);
                break;

            // Leitura dos valores de A:
            case 2:
                sscanf(str, "%c", &afd->A);
                break;

            // Leitura dos valores de S:
            case 3:
                sscanf(str, "%hu", &afd->S);
                break;

            // Leitura dos valores de F:
            case 4:
                afd->F = readsF(str, afd->F);
                break;

            // Leitura dos valores de D:
            case 5:
                sscanf(str, "%hu %c %hu", &val1, &le, &val2);
                afd->D = addToD(val1, le, val2, afd->D);

                break;
        }

    } //end while fgets

    if(dados)
        fclose(dados);

    conversaoafder(afd);

    exit(EXIT_SUCCESS);
}

void simplificar(char expressao[SBUFF])
{
    simpos = 0;
    simplificarparenteses(expressao);
    simpos = 0;
    simplificarvazios(expressao);
   // printf("%s\n", expressao);
}

// Retira parenteses nao obrigatórios de uma expressao regular
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

                if(expressao[simpos] != 41)  // entao foi excluido parentese que fecha, portanto excluiremos tambem aquele que abre
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
                    // nada eh excluido
                    simpos++;
                }
                break;

            case 1:
                if(flag)  // entao nao encontramos nenhum sinal de uniao, talvez de pra excluir os parenteses. antes, precisamos verificar se imediatamente após os parenteses ha uma estrela de kleene; caso afirmativo, parenteses se matem
                {
                    if(expressao[simpos + 1] == 42)  // estrela de kleene
                    {
                        // Só pode excluir os parenteses se, entre eles, houver APENAS uma letra
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
                        // podemos excluir parenteses (ao menos este que fecha, que esta na posicao simpos)
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

    printf("\n\nA expressao encontrada foi:\n\n");
    printf("%s\n", expressao);
    printf("\n\n");
}

// Funcao que atualiza a quantidade de estados no autômato
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

// Funcao para ler a entrada do terminal
struct automato *readsuser(void)
{
    int entrada = 1; // Variavel para identificar quais dados estao sendo lidos;
    //1 para K; 2 para A; 3 para S; 4 para F; 5 para D.
    unsigned short int val1, val2; // variaveis para receber valores de entrada.
    char str[121], // 'str' armazena a string de uma linha do arquivo de entrada.
         le; // 'le' recebe tipos char no conjunto delta de funcões.

    struct automato *afnd = (struct automato *)malloc(sizeof(struct automato));
    afnd -> F = NULL;
    afnd -> D = NULL;

    while(1)
    {
        // Se a linha do arquivo comeca com um # (valor 35), entao a linha nao fica armazenada em nossa struct. O contador 'entrada' nos informa se estamos lendo valores de K, A, S, F ou D conforme explicado acima.

        switch(entrada)
        {
            // Leitura dos valores de K:
            case 1:

              // printf("# Digite um valor inteiro para a quantidade total de lugares (K):\n");

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
                        {/**/}
                        else
                            entradainvalida();
                    }
                }
                break;

            /* Leitura dos valores de A: */
            case 2:
              //  printf("# Digite a maior letra que representa o alfabeto de seu autômato:\n#\tExemplo: A='c', entao o alfabeto eh {a, b, c}.\n");

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

            // Leitura dos valores de S:
            case 3:
               // printf("# Digite um valor inteiro para indicar o local onde o autômato comeca (S): \n");
                while(1)
                {
                    fgets(str, sizeof(str), stdin);
                    if((str[0] >= 48) && (str[0] <= 57))
                    {
                        sscanf(str, "%hu", &afnd -> S);
                       // printf("# Digite valores inteiros que indiquem o(s) local(is) onde o autômato termina.\n# Caso seja mais de um local, os separe apenas com espacos simples.\n");

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

            // Leitura dos valores de F:
            case 4:
                while(1)
                {
                    fgets(str, sizeof(str), stdin);

                    if((str[0] >= 48) && (str[0] <= 57))
                    {
                        afnd -> F = readsF(str, afnd -> F);
                       // printf("# Digite as funcões de transicao do autômato separadas por um linefeed.\n#\tExemplo: 0 a 1\n#\tOnde 0 eh o local inicial desta transicao,\n");
                       // printf("#\t'a' eh o caractere lido\n");
                       // printf("#\te 1 eh o local final da transicao.\n");


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

            // Leitura dos valores de D:
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

            // Fim da entrada de dados
            case 6:
                return afnd;
                break;
        }

    } //end while fgets

    return afnd;
}

// Funcao para construir a lista de conjunto delta de funcões dentro da quintupla, mas com Le sendo do tipo string.
struct delta *addStringToD(unsigned short int val1, char le[SBUFF], unsigned short int val2, struct delta *afndD)
{
    struct delta *aux = malloc(sizeof(struct delta));

    struct delta *deltahead = afndD;

    aux->prox = NULL;
    aux->Ei = val1;
    aux->Ef = val2;

    for(int i = 0; i < SBUFF; i++)
        aux->Le[i] = le[i];

    // Caso a lista de conjunto delta de funcões esteja vazia, o primeiro estado eh armazenado prontamente.
    if(afndD == NULL)
    {
        // Marcamos aqui o inicio desta lista.
        deltahead = aux;
    }
    else
    {
        struct delta *deltaant = NULL;
        // Caso a lista de conjunto delta de funcões nao esteja vazia, utilizamos a variavel auxiliar para armazenar uma nova tripla na lista.
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

// Funcao para construir a lista de conjunto delta de funcões dentro da quintupla.
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

    // Caso a lista de conjunto delta de funcões esteja vazia, o primeiro estado eh armazenado prontamente.
    if(afndD == NULL)
    {
        // Marcamos aqui o inicio desta lista.
        deltahead = aux;
    }
    else
    {
        struct delta *deltaant = NULL;
        // Caso a lista de conjunto delta de funcões nao esteja vazia, utilizamos a variavel auxiliar para armazenar uma nova tripla na lista.
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

// Continua a identificar casos de estrela de Kleene e apaga estas transicões enquanto copia sua ER as outras transicões que passam por este estado excluido
struct delta *kleene(char er[SBUFF], unsigned short int target, struct delta *afdD)
{
    struct delta *headdelta = afdD;
    struct delta *ant = NULL;
    char star[SBUFF] = "(";
    char aux[SBUFF] = "\0";

    strcat(star, er);

    // Agora, iremos procurar se ha outro caractere na estrela de kleene, que entrara como uniao
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

    // Iremos apagar os caminhos que levam de 'target' a 'target'
    while(afdD != NULL)
    {
        if((afdD->Ei == target) && (afdD->Ef == target))
        {
            // Caso onde voltamos para a estrela de Kleene, portanto vamos apaga-la
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

    // Iremos adicionar 'star' ao inicio de cada ER que parte de target
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

// Quando encontrar uma transicao "ei le ef" que coincide com o "x" obtido pelo argumento, a funcao copia a transicao e substitui "le ef" pelos argumentos "y, z"
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

// Funcao para construir a lista de estados finais dentro da quintupla.
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

void help(void)
{
    IFDEBUG("help()");
    printf("\n%s - %s\n", "Auto2.c", "Capaz de converter um AFD em ER");
    printf("\nOpcoes:\n");
    printf("\t-h,  --help\n\t\tMostra tela help.\n");
    printf("\t-d,\n\t\tA entrada de dados eh uma quintupla de um AFD que sera\n\t\tconvertido para uma ER.\n");
    printf("\t-PIPE,\n\t\tEntrada no formato: cat NOME_DO_ARQUIVO.txt | ./auto2.x -FLAG\n\t\tO pipe coloca o conteudo do txt no programa.\n\n");
    printf("\t-f NOME_DO_ARQUIVO,\n\t\tOutra forma de rodar o programa, ./auto2.x -d -f NOME_DO_ARQUIVO.txt,\n\t\tfaz a entrada de um txt.\n\n");
    printf("\t-V,  --version\n\t\tMostra informacoes de versao do programa.\n\n");
    printf("\t-v,  --verbose\n\t\tSeleciona nivel de verbose (cumulative).\n\n");
    
    printf("\n");
    exit(EXIT_FAILURE);
}


/*void help(void)
{
    IFDEBUG("help()");
    printf("\n%s - %s\n", "Auto2.c", "Capaz de converter um AFD em ER");
    printf("\nOpcoes:\n");
    printf("\t-h,  --help\n\t\tShow this help.\n");
    printf("\t-V,  --version\n\t\tShow version and copyright information.\n");
    printf("\t-v,  --verbose\n\t\tSet verbose level (cumulative).\n");
    printf("\t-d,\n\t\tA entrada de dados eh uma quintupla de um AFD que sera\n\t\tconvertido para uma ER.\n");
    printf("\t-PIPE,\n\t\tEntrada no formato: cat NOME_DO_ARQUIVO.txt | ./auto2.x -FLAG\n\t\tO pipe coloca o conteudo do txt no programa.\n\n");
    printf("\t-f NOME_DO_ARQUIVO,\n\t\tOutra forma de rodar o programa, ./auto2.x -d -f NOME_DO_ARQUIVO.txt,\n\t\tfaz a entrada de um txt.\n");
    printf("\n");
    exit(EXIT_FAILURE);
}*/

void auto2_init(void)
{
    IFDEBUG("auto2_init()");
    /* initialization */
    return;
}
