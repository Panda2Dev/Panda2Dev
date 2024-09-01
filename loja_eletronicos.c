#include <stdio.h>
#include <stdlib.h>

int main () {
    //define tamanho das constantes
    #define MAX_USUARIOS 10
    #define TAMANHO_NOME 30
    #define TAMANHO_SENHA 5
    #define LINHAS 5
    #define COLUNAS 3
    #define TAMANHO_ID 7
    #define TAMANHO_STATUS 20
    //

    const char SENHA_CADASTRO = "2024";
    //produto
    struct Produto{
        char id[TAMANHO_ID];
        char nome[TAMANHO_NOME];
        char status[TAMANHO_STATUS];
    };

    //usuario
    struct Usuario {
        char nome[TAMANHO_NOME];
        char cargo [TAMANHO_NOME];
        char senha [TAMANHO_SENHA];
    };
   

}



