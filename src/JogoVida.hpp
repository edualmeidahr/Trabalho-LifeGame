#ifndef JOGOVIDA_HPP
#define JOGOVIDA_HPP
#include <iostream>
#include <fstream>


using namespace std;

class JogoVida {
    private:
        int **tabuleiro;
        int **tabuleiroAux;
        int linhas;
        int colunas;
    public:
        JogoVida();
        ~JogoVida();
        void inicializarMundo();
        void imprimeMundo();
        void proximoCiclo();
        int contaVizinhosVivos(int i, int j);
};

#endif