#ifndef DECISION_TREE_GAME_HPP
#define DECISION_TREE_GAME_HPP

#include "ScreenContext.hpp"
#include "simpleList.hpp"
#include "searchTree.hpp"

#include "pairList.hpp"
#include "PlayerData.hpp"

class DecisionTreeGame {
private:
    // Estado de execução
    bool isRunning;

    // Controle de pontuação
    float score;
    float bestScore;

    // Estruturas de dados
    simpleList::ListNode* listHead;
    searchTree::TreeNode* treeRoot;

    pairList::PlayerListNode* playerListHead;
    std::string currentPlayerName;
    // Contexto de telas (menus, jogo, game over...)
    ScreenContext context;

    // Métodos de inicialização e teardown
    // void highestScoreRead();
    // void highestScoreUpdate();
    void buildList();
    void buildTree();
    void loadAllPlayersData();
    void saveAllPlayersData();
    PlayerData* getCurrentPlayerData();
    
public:
    DecisionTreeGame();
    ~DecisionTreeGame();

    searchTree::TreeNode* getGameTreeRoot();
    simpleList::ListNode* getGameListHead();
    pairList::PlayerListNode* getGamePlayerDataHead();

    

    // API pública
    void run();
};

#endif // DECISION_TREE_GAME_HPP