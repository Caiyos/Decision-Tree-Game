#ifndef SCREENCONTEXT_HPP
#define SCREENCONTEXT_HPP

#include <string>
#include "IScreen.hpp"
#include "searchTree.hpp"
#include "simpleList.hpp"
#include "PlayerData.hpp"   
#include "pairList.hpp"  

class ScreenContext {
private:
    IScreen* currentScreen;
    searchTree::TreeNode* gameTreeRoot;
    simpleList::ListNode* gameListHead;

    std::string finalMessage;

    pairList::PlayerListNode* gamePlayerDataHead; 
    std::string currentPlayerName;                
    PlayerData* currentPlayerDataPtr;             

    bool gameEndedThisTurn;
    bool lastGameWasWin;

    bool requestSaveData;

public:
    ScreenContext();
    ~ScreenContext();

    void setState(IScreen* state);
    void display();
    void handleInput(char choice);

    std::string getFinalMessage() const;
    void setFinalMessage(const std::string& message);

    void setGameTreeRoot(searchTree::TreeNode* r);
    searchTree::TreeNode* getGameTreeRoot() const;

    void setGameListHead(simpleList::ListNode* head);
    simpleList::ListNode* getGameListHead() const;

    void setGamePlayerDataHead(pairList::PlayerListNode* head);
    pairList::PlayerListNode*& getGamePlayerDataHead() { return gamePlayerDataHead; }

    void setCurrentPlayerName(const std::string& name); 
    const std::string& getCurrentPlayerName() const { return currentPlayerName; }

    void setCurrentPlayerDataPtr(PlayerData* playerPtr); 
    PlayerData* getCurrentPlayerDataPtr() const { return currentPlayerDataPtr; }

    void setGameResult(bool win);
    bool hasGameEnded() const { return gameEndedThisTurn; }
    bool wasLastGameWin() const { return lastGameWasWin; }
    void resetGameEndFlags();

    void requestDataSave();
    bool hasSaveDataRequest() const { return requestSaveData; }
    void resetSaveDataRequest();
};

#endif // SCREENCONTEXT_HPP