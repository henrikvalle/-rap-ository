#ifndef FORCA_H_INCLUDED
#define FORCA_H_INCLUDED

#ifdef _WIN32
# define CLEAR_SCREEN system ("cls")
#else
# define CLEAR_SCREEN puts("\x1b[H\x1b[2J")
#endif

struct noSecreto{
    int status;
    char palavra[31];
    char assunto[101];
    struct noSecreto * prox;
};
typedef struct noSecreto NoSecreto;
typedef struct noSorteada NoSorteada;

int temPalavraNaoUsada(NoSecreto *l);
NoSecreto * retiraUmElemento (NoSecreto* l, char v[31]);
NoSecreto * insereUsadas (NoSecreto* l, char word[31]);
int tamanhoListaSecreta(NoSecreto *l);
NoSecreto * retornaPalavraPos(NoSecreto *l, int pos);
int geraAleatorio(int maximo);
NoSecreto * inicializaListaSecreta();
NoSecreto * carregaListaArquivo(NoSecreto *l, char nomeArq[255]);
void imprimeListaSecreta(NoSecreto *l);
NoSecreto * inserePalavraSecreta(NoSecreto *l,char word[31],char subject[100]);
NoSecreto * sorteiaPalavra(NoSecreto *l);



#endif // FORCA_H_INCLUDED
