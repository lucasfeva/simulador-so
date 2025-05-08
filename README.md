# Simulador de Sistema Operacional em C++

Este repositório contém um esqueleto de simulador de SO em C++, focado em escalonamento de processos via algoritmo Round Robin. O objetivo é servir como base para trabalhos acadêmicos de Sistemas Operacionais, permitindo fácil extensão para funcionalidades mais avançadas.

---

## 🚀 Funcionalidades Implementadas

- **funcoes.hpp**  
  Arquivo de includes globais e `using namespace std;` para facilitar o uso de bibliotecas padrão.

- **Processo.hpp / Processo.cpp**  
  - Modelo de processo com atributos:
    - `pid`  
    - `estado` (índice em `vector<string> estadosStr`)  
    - `tempoRestante`  
  - Métodos para:
    - `getPid()`, `getEstado()`, `getTempoRestante()`  
    - `setEstado(int)`  
    - `executar(int quantum)`  

- **Escalonador.hpp / Escalonador.cpp**  
  - Implementação única de escalonador Round Robin sem herança:
    - Fila estática (`Processo* fila[CAPACIDADE]`)  
    - Operações:  
      - `adicionarProcesso(Processo*)`  
      - `removerProcesso(int pid)`  
      - `escolherProximo()` (aplica quantum, atualiza estado e remove processos finalizados)  

- **main.cpp**  
  - Exemplo de uso: cria 3 processos, adiciona ao escalonador e roda um loop até conclusão de todos os processos, imprimindo PID, tempo restante e estado a cada ciclo.

---

## 🎯 ToDo

1. **Menu de interação**  
   - Interface de console para o usuário:  
     - Adicionar/remover processos em tempo real  
     - Escolher quantum  
     - Selecionar algoritmo de escalonamento

2. **Geração dinâmica de processos**  
   - Leitura de parâmetros do usuário ou de arquivo (PID, tempo, prioridade, etc.)  

3. **Gerenciador de Memória**  
   - Simulação de alocação contínua ou paginada  
   - Métodos de `alocar()` e `liberar()` blocos de memória para processos

4. **Gerenciamento de Recursos**  
   - Classe `Recurso` e subclasses (CPU, Disco, Impressora, etc.)  
   - Controle de requisição e liberação de recursos por processo  

5. **Simulação de Threads**  
   - Múltiplos threads que representam processos

6. **Suporte a Outros Algoritmos de Escalonamento**  
   - FIFO, Prioridade, SJF.
   - Arquitetura modular para adicionar novas classes de escalonador

