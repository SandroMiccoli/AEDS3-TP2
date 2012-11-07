/*
  Módulo de LCS (Longest common subsequence)

  Função que retorna o LCS de uma palavra

  Criação: 02/11/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "matriz.h"

int max(int a, int b){
    return a>=b?a:b;
}

int lcs(char * palavra, int len, Matriz * estados){

    char palCon; // Char da palavra a ser lida continuamente
    char palRev; // Char da palavra a ser lida reversamente

    int j,i,lcs;

    for (i = len - 1; i >= 0; i--){
            palRev = palavra[i];

        for (j = 0; j < len; j++){
            palCon = palavra[j];

            if (palCon == palRev){
                estados->matriz[1][j+1] = estados->matriz[0][j]+1;
            }
            else {
                estados->matriz[1][j+1] = max(estados->matriz[1][j],estados->matriz[0][j+1]);
            }
        }
        for (int k = 0; k <= len; k++){
            estados->matriz[0][k] = estados->matriz[1][k];
        }
    }

    lcs = len-estados->matriz[1][j];

    printf("%d\n",lcs);

    return lcs;

}
