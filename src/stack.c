#include "../headers/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para inicializar duas pilhas: gibis e ingressos
void initStacks(Stack *gibis, Stack *ingressos)
{
    gibis->top = NULL;
    ingressos->top = NULL;

    printf("\nPilhas de 'gibis' e 'ingressos' inicializadas com sucesso.\n\n");
}

void selectStackAndCount(int *selectedStack, int *count)
{
    printf("\n===== Em qual pilha desejar adicionar os prêmios? =====\n");
    printf("[0] Gibis\n");
    printf("[1] Ingressos\n\n");
    printf("Sua escolha: ");
    scanf("%d", selectedStack);

    // Validação da escolha
    while (*selectedStack != 0 && *selectedStack != 1)
    {
        printf("\nOpção inválida! Tente novamente.\n");
        printf("[0] Gibis\n");
        printf("[1] Ingressos\n\n");
        printf("Sua escolha: ");
        scanf("%d", selectedStack);
    }

    printf("=======================================================\n");

    printf("\n=========== Quantos prêmios deseja inserir? ===========\n");
    printf("Digite a quantidade: ");
    scanf("%d", count);

    // Validação do número de prêmios
    while (*count <= 0)
    {
        printf("\nQuantidade inválida. Insira um valor maior que 0.\n");
        printf("\n=========== Quantos prêmios deseja inserir? ===========\n");
        printf("Digite a quantidade: ");
        scanf("%d", count);
    }

    printf("=======================================================\n");
}

// Função para inserir um item na pilha
void pushToStack(Stack *stack, const char *type, const char *description)
{
    // Alocar memória para o novo nó
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    if (!newNode)
    {
        printf("Erro ao alocar memória para o novo prêmio.\n");
        return;
    }

    // Configurar os dados do novo nó
    strncpy(newNode->data.type, type, sizeof(newNode->data.type) - 1);
    newNode->data.type[sizeof(newNode->data.type) - 1] = '\0';
    strncpy(newNode->data.description, description, sizeof(newNode->data.description) - 1);
    newNode->data.description[sizeof(newNode->data.description) - 1] = '\0';

    // Inserir o nó no topo da pilha
    newNode->next = stack->top;
    stack->top = newNode;
}

void insertItemsToStack(Stack *stack, int count, const char *type)
{
    for (int i = 0; i < count; i++)
    {
        char description[50];

        // Exibir o número do item que está sendo inserido
        printf("\nInserindo %s %d de %d:\n", type, i + 1, count);

        // Solicitar a descrição do prêmio
        printf("Descrição: ");
        scanf(" %[^\n]", description); // Lê a linha completa do input

        // Criar o dado do prêmio
        StackItem data;
        strncpy(data.type, type, sizeof(data.type) - 1);
        data.type[sizeof(data.type) - 1] = '\0';
        strncpy(data.description, description, sizeof(data.description) - 1);
        data.description[sizeof(data.description) - 1] = '\0';

        // Inserir na pilha
        pushToStack(stack, data.type, data.description);
    }

    // Mensagem de sucesso após a inserção de todos os prêmios
    printf("\nPrêmios inseridos com sucesso na pilha de %s!\n", type);

    printf("=======================================================\n\n");
}