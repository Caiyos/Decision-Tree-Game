#include <iostream>

#include "ListScreen.hpp"
#include "TechnicalInfoScreen.hpp"

ListScreen::ListScreen(ScreenContext* ctx) 
    : IScreen(ctx)
{
    gameListHead = context->getGameListHead();
}

void ListScreen::display() 
{
    std::cout << "=== Lista original ===\n";

    simpleList::printList(gameListHead);

    std::cout << "Pressione qualquer tecla para voltar ao menu anterior.\n";
}

void ListScreen::handleInput(char choice) 
{
    context->setState(new TechnicalInfoScreen(context));
}