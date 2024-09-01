#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define tamanho das constantes
#define MAX_USUARIOS 10
#define TAMANHO_NOME 30
#define TAMANHO_SENHA 5
#define LINHAS 5
#define COLUNAS 3
#define TAMANHO_ID 7
#define TAMANHO_STATUS 20
//

const char SENHA_CADASTRO = "2025";
// produto
typedef struct
{
    char id[TAMANHO_ID];
    char nome[TAMANHO_NOME];
    char status[TAMANHO_STATUS];
} Produto;

// usuario
typedef struct
{
    char nome[TAMANHO_NOME];
    char cargo[TAMANHO_NOME];
    char senha[TAMANHO_SENHA];
} Usuario;

// cria um array para armazena os produtos
Produto produtos[LINHAS][COLUNAS];
int quantidadeProdutos = 0;

// cria um array para armazena os usuarios
Usuario usuarios[MAX_USUARIOS];
int quantidadeUsuarios = 0;

// funcao para cadastar um novo usuario
void cadastrarUsuario()
{
    char senha[TAMANHO_SENHA];

    printf("Digite a senha de cadastro: ");
    scanf("%s", senha);
    getchar();

    if (strcmp(senha, SENHA_CADASTRO) != 0)
    {
        printf("Senha incorreta! Retornando ao menu principal.\n");
        return;
    }

    // verifica se a quantidade de usuarios excedeu o limite estabelecido.
    if (quantidadeUsuarios >= MAX_USUARIOS)
    {
        printf("Limite maximo de usuarios atingido!\n");
        return;
    }

    // recebe o nome do usuario
    printf("Digite o nome do usuario: ");
    scanf("%s", &usuarios[quantidadeUsuarios].nome);

    printf("Digite o cargo do usuario (Admin ou Vendedor): "); // recebe o cargo do usuario
    scanf("%s", &usuarios[quantidadeUsuarios].cargo);
    getchar();

    printf("Digite a senha (maximo 4 digitos): "); // recebe a senha do usuario
    scanf("%4s", &usuarios[quantidadeUsuarios].senha);
    getchar();

    quantidadeUsuarios++; // incrementa a variavel em 1
    printf("Usuario cadastrado com sucesso!\n");
}
