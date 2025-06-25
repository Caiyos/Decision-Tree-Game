#include <iostream>
#include <conio.h> // teclas...
#include <chrono>
#include <thread> // sleep...
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

#include "game.hpp"
#include "console.hpp"

using namespace std;
using namespace console;

namespace game
{

enum COLOR
{
    // wincon.h, biblioteca c específica para trabalhar com terminal do windows, cores prontas
    FOREGROUND_BLUE   = 0x1,
    FOREGROUND_GREEN  = 0x2,
    FOREGROUND_RED    = 0x4,
    FOREGROUND_WHITE  = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE,
    FOREGROUND_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN,

    BACKGROUND_BLUE   = 0x10,
    BACKGROUND_GREEN  = 0x20,
    BACKGROUND_RED    = 0x40,
    BACKGROUND_WHITE  = BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED | 0x80
};

typedef struct _PIXEL
{
    // tipo de char maior que suporta o unicode que consta no wincon.h
    wchar_t unicode; // usa elementos de blocos do unicode, maior variedade de caracteres
    COLOR color;
} PIXEL;

// Controlar os estados do jogo
bool isRunning = true;
bool isWaiting = true;
bool isGameOver = false;

float SCORE = 0.0;
int BEST = 0;

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
    console::setConsoleWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    console::hideConsoleCursor();

    srand((unsigned)time(NULL)); // usada para definir a semente (seed) do gerador
                                 // de números pseudo-aleatórios usado pela função rand

    
    highestScoreRead();
}

// Limpa e reinicia o jogo
void resetGame()
{
    isRunning = true;
    isWaiting = true;
    isGameOver = false;

    SCORE = 0.0;
}

// Função para processar interação com o jogador
void processInput()
{
    if (kbhit()) // checa se tecla pressionada
    {
        char ch = getch();
        if (ch == 13 && isGameOver) // ENTER
        {
            resetGame();
        }
        if (ch == 32) // BARRA DE ESPAÇO
        {
            if (isWaiting) isWaiting = false;
        }
        if (ch == 27) // ESC
        {
            isRunning = false;
        }
    }
}


// Função para atualizar a lógica do jogo
void update(double deltaTime)
{

    // A partir daqui lógicas e funções que dependem do status GAMEOVER

}

// Função para desenhar a tela do jogo
void render()
{
    // Limpa o buffer de tela
    clearBuffer();

    std::wstringstream ss;
    ss << L"SCORE: " << static_cast<int>(SCORE);
    drawString(1, 1, ss.str());

    ss.str(L""); ss.clear();                // limpa para reusar
    ss << L"BEST: " << BEST;
    drawString(1, 3, ss.str()); 

    if (isGameOver)
    {
        drawString(41, 11, L"-- GAMEOVER --");
        drawString(31, 13, L"PRESSIONE  -- ESC --  PARA SAIR");
        drawString(29, 14, L"PRESSIONE -- ENTER -- PARA RECOMEÇAR");
    }

    if (isWaiting)
        drawString(25, 12, L"-- PRESSIONE A BARRA DE SPAÇO PARA COMEÇAR --");

    writeBufferToConsole();
}

// Função que trata o loop principal do jogo
int run()
{
    // Setup inicial do jogo
    setup();

    // Loop do jogo
    while (isRunning)
    {
        // Processa interação com o jogador
        processInput();

        // Renderiza a tela do jogo
        render();
    }

    // Libera memoria alocadas
    freeBufferMemory();

    return 0;
}

}
