#include "ScreenContext.hpp"
#include "MainMenuScreen.hpp"
#include "PlayerNameScreen.hpp" 
#include <iostream>

ScreenContext::ScreenContext()
    : currentScreen(nullptr),
      gameTreeRoot(nullptr),
      gameListHead(nullptr),
      finalMessage(""),
      gamePlayerDataHead(nullptr), 
      currentPlayerName(""),
      currentPlayerDataPtr(nullptr), 
      gameEndedThisTurn(false),
      lastGameWasWin(false),
      requestSaveData(false)
{
    setState(new PlayerNameScreen(this)); 
}

ScreenContext::~ScreenContext() {
    delete currentScreen;
    currentScreen = nullptr;
}

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

void ScreenContext::setGamePlayerDataHead(pairList::PlayerListNode* head) {
    gamePlayerDataHead = head;
}

void ScreenContext::setCurrentPlayerName(const std::string& name) {
    currentPlayerName = name;
}

void ScreenContext::setCurrentPlayerDataPtr(PlayerData* playerPtr) {
    currentPlayerDataPtr = playerPtr;
}

void ScreenContext::setGameResult(bool win) 
{
    gameEndedThisTurn = true;
    lastGameWasWin = win;
    if (currentPlayerDataPtr) {
        currentPlayerDataPtr->gamesPlayed++;
        if (win) {
            currentPlayerDataPtr->wins++;
        } 
        else {
            currentPlayerDataPtr->losses++;
        }
    }
}

void ScreenContext::resetGameEndFlags() {
    gameEndedThisTurn = false;
    lastGameWasWin = false;
}

void ScreenContext::requestDataSave() {
    requestSaveData = true;
}

void ScreenContext::resetSaveDataRequest() {
    requestSaveData = false;
}