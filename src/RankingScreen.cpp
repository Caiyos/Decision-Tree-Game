#include "RankingScreen.hpp"
#include "MainMenuScreen.hpp" // Adicionado para new MainMenuScreen
#include "pairList.hpp"
#include "PlayerData.hpp"
#include <iostream>

RankingScreen::RankingScreen(ScreenContext* ctx) : IScreen(ctx), context(ctx){}

void RankingScreen::display(){
    system("cls");
    std::cout << "=== RANKING GERAL ===\n";
    std::cout << "\n";
    pairList::PlayerListNode* current = context->getGamePlayerDataHead();

    if (current == nullptr) {
        std::cout << "Nenhum jogador encontrado.\n";
        return;
    }

    std::cout << "Nome\tJogos\tVitorias\tDerrotas\n";
    while (current != nullptr) {
        std::cout << current->data.name << "\t"
                  << current->data.gamesPlayed << "\t"
                  << current->data.wins << "\t\t" 
                  << current->data.losses << "\n";
        current = current->next;
    }
    
    std::cout << "\n";
    std::cout << "Pressione qualquer tecla para voltar ao Menu Principal...\n";
}

void RankingScreen::handleInput(char input){
    context->setState(new MainMenuScreen(context));
}