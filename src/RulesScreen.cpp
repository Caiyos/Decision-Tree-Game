#include <iostream>

#include "RulesScreen.hpp"
#include "MainMenuScreen.hpp"

RulesScreen::RulesScreen(ScreenContext* ctx) 
  : IScreen(ctx)
{}

void RulesScreen::display() 
{
    std::cout << "Regras do jogo:                                            \n";
    std::cout << "1. Descubra o que está acontecendo no Asilo Mount Massive. \n";
    std::cout << "2. Faça escolhas que afetarão o resultado do jogo. \n";
    std::cout << "3. Use sua inteligência e sorte para sobreviver aos horrores. \n";
    std::cout << "4. Explore o ambiente e colete informações. \n";
    std::cout << "5. O jogo termina quando você alcançar um dos finais. \n";
    std::cout << "                                                           \n";
    std::cout << "Pressione qualquer tecla para voltar ao menu.              \n";
}

void RulesScreen::handleInput(char choice) 
{
    context->setState(new MainMenuScreen(context));
}
