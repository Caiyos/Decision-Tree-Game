#include <iostream>
#include <conio.h>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <windows.h>

#include "game.hpp"
#include "ScreenContext.hpp"
#include "MainMenuScreen.hpp"
#include "simpleList.hpp"

using namespace std;

namespace game
{

// Controlar os estados do jogo
/*
bool isWaiting = true;
bool isGameOver = false;
*/

bool isRunning = true;

float SCORE = 0.f;
float BEST = 0.f;

ScreenContext context;
simpleList::ListNode *lista = nullptr;


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

void buildList()
{
    FILE *file = fopen("story.txt", "r");
    if (file == NULL) {
        cerr << "Erro ao abrir o arquivo story.txt" << endl;
        return;
    }

    char linha[256];
    
    while (fgets(linha, sizeof(linha), file) != NULL)
    {
        std::stringstream ss(linha);
        std::string texto, idStr, aliveStr;

        if(getline(ss, idStr, ';') && getline(ss, texto, ';') && getline(ss, aliveStr))
        {
            int id = std::stoi(idStr);
            int aliveInt = std::stoi(aliveStr);
            bool aliveBool = (aliveInt == 1);

            simpleList::insertEnd(&lista, id, texto, aliveBool);
        }
    }

    fclose(file);
}

// Configuração inicial do jogo
void setup()
{
    highestScoreRead();
    buildList();
}

// Limpa e reinicia o jogo
void resetGame()
{
    /*
    isRunning = true;
    isWaiting = true;
    isGameOver = false;
    */
}


// Função que trata o loop principal do jogo
void run()
{
    SetConsoleOutputCP(CP_UTF8); // Configura a saída do console para UTF-8, permitindo caracteres especiais como acentos
    char choice;

    // Setup inicial do jogo
    setup();

    context.setState(new MainMenuScreen(&context));

    // Loop do jogo
    while (isRunning) {
        simpleList::printList(lista);
        Sleep(3000);
        // context.display();
        // choice = _getch();
        // context.handleInput(choice);
        system("cls");
    }

    simpleList::freeList(lista); // Libera a memória alocada para a lista
    lista = nullptr; // Reseta o ponteiro da lista para evitar dangling pointers (acontece quando o ponteiro aponta para um local de memória que já foi liberado)
}

}
