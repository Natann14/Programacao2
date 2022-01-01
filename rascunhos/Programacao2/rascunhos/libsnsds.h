#ifndef libsnsds_h
    #define libsnsds_h
/*-----------------------------------------------------------------------*/

    void normalizar_x(void); //chamada da funcao do ex1.c
/*-----------------------------------------------------------------------*/
    
    void numeros_aleatorios(void); //chamada da funcao do ex2.c
/*-----------------------------------------------------------------------*/
    
    void desenho_circulo(void); //chamada da funcao do ex5.c
/*-----------------------------------------------------------------------*/

    //funcoes ex4.c
    void prefixo(char palavra1[], char palavra2[]);
    void sufixo(char palavra1[], char palavra2[]);
    void subpalavra(char palavra1[], char palavra2[]);
    void concatenacao(char palavra1[], char palavra2[]);
/*-----------------------------------------------------------------------*/
    
    void inverter(char vetor[], int inicio, int fim); //chamada da funcao do ex9.c

/*-----------------------------------------------------------------------*/
    void multiplicar(int linhas, int colunas, int linhas2, int colunas2, int matriz[linhas][colunas], int matriz2[linhas2][colunas2]);

/*-----------------------------------------------------------------------*/
    //void multiplicar(int linhas, int colunas, int linhas2, int colunas2, int matriz[linhas][colunas], int matriz2[linhas2][colunas2]);


#endif
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<allegro.h>
#include<string.h>
