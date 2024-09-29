/**
 * @version 1.0
 * @date 19/09/2024
 * @author Mateus Santos de jesus
 * @author David Santos Pereira
 * @author Marcos vinícius Santos Reis
 */
#include <stdio.h>  // biblioteca Entrada e Saída PADRÃO
#include <stdlib.h> // biblioteca Alocar memória
#include <string.h> // biblioteca manipular Strings
#include <unistd.h> // biblioteca controle de tempo(sleep)

// define tamanho das constantes
#define MAX_USUARIOS 10   /**< Define o máximo de usuarios */
#define TAMANHO_NOME 30   /**<Define o tamanho do nome */
#define TAMANHO_SENHA 5   /**< Define o tamanho máximo da senha */
#define LINHAS 5          /**<Define tamanho das linhas */
#define COLUNAS 3         /**< Define o tamanho das colunas */
#define TAMANHO_ID 7      /**< Define o tamanho máximo do id */
#define TAMANHO_STATUS 20 /**< Define o tamanho máximo do status */

// senha para cadastro de novos usuários
const char SENHA_CADASTRO[] = "2025";
/**
 * @struct Produto
 * @brief Armazena informações sobre um produto*/
typedef struct
{
    char id[TAMANHO_ID];         /**<Id do produto. */
    char nome[TAMANHO_NOME];     /**<Nome do produto. */
    char status[TAMANHO_STATUS]; /**<Status do produto. */
} Produto;

/**
 * @struct Usuario
 * @brief Armazena informações sobre um usuário
 */
typedef struct
{
    char nome[TAMANHO_NOME];   /**<Nome do usuario. */
    char cargo[TAMANHO_NOME];  /**<Cargo do usuario. */
    char senha[TAMANHO_SENHA]; /**<Senha do usuario. */
} Usuario;

// cria um array para armazena os produtos
Produto produtos[LINHAS][COLUNAS]; // matriz produtos
int quantidadeProdutos = 0;        // contador qtd produtos

// cria um array para armazena os usuarios
Usuario usuarios[MAX_USUARIOS];
int quantidadeUsuarios = 0; // contador qtd usuario

/**
 * @brief funcao para cadastar um novo usuario
 *  */
void cadastrarUsuario()
{
    // senha de cadastro
    char senha[TAMANHO_SENHA];
    // armazena a opção selecionada
    int opcao = 0;
    do // laço do while para continuidade da funcao cadastrarUsuario
    {
        // recebe senha de cadastro
        printf("\nDigite a senha de cadastro: ");
        scanf("%s", senha);
        getchar();

        // verifica se a senha esta incorreta com strcmp
        if (strcmp(senha, SENHA_CADASTRO) != 0)
        {
            // recebe opção do usuario
            printf("Senha incorreta!\n");
            printf("1 - Tentar novamente\n");
            printf("2 - Retornar ao menu anterior\n");
            printf("Porfavor, selecione uma das opcoes acima: ");
            scanf("%d", &opcao);
            system("cls || clear");
            getchar();
            // switch case para receber opcao do usuario
            switch (opcao)
            {
            case 1:
                continue; // Recomeca o loop
                break;
            case 2:
                return; // retorna ao menu anterior
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                printf("Pressione enter para continuar...");
                getchar();
                system("cls || clear");
                continue;
                break;
            }
        }
    } while (strcmp(senha, SENHA_CADASTRO) != 0); // verificação para o laço continuar com strcmp se a senha de cadastro ainda for incorreta

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
    do
    {
        printf("Digite o cargo do usuario (Admin ou Vendedor): ");
        scanf("%s", usuarios[quantidadeUsuarios].cargo);
        getchar();
        // verifica se cargo eh invalido e diz pra digitar novamente
        if (strcasecmp(usuarios[quantidadeUsuarios].cargo, "Admin") != 0 && strcasecmp(usuarios[quantidadeUsuarios].cargo, "Vendedor") != 0)
        {
            printf("CARGO INVALIDO! Digite Admin ou Vendedor\n");
        }
    } while (strcasecmp(usuarios[quantidadeUsuarios].cargo, "Admin") != 0 && strcasecmp(usuarios[quantidadeUsuarios].cargo, "Vendedor") != 0);

    char senha_usuario[TAMANHO_SENHA];
    do
    {
        // recebe a senha do usuario
        printf("Digite a senha (maximo 4 digitos): "); // recebe a senha do usuario
        scanf("%s", senha_usuario);
        // remove o caractere de nova linha se estiver presente
        senha_usuario[strcspn(senha_usuario, "\n")] = '\0';

        // verifica se a senha ultrapassa o limite estabelecido
        if (strlen(senha_usuario) > 4)
        {
            printf("Erro a senha tem mais de 4 digitos.\n");
            printf("Pressione enter para continuar...");
            getchar();
            getchar();
            system("cls || clear");
        }
        else
        { // verifica se a quantidade usuarios ainda não excedeu o limite máximo
            if (quantidadeUsuarios < MAX_USUARIOS)
            {
                strncpy(usuarios[quantidadeUsuarios].senha, senha_usuario, TAMANHO_SENHA);
                usuarios[quantidadeUsuarios].senha[TAMANHO_SENHA - 1] = '\0'; // Garante que a string estah terminada
                quantidadeUsuarios++;                                         // incrementa a variavel em 1
                printf("Usuario cadastrado com sucesso!\n");                  // exibe mensagem de sucesso.
                printf("Pressione 'enter' para continuar...");
                getchar();
                system("cls || clear"); // limpa a tela
            }
            else
            {
                printf("numero maximo de usuarios atingido");
            }
        }
    } while (strlen(senha_usuario) > 4); // repete o loop enquanto a senha digitada for maior que 4
}

