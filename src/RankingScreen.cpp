#include "RankingScreen.hpp"
#include "TechnicalInfoScreen.hpp"
#include "pairList.hpp"
#include "PlayerData.hpp"
#include <iostream>

RankingScreen::RankingScreen(ScreenContext* ctx) 
  : IScreen(ctx)
{
    playerListHead = context->getGamePlayerListHead();
    current = playerListHead; // Inicializa o ponteiro atual
}

void RankingScreen::display()
{
    std::cout << "=== RANKING GERAL ===\n";
    std::cout << "\n";

    if (current == nullptr) {
        std::cout << "Nenhum jogador encontrado.\n";
        return;
    }

    std::cout << "Nome\tJogos\tVitorias\tDerrotas\n";
    while (current != nullptr) 
    {
        std::cout << current->data.name << "\t"
                  << current->data.gamesPlayed << "\t"
                  << current->data.wins << "\t\t" 
                  << current->data.losses << "\n";

        // Avança para o próximo jogador na lista
        current = current->next;
    }
    
    std::cout << "\n";
    std::cout << "Pressione qualquer tecla para voltar ao menu anterior...\n";
}

void RankingScreen::handleInput(char input)
{
    context->setState(new TechnicalInfoScreen(context));
}