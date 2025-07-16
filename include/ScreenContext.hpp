#ifndef SCREENCONTEXT_HPP
#define SCREENCONTEXT_HPP

#include "IScreen.hpp"
#include "searchTree.hpp"
#include "simpleList.hpp"

class ScreenContext {
private:
    IScreen* currentScreen;
    searchTree::TreeNode* gameTreeRoot;
    simpleList::ListNode* gameListHead;

    std::string finalMessage;

public:
    ScreenContext();
    
    void setState(IScreen* state);
    void display();
    void handleInput(char choice);

    std::string getFinalMessage() const;
    void setFinalMessage(const std::string& message);

    void setGameTreeRoot(searchTree::TreeNode* r);
    searchTree::TreeNode* getGameTreeRoot() const;

    void setGameListHead(simpleList::ListNode* head);
    simpleList::ListNode* getGameListHead() const;
};

#endif // SCREENCONTEXT_HPP