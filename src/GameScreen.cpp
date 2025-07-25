#include <iostream>

#include "GameScreen.hpp"
#include "MainMenuScreen.hpp"
#include "GameOverScreen.hpp"
#include "ScreenContext.hpp"

GameScreen::GameScreen(ScreenContext* ctx)
  : IScreen(ctx)
{
  // busca a raiz no Context
  root = context->getGameTreeRoot();
  currentNode = root;
}

void GameScreen::display() {
    std::cout << "=== Contexto ===\n";
    if (currentNode) {
        std::cout << currentNode->text << "\n\n";
    } else {
        std::cout << "Fim do jogo ou erro na árvore de decisões.\n\n";
    }
    std::cout << "=== Faça sua escolha ===\n";
    std::cout << "1. Sim\n";
    std::cout << "2. Não\n";
    std::cout << "0. Sair para o menu\n";
}

void GameScreen::checkGameOver() 
{
    if (!currentNode->left && !currentNode->right) 
    {
        std::string message;
        bool isWin = currentNode->alive; 

        if (isWin) {
            message = "Parabéns! " + currentNode->text;
        } 
        else {
            message = currentNode->text + " Boa sorte na próxima tentativa.";
        }

        context->setFinalMessage(message);
        context->setGameResult(isWin);
        context->setState(new GameOverScreen(context));
        
    }
}

void GameScreen::handleInput(char choice) 
{
    switch (choice) {
        case '1':
            if (currentNode && currentNode->right) {
                currentNode = currentNode->right;
                checkGameOver();
            }
            break;

        case '2':
            if (currentNode && currentNode->left) {
                currentNode = currentNode->left;
                checkGameOver();
            }
            break;

        case '0':
            context->setState(new MainMenuScreen(context));
            break;
    }
}
