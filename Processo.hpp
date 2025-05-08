#ifndef PROCESSO_HPP
#define PROCESSO_HPP

#include "funcoes.hpp"

class Processo {
private:
    int pid;
    int estado;                 // índice no vetor de estados
    int tempoRestante;
    static vector<string> estadosStr;
public:
    Processo(int pid, int tempo);
    int getPid();
    string getEstado();
    void setEstado(int e);
    int getTempoRestante();
    void executar(int quantum);
};

#endif // PROCESSO_HPP
