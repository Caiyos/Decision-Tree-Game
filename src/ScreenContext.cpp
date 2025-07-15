#include "ScreenContext.hpp"

// Construtor inicializa ponteiro como nulo
ScreenContext::ScreenContext()
  : gameTreeRoot(nullptr)
{}

void ScreenContext::setGameTreeRoot(searchTree::TreeNode* root) {
    gameTreeRoot = root;
}

searchTree::TreeNode* ScreenContext::getGameTreeRoot() const {
    return gameTreeRoot;
}

void ScreenContext::setState(IScreen* state) {
    currentScreen = state;
}

void ScreenContext::display() {
    if (currentScreen) currentScreen->display();
}

void ScreenContext::handleInput(char choice) {
    if (currentScreen) currentScreen->handleInput(choice);
}
