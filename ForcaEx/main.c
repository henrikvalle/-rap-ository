#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "forcaex.h"
#include <locale.h>
void exibe()
{
    printf("Desenvolvido por: Henrique Valle 18135 e Leticia Marinho 18144\n\n");
}

int main()
{
    setlocale(LC_ALL,"");
    NoSecreto * lstSecreta = inicializaListaSecreta();
    NoSecreto * sorteada;
    NoSecreto * usadas = inicializaListaSecreta();
    lstSecreta = carregaListaArquivo(lstSecreta,"palavras.dat");

    char nome[31] = "Usuario1",palavra2[31],letra;
    int op,sair = 0,tentativas = 0;

do{
     system("cls");
     exibe();
     printf("1 - Configuração\n");
     printf("2 - Jogar\n");
     printf("0 - Sair\n");
     scanf("%d",&op);

     if(op == 1)
     {
          system("cls");
          printf("Digite seu nickname:\n");
          scanf("%s",nome);
     }

     if(op == 2)
        {
            system("cls");
            exibe();
            printf("\t\tBem vindo %s!\n",nome);
            char  palavra[31];

            do{
                system("cls");
                sorteada = sorteiaPalavra(lstSecreta);

                if(sorteada!=NULL)
                    {
                        strcpy(palavra2,sorteada->palavra);

                        for(int i = 0; i<strlen(sorteada->palavra); i++)
                            {
                                palavra2[i] = '*';
                            }

                        for(int a=0; a<strlen(sorteada->palavra)*3; a++)
                        {
                            exibe();
                            printf("\t\tBem vindo %s!\n",nome);
                            printf("Assunto: %s\n",sorteada->assunto);
                             printf("%s\n",palavra2);
                            if(strcmp(palavra2,sorteada->palavra) == 0)
                            {
                                system("cls");
                                printf("\nAcertou!!! Tentativas: %d\n",tentativas);break;
                            }

                            printf("Digite uma letra:\n");
                            scanf("%c",&letra);
                            system("cls");
                            fflush(stdin);
                             for(int i = 0; i<strlen(sorteada->palavra); i++)
                            {
                                if(sorteada->palavra[i] == letra)
                                {
                                    palavra2[i] = letra;
                                }
                            }

                            tentativas++;
                        }
                        if((tentativas = strlen(sorteada->palavra)*3) && (strcmp(palavra2,sorteada->palavra) != 0))
                        {
                          printf("Não acertou!!! Que pena!!!");
                          printf("Ultrapassou o número de tentativas: %d\n",tentativas);
                        }
                        usadas = insereUsadas(usadas,sorteada->palavra);
                        lstSecreta = retiraUmElemento(lstSecreta,sorteada->palavra);
                    }
            else
            {
            printf("Nao existe palavra disponivel!\n\n");
            sair++;
            }
       }while(getchar()!='f' && sair == 0);

      }

}while(op != 0);



return 0;
}
