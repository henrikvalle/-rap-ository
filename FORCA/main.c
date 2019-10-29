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
    int op,r=0,tentativas=0;
    char nome[21];
    NoSecreto * lstSecreta = inicializaListaSecreta();
    NoSecreto * sorteada;
    NoSecreto * usadas = inicializaListaSecreta();
    lstSecreta = carregaListaArquivo(lstSecreta,"palavras.dat");
    imprimeListaSecreta(lstSecreta);
do
{
    system("cls");
    exibe();
    printf("1.Configuração\n2.Jogar\n0.Sair\n");
    scanf("%d",&op);

    switch(op)
    {
        case 0:
            r=1;break;

        case 1:
            printf("Insira seu nickname");
            scanf("%s",nome); break;

        case 2:
             do
                {
                    system("cls");
                    //imprimeListaSecreta(lstSecreta);
                    sorteada= sorteiaPalavra(lstSecreta,usadas);
                    if(sorteada!=NULL)
                        {
                            do
                            {
                                system("cls");
                                printf("%s\n", sorteada->assunto);
                                tentativas++;
                            }(while tentativas<strlen(sorteada->palavra)*3)

                            lstSecreta = retiraUmElemento(lstSecreta,sorteada->palavra);

                        }

                    else
                        {
                            printf("Nao tem palavra disponivel!\n\n");
                        }
    }while(getchar()!='f');

    }(while r!=1);

}
    NoL * letras = inicializaListaSecreta();

    return 0;
}
