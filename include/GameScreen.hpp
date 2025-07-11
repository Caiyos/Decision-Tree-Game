#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include <vector>

#include "IScreen.hpp"
#include "ScreenContext.hpp"

class GameScreen : public IScreen {
private:
    typedef struct DecisionNode {
        std::string question;
        bool go;

        DecisionNode* yes;
        DecisionNode* no;
    } DecisionNode;

    ScreenContext* context;
    DecisionNode* root;
    DecisionNode* currentNode;
    
    void setupGame();
    void checkGameOver();

public:
    GameScreen(ScreenContext* ctx);
    void display() override;
    void handleInput(char choice) override;
};

#endif // GAMESCREEN_HPP
