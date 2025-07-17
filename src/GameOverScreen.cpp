#include <iostream>

#include "GameOverScreen.hpp"
#include "GameScreen.hpp"
#include "TechnicalInfoScreen.hpp"

GameOverScreen::GameOverScreen(ScreenContext* ctx) 
    : IScreen(ctx), context(ctx)
{
    message = context->getFinalMessage();
}

void GameOverScreen::display() {
    std::cout << "=== Fim de Jogo ===\n";
    std::cout << message << "\n\n";
    std::cout << "Escolha uma opção:\n";
    std::cout << "1. Jogar Novamente\n";
    std::cout << "2. Informações Técnicas\n";
    std::cout << "0. Sair\n";
}

void GameOverScreen::handleInput(char choice) {
    switch (choice) {
        case '1':
            context->setFinalMessage(""); 
            context->setState(new GameScreen(context));
            context->requestDataSave();
            break;
        case '2':
            context->setState(new TechnicalInfoScreen(context));
            context->requestDataSave();
            break;
        case '0':
            context->requestDataSave();
            exit(0);
        default:
            std::cout << "Opção inválida\n";
    }
}
