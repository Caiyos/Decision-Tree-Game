#include <iostream>

#include "MainMenuScreen.hpp"
#include "StoryScreen.hpp"
#include "RulesScreen.hpp"
#include "GameScreen.hpp"

MainMenuScreen::MainMenuScreen(ScreenContext* ctx) : context(ctx) {}

void MainMenuScreen::display() {
    std::cout << "=== Menu Principal ===\n";
    std::cout << "1. Jogar\n";
    std::cout << "2. Historia\n";
    std::cout << "3. Regras\n";
    std::cout << "0. Sair\n";
}

void MainMenuScreen::handleInput(char choice) {
    switch (choice) {
        case '1':
            context->setState(new GameScreen(context));
            break;
        case '2':
            context->setState(new StoryScreen(context));
            break;
        case '3':
            context->setState(new RulesScreen(context));
            break;
        case '0':
            exit(0);
        default:
            std::cout << "Opção inválida\n";
    }
}