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

    // Estruturas de dados
    simpleList::ListNode* listHead;
    searchTree::TreeNode* treeRoot;
    pairList::PlayerListNode* playerListHead;

    // Dados do jogador atual
    std::string currentPlayerName;

    // Contexto de telas (menus, jogo, game over...)
    ScreenContext context;

    // Métodos de inicialização
    void buildList();
    void buildTree();
    void loadAllPlayersData();
    void saveAllPlayersData();

    // Métodos de manipulação de dados do jogador
    PlayerData* getCurrentPlayerData();

    // Sair do jogo
    void exitGame() { isRunning = false; }

    // Limpeza de memória
    void deleteTree(searchTree::TreeNode* node);
    void deleteList(simpleList::ListNode* node);
    void deletePlayerList(pairList::PlayerListNode* node);

    // Reordena a lista de jogadores
    void reorderPlayerList();

public:
    DecisionTreeGame();
    ~DecisionTreeGame();

    // API pública
    void run();
};

#endif // DECISION_TREE_GAME_HPP