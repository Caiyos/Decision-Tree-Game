#include "DecisionTreeGame.hpp"
#include "MainMenuScreen.hpp"
#include <conio.h>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>


DecisionTreeGame::DecisionTreeGame()
  : isRunning(true),
    // score(0.f),
    // bestScore(0.f),
    listHead(nullptr),
    treeRoot(nullptr),
    context()
{
    // highestScoreRead();
    SetConsoleOutputCP(CP_UTF8);
    buildList();
    buildTree();
}

DecisionTreeGame::~DecisionTreeGame()
{
    // liberar memória da lista e da árvore?
}

/*
void DecisionTreeGame::highestScoreRead()
{
    FILE* file = fopen("highestScore.txt", "r");
    if (!file) return;

    float hist = 0.f;
    char buffer[64];
    if (fgets(buffer, sizeof(buffer), file)) {
        sscanf(buffer, "%*s %*s %*s %*s %f", &hist);
    }
    fclose(file);
    bestScore = hist;
}
*/

/*
void DecisionTreeGame::highestScoreUpdate()
{
    if (score <= bestScore) return;

    bestScore = score;
    FILE* file = fopen("highestScore.txt", "w");
    if (!file) {
        std::cerr << "Não foi possível abrir highestScore.txt para escrita\n";
        exit(1);
    }
    fprintf(file, "Melhor score historico foi %.1f", bestScore);
    fclose(file);
}
*/

void DecisionTreeGame::buildList()
{
    FILE* file = fopen("story.txt", "r");
    if (!file) {
        std::cerr << "Erro ao abrir story.txt\n";
        return;
    }

    char line[256];

    while (fgets(line, sizeof(line), file)) 
    {
        std::stringstream ss(line);
        std::string idStr, text, aliveStr;

        if (getline(ss, idStr, ';') && getline(ss, text, ';') && getline(ss, aliveStr))
        {
            int id = std::stoi(idStr);
            int al = std::stoi(aliveStr);
            bool alive = (al == 1);

            simpleList::insertEnd(&listHead, id, text, alive);
        }
    }
    
    fclose(file);
}

void DecisionTreeGame::buildTree()
{
    simpleList::ListNode* node = listHead;

    while (node != nullptr)
    {
        treeRoot = searchTree::insert(treeRoot, node->text, node->id, node->alive);

        node = node->next;
    }
}

searchTree::TreeNode* DecisionTreeGame::getGameTreeRoot()
{
    return treeRoot;
}

void DecisionTreeGame::run()
{
    char choice;

    context.setGameTreeRoot(treeRoot);
    context.setState(new MainMenuScreen(&context));

    while (isRunning) {
        context.display();
        choice = _getch();
        context.handleInput(choice);
        system("cls");
    }

    // highestScoreUpdate();
}
