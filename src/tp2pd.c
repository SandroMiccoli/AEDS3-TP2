/*
  Trabalho Prático 2 - Paradigma Guloso e Programação Dinâmica

  Encontrar o palíndromo mínimo dada uma palavra de entrada

  Criação: 27/10/12
  Autor: Sandro Miccoli

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arquivos.h"
#include "matriz.h"
#include "lcs.h"

#define MAXCHAR 5000

int main(int argc, char *argv[]){


    if (argc == 3){ // Nome do arquivo (argv[0]) mais os dois parâmetros

        char entrada[40] = "entrada/";
        char saida[40] = "saida/";
        int k; // Instâncias de matrizes
        char *palavra;
        palavra = (char *) malloc (MAXCHAR * sizeof(char));
        int tamPalavra;

        Matriz estados; // Matriz n x 2, onde n é o tamanho da string e possui dois estados, o atual e o anterior.

        strcat(entrada,argv[1]);
        strcat(saida,argv[2]);

        FILE * inp = abreArquivoLeitura(entrada);
        FILE * out = abreArquivoEscrita(saida);

        fscanf(inp, "%d ", &k); // Lê as k instâncias de problemas

        for (int l=0; l<k; l++){

            fscanf(inp,"%s\n",palavra);
            tamPalavra = strlen(palavra);

            criaMatriz(2,tamPalavra+1,&estados);

            preencheMatriz(0,&estados); // Preenche matriz toda com 0

            fprintf(out,"%d\n",lcs(palavra, tamPalavra, &estados));

            //imprimeMatriz(estados);

            destroiMatriz(&estados);

        }

        free(palavra);
        fechaArquivo(inp);
        fechaArquivo(out);

    }
    else{
        printf("Número incorreto de parâmetros. Fazer seguir exemplo:\n\n\t./tp1 input.txt output.txt\n\n"); exit(0);
    }
    return 0;
}
