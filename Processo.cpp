#include "Processo.hpp"

// Inicializa o vetor de estados
vector<string> Processo::estadosStr = {
    "PRONTO",
    "EXECUTANDO",
    "BLOQUEADO",
    "FINALIZADO"
};

Processo::Processo(int pid, int tempo) {
    this->pid = pid;
    this->tempoRestante = tempo;
    this->estado = 0;          // PRONTO
}

int Processo::getPid() {
    return pid;
}

string Processo::getEstado() {
    return estadosStr[estado];
}

void Processo::setEstado(int e) {
    estado = e;
}

int Processo::getTempoRestante() {
    return tempoRestante;
}

void Processo::executar(int quantum) {
    if (tempoRestante <= 0) return;
    int execTime = (quantum < tempoRestante ? quantum : tempoRestante);
    tempoRestante -= execTime;
    if (tempoRestante == 0)
        estado = 3;            // FINALIZADO
    else
        estado = 0;            // PRONTO
}
