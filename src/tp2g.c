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
#include "guloso.h"

#define MAXCHAR 5000

int main(int argc, char *argv[]){


    if (argc == 3){ // Nome do arquivo (argv[0]) mais os dois parâmetros

        char entrada[40] = "entrada/";
        char saida[40] = "saida/";
        int k; // Instâncias de palavras
        char *palavra;
        palavra = (char *) malloc (MAXCHAR * sizeof(char));
        int tamPalavra;

        strcat(entrada,argv[1]);
        strcat(saida,argv[2]);

        FILE * inp = abreArquivoLeitura(entrada);
        FILE * out = abreArquivoEscrita(saida);

        fscanf(inp, "%d ", &k); // Lê as k instâncias de problemas

        for (int l=0; l<k; l++){

            fscanf(inp,"%s\n",palavra);
            tamPalavra = strlen(palavra);

            printf("%d\n",guloso(palavra, tamPalavra));

            fprintf(out,"%d\n",guloso(palavra, tamPalavra));


        }

        free(palavra);
        fechaArquivo(inp);
        fechaArquivo(out);

    }
    else{
        printf("Número incorreto de parâmetros. Fazer seguir exemplo:\n\n\t./tp2 input.txt output.txt\n\n"); exit(0);
    }
    return 0;
}
