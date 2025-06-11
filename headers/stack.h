#ifndef STACK_H
#define STACK_H

// Estrutura para armazenar os dados de um item da pilha
typedef struct
{
    char type[10];         // Tipo do item ("gibi" ou "ingresso")
    char description[100]; // Descrição do item
} StackItem;

// Estrutura para representar um nó na pilha
typedef struct StackNode
{
    StackItem data;         // Dados do item
    struct StackNode *next; // Ponteiro para o próximo nó
} StackNode;

// Estrutura para a pilha
typedef struct
{
    StackNode *top; // Ponteiro para o topo da pilha
} Stack;

// Definição da função que inicializa as pilhas
void initStacks(Stack *gibis, Stack *ingressos);

// Definição da função que insere um dado na pilha
void pushToStack(Stack *stack, const char *type, const char *description);

// Definição da função para selecionar em qual pilha os dados serão inseridos
void selectStackAndCount(int *selectedPilha, int *count);

// Definição da função que irá gerar um loop para inserir vários prêmios na pilha
void insertItemsToStack(Stack *stack, int count, const char *type);

// Definição da função para selecionar de qual pilha irá listar os dados
void selectStackToList(int *selectedStack);

// Definição da função que vai listar os dados da pilha
void listStack(Stack *stack, const char *type);

#endif
