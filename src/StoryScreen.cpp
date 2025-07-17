#include <iostream>

#include "StoryScreen.hpp"
#include "MainMenuScreen.hpp"

StoryScreen::StoryScreen(ScreenContext* ctx) : IScreen(ctx), context(ctx) {}

void StoryScreen::display() {
    std::cout << "História do jogo:                                           \n";
    std::cout << "Era uma vez um herói que lutava contra monstros.            \n";
    std::cout << "Ele precisava coletar itens mágicos para aumentar seu poder.\n";
    std::cout << "Mas havia muitos obstáculos pelo caminho.                   \n";
    std::cout << "Ele enfrentou desafios e superou todos eles.                \n";
    std::cout << "Agora ele é o maior herói de todos os tempos!               \n";
    std::cout << "                                                            \n";
    std::cout << "Pressione qualquer tecla para voltar ao menu.               \n";
}

void StoryScreen::handleInput(char choice) {
    context->setState(new MainMenuScreen(context));
}