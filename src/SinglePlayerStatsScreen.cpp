#include "SinglePlayerStatsScreen.hpp"
#include "PlayerData.hpp"
#include "TechnicalInfoScreen.hpp"
#include "MainMenuScreen.hpp"
#include <iostream>
#include <cctype> // Necessário para isprint()

SinglePlayerStatsScreen::SinglePlayerStatsScreen(ScreenContext* ctx)
  : IScreen(ctx) 
{
    playerName = context->getCurrentPlayerName();
    player = nullptr;
    playerListHead = context->getGamePlayerListHead();
}

void SinglePlayerStatsScreen::display()
{
    std::cout << "=== ESTATISTICAS DO JOGADOR ===\n";
    std::cout << "\n";
    
    // Busca o nó do jogador na lista
    pairList::PlayerListNode* node = pairList::findPlayerNode(playerListHead, playerName);
    if (node != nullptr) 
    {
        player = &(node->data);
    }

    if (player) 
    {
        // Exibe as estatísticas
        std::cout << "Nome: " << player->name << "\n";
        std::cout << "Jogos Jogados: " << player->gamesPlayed << "\n";
        std::cout << "Vitorias: " << player->wins << "\n";
        std::cout << "Derrotas: " << player->losses << "\n";
    } 
    else 
    {
        std::cout << "Jogador '" << playerName << "' nao encontrado.\n";
    }

    std::cout << "Pressione qualquer tecla para voltar para o menu anterior...\n";
}

void SinglePlayerStatsScreen::handleInput(char input)
{
    if(context->getFinalMessage() == "")
    {
        context->setState(new MainMenuScreen(context));
    }
    else
    {
        context->setState(new TechnicalInfoScreen(context));
    }
}