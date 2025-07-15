#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include <vector>

#include "IScreen.hpp"
#include "ScreenContext.hpp"
#include "searchTree.hpp"

class GameScreen : public IScreen {
private:
    using TreeNode = searchTree::TreeNode;

    ScreenContext* context;
    TreeNode* root;         
    TreeNode* currentNode;  

    void checkGameOver();

public:
    GameScreen(ScreenContext* ctx);
    void display() override;
    void handleInput(char choice) override;
};

#endif // GAMESCREEN_HPP