/**
 * @brief funcao retorna uma lista com todos os produtos  */
void relatorioProduto()
{
    int contador = 1;

    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            if (strlen(produtos[i][j].id) > 0)
            {
                printf("\n\nProduto %d:\n", contador);
                printf("ID: %s\n", produtos[i][j].id);
                printf("Nome: %s\n", produtos[i][j].nome);
                printf("Status: %s\n", produtos[i][j].status);
                printf("\n");
                contador++;
            }
        }
    }
    if (contador == 1)
    {
        printf("Nenhum produto cadastrado.\n");
        printf("Pressione 'enter' para continuar...");
        getchar();
        system("cls || clear"); // limpa a tela
    }
}
/**
 * @brief  função para cadastrar os produtos*/
void cadastrarProduto()
{
    // verifica se o limite de produtos foi atingido
    if (quantidadeProdutos >= LINHAS * COLUNAS)
    {
        printf("Limite máximo de produtos atingido!\n");
        return;
    }

    int linha = quantidadeProdutos / COLUNAS;
    int coluna = quantidadeProdutos % COLUNAS;
    while (1)
    {
        char id_digitado[100];
        // recebe ID do produto
        printf("Digite o ID do produto (OBS: o id precisa ter 6 digitos): ");
        scanf("%s", id_digitado);
        getchar();
        // verifica se o id digitado possui 6 digitos
        if (strlen(id_digitado) != 6)
        {
            printf("ID invalido!O ID precisa ter 6 digitos. Pressione Enter para tentar novamente...");
            getchar();
            system("cls || clear");
            continue; // volta ao inicio do loop para solicitar a entrada novamente
        }
        else
        {
            // copia o id digitado para o array de produtos se o id estiver correto
            strcpy(produtos[linha][coluna].id, id_digitado);
            break; // interrompe o loop
        }
    }

    do
    {
        // recebe nome do produto
        printf("Digite o nome do produto: ");
        fgets(produtos[linha][coluna].nome, TAMANHO_NOME, stdin);

        produtos[linha][coluna].nome[strcspn(produtos[linha][coluna].nome, "\n")] = 0; // Remover o '\n' do final
        // verifica se o nome eh nulo
        if (strcmp(produtos[linha][coluna].nome, "") == 0)
        {
            printf("Nome do produto nao pode ser nulo! Digite um nome valido\n");
        }

    } while (strcmp(produtos[linha][coluna].nome, "") == 0); // se o nome estive fazio o loop é repetido

    do
    {
        // recebe status do produto
        printf("Digite o status do produto (OBS: Status deve ser Ativo ou Pendente): ");
        fgets(produtos[linha][coluna].status, TAMANHO_STATUS, stdin);
        produtos[linha][coluna].status[strcspn(produtos[linha][coluna].status, "\n")] = 0; // Remover o '\n' do final
        // verifica se o status eh valido
        if (strcasecmp(produtos[linha][coluna].status, "Ativo") != 0 && strcasecmp(produtos[linha][coluna].status, "Pendente") != 0)
        {
            printf("Status Invalido! Digite Ativo ou Pendente\n");
        }
    } while (strcasecmp(produtos[linha][coluna].status, "Ativo") != 0 && strcasecmp(produtos[linha][coluna].status, "Pendente") != 0);

    // aumenta qtd de produtos
    quantidadeProdutos++;
    printf("\nProduto cadastrado com sucesso!\n");
    printf("Pressione 'enter' para continuar...");
    getchar();
    system("cls || clear");
}
/**
 * @brief  função para fazer a exclusão de produtos
 * */
