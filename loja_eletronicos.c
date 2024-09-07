#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// funcao sleep
#include <unistd.h>

// define tamanho das constantes
#define MAX_USUARIOS 10
#define TAMANHO_NOME 30
#define TAMANHO_SENHA 5
#define LINHAS 5
#define COLUNAS 3
#define TAMANHO_ID 7
#define TAMANHO_STATUS 20
//

const char SENHA_CADASTRO[] = "2025";
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
    scanf("%s", usuarios[quantidadeUsuarios].nome);

    printf("Digite o cargo do usuario (Admin ou Vendedor): "); // recebe o cargo do usuario
    scanf("%s", usuarios[quantidadeUsuarios].cargo);
    getchar();

    printf("Digite a senha (maximo 4 digitos): "); // recebe a senha do usuario
    scanf("%4s", usuarios[quantidadeUsuarios].senha);
    getchar();

    quantidadeUsuarios++; // incrementa a variavel em 1
    printf("Usuario cadastrado com sucesso!\n");
}

void Sistema()
{
    char nome[TAMANHO_NOME];
    char senha[TAMANHO_SENHA];
    int opcao;
    do
    {

        // recebe o nome do usuario já criado no sistema
        printf("Digite o nome do usuario: ");
        scanf("%s", nome);
        getchar();

        // recebe a senha do usuario já criado no sistema
        printf("Digite a senha do usuario: ");
        scanf("%s", senha);
        getchar();

        // verifico se o nome e senha do usuario são válidos
        for (int i = 0; i < quantidadeUsuarios; i++)
        {
            // uso strcmp para fazer a comparação do nome e senha digitado pelo usuario com os contidos no sistema
            if (strcmp(nome, usuarios[i].nome) == 0 && strcmp(senha, usuarios[i].senha) == 0)
            {
                printf("Bem vindo ao sistema da MDM Eletronica\n");
                printf("Usuario: %s.\n", usuarios[i].nome);
                printf("Cargo: %s.\n\n", usuarios[i].cargo);
                do
                {
                    printf("1.Cadastro Produto\n");
                    printf("2.Consultar Produto\n");
                    printf("3.Excluir Produto\n");
                    printf("4.Atualizar Produto\n");
                    printf("5.Sair\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcao);
                    getchar();

                    switch (opcao)
                    {
                    case 1:
                        //
                        break;
                    case 2:
                        // consulta produto
                        break;
                    case 3:
                        // excluir produto
                        break;
                    case 4:
                        // atualizar produto
                        break;
                    case 5:
                        printf("Saindo do Usuario");
                        for (int i = 0; i < 3; i++)
                        {
                            printf(".");
                            fflush(stdout);
                            sleep(1);
                        }
                        break;
                    default:
                        printf("Digite uma opção valida.\n");
                    }
                } while (opcao != 5);

                return;
            }
        }
        printf("Usuario ou senha incorretos\n");
    } while (1);
}

// funcao principal
int main()
{
    int opcao;

    do
    {
       
        printf("\n----------------------------------\n");
        printf("MDM Eletronica - Tela inicial\n");
        printf("1. Cadastro de Usuario\n");
        printf("2. Entrar no Sistema\n");
        printf("3. Sair\n");
        printf("\n----------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao)
        {
        case 1:
            cadastrarUsuario();

            break;
        case 2:
            Sistema();
            break;
        case 3:
            printf("Saindo do Sistema");
            for (int i = 0; i < 3; i++)
            {
                printf(".");
                fflush(stdout);
                sleep(1);
            }
            break;
        default:
            printf("Porfavor, selecione uma opcao valida\n");
            printf("Pressione enter para continuar\n");
            getchar();
            system("cls");
            break;
        }
        
       

    } while (opcao != 3);
         

    return 0;
}