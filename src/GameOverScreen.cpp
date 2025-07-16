#include <iostream>

#include "GameOverScreen.hpp"
#include "GameScreen.hpp"
#include "TechnicalInfoScreen.hpp"

GameOverScreen::GameOverScreen(ScreenContext* ctx) 
    : context(ctx)
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
            context->setFinalMessage(""); // Limpa a mensagem final
            context->setState(new GameScreen(context));
            break;
        case '2':
            context->setState(new TechnicalInfoScreen(context));
            break;
        case '0':
            exit(0);
        default:
            std::cout << "Opção inválida\n";
    }
}