void excluirProduto()
{
    char id_excluir[TAMANHO_ID];
    // recebe o ID do produto que será excluido
    printf("Digite o ID do produto que deseja excluir: ");
    scanf("%s", id_excluir);
    getchar();
    // encontra o ID correspondente na matriz
    int encontrar_id = 0;
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            // com o id encontrado, realiza a exclusão
            if (strcmp(produtos[i][j].id, id_excluir) == 0)
            {
                printf("Excluindo produto");
                for (int i = 0; i < 3; i++)
                {
                    printf(".");
                    fflush(stdout);
                    sleep(1);
                }
                // limpa os valores que o id tinha armazenado no array
                encontrar_id = 1;
                produtos[i][j].id[0] = '\0';
                produtos[i][j].nome[0] = '\0';
                produtos[i][j].status[0] = '\0';
                quantidadeProdutos--;
                printf("Produto excluído!\n");
                system("cls || clear");
            }
        }
    }
    // caso não seja encontrado o id
    if (!encontrar_id)
    {
        int opcao;
        printf("Produto nao encontrado no sistema!\n\n");
        do
        {
            printf("1 - Tentar novamente\n");
            printf("2 - Voltar ao menu anterior\n");
            printf("Selecione uma das opcoes acima: ");
            scanf("%d", &opcao);
            getchar();
            system("cls || clear");
            switch (opcao)
            {
            case 1:
                excluirProduto();
                break;
            case 2:
                Sistema();
                break;
            default:
                printf("Porfavor selecione uma opcao valida\n");
                printf("Pressione enter para continuar...");
                getchar();
                system("cls || clear");
                break;
            }
        }

        while ((opcao != 1) || (opcao != 2)); // se as opções forem diferentes de 1 ou 2 o loop é repetido
    }
}
/**
 * @brief  função para atualizar os produtos existentes no sistema*/
void atualizarProduto()
{
    char id_atualizar[TAMANHO_ID];
    // recebe o ID do produto que será atualizado
    printf("Digite o ID do produto que deseja atualizar: ");
    scanf("%s", id_atualizar);
    getchar();
    // encontra o ID correspondente na matriz
    int encontrar_id = 0;
    int linha, coluna;
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            // com o id encontrado, realiza a atualização dos seus indices
            if (strcmp(produtos[i][j].id, id_atualizar) == 0)
            {
                printf("Procurando produto");
                for (int i = 0; i < 2; i++)
                {
                    printf(".");
                    fflush(stdout);
                    sleep(1);
                }
                printf("\nProduto encontrado");
                linha = i;
                coluna = j;
                encontrar_id = 1;
                while (1)
                {
                    char id_digitado[100];
                    // recebe novo id do produto
                    printf("\nDigite o novo ID do produto (6 digitos): ");
                    fgets(id_digitado, sizeof(id_digitado), stdin);
                    id_digitado[strcspn(id_digitado, "\n")] = 0;
                    // verifica se p novo id do produto esta correto
                    if (strlen(id_digitado) != 6)
                    {
                        printf("ID invalido!Digite um ID com 6 digitos. Pressione Enter para continuar...");
                        getchar();
                        system("cls || clear");
                        continue; // volta ao inicio do loop para solicitar a entrada novamente
                    }
                    else
                    {
                        // copia o id digitado para o array de produtos
                        strcpy(produtos[i][j].id, id_digitado);
                        break; // interrompe o loop
                    }
                }
                do
                {
                    // recebe novo nome do produto
                    printf("Digite o nome do produto: ");
                    fgets(produtos[linha][coluna].nome, TAMANHO_NOME, stdin);

                    produtos[linha][coluna].nome[strcspn(produtos[linha][coluna].nome, "\n")] = 0; // Remover o '\n' do final
                    // verifica se o nome eh nulo
                    if (strcmp(produtos[linha][coluna].nome, "") == 0)
                    {
                        printf("Nome do produto nao pode ser nulo! Digite um nome valido\n");
                    }

                } while (strcmp(produtos[linha][coluna].nome, "") == 0); // se o nome estive fazio o loop é repetido

                do
                {
                    // recebe novo status do produto
                    printf("Digite o status do produto (OBS: Status deve ser Ativo ou Pendente): ");
                    fgets(produtos[linha][coluna].status, TAMANHO_STATUS, stdin);
                    produtos[linha][coluna].status[strcspn(produtos[linha][coluna].status, "\n")] = 0; // Remover o '\n' do final
                    // verifica se o status eh valido
                    if (strcasecmp(produtos[linha][coluna].status, "Ativo") != 0 && strcasecmp(produtos[linha][coluna].status, "Pendente") != 0)
                    {
                        printf("Status Invalido! Digite Ativo ou Pendente\n");
                    }
                } while (strcasecmp(produtos[linha][coluna].status, "Ativo") != 0 && strcasecmp(produtos[linha][coluna].status, "Pendente") != 0);

                printf("\nProduto atualizado com sucesso!\n");
                printf("Pressione 'enter' para continuar...");
                getchar();
                system("cls || clear");
            }
        }
    }
    // caso não seja encontrado o produto, retorna para o inicio da função
    if (!encontrar_id)
    {
        int opcao;
        do
        {
            printf("Produto nao encontrado no sistema!\n\n");
            printf("1 - Tentar novamente\n");
            printf("2 - Voltar ao menu anterior\n");
            printf("Selecione uma das opcoes acima: ");
            scanf("%d", &opcao);
            getchar();
            system("cls || clear");

            switch (opcao)
            {
            case 1:
                atualizarProduto();
                break;
            case 2:
                Sistema();
                break;
            default:
                printf("Porfavor selecione uma opcao valida.\n");
                printf("Pressione enter para continuar...");
                system("cls || clear");
                getchar();
                continue;
                break;
            }
        } while ((opcao != 1) || (opcao != 2));
    }
}
/**
 * @brief função para consultar os IDs de produto contidos no sistema */
