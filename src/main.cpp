#include <iostream>
#include "JogoVida.hpp"

using namespace std;

int main() {
    JogoVida jogoVida;
    jogoVida.inicializarMundo();
    jogoVida.imprimeMundo();
    jogoVida.proximoCiclo();
    cout << endl;
    jogoVida.imprimeMundo();
}