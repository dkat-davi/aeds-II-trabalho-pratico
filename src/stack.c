#include "../headers/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para inicializar duas pilhas: gibis e ingressos
void initStacks(Stack *gibis, Stack *ingressos)
{
    gibis->top = NULL;
    ingressos->top = NULL;

    printf("\nLOG: Pilhas de 'gibis' e 'ingressos' inicializadas com sucesso.\n\n");
}

// Função para selecionar em qual pilha e quantos dados serão inseridos nela
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

// Função que irá gerar um loop para o usuário inserir vários prêmios na pilha
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

// Função para selecionar de qual pilha listar os dados
void selectStackToList(int *selectedStack)
{
    printf("\n================== Selecionar Pilha =================\n");
    printf("[0] Gibis\n");
    printf("[1] Ingressos\n");
    printf("Sua escolha: ");
    scanf("%d", selectedStack);

    // Validar o input do usuário
    while (*selectedStack < 0 || *selectedStack > 1)
    {
        printf("Opção inválida! Escolha [0] Gibis ou [1] Ingressos: ");
        scanf("%d", selectedStack);
    }
}

// Função que lista os dados da pilha
void listStack(Stack *stack, const char *type)
{
    if (stack->top == NULL)
    {
        printf("\nA pilha de %s está vazia!\n", type);
        printf("\n=======================================================\n\n");
        return;
    }

    printf("\n=========== Lista de Prêmios na Pilha de %s ===========\n", type);

    StackNode *current = stack->top;
    while (current != NULL)
    {
        printf("%s: %s\n", type, current->data.description);
        current = current->next;
    }

    printf("\nFim da listagem.\n");

    printf("\n=======================================================\n\n");
}

// Função para verificar se a pilha contém prêmios
int isStackEmpty(const Stack *stack)
{
    return (stack->top == NULL);
}

// Função para remover um prêmio do topo da pilha e retornar sua descrição
char *popFromStack(Stack *stack)
{
    if (stack->top == NULL)
    {
        printf("\nA pilha está vazia! Nenhum prêmio para remover.\n");
        return NULL;
    }

    // Armazena o nó do topo
    StackNode *temp = stack->top;

    // Copia a descrição do prêmio para uma string dinâmica
    char *removedDescription = malloc(strlen(temp->data.description) + 1);
    if (removedDescription == NULL)
    {
        printf("Erro ao alocar memória para a descrição removida.\n");
        return NULL;
    }
    strcpy(removedDescription, temp->data.description);

    // Atualiza o topo para o próximo nó
    stack->top = stack->top->next;

    // Libera a memória do nó removido
    free(temp);

    printf("\nPrêmio removido com sucesso!\n");
    return removedDescription;
}