void consultaId()
{
    char id_consulta[TAMANHO_ID];
    // recebe o ID do produto que será encontrado
    printf("Digite o ID para consulta de produto: ");
    scanf("%s", id_consulta);
    getchar();
    // encontra o ID correspondente na matriz
    int encontrar_id = 0;
    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            // com o id encontrado, realiza a consulta dos seus indices
            if (strcmp(produtos[i][j].id, id_consulta) == 0)
            {

                printf("\nProduto encontrado\n");
                printf("ID: %s\n", produtos[i][j].id);
                printf("Nome: %s\n", produtos[i][j].nome);
                printf("Status: %s\n", produtos[i][j].status);
                printf("\n");
                encontrar_id = 1;
                printf("Produto encontrado com sucesso!\n");
                printf("Pressione 'enter' para continuar... ");
                getchar();
                system("cls || clear");
                break;
            }
        }
    }
    // caso não seja encontrado o produto, retorna para o inicio da função
    if (!encontrar_id)
    {
        int opcao;
        printf("Produto nao encontrado no sistema!\n\n");
        do
        {
            printf("1 - Tentar novamente\n");
            printf("2 - Voltar ao menu anterior\n");
            printf("Selecione uma das opcoes acima: ");
            scanf("%d", &opcao);
            getchar();
            system("cls || clear");

            switch (opcao)
            {
            case 1:
                consultaId();
                break;
            case 2:
                Sistema(); // volta a menu de sistema
                break;
            default:
                printf("Porfavor selecione uma opcao valida\n");
                printf("Pressione Enter para continuar...");
                getchar();
                system("cls || clear");
                break;
            }
        } while ((opcao != 1) || (opcao != 2));
    }
}
/**
 * @brief  função para entrar no sistema da MDM Eletrônica */
