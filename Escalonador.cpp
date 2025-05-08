#include "Escalonador.hpp"

Escalonador::Escalonador(int q) {
    tamanho = 0;
    indice = 0;
    quantum = q;
}

bool Escalonador::adicionarProcesso(Processo* p) {
    if (tamanho >= CAPACIDADE) return false;
    int pos = (indice + tamanho) % CAPACIDADE;
    fila[pos] = p;
    tamanho++;
    return true;
}

bool Escalonador::removerProcesso(int pid) {
    if (tamanho == 0) return false;
    int offset = -1;
    for (int i = 0; i < tamanho; ++i) {
        int pos = (indice + i) % CAPACIDADE;
        if (fila[pos]->getPid() == pid) {
            offset = i;
            break;
        }
    }
    if (offset == -1) return false;
    for (int i = offset; i < tamanho - 1; ++i) {
        int from = (indice + i + 1) % CAPACIDADE;
        int to   = (indice + i) % CAPACIDADE;
        fila[to] = fila[from];
    }
    tamanho--;
    if (indice >= tamanho) indice = 0;
    return true;
}

Processo* Escalonador::escolherProximo() {
    if (tamanho == 0) return nullptr;
    Processo* p = fila[indice];
    p->setEstado(1);               // EXECUTANDO
    p->executar(quantum);
    if (p->getTempoRestante() == 0) {
        removerProcesso(p->getPid());
    } else {
        p->setEstado(0);           // PRONTO
        indice = (indice + 1) % tamanho;
    }
    return p;
}
