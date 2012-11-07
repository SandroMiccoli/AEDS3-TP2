/*
  Módulo de paradigma guloso para encontrar o menor valor de caracteres a ser inserido em uma palavra para ela se tornar um palíndromo

  Criação: 06/11/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "guloso.h"

//
// Verifica se palavra é palindromo
//
int palindromo(char *palavra, int len){
    len--;

    for (int i=0; i <= len; i++){
        if (palavra[i]!=palavra[len-i]) return 0;
    }

    return 1;

}

//
// Algoritmo guloso que vasculha a palavra para encontrar o maior palíndromo que seja sufixo ou prefixo da palavra.
//
int guloso(char * palavra, int len){
    int lenPalin=0;

    char * palavraInv = malloc(sizeof(char) * len+1);
    int i,j;

    // Inverte a palavra original
    for (i = len - 1,j = 0; i >= 0; i--, j++) {
        palavraInv[j] = palavra[i];
    }
    palavraInv[len] = '\0';

    for (i=len-1; i >= 0; i--){

        if (palindromo(&palavra[i],len-i)){
            if (len-i > lenPalin) lenPalin=len-i;
        }

        if (palindromo(&palavraInv[i],len-i)){
            if (len-i > lenPalin) lenPalin=len-i;
        }
    }


    return len-lenPalin;
}
