#include "ScreenContext.hpp"
#include "MainMenuScreen.hpp"
#include "PlayerNameScreen.hpp" 
#include <iostream>

ScreenContext::ScreenContext()
  : currentScreen(nullptr),
    gameTreeRoot(nullptr),
    gameListHead(nullptr),
    GamePlayerListHead(nullptr), 
    finalMessage(""),
    currentPlayerName(""),
    currentPlayerDataPtr(nullptr), 
    requestSaveData(false),
    exitRequested(false)
{}

ScreenContext::~ScreenContext() {
    delete currentScreen;
    currentScreen = nullptr;
}

void ScreenContext::setState(IScreen* state) {
    delete currentScreen;
    currentScreen = state;
}

void ScreenContext::display() {
    if (currentScreen) currentScreen->display();
}

void ScreenContext::handleInput(char choice) {
    if (currentScreen) currentScreen->handleInput(choice);
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

void ScreenContext::setGamePlayerListHead(pairList::PlayerListNode* head) {
    GamePlayerListHead = head;
}

pairList::PlayerListNode* ScreenContext::getGamePlayerListHead() const {
    return GamePlayerListHead;
}

void ScreenContext::setCurrentPlayerName(const std::string& name) {
    currentPlayerName = name;
}

const std::string& ScreenContext::getCurrentPlayerName() const {
    return currentPlayerName;
}

void ScreenContext::setCurrentPlayerDataPtr(PlayerData* playerPtr) {
    currentPlayerDataPtr = playerPtr;
}

PlayerData* ScreenContext::getCurrentPlayerDataPtr() const {
    return currentPlayerDataPtr;
}

void ScreenContext::setGameResult(bool win) 
{
    if (currentPlayerDataPtr) 
    {
        currentPlayerDataPtr->gamesPlayed++;

        if (win) 
        {
            currentPlayerDataPtr->wins++;
        } 
        else 
        {
            currentPlayerDataPtr->losses++;
        }
    }
}

void ScreenContext::requestDataSave() 
{
    requestSaveData = true;
}

bool ScreenContext::hasSaveDataRequest() {
    return requestSaveData;
}

void ScreenContext::resetSaveDataRequest() 
{
    requestSaveData = false;
}

void ScreenContext::requestExit() {
    exitRequested = true;
}

bool ScreenContext::isExitRequested() const {
    return exitRequested;
}

