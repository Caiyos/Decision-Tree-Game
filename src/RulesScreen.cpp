#include <iostream>

#include "RulesScreen.hpp"
#include "MainMenuScreen.hpp"

RulesScreen::RulesScreen(ScreenContext* ctx) : IScreen(ctx), context(ctx) {}

void RulesScreen::display() {
    std::cout << "Regras do jogo:                                            \n";
    std::cout << "1. Escolha suas ações sabiamente.                          \n";
    std::cout << "2. Colete itens para aumentar seu poder.                   \n";
    std::cout << "3. Enfrente desafios e inimigos pelo caminho.              \n";
    std::cout << "4. Você pode voltar ao menu a qualquer momento.            \n";
    std::cout << "                                                           \n";
    std::cout << "Pressione qualquer tecla para voltar ao menu.              \n";
}

void RulesScreen::handleInput(char choice) {
    context->setState(new MainMenuScreen(context));
}
