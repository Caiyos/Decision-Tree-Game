#ifndef LISTSCREEN_HPP
#define LISTSCREEN_HPP

#include "IScreen.hpp"
#include "ScreenContext.hpp"
#include "simpleList.hpp"

class ListScreen : public IScreen {
private:
    ScreenContext* context;

    simpleList::ListNode* gameListHead;
    
public:
    ListScreen(ScreenContext* ctx);
    void display() override;
    void handleInput(char choice) override;
};

#endif // LISTSCREEN_HPP
