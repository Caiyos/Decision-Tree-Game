#ifndef DECISION_TREE_GAME_HPP
#define DECISION_TREE_GAME_HPP

#include "ScreenContext.hpp"
#include "simpleList.hpp"
#include "searchTree.hpp"

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

    // Contexto de telas (menus, jogo, game over...)
    ScreenContext context;

    // Métodos de inicialização e teardown
    // void highestScoreRead();
    // void highestScoreUpdate();
    void buildList();
    void buildTree();

public:
    // Construtor e destrutor
    DecisionTreeGame();
    ~DecisionTreeGame();

    searchTree::TreeNode* getGameTreeRoot();
    simpleList::ListNode* getGameListHead();

    // API pública
    void run();
};

#endif // DECISION_TREE_GAME_HPP