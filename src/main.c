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
    Stack stackGibis, stackIngressos;

    // Inicializando as pilhas
    initStacks(&stackGibis, &stackIngressos);

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
        sleep(0.5);
        clearTerminal();

        switch (opcao)
        {
        case 1:
            mainQueue(1);
            clearTerminal();
            break;
        case 2:
            mainQueue(2);
            break;
        case 3:
            mainQueue(3);
            break;
        case 4:
            // Variáveis que armazenam em qual pilha o usuário vai inserir os prêmios e quantos prêmios ele vai inserir
            int selectedStack, count;

            // Função que vai possibilitar o usuário selecionar a pilha e quantidade de prêmios
            selectStackAndCount(&selectedStack, &count);

            if (selectedStack == 0)
            {
                printf("\n==================== Pilha de gibis ===================\n");
                insertItemsToStack(&stackGibis, count, "gibi");
            }
            else
            {
                printf("\n================== Pilha de ingressos =================\n");
                insertItemsToStack(&stackIngressos, count, "ingresso");
            }

            break;
        case 5:
            printf("Listar prêmios de qual pilha? [gibi | ingresso]\n");
            // Exibe a listagem com todos os clientes na fila
            break;
        case 6:
            mainList(6, NULL, NULL);
            break;
        case 7:
            mainList(7, NULL, NULL);
            break;
        case 8:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 8);

    return 0;
}
