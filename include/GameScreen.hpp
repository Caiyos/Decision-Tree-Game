#ifndef GAMESCREEN_HPP
#define GAMESCREEN_HPP

#include <vector>

#include "IScreen.hpp"
#include "ScreenContext.hpp"
#include "searchTree.hpp"

class GameScreen : public IScreen {
private:
    using TreeNode = searchTree::TreeNode;

    TreeNode* root;         
    TreeNode* currentNode;  
    
public:
    GameScreen(ScreenContext* ctx);
    void display() override;
    void checkGameOver();
    void handleInput(char choice) override;
};

#endif // GAMESCREEN_HPP
