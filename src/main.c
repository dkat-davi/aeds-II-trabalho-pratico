#include "../headers/queue.h"
#include "../headers/stack.h"
#include "../headers/list.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void clearTerminal()
{
    // Detecta o sistema operacional e limpa o terminal
#ifdef _WIN32
    system("cls"); // Comando para Windows
#else
    system("clear"); // Comando para Linux/macOS
#endif
}

void exibirMenu()
{
    printf("=========================================\n");
    printf("Escolha uma das opcoes abaixo:\n");

    printf("1. Adicionar clientes à fila\n");
    printf("2. Premiar cliente\n");
    printf("3. Listar clientes na fila\n");

    printf("4. Adicionar prêmios na pilha\n");
    printf("5. Listar prêmios na pilha\n");

    printf("6. Exibir lista de ganhadores\n");
    printf("7. Limpar lista de ganhadores\n");

    printf("\n8. Sair do programa\n");
    printf("=========================================\n");
    printf("Digite sua opcao: ");
}

int main()
{
    int opcao;

    printf("=========================================\n");
    printf("          Sistema de Premiacoes          \n");
    printf("=========================================\n");

    do
    {
        exibirMenu();
        scanf("%d", &opcao);

        clearTerminal();
        printf("\nProcessando...\n");
        sleep(1);
        clearTerminal();

        switch (opcao)
        {
        case 1:
            mainQueue(1);
            clearTerminal();
            break;
        case 2:
            printf("Premiar cliente de qual fila? [gibi | ingresso]\n");
            printf("Cliente [nome do cliente] premiado com o [gibi | ingresso]: [descrição do prêmio] \n");
            break;
        case 3:
            printf("Listar clientes de qual fila? [gibi | ingresso]\n");
            // Exibe a listagem com todos os clientes na fila
            break;
        case 4:
            printf("Inserir em qual pilha? [gibi | ingresso]\n");
            printf("Dados do prêmio?\n");

            printf("Prêmio inserido com sucesso na prilha de [gibi | ingresso] \n");

            break;
        case 5:
            printf("Listar prêmios de qual pilha? [gibi | ingresso]\n");
            // Exibe a listagem com todos os clientes na fila
            break;
        case 6:
            printf("Lista todos os ganhadores com os prêmios que ganharam: \n");
            break;
        case 7:
            printf("Limpa a lista de ganhadores.\n");
            // Implementar função para retirar gibi da pilha.
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}
