#include "funcoes.hpp"
#include "Processo.hpp"
#include "Escalonador.hpp"

int main() {
    // ToDo: implementar um menu interativo para o usuário escolher o algoritmo de escalonamento
    Escalonador escalonador(2);

    Processo p1(1, 5);
    Processo p2(2, 3);
    Processo p3(3, 7);

    escalonador.adicionarProcesso(&p1);
    escalonador.adicionarProcesso(&p2);
    escalonador.adicionarProcesso(&p3);

    cout << "Iniciando simulacao Round Robin (quantum = 2)\n\n";

    Processo* atual = nullptr;
    while ((atual = escalonador.escolherProximo()) != nullptr) {
        cout << "Processo " << atual->getPid()
             << " | Tempo Restante: " << atual->getTempoRestante()
             << " | Estado: " << atual->getEstado() << "\n";
    }

    cout << "\nTodos os processos foram finalizados.\n";
    
    return 0;
}
 