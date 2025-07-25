#include <iostream>

#include "StoryScreen.hpp"
#include "MainMenuScreen.hpp"

StoryScreen::StoryScreen(ScreenContext* ctx) 
  : IScreen(ctx)
{}

void StoryScreen::display() 
{
    std::cout << "História do jogo:                                           \n";
    std::cout << "Você é Miles Upshur, um repórter investigativo com ambição que está a ponto de conhecer o Inferno na Terra. \n";
    std::cout << "Sempre pronto a se arriscar aprofundando-se nas histórias que nenhum outro jornalista se atreveria a investigar, \n";
    std::cout << "você vai descobrir o segredo negro no coração do Manicômio de Monte Massive.\n";
    std::cout << "Fique vivo o quanto puder, gravando tudo. \n";
    std::cout << "Você não é um lutador; para vasculhar os horrores de Monte Massive e expor a verdade, \n";
    std::cout << "suas únicas escolhas são correr, se esconder ou morrer. \n";
    std::cout << "\n";
    std::cout << "Pressione qualquer tecla para voltar ao menu.\n";
}

void StoryScreen::handleInput(char choice) 
{
    context->setState(new MainMenuScreen(context));
}