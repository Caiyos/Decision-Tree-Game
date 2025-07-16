#include <iostream>

#include "TechnicalInfoScreen.hpp"
#include "ListScreen.hpp"
#include "TreeScreen.hpp"
#include "GameOverScreen.hpp"

TechnicalInfoScreen::TechnicalInfoScreen(ScreenContext* ctx) 
    : context(ctx)
{}

void TechnicalInfoScreen::display() {
    std::cout << "=== Informações técnicas ===\n";
    std::cout << "1. Mostrar a lista simplesmente encadeada que dá origem à árvore\n";
    std::cout << "2. Listar a árvore em ordem\n";
    std::cout << "3. ????\n";
    std::cout << "0. Voltar para o menu anterior\n";
}

void TechnicalInfoScreen::handleInput(char choice) {
    switch (choice) {
        case '1':
            context->setState(new ListScreen(context));
            break;
        case '2':
            context->setState(new TreeScreen(context));
            break;
        case '3':
            break;
        case '0':
            context->setState(new GameOverScreen(context));
            break;
        default:
            std::cout << "Opção inválida\n";
    }
}