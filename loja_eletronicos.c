//inclui biblioteca padrão para entrada e saída de dados
#include <stdio.h>
//inclui biblioteca padrão para manipulação de alocação de memória
#include <stdlib.h>
//inclui biblioteca padrão para manipulação de strings
#include <string.h>
//inclui biblioteca da API POSIX (sleep)
#include <unistd.h>

// define tamanho das constantes
#define MAX_USUARIOS 10
#define TAMANHO_NOME 30
#define TAMANHO_SENHA 5
#define LINHAS 5
#define COLUNAS 3
#define TAMANHO_ID 7
#define TAMANHO_STATUS 20
//declaração da senha como constante para acessar o cadastro de usuários
const char SENHA_CADASTRO[] = "2025";
// struct para produto
typedef struct
{
    char id[TAMANHO_ID];
    char nome[TAMANHO_NOME];
    char status[TAMANHO_STATUS];
} Produto;

// struct para usuário
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
    // recebe a senha de cadastro de usuarios
    printf("Digite a senha de cadastro: ");
    scanf("%s", senha);
    getchar(); // Limpar o buffer de entrada
    // verifica se a senha de cadastro digitada é válida
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
    // recebe o cargo do usuario
    printf("Digite o cargo do usuario (Admin ou Vendedor): "); 
    scanf("%s", usuarios[quantidadeUsuarios].cargo);
    getchar(); // Limpar o buffer de entrada
    // recebe a senha do usuario
    printf("Digite a senha (maximo 4 digitos): "); 
    scanf("%4s", usuarios[quantidadeUsuarios].senha);
    getchar(); // Limpar o buffer de entrada
    //limpa a tela
    system("clear || cls"); // apaga parte anterior do código na tela
    quantidadeUsuarios++; // incrementa a variavel em 1
    printf("Usuario cadastrado com sucesso!\n");
    printf("Pressione 'enter' para continuar");
    getchar(); // Limpar o buffer de entrada
    //limpa a tela
    system("clear || cls"); // apaga parte anterior do código na tela
}
//retorna uma lista com todos os produtos
void consultarProduto() {
    int contador = 1;

    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            if (strlen(produtos[i][j].id) > 0) {
                printf("Produto %d:\n", contador);
                printf("ID: %s\n", produtos[i][j].id);
                printf("Nome: %s\n", produtos[i][j].nome);
                printf("Status: %s\n", produtos[i][j].status);
                printf("\n"); 
                contador++; 
            }
        }
    }
    if (contador == 1) {
        printf("Nenhum produto cadastrado.\n");
    }
} // funcao para cadastar um novo produto
void cadastrarProduto() {
    // verifica se a quantidade de produtos excedeu o limite estabelecido.
    if (quantidadeProdutos >= LINHAS * COLUNAS) {
        printf("Limite máximo de produtos atingido!\n");
        return;
    }

    int linha = quantidadeProdutos / COLUNAS;
    int coluna = quantidadeProdutos % COLUNAS;
    // recebe ID do produto
    printf("Digite o ID do produto (6 digitos): ");
    scanf("%6s", produtos[linha][coluna].id);
    getchar(); // Limpar o buffer de entrada
    // recebe nome do produto
    printf("Digite o nome do produto: ");
    scanf("%s", produtos[linha][coluna].nome);
    getchar(); // Limpar o buffer de entrada
    // recebe status do produto
    printf("Digite o status do produto: ");
    fgets(produtos[linha][coluna].status, TAMANHO_STATUS, stdin);
    produtos[linha][coluna].status[strcspn(produtos[linha][coluna].status, "\n")] = 0; // Remover o '\n' do final

    quantidadeProdutos++;
    printf("Produto cadastrado com sucesso!\n");
    printf("Pressione 'enter' para continuar ");
    getchar(); // Limpar o buffer de entrada
    system("clear || cls"); // apaga parte anterior do código na tela
}
// funcao para o sistema
void Sistema()
{
    char nome[TAMANHO_NOME];
    char senha[TAMANHO_SENHA];
    int opcao;
    do
    {
        system("clear || cls"); // apaga parte anterior do código na tela
        // recebe o nome do usuario já criado no sistema
        printf("Digite o nome do usuario: ");
        scanf("%s", nome);
        getchar(); // Limpar o buffer de entrada

        // recebe a senha do usuario já criado no sistema
        printf("Digite a senha do usuario: ");
        scanf("%s", senha);
        getchar(); // Limpar o buffer de entrada
        system("clear || cls"); // apaga parte anterior do código na tela

        // verifico se o nome e senha do usuario são válidos
        for (int i = 0; i < quantidadeUsuarios; i++)
        {
            // uso strcmp para fazer a comparação do nome e senha digitado pelo usuario com os contidos no sistema
            if (strcmp(nome, usuarios[i].nome) == 0 && strcmp(senha, usuarios[i].senha) == 0)
            {
                // Mostra Tela Inicial do Sistema com o Nome e Cargo do usuário que logou
                printf("Bem vindo ao sistema da MDM Eletronica\n");
                printf("Usuario: %s.\n", usuarios[i].nome);
                printf("Cargo: %s.\n\n", usuarios[i].cargo);
                do
                {
                    // Opção para cadastro de produto
                    printf("1.Cadastro Produto\n");
                    // Opção para consulta de produto
                    printf("2.Consultar Produto\n");
                    // Opção para exclusão de produto
                    printf("3.Excluir Produto\n");
                    // Opção para atualização de produto
                    printf("4.Atualizar Produto\n");
                    // Opção para sair do sistema
                    printf("5.Sair\n");
                    printf("Escolha uma opcao: ");
                    scanf("%d", &opcao);
                    getchar(); // Limpar o buffer de entrada
                    // switch case que recebe a opção selecionada pelo usuário logado
                    switch (opcao)
                    {
                    // Opção (1) para cadastro de produto
                    case 1:
                        cadastrarProduto();
                        break;
                    // Opção (2) para consulta de produto
                    case 2:
                        consultarProduto();
                        break;
                    // Opção (3) para excluir um produto
                    case 3:
                        // excluir produto
                        break;
                    // Opção (4) para atualizar um produto
                    case 4:
                        // atualizar produto
                        break;
                    // Opção (5) para sair do sistema
                    case 5:
                        printf("Saindo do Usuario");
                        for (int i = 0; i < 3; i++)
                        {
                            printf(".");
                            fflush(stdout);
                            sleep(1);
                        }
                        system("clear || cls"); // apaga parte anterior do código na tela
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
        // Tela Inicial para o usuário
        printf("\n----------------------------------\n");
        printf("MDM Eletronica - Tela inicial\n");
        // Opção para Cadastro de novo usuário
        printf("1. Cadastro de Usuario\n");
        // Opção para entrar no sistema com um usuário cadastrado
        printf("2. Entrar no Sistema\n");
        // Opção para sair da tela inicial e finalizar a execução do código
        printf("3. Sair\n");
        printf("\n----------------------------------\n");
        // Recebe opção digitada pelo usuário
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada
        system("clear || cls"); // apaga parte anterior do código na tela
         // switch case que recebe a opção selecionada pelo usuário
        switch (opcao)
        {
        // Opção (1) para cadastro de usuário
        case 1:
            cadastrarUsuario();
            break;
        // Opção (2) para acessar o sistema com um usuário cadastrado
        case 2:
            Sistema();
            break;
        // Opção (3) para sair do sistema e finalizar a execução do código
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
            printf("Por favor, selecione uma opcao valida\n");
            printf("Pressione enter para continuar\n");
            getchar(); // Limpar o buffer de entrada
            system("clear || cls"); // apaga parte anterior do código na tela
            break;
        }
        
       

    } while (opcao != 3);
         

    return 0;
}