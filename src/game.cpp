#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <algorithm>

#include "game.hpp"
#include "ScreenContext.hpp"
#include "MainMenuScreen.hpp"

using namespace std;

namespace game
{

// Controlar os estados do jogo
bool isRunning = true;
bool isWaiting = true;
bool isGameOver = false;

float SCORE = 0.f;
float BEST = 0.f;

ScreenContext context;

// Variável para armazenar o melhor score
void highestScoreUpdate()
{
    if(SCORE>BEST)
    {
        BEST = SCORE;

        // w irá sobrescrever o melhor score antigo
        FILE *file = fopen("highestScore.txt", "w");
        if (file == NULL)
        {
            exit(1);
        }

        fprintf(file, "Melhor score historico foi %.1f", SCORE);

        fclose(file);
    }

}

// Lê o melhor score do arquivo
void highestScoreRead()
{
    FILE *file = fopen("highestScore.txt", "r");
    if (file == NULL) {
        return;
    }

    char linha[32];  // Buffer que armazena cada linha
    float bestHistorico = 0.0;

    if (fgets(linha, sizeof(linha), file) != NULL)
    {
        sscanf(linha, "%*s %*s %*s %*s %f", &bestHistorico);
    }

    fclose(file);
    BEST = bestHistorico;
}

// Configuração inicial do jogo
void setup()
{
    highestScoreRead();
}

// Limpa e reinicia o jogo
void resetGame()
{
    isRunning = true;
    isWaiting = true;
    isGameOver = false;
}

// Função que trata o loop principal do jogo
void run()
{
    char choice;

    // Setup inicial do jogo
    setup();

    context.setState(new MainMenuScreen(&context));

    // Loop do jogo
    while (isRunning) {
        context.display();
        choice = _getch();
        context.handleInput(choice);
        system("cls");
    }
}

}
