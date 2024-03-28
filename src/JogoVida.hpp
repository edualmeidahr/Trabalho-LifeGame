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
        bool verificaIgualdade = true; 
        public:
            JogoVida();
            ~JogoVida();
            bool getVerificaIgualdade();
            void inicializarMundo();
            void imprimeMundo();
            void escreverNoArquivo();
            void proximoCiclo();
            int contaVizinhosVivos(int i, int j);
};

#endif