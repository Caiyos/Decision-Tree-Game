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
    // score(0.f),
    // bestScore(0.f),
    listHead(nullptr),
    treeRoot(nullptr),
    playerListHead(nullptr),
    currentPlayerName(""),
    context()
    {
    // highestScoreRead();
    SetConsoleOutputCP(CP_UTF8);
    buildList();
    buildTree();
    loadAllPlayersData();

    context.setGamePlayerDataHead(playerListHead);
    }

DecisionTreeGame::~DecisionTreeGame()
{
    saveAllPlayersData();
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

void DecisionTreeGame::loadAllPlayersData() 
{
    std::cout << "DEBUG: Tentando abrir player_data.txt para leitura...\n";
    FILE* file = fopen("player_data.txt", "r");
    if (!file) {
        std::cerr << "player_data.txt não encontrado ou não pôde ser aberto. Iniciando sem dados de jogadores.\n";
        std::cout << "DEBUG: Nao abriu para leitura. Retornando.\n";
        _getch();
        return;
    }
    std::cout << "DEBUG: player_data.txt aberto para leitura com sucesso.\n";
    _getch();

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
                pairList::insertEnd(playerListHead, pd);
            } catch (const std::invalid_argument& e) {
                std::cerr << "Erro ao analisar linha de dados do jogador: " << line << " - " << e.what() << std::endl;
                _getch();
            } catch (const std::out_of_range& e) {
                std::cerr << "Erro ao analisar linha de dados do jogador (fora do alcance): " << line << " - " << e.what() << std::endl;
                _getch();
            }
        }
    }

    fclose(file); 
    std::cout << "DEBUG: player_data.txt fechado apos leitura.\n";
    _getch();
}

void DecisionTreeGame::saveAllPlayersData() 
{
    FILE* file = fopen("player_data.txt", "w");
    if (!file) {
        std::cerr << "Erro: Não foi possível abrir player_data.txt para escrita\n";
        return;
    }
    std::cout << "Arquivo abridu\n";

    pairList::PlayerListNode* current = playerListHead;
    std::cout << "Quantidade de bichin: " << pairList::size(playerListHead) << "\n";
    _getch();
    while (current != nullptr) {
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
    if (node != nullptr) {
        return &(node->data); // Retorna um ponteiro para os dados do PlayerData dentro do nó
    }
    return nullptr; 
}

searchTree::TreeNode* DecisionTreeGame::getGameTreeRoot()
{
    return treeRoot;
}

simpleList::ListNode* DecisionTreeGame::getGameListHead()
{
    return listHead;
}

pairList::PlayerListNode* DecisionTreeGame::getGamePlayerDataHead()
{
    return playerListHead;
}
void DecisionTreeGame::run()
{
    char choice;

    context.setGameTreeRoot(treeRoot);
    context.setGameListHead(listHead);
    context.setState(new PlayerNameScreen(&context));

    while (isRunning) {
        context.display();
        choice = _getch();
        context.handleInput(choice);
        system("cls");

        if (context.getCurrentPlayerDataPtr() == nullptr && !context.getCurrentPlayerName().empty()) {
            //Se tiver um jogador logado mas não tiver os dados 
            currentPlayerName = context.getCurrentPlayerName(); 
            context.setCurrentPlayerDataPtr(this->getCurrentPlayerData());
        }

        if (context.hasGameEnded()) {
            context.resetGameEndFlags(); 
        }

        if (context.hasSaveDataRequest()) {
            saveAllPlayersData();           
            context.resetSaveDataRequest(); 
        }
    }

    // highestScoreUpdate();
}
