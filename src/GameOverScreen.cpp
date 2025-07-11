#include <iostream>

#include "GameOverScreen.hpp"
#include "MainMenuScreen.hpp"

GameOverScreen::GameOverScreen(ScreenContext* ctx, std::string message) : context(ctx), message(message) {}

void GameOverScreen::display() {
    std::cout << "=== Fim de Jogo ===\n";
    std::cout << message << "\n\n";
    std::cout << "Pressione qualquer tecla para voltar ao menu principal.\n";
}

void GameOverScreen::handleInput(char choice) {
    context->setState(new MainMenuScreen(context));
}
