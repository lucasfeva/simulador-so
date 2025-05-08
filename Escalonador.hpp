#ifndef ESCALONADOR_HPP
#define ESCALONADOR_HPP

#include "funcoes.hpp"
#include "Processo.hpp"

class Escalonador {
private:
    static const int CAPACIDADE = 128;
    Processo* fila[CAPACIDADE];
    int tamanho;
    int indice;
    int quantum;
public:
    Escalonador(int quantum = 1);
    bool adicionarProcesso(Processo* p);
    bool removerProcesso(int pid);
    Processo* escolherProximo();
};

#endif // ESCALONADOR_HPP
