#include <iostream>

#include "GameOverScreen.hpp"
#include "GameScreen.hpp"
#include "MainMenuScreen.hpp"
#include "TechnicalInfoScreen.hpp"

GameOverScreen::GameOverScreen(ScreenContext* ctx) 
    : IScreen(ctx)
{
    message = context->getFinalMessage();
}

void GameOverScreen::display() 
{
    std::cout << "=== Fim de Jogo ===\n";
    std::cout << message << "\n\n";
    std::cout << "Escolha uma opção:\n";
    std::cout << "1. Jogar Novamente\n";
    std::cout << "2. Informações Técnicas\n";
    std::cout << "0. Sair para o Menu Principal\n";
}

void GameOverScreen::handleInput(char choice) 
{
    switch (choice) {
        case '1':
            context->setFinalMessage(""); 
            context->setState(new GameScreen(context));
            break;
        case '2':
            context->setState(new TechnicalInfoScreen(context));
            break;
        case '0':
            context->setFinalMessage("");
            context->setState(new MainMenuScreen(context));
            break;
        default:
            std::cout << "Opção inválida\n";
    }
}
