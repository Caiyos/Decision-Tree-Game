#include <iostream>

#include "TreeScreen.hpp"
#include "TechnicalInfoScreen.hpp"

TreeScreen::TreeScreen(ScreenContext* ctx) 
    : context(ctx) 
{
    gameTreeRoot = context->getGameTreeRoot();
}

void TreeScreen::display() {
    std::cout << "=== Árvore em ordem ===\n";
    
    if (gameTreeRoot) {
        searchTree::printTree(gameTreeRoot);
    } else {
        std::cout << "Árvore vazia.\n";
    }

    std::cout << "Pressione qualquer tecla para voltar ao menu anterior.\n";
}

void TreeScreen::handleInput(char choice) {
    context->setState(new TechnicalInfoScreen(context));
}