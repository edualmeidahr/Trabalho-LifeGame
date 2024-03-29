#include "JogoVida.hpp"

using namespace std;

JogoVida::JogoVida()
{
    ifstream inFile;
    inFile.open("datasets/input.mps");

    if (!inFile)
    {
        cerr << "Não foi possível abrir o arquivo" << endl;
        exit(1);
    }
    inFile >> linhas;
    colunas = linhas;
    inFile.close();
    tabuleiro = (int **)malloc(linhas * sizeof(int *));
    tabuleiroAux = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++)
    {
        tabuleiro[i] = (int *)malloc(colunas * sizeof(int));
        tabuleiroAux[i] = (int *)malloc(colunas * sizeof(int));
    }
}

JogoVida::~JogoVida()
{
    for (int i = 0; i < linhas; i++)
    {
        free(tabuleiro[i]);
        free(tabuleiroAux[i]);
    }
    free(tabuleiro);
    free(tabuleiroAux);
}

void JogoVida::inicializarMundo()
{
    ifstream inFile;
    inFile.open("datasets/input.mps");

    if (!inFile)
    {
        cerr << "Não foi possível abrir o arquivo" << endl;
        exit(1);
    }
    inFile >> linhas;
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            inFile >> tabuleiro[i][j];
        }
    }
}

void JogoVida::imprimeMundo()
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            cout << tabuleiro[i][j] << " ";
        }
        cout << endl;
    }
}

int JogoVida::contaVizinhosVivos(int linhas, int colunas)
{
    int vizinhosVivos = 0;
    // Usar o this->linhas para acessar o atributo linhas da classe e o mesmo para coluna

    // Arrays para verificar as células vizinhas
    int arrayX[] = {-1, -1, -1, 0, 0, +1, +1, +1};
    int arrayY[] = {-1, 0, +1, -1, +1, -1, 0, +1};

    // Percorrer as células vizinhas
    for (int i = 0; i < 8; i++)
    {
        int x = linhas + arrayX[i];
        int y = colunas + arrayY[i];
        // Verificar se a célula vizinha está dentro dos limites do tabuleiro
        if (x >= 0 && x < this->linhas && y >= 0 && y < this->colunas)
        {
            // Verificar se a célula vizinha está viva
            if (tabuleiro[x][y] == 1)
            {
                vizinhosVivos++;
            }
        }
    }
    return vizinhosVivos;
}

void JogoVida::proximoCiclo()
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            int vizinhosVivos = contaVizinhosVivos(i, j);
            if (tabuleiro[i][j] == 1)
            {
                if (vizinhosVivos < 2 || vizinhosVivos > 3)
                {
                    tabuleiroAux[i][j] = 0;
                }
                else if(vizinhosVivos == 2 || vizinhosVivos ==3){
                    tabuleiroAux[i][j] = 1;
                }
            }
            else
            {
                if (vizinhosVivos == 3)
                {
                    tabuleiroAux[i][j] = 1;
                }
            }
        }
    }
    // Atualiza o tabuleiro
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            if (tabuleiro[i][j] != tabuleiroAux[i][j])
            {
                verificaIgualdade = false;
            }
            tabuleiro[i][j] = tabuleiroAux[i][j];
        }
    }
}

void JogoVida::escreverNoArquivo(){
    ofstream outFile;
    outFile.open("datasets/gerações.mps",ios::app);
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            outFile << tabuleiro[i][j] << " ";
        }
        outFile << endl;
    }
    outFile << endl;
    outFile.close();
}

bool JogoVida::getVerificaIgualdade(){
    return verificaIgualdade;
}