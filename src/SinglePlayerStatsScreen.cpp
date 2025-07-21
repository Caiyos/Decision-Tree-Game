#include "SinglePlayerStatsScreen.hpp"
#include "PlayerData.hpp"
#include "TechnicalInfoScreen.hpp"
#include "MainMenuScreen.hpp"
#include <iostream>
#include <cctype> 

SinglePlayerStatsScreen::SinglePlayerStatsScreen(ScreenContext* ctx, const std::string& name)
        : IScreen(ctx),  playerName(name) {} 

void SinglePlayerStatsScreen::display(){
    if(playerName != ""){
        system("cls");
        std::cout << "=== ESTATISTICAS DO JOGADOR ===\n";
        std::cout << "\n";

        PlayerData* player = nullptr;
        
        pairList::PlayerListNode* node = pairList::findPlayerNode(context->getGamePlayerListHead(), playerName);
        if (node != nullptr) {
            player = &(node->data);
        }

        if (player) {
            std::cout << "Nome: " << player->name << "\n";
            std::cout << "Jogos Jogados: " << player->gamesPlayed << "\n";
            std::cout << "Vitorias: " << player->wins << "\n";
            std::cout << "Derrotas: " << player->losses << "\n";
        } else {
            std::cout << "Jogador '" << playerName << "' nao encontrado.\n";
        }
        std::cout << "Pressione qualquer tecla para voltar...\n";
    }
    else{
        system("cls"); 
        std::cout << "=== Digite o nome do jogador ===\n";
        std::cout << "Nome: " << playerName << "_ \n"; 
        std::cout << "Pressione Enter para buscar ou Backspace para apagar.\n";
    }
}

void SinglePlayerStatsScreen::handleInput(char input){
    if (input == '\r' || input == '\n') { 
        if (playerName.empty()) {
            return; 
        }
        else {
            context->setState(new MainMenuScreen(context));
        }
    } else if (input == '\b' || input == 127) { 
        if (!playerName.empty()) {
            playerName.pop_back(); 
        }
    } else if (isprint(input)) { 
        playerName += input; 
    }
}