#include "../headers/queue.h"
#include "../headers/stack.h"
#include "../headers/list.h"
#include "../headers/main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void clearTerminal()
{
    // Detecta o sistema operacional e limpa o terminal
#ifdef _WIN32
    system("cls"); // Comando para Windows
#else
    system("clear"); // Comando para Linux/macOS
#endif
}


void pressEnter() {
    printf("\n\nPressione Enter para continuar...");
    while (getchar() != '\n');
    getchar();
    clearTerminal();

}


void exibirMenu()
{
    printf("=======================================================\n");
    printf("                 Sistema de Premiacoes                 \n");
    printf("=======================================================\n");
    printf("Escolha uma das opcoes abaixo:\n");
    printf("1. Adicionar clientes à fila\n");
    printf("2. Premiar cliente\n");
    printf("3. Listar clientes na fila\n");

    printf("4. Adicionar prêmios na pilha\n");
    printf("5. Listar prêmios na pilha\n");

    printf("6. Exibir lista de ganhadores\n");
    printf("7. Limpar lista de ganhadores\n");

    printf("\n8. Sair do programa\n");
    printf("=======================================================\n");
    printf("Digite sua opcao: ");
}

int main()
{
    Stack stackGibis, stackIngressos;
    Queue queueGibis, queueIngressos;
    linkedList* list = NULL;


    // Inicializando as pilhas
    initStacks(&stackGibis, &stackIngressos);

    // Inicializando as filas
    initQueue(&queueGibis);
    initQueue(&queueIngressos);

    // Inicializando a lista
    if (list == NULL) {
        list = createLinkedList();
    }

    int opcao;

    // Loop principal do programa
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
            newCustomer(&queueGibis, &queueIngressos);
            pressEnter();
            break;
        case 2:
            Customer removedCustomer = rewardCustomer(&queueGibis, &queueIngressos);
            if (strcmp(removedCustomer.preference, "gibi") == 0)
                printf("Premiando cliente: %s com o prêmio: %s\n", removedCustomer.name, popFromStack(&stackGibis));
            else if (strcmp(removedCustomer.preference, "ingresso") == 0)
                printf("Premiando cliente: %s com o prêmio: %s\n", removedCustomer.name, popFromStack(&stackIngressos));
            addCustomer(list, removedCustomer.name, removedCustomer.preference);
            pressEnter();
            break;
        case 3:
            showCustomers(&queueGibis, &queueIngressos);
            pressEnter();
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
            pressEnter();
            break;
        case 5:
            // Variável para armazenar a escolha da pilha
            int selectedStackToList;

            // Selecionar de qual pilha listar os dados
            selectStackToList(&selectedStackToList);

            // Listar os dados da pilha correspondente
            if (selectedStackToList == 0)
            {
                listStack(&stackGibis, "Gibi");
            }
            else
            {
                listStack(&stackIngressos, "Ingresso");
            }
            pressEnter();
            break;
        case 6:
            displayWinners(list);
            pressEnter();
            break;
        case 7:
            list = lFreeList(list);
            printf("Lista de ganhadores limpa com sucesso.\n");
            pressEnter();
            break;
        case 8:
            printf("Saindo do programa...\n");
            break;
        default:
            printf("Opcao invalida! Tente novamente.\n");
            pressEnter();
        }
    } while (opcao != 8);

    return 0;
}
