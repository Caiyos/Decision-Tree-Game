#include "ScreenContext.hpp"

// Construtor inicializa ponteiro como nulo
ScreenContext::ScreenContext()
  : gameTreeRoot(nullptr),
    gameListHead(nullptr),
    finalMessage("")
{}

void ScreenContext::setFinalMessage(const std::string& message) {
    finalMessage = message;
}

std::string ScreenContext::getFinalMessage() const {
    return finalMessage;
}

void ScreenContext::setGameTreeRoot(searchTree::TreeNode* root) {
    gameTreeRoot = root;
}

searchTree::TreeNode* ScreenContext::getGameTreeRoot() const {
    return gameTreeRoot;
}

void ScreenContext::setGameListHead(simpleList::ListNode* head) {
    gameListHead = head;
}

simpleList::ListNode* ScreenContext::getGameListHead() const {
    return gameListHead;
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
