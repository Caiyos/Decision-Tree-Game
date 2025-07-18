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
    // Estado atual da tela
    IScreen* currentScreen;

    // Estruturas de dados do jogo
    searchTree::TreeNode* gameTreeRoot;
    simpleList::ListNode* gameListHead;
    pairList::PlayerListNode* GamePlayerListHead; 

    // Mensagem final do jogo
    std::string finalMessage;

    // Dados do jogador atual
    std::string currentPlayerName;                
    PlayerData* currentPlayerDataPtr;             

    // Flags de estado do jogo
    bool requestSaveData;

public:
    ScreenContext();
    ~ScreenContext();

    void setState(IScreen* state);
    void display();
    void handleInput(char choice);

    // Getters e Setters
    std::string getFinalMessage() const;
    void setFinalMessage(const std::string& message);

    void setGameTreeRoot(searchTree::TreeNode* r);
    searchTree::TreeNode* getGameTreeRoot() const;

    void setGameListHead(simpleList::ListNode* head);
    simpleList::ListNode* getGameListHead() const;

    void setGamePlayerListHead(pairList::PlayerListNode* head);
    pairList::PlayerListNode* getGamePlayerListHead() const;

    void setCurrentPlayerName(const std::string& name); 
    const std::string& getCurrentPlayerName() const;

    void setCurrentPlayerDataPtr(PlayerData* playerPtr); 
    PlayerData* getCurrentPlayerDataPtr() const;

    // Flags de estado do jogo
    void setGameResult(bool win);

    // Manipulação de dados do jogador
    void requestDataSave();
    bool hasSaveDataRequest();
    void resetSaveDataRequest();
};

#endif // SCREENCONTEXT_HPP