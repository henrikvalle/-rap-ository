#include <stdio.h>
#include <stdlib.h>
#include "forca.h"
#include "forca.c"
void exibe()
{
    printf("Desenvolvido por Henrique Valle e Leticia Marinho\n\n");
}

int main()
{
    exibe();
    NoSecreto * lstSecreta = inicializaListaSecreta();
    NoSecreto * sorteada;
    lstSecreta = carregaListaArquivo(lstSecreta,"palavras.dat");
    imprimeListaSecreta(lstSecreta);

      do{
        system("cls");
        exibe();
        imprimeListaSecreta(lstSecreta);

        sorteada= sorteiaPalavra(lstSecreta);
        if(sorteada!=NULL){
            printf("%s\n", sorteada->palavra);
        }else{
            printf("N�o tem palavra dispon�vel!\n\n");
        }
    }while(getchar()!='f');



    NoL * letras = inicializaListaSecreta();

    return 0;
}
