#include <iostream>
#include "JogoVida.hpp"

using namespace std;

int main() {
    int geracoes;
    cout << "Digite o número de gerações: ";
    cin >> geracoes;

    JogoVida jogoVida;
    jogoVida.inicializarMundo();
    jogoVida.escreverNoArquivo();
    for (int i = 0; i < geracoes; i++){
        jogoVida.proximoCiclo();
        if(jogoVida.getVerificaIgualdade() == true){
            cout << "O mundo não mudou, não há mais gerações possíveis" << endl;
            break;
        }
        jogoVida.escreverNoArquivo();
    }
    
    return 0;
}