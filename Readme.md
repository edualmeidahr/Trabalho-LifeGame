<h1 align="center" font-size="200em"><b>Busca DFS, BFS e randômica</b></h1>

<div align = "center" >
<!-- imagem -->

[![requirement](https://img.shields.io/badge/IDE-Visual%20Studio%20Code-informational)](https://code.visualstudio.com/docs/?dv=linux64_deb)
![Make](https://img.shields.io/badge/Compilacao-Make-orange)
![Linguagem](https://img.shields.io/badge/Linguagem-C%2B%2B-blue)
</div>

## 📌Sumário
- [Introdução](#Introdução)
- [Objetivos](#Objetivos)
- [Problema apresentado](#Problema-apresentado)
- [Arquivos](#Arquivos)
- [Resolução do Problema](#Resolução-do-problema)
- [Resultados](#Resultados)
- [Conclusão](#Conclusão)
- [Compilação e execução](#Compilação-e-execução)
- [Contato](#Contato)

## ✒️Introdução
<p align="justify">
    O jogo da Vida, é um autómato celular desenvolido pelo matemático John Conway na década de 1970. <br>
    O jogo da Vida acontece em uma grade bidimensional, em que cada célula pode estar viva ou morta. O jogo evolui em etapas de tempo, seguindo algumas regras básicas que determinam o estado de cada célula nas gerações subsequentes.<br>
</p>

## 💻Objetivos

O principal obejtivo desse trabalho é revisar conceitos anteriores já vistos no curso. Principamente a questão de manipulação de matrizes, a quall é usada para o controle de fluxo e lógica do jogo.


## Problema-apresentado
<storng><h4>Regras Principais:</h4></strong>
- Crie uma matriz N x N para representar o tabuleiro do Jogo da Vida.
- Inicialize o tabuleiro com céculas vivas (1) e mortas(0).
- Implemente uma função para exibir o estado atual do tabuleiro.
- Implemente uma função para calcular a próxima geração do Jogo da Vida com base nas seguintes regras:
    -Uma célula viva com menos de dois vizinhos vivos morre (solidão).
    -Uma célula viva com mais de três vizinhos vivos morre (superpopulaçõa).
    -Uma célula viva com dois ou três vizinhos sobrevive.
    -Uma célula morta com exatamente três vizinhos vivos se torna viva (reprodução)
<div align = "center">
<img src="imgs/JogoDaVida.png" alt="Exemplo tabuleiro" width=300px> 
<div>

<strong><h4>Condições impostas: </h4></strong>
- Ler a matriz de entrada em um arquivo, considerando um tamanho mínimo de 5x5.
- Considere uma fração de 2 para 1 para compor os valores de 0s e 1s, sendo o número de 1s em menor quantidade para produtiz um melhor espalhamento.
- A cada interação, faça as avaliações utilizando a matriz atual e produza os resultados da avaliação em uma nova matriz. Feito isso, salve a matriz avaliada como parte de seus resultados em um arquivo chamado gerações.mps.
- O arquivo gerações.mps deve ser organizado para mostrar todas as evoluções, contando inclusive com a matriz de origem da execução.
- Na tela, basta apresentar as mensagens de algoritmo executando e processo de geração finalizado.
- Como entradas, pedir ao usuário para digitar apenas o número de gerações a ser avaliado.
- Para a matriz de entrada, crie um pasta chamda datasets dentro do seu projeto e fora da pasta src, armazenando ela como input.mps.

## 📄Arquivos
- <strong>Main.cpp:</strong> Primeiro recebe como entrada a quantidade de gerações que o usuário deseja. Depois é chamado as funções para inicializar o tabuleiro e escrever no arquivo, após isso, são chamadas as próximas gerações com a função proximoCiclo, e isso dentro de um for para que seja feita a quantidade escolhida anteriormente.
- <strong>JogoVida.hpp:</strong> Criada as funções que irão fazer toda o fluxo e lógico do jogo, e também escreve no arquivo.
- <strong>JogoVida.cpp:</strong> Feita a estruturação das funções criadas no arquivo JogoVida.hpp.

## 🔨Resolução do problema
<h3><b>Implementação da Jogo</b></h3>

*Arquivos lista.hpp e lista.cpp*<br>
- ```inicialiazarMundo```: Lê a matriz do arquivo input.mps.
- `imprimeMundo`: imprime o tabuleiro.
- `escreverArquivo`: escreve o tabuleiro atual no arquivo gerações.mps
- ``: imprime a lista.
- `contaVizinhosVivos`: Recece como parâmetro uma casa do tabuleiro e verifica quantos vizinhos vivo ela tem, por meio de um sistema de joystick, como segue abaixo:
<div aling="center">
<img src="imgs/FunçãovizinhosVivos.png" alt="Função contaVizinhosVivos" widht=200px> 
<div>
- `proximoCiclo`: Percorre o tabuleiro verificando quantos vizinhos vivo cada posição tem(usando a fuunção acima), e a partir disso, veririca se de acordo com as regras importas, ela continuará viva ou morta para a próxima geração. E por fim ela atualiza o tabuleiro.
<div aling="center">
<img src="imgs/FuncaoProximoCiclo.png" alt="Função proximoCiclo" widht=200px> 
<div>
- `verificaIgualdade`: Esse atributo é usado para verificar caso duas gerações seguidas sejam iguals, assim determinando que o jogo chegou ao fim, pois o tabuleiro continuará sempre igual.



## 🎯Resultados
Como resultado temos todas as gerações criadas salvas num arquivo gerações.mps (a quantidade escolhida pelo usuário). Lembrando também que caso tenham duas gerações seguidas iguais o jogo deve ser encerrado e mostrado uma mensagem na tela. Nesse caso o jogo terminaria antes do previsto.
## ✔️Conclusão
Ao final desse projeto, tem-se que o objetivo foi alcançado, uma vez que foi usado vários concceitos vistos anteriormente no curs, como manipulação de matrizes e de arquivos. 
Sobre o jogo em si, foi notável que é um jogo muito interessante e apesar de suas regras simples, ele é capaz e gerar padrões surpreendentemente complexos e até mesmo simular fenômenos semlehantes aos observados na vida real, como a formação de estruturas estáveis, osciladores e espaçonaves.

## 👾Compilação e execução
* Especificações da máquina em que o código foi rodado:
  * Processador AMD Ryzen7 5700u;
  * Sistema Operacional Ubuntu 22.04;
  * 12GB de RAM.
* | Comando                |  Função                                                                                           |                     
  | -----------------------| ------------------------------------------------------------------------------------------------- |
  |  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
  |  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
  |  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


 
