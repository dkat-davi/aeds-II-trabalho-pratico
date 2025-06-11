# Relatório do Trabalho Prático: Listas, Filas e Pilhas

---

## Introdução

Este trabalho prático teve como objetivo implementar e explorar estruturas de dados fundamentais: listas ligadas, filas e pilhas. O sistema desenvolvido permite ao usuário interagir por meio de um menu para manipular essas estruturas, incluindo inserção, remoção, listagem e gerenciamento de dados associados a clientes e prêmios.

---

## Estrutura do Projeto

O projeto está organizado em duas pastas principais:

- `/headers` — Contém os arquivos header (`.h`) com as definições das funções e estruturas para cada tipo de dado (lista, fila e pilha).
- `/src` — Contém o código-fonte principal, incluindo a lógica das estruturas e o arquivo `main.c` que coordena a execução e interação do usuário.

### Organização dos Arquivos

| Arquivo   | Função                                                                |
| --------- | --------------------------------------------------------------------- |
| `list.h`  | Definição da lista ligada e suas operações                            |
| `queue.h` | Definição do menu e operações da fila                                 |
| `stack.h` | Definição da pilha, itens e operações associadas                      |
| `main.c`  | Controle do fluxo do programa, exibição do menu e chamadas principais |

---

## Detalhamento das Estruturas de Dados

### Lista Ligada (`list.h`)

- Estrutura do tipo `linkedList`.
- Suporte para:
  - Criação da lista.
  - Inserção no início e no fim.
  - Remoção de elementos pelo nome.
  - Busca por elemento.
  - Exibição da lista completa.
  - Liberação da memória.
- Função central `mainList` para orquestrar operações.

### Fila (`queue.h`)

- Interface básica para manipulação da fila.
- Função `mainQueue` que controla as operações de inserção, remoção e listagem da fila de clientes.

### Pilha (`stack.h`)

- Implementação com nós encadeados (`StackNode`).
- Dois tipos de pilha:
  - Pilha de gibis.
  - Pilha de ingressos.
- Estrutura para armazenar o tipo e descrição do item.
- Funções para:
  - Inicializar pilhas.
  - Inserir itens.
  - Selecionar pilha e quantidade para inserção.
  - Listar itens da pilha.
  - Remover itens (desempilhar).
  - Validar se a pilha está vazia.

---

## Fluxo do Programa (`main.c`)

- Exibição do menu de opções para o usuário.
- Uso de `switch` para tratar as opções escolhidas.
- Chamada das funções principais para filas, listas e pilhas.
- Limpeza do terminal e pausas para melhor experiência visual.
- Implementação para permitir inserção de clientes na fila, premiação, listagem, gerenciamento de pilhas de prêmios, e exibição e limpeza da lista de ganhadores.

---

## Logs de Execução Exemplo

[Neste link](logs.md) é possível vizualizar alguns logs gerados durante a execução do sistema.

Este tipo de log detalhado foi utilizado para testar todas as funcionalidades de inserção, remoção, e casos de erro, garantindo que o sistema responde corretamente às operações.

---

## Resultados Obtidos

- Implementação funcional e testada de:
  - Lista ligada com inserção, remoção e busca.
  - Fila de clientes com inserção e remoção.
  - Pilhas com tipos diferenciados para gerenciamento de prêmios.
- Interface de usuário via terminal que permite manipulação fácil das estruturas.
- Separação clara de responsabilidades entre arquivos e funções, facilitando manutenção e extensão futura.

---

## Conclusão

Este trabalho prático permitiu aplicar conceitos teóricos de estruturas de dados em um programa funcional e interativo. A divisão modular do código, uso de estruturas dinâmicas, e implementação dos métodos garantem um sistema robusto para gerenciamento de clientes e prêmios.

Recomenda-se testar exaustivamente o sistema em diferentes cenários para assegurar a integridade e corretude das operações.

---

## Autores

- [Davi Kalel Andrade Teixeira](https://github.com/dkat-davi)
- [Felipe Monteiro](https://github.com/felipe-monteiro16)
