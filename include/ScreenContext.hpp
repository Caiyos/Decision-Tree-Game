#ifndef SCREENCONTEXT_HPP
#define SCREENCONTEXT_HPP

#include "IScreen.hpp"
#include "searchTree.hpp"

class ScreenContext {
private:
    IScreen* currentScreen;
    searchTree::TreeNode* gameTreeRoot;;
public:
    ScreenContext();
    
    void setState(IScreen* state);
    void display();
    void handleInput(char choice);

    void setGameTreeRoot(searchTree::TreeNode* r);
    searchTree::TreeNode* getGameTreeRoot() const;
};

#endif // SCREENCONTEXT_HPP