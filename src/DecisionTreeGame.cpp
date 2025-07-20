#include "DecisionTreeGame.hpp"
#include "PlayerNameScreen.hpp"
#include <conio.h>
#include <windows.h>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <iostream>


DecisionTreeGame::DecisionTreeGame()
  : isRunning(true),
    listHead(nullptr),
    treeRoot(nullptr),
    playerListHead(nullptr),
    currentPlayerName(""),
    context()
{
    SetConsoleOutputCP(CP_UTF8);
    buildList();
    buildTree();
    loadAllPlayersData();
}

DecisionTreeGame::~DecisionTreeGame()
{
    reorderPlayerList();
    saveAllPlayersData();
    
    deleteTree(treeRoot);
    deleteList(listHead);
    deletePlayerList(playerListHead);
}

void DecisionTreeGame::buildList()
{
    FILE* file = fopen("story.txt", "r");
    if (!file) {
        std::cerr << "Erro ao abrir story.txt\n";
        return;
    }

    char line[4096];

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

void DecisionTreeGame::loadAllPlayersData() 
{
    FILE* file = fopen("player_data.txt", "r");
    if (!file) {
        std::cerr << "player_data.txt não encontrado ou não pôde ser aberto. Iniciando sem dados de jogadores.\n";
        _getch();
        return;
    }

    char line[256]; 

    while (fgets(line, sizeof(line), file)) 
    {
        std::stringstream ss(line);
        std::string name, gamesPlayedStr, winsStr, lossesStr;

        if (std::getline(ss, name, ';') &&
            std::getline(ss, gamesPlayedStr, ';') &&
            std::getline(ss, winsStr, ';') &&
            std::getline(ss, lossesStr)) {
            try {

                int gamesPlayed = std::stoi(gamesPlayedStr);
                int wins = std::stoi(winsStr);
                int losses = std::stoi(lossesStr);

                PlayerData pd(name, gamesPlayed, wins, losses); 
                pairList::insertSorted(&playerListHead, pd);

            } 
            catch (const std::invalid_argument& e) 
            {
                std::cerr << "Erro ao analisar linha de dados do jogador: " << line << " - " << e.what() << std::endl;
                _getch();
            } 
            catch (const std::out_of_range& e) 
            {
                std::cerr << "Erro ao analisar linha de dados do jogador (fora do alcance): " << line << " - " << e.what() << std::endl;
                _getch();
            }
        }
    }

    fclose(file); 
}

void DecisionTreeGame::saveAllPlayersData() 
{
    FILE* file = fopen("player_data.txt", "w");
    if (!file) {
        std::cerr << "Erro: Não foi possível abrir player_data.txt para escrita\n";
        return;
    }

    pairList::PlayerListNode* current = context.getGamePlayerListHead();
    while (current != nullptr) 
    {
        if (fprintf(file, "%s;%d;%d;%d\n",
                    current->data.name.c_str(),
                    current->data.gamesPlayed,
                    current->data.wins,
                    current->data.losses) < 0) {
            std::cerr << "Erro ao escrever dados do jogador " << current->data.name << " em player_data.txt\n";
        }

        current = current->next;
    }
    fclose(file);
}

PlayerData* DecisionTreeGame::getCurrentPlayerData() 
{
    pairList::PlayerListNode* node = pairList::findPlayerNode(playerListHead, currentPlayerName);
    if (node != nullptr) 
    {
        return &(node->data); // Retorna um ponteiro para os dados do PlayerData dentro do nó
    }

    return nullptr; 
}

void DecisionTreeGame::deleteTree(searchTree::TreeNode* node) 
{
    if (node == nullptr) return;

    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void DecisionTreeGame::deleteList(simpleList::ListNode* node) 
{
    while (node != nullptr) {
        simpleList::ListNode* temp = node;
        node = node->next;
        delete temp;
    }
}

void DecisionTreeGame::deletePlayerList(pairList::PlayerListNode* node) 
{
    while (node != nullptr) {
        pairList::PlayerListNode* temp = node;
        node = node->next;
        delete temp;
    }
}

void DecisionTreeGame::reorderPlayerList()
{
    pairList::PlayerListNode* oldHead = context.getGamePlayerListHead();
    pairList::PlayerListNode* sorted = pairList::reorderList(oldHead);
    context.setGamePlayerListHead(sorted);
}

void DecisionTreeGame::run()
{
    char choice;

    context.setGameTreeRoot(treeRoot);
    context.setGameListHead(listHead);
    context.setGamePlayerListHead(playerListHead);

    context.setState(new PlayerNameScreen(&context));

    while (isRunning) {
        context.display();
        choice = _getch();
        context.handleInput(choice);
        system("cls");

        if (context.isExitRequested()) 
        {
            exitGame();
            break;
        }

        if (context.getCurrentPlayerDataPtr() == nullptr && !context.getCurrentPlayerName().empty()) //Se tiver um jogador logado mas não tiver os dados
        {
            currentPlayerName = context.getCurrentPlayerName(); 
            context.setCurrentPlayerDataPtr(this->getCurrentPlayerData());
        }

        if (context.hasSaveDataRequest()) 
        {
            saveAllPlayersData();           
            context.resetSaveDataRequest(); 
        }
    }
}
