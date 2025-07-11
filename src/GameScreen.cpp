#include <iostream>

#include "GameScreen.hpp"
#include "MainMenuScreen.hpp"
#include "GameOverScreen.hpp"

GameScreen::GameScreen(ScreenContext* ctx) : context(ctx), root(nullptr), currentNode(nullptr) {
    setupGame();
    currentNode = root;
}

void GameScreen::setupGame() {
    // Level 1
    root = new DecisionNode{"Você acorda em uma cabana escura. Sair pela porta?", true, nullptr, nullptr};
    // Level 2
    root->yes = new DecisionNode{"Você ouve passos lá fora. Esconder-se debaixo da cama?", true, nullptr, nullptr};
    root->no = new DecisionNode{"Você encontra uma faca na cozinha. Pegar a faca?", true, nullptr, nullptr};
    // Level 3
    root->yes->yes = new DecisionNode{"A porta se abre lentamente. Ficar imóvel?", true, nullptr, nullptr};
    root->yes->no = new DecisionNode{"Você vê uma janela aberta. Pular pela janela?", true, nullptr, nullptr};
    root->no->yes = new DecisionNode{"Você ouve um grito vindo do porão. Investigar?", true, nullptr, nullptr};
    root->no->no = new DecisionNode{"Você encontra um telefone sem sinal. Tentar consertar?", true, nullptr, nullptr};
    // Level 4 (leaves)
    root->yes->yes->yes = new DecisionNode{"Você sobreviveu à noite!", true, nullptr, nullptr};
    root->yes->yes->no = new DecisionNode{"A criatura te encontra.", false, nullptr, nullptr};
    root->yes->no->yes = new DecisionNode{"Você escapa pela floresta!", true, nullptr, nullptr};
    root->yes->no->no = new DecisionNode{"Você cai e se machuca.", false, nullptr, nullptr};
    root->no->yes->yes = new DecisionNode{"Você encontra um sobrevivente!", true, nullptr, nullptr};
    root->no->yes->no = new DecisionNode{"O grito era uma armadilha.", false, nullptr, nullptr};
    root->no->no->yes = new DecisionNode{"O telefone funciona! Resgate a caminho.", true, nullptr, nullptr};
    root->no->no->no = new DecisionNode{"Você faz barulho e é encontrado.", false, nullptr, nullptr};
}

void GameScreen::display() {
    std::cout << "=== Contexto ===\n";
    if (currentNode) {
        std::cout << currentNode->question << "\n\n";
    } else {
        std::cout << "Fim do jogo ou erro na árvore de decisões.\n\n";
    }
    std::cout << "=== Faça sua escolha ===\n";
    std::cout << "1. Sim\n";
    std::cout << "2. Não\n";
    std::cout << "0. Sair do Jogo\n";
}

void GameScreen::checkGameOver() {
    if (!currentNode->yes && !currentNode->no) {
        std::string message;
        if (currentNode->go) {
            message = "Parabéns! " + currentNode->question;
        } else {
            message = currentNode->question + " Boa sorte na próxima tentativa.";
        }
        context->setState(new GameOverScreen(context, message));
    }
}

void GameScreen::handleInput(char choice) {
    switch (choice) {
        case '1': // Sim
            if (currentNode && currentNode->yes) {
                currentNode = currentNode->yes;
                checkGameOver();
            }
            break;
        case '2': // Não
            if (currentNode && currentNode->no) {
                currentNode = currentNode->no;
                checkGameOver();
            }
            break;
        case '0': // Sair do Jogo
            context->setState(new MainMenuScreen(context));
            break;
    }
}