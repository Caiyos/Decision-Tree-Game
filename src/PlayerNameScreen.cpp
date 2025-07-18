#include "PlayerNameScreen.hpp"
#include "ScreenContext.hpp"
#include "MainMenuScreen.hpp"
#include "pairList.hpp" 
#include "PlayerData.hpp" 

#include <iostream>
#include <limits>
#include <conio.h>
#include <string.h>
#include <windows.h> // Para Sleep

PlayerNameScreen::PlayerNameScreen(ScreenContext*context)
    : IScreen(context)
{
    playerListHead = context->getGamePlayerListHead();
}

void PlayerNameScreen::display() 
{
    std::cout << "=== Bem-vindo ao Jogo! === \n";
    std::cout << "\n";
    std::cout << "Escolha o seu nome de jogador: \n";
    std::cout << playerNameInput;
}

void PlayerNameScreen::handleInput(char input) 
{
    if (input == '\r' || input == '\n') { // Tecla Enter
        
        if (playerNameInput.empty()) {
            return;
        }

        std::string enteredName = playerNameInput;
        playerNameInput.clear();

        pairList::PlayerListNode* existingPlayerNode = pairList::findPlayerNode(playerListHead, enteredName);

        if (existingPlayerNode != nullptr) 
        {
            std::cout << "\nOla, " << enteredName << "! Encontrei seu progresso.\n";
            std::cout << "Deseja continuar com este jogador? (S/N)\n> ";
            char choice = _getch();
            std::cout << choice << "\n";

            if (choice == 's' || choice == 'S') {
                context->setCurrentPlayerName(enteredName);
                context->setCurrentPlayerDataPtr(&(existingPlayerNode->data));

                /*
                if (context->getCurrentPlayerDataPtr()) {
                    std::cout << "DEBUG: PlayerDataPtr is VALID for player: " << context->getCurrentPlayerDataPtr()->name << std::endl;
                } else {
                    std::cout << "DEBUG: PlayerDataPtr is NULL after setting!" << std::endl;
                }
                _getch();
                */

                context->setState(new MainMenuScreen(context));
                return;
            } 
            else {
                std::cout << "\nPor favor, escolha um nome diferente.\n";
                _getch();
                return;
            }
        } 
        else 
        {
            std::cout << "\nBem-vindo, " << enteredName << "! Criando novo progresso.\n";
            Sleep(1000); // Simula um pequeno atraso para a experiência do usuário

            context->setCurrentPlayerName(enteredName);

            PlayerData newPlayer(enteredName, 0, 0, 0);

            // std::cout << "DEBUG: newPlayer criada. Nome: " << newPlayer.name << std::endl; // PAUSA 2
            // _getch(); // SE O CRASH FOR AQUI, o problema é newPlayer (pouco provável)

            pairList::insertSorted(&playerListHead, newPlayer);

            pairList::PlayerListNode* newNode = pairList::findPlayerNode(playerListHead, enteredName);

            if (newNode) { // Testa se o player foi adicionado
                context->setCurrentPlayerDataPtr(&(newNode->data));
                context->requestDataSave();
                
                /*
                if (context->getCurrentPlayerDataPtr()) {
                    std::cout << "DEBUG: PlayerDataPtr is VALID for player: " << context->getCurrentPlayerDataPtr()->name << std::endl;
                } else {
                    std::cout << "DEBUG: PlayerDataPtr is NULL after setting!" << std::endl;
                }
                _getch();
                */
            }

            // _getch();
            context->setState(new MainMenuScreen(context));
        }

    } else if (input == '\b' || input == 127) { //Del

        if (!playerNameInput.empty()) {
            playerNameInput.pop_back();
        }

    } else if (isprint(input)) {

        playerNameInput += input;

    }
}