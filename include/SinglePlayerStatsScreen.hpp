#ifndef SINGLEPLAYERSTATSSCREEN_HPP
#define SINGLEPLAYERSTATSSCREEN_HPP

#include "IScreen.hpp"
#include "ScreenContext.hpp"
#include "pairList.hpp"

#include <string.h>

class SinglePlayerStatsScreen : public IScreen {
private:
    std::string playerName;

    PlayerData* player;

    pairList::PlayerListNode* playerListHead;
    
public:
    SinglePlayerStatsScreen(ScreenContext* ctx);
    void display() override;
    void handleInput(char choice) override;
};

#endif // SINGLEPLAYERSTATSSCREEN_HPP
