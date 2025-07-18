#ifndef TREESCREEN_HPP
#define TREESCREEN_HPP

#include "IScreen.hpp"
#include "ScreenContext.hpp"
#include "searchTree.hpp"

class TreeScreen : public IScreen {
private:
    searchTree::TreeNode* gameTreeRoot;
    
public:
    TreeScreen(ScreenContext* ctx);
    void display() override;
    void handleInput(char choice) override;
};

#endif // TREESCREEN_HPP
