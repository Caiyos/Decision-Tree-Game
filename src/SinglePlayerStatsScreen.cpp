#include "SinglePlayerStatsScreen.hpp"
#include "pairList.hpp"
#include "PlayerData.hpp"
#include "MainMenuScreen.hpp" // Adicionado para new MainMenuScreen
#include <iostream>
#include <cctype> // Necessário para isprint()

SinglePlayerStatsScreen::SinglePlayerStatsScreen(ScreenContext* ctx, const std::string& name)
        : IScreen(ctx), context(ctx), playerName(name) {} // Assumindo que IScreen(ctx) e context(ctx) estão OK

void SinglePlayerStatsScreen::display(){
    // Lógica para quando o playerName não está vazio (mostra as estatísticas ou jogador não encontrado)
    if(playerName != ""){
        system("cls");
        std::cout << "=== ESTATISTICAS DO JOGADOR ===\n";
        std::cout << "\n";

        PlayerData* player = nullptr;
        
        // Busca o nó do jogador na lista
        pairList::PlayerListNode* node = pairList::findPlayerNode(context->getGamePlayerDataHead(), playerName);
        if (node != nullptr) {
            player = &(node->data);
        }

        if (player) {
            // Exibe as estatísticas
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