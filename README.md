# Trabalho Prático: Listas, Filas e Pilhas

## Resumo

Este trabalho consiste em implementar uma solução para a distribuição de gibis e ingressos de cinema em um shopping center. A solução inclui:

- **Lista Duplamente Encadeada**: Para registrar os ganhadores de prêmios.
- **Filas Estáticas**: Para gerenciar os clientes em espera.
- **Pilhas Dinâmicas**: Para armazenar gibis e ingressos.

A entrega inclui o código-fonte comentado, um relatório detalhado e logs de execução que demonstram o funcionamento correto do sistema.

## Estruturas Utilizadas

### Lista Duplamente Encadeada

- **Função**: Armazenar os nomes dos ganhadores de prêmios.
- **Implementação**: Alocação dinâmica de memória.
- **Operações**:
  - Inserção no início/fim.
  - Remoção.
  - Impressão dos nomes de todos os ganhadores.

### Filas Estáticas

- **Função**: Gerenciar os clientes em espera.
- **Implementação**: Alocação estática de memória.
- **Operações**:
  - Inserção.
  - Remoção.
  - Verificação de estado (vazia/cheia).

### Pilhas Dinâmicas

- **Função**: Armazenar gibis e ingressos.
- **Implementação**: Alocação dinâmica de memória.
- **Operações**:
  - Empilhar (push).
  - Desempilhar (pop).
  - Verificação de estado (vazia).

## Requisitos

1. Registrar ganhadores em uma lista duplamente encadeada.
2. Gerenciar duas filas de clientes de forma independente.
3. Gerenciar duas pilhas (gibis e ingressos) para distribuição de prêmios.
4. Exibir, a qualquer momento, a lista de ganhadores.
5. Executar testes exaustivos para cobrir situações como:
   - Pilha cheia.
   - Fila vazia.
   - Operações simultâneas nas filas e pilhas.

## Organização do Código

O código será dividido em três módulos principais:

1. **Lista**: Implementação da lista duplamente encadeada.
2. **Fila**: Implementação das filas estáticas.
3. **Pilha**: Implementação das pilhas dinâmicas.

## Logs de Execução

Exemplo de log:

```
=======================================================================
Inicio da execucao: programa que implementa lista duplamente encadeada.
=======================================================================
Inicializei a lista de ganhadores.
Inseri ganhador: João
Inseri ganhador: Maria
Lista atual: [João, Maria]
Removi ganhador: João
Lista atual: [Maria]
=======================================================================
Inicio da execucao: programa que implementa filas e pilhas.
=======================================================================
Inicializei as filas de clientes.
Fila de gibis: [Ana, Pedro]
Fila de ingressos: [Lucas, Carla]
Empilhei gibis: Batman, Superman
Empilhei ingressos: Vingadores, Avatar
Distribuí prêmio: Ana ganhou Batman
Distribuí prêmio: Lucas ganhou Vingadores
Filas e pilhas atualizadas.
```

## Relatório

O relatório incluirá:

- Diagrama das estruturas.
- Detalhes de implementação (com ilustrações).
- Análise de desempenho.
- Conclusões e dificuldades encontradas.

## Instruções para Execução

1. Compile o código utilizando um compilador de sua preferência (ex: GCC para C/C++).
2. Execute o programa e siga as instruções no terminal para adicionar clientes, empilhar prêmios e distribuir os prêmios.

## Conclusão

Este trabalho visa explorar conceitos fundamentais de estrutura de dados, proporcionando uma aplicação prática para listas, filas e pilhas. Certifique-se de testar exaustivamente o sistema para garantir seu funcionamento correto em diversas situações.

---

**Autores**:

- [Davi Kalel Andrade Teixeira](https://github.com/dkat-davi)
- [Felipe Monteiro](https://github.com/felipe-monteiro16)