void Sistema()
{
    char nome[TAMANHO_NOME];
    char senha[TAMANHO_SENHA];
    // armazena a opção a ser selecionada
    int opcao;
    char cargo[TAMANHO_NOME];
    do // do while para continuidade da execução do código principal
    {
        system("cls || clear");
        // recebe o nome do usuario já criado no sistema
        printf("Digite o nome do usuario: ");
        scanf("%s", nome);
        getchar();

        // recebe a senha do usuario já criado no sistema
        printf("Digite a senha do usuario: ");
        scanf("%s", senha);
        getchar();
        system("cls || clear");

        // verifico se o nome e senha do usuario são válidos
        int usuarioEncontrado = 0;
        for (int i = 0; i < quantidadeUsuarios; i++)
        {
            // uso strcasecmp para fazer a comparação do nome e  strcmp para senha digitado pelo usuario com os contidos no sistema
            if (strcasecmp(nome, usuarios[i].nome) == 0 && strcmp(senha, usuarios[i].senha) == 0)
            {
                strcpy(cargo, usuarios[i].cargo);
                printf("Bem vindo ao sistema da MDM Eletronica\n");
                printf("Usuario: %s.\n", usuarios[i].nome);
                printf("Cargo: %s.\n\n", usuarios[i].cargo);
                usuarioEncontrado = 1;
                do
                {
                    // if para caso o cargo seja "Admin"
                    if (strcasecmp(cargo, "Admin") == 0)
                    {
                        printf("1.Cadastro Produto\n");
                        printf("2.Relatorio de Produtos\n");
                        printf("3.Consultar Produto\n");
                        printf("4.Atualizar Produto\n");
                        printf("5.Excluir Produto\n");
                        printf("6.Sair\n");
                        printf("Escolha uma opcao: ");
                    }
                    // else if para caso o cargo seja "Vendedor"
                    else if (strcasecmp(cargo, "Vendedor") == 0)
                    {
                        printf("1.Consultar Produto\n");
                        printf("2.Relatorio dos Produtos\n");
                        printf("3.Sair\n");
                        printf("Escolha uma opcao: ");
                    }
                    // recebe opção que o usuario digita
                    scanf("%d", &opcao);
                    getchar();
                    // If para entrar no switch case do cargo Admin
                    if (strcasecmp(cargo, "Admin") == 0)
                    {
                        switch (opcao)
                        {
                        case 1:
                            cadastrarProduto(); // vai para função de cadastro de produtos
                            break;
                        case 2:
                            relatorioProduto();
                            break;
                        case 3:
                            consultaId(); // vai para função de consulta de produtos
                            break;
                        case 4:
                            atualizarProduto(); // vai para função de atualização de produtos
                            break;
                        case 5:
                            excluirProduto(); // vai para função de exclusão de produtos
                            break;
                        case 6: // sai do usuário Admin e volta para menu inicial
                            system("cls || clear");
                            main(); // volta ao menu inicial
                            break;
                        default:
                            printf("Digite uma opção valida.\n");
                        }
                    }
                    // else if para entrar no switch case do cargo Vendedor
                    else if (strcasecmp(cargo, "Vendedor") == 0)
                    {
                        switch (opcao)
                        {
                        case 1:
                            consultaId(); // vai para função de consulta de produtos
                            break;
                        case 2:
                            relatorioProduto(); // vai para função de relatorio que retorna todos os produtos no sistema
                            break;
                        case 3: // sai do usuário Vendedor e volta para menu inicial
                            printf("Saindo do Usuario Vendedor");
                            for (int i = 0; i < 3; i++)
                            {
                                printf(".");
                                fflush(stdout);
                                sleep(1);
                            }
                            system("cls || clear");
                            break;
                        default:
                            printf("Digite uma opção valida.\n");
                        }
                    }
                    // while que continua enquanto as opçoes de "sair" de ambos os carros não ter sido digitada
                } while ((strcasecmp(cargo, "Admin") == 0 && opcao != 5) || (strcasecmp(cargo, "Vendedor") == 0 && opcao != 3));

                return;
            }
        }
        // caso o usuario nao tenha sido encontrado
        if (!usuarioEncontrado)
        {
            printf("Erro!!! Usuario inexistente");
            for (int i = 0; i < 3; i++)
            {
                printf(".");
                fflush(stdout);
                sleep(1);
            }
            system("cls || clear");
            return;
        }

    } while (1);
}

// funcao principal do código
int main()
{
    int opcao;

    do // do while para continuidade da tela inicial do sistema
    {

        printf("\n----------------------------------\n");
        printf("MDM Eletronica - Tela inicial\n");
        printf("1. Cadastro de Usuario\n");
        printf("2. Entrar no Sistema\n");
        printf("3. Sair");
        printf("\n----------------------------------\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar();
        system("cls || clear");
        // switch case para receber opção do usuario
        switch (opcao)
        {
        case 1:
            cadastrarUsuario(); // vai para função de cadastro de usuarios
            break;
        case 2:
            Sistema(); // vai para função principal do usuario
            break;
        case 3: // sai do sistema e encerra o programa
            printf("Saindo do Sistema");
            for (int i = 0; i < 3; i++)
            {
                printf(".");
                fflush(stdout);
                sleep(1);
            }
            exit(1); // encerrar o programa
            break;
        default: // caso não seja digitada nenhuma opção válida
            printf("Porfavor, selecione uma opcao valida\n");
            printf("Pressione enter para continuar...");
            getchar();
            system("cls || clear");
            break;
        }

    } while (opcao != 3); // o codigo se repete enquanto a opção 3 "sair" não ter sido escolhida

    return 0; // return 0 para encerramento do codigo main
}
