#ifndef PLAYER_NAME_SCREEN_HPP
#define PLAYER_NAME_SCREEN_HPP

#include "IScreen.hpp"
#include "ScreenContext.hpp"
#include <string>

class PlayerNameScreen : public IScreen {
private:
    std::string playerNameInput; 
public:
    PlayerNameScreen(ScreenContext* ctx);
    void display() override;
    void handleInput(char input) override;
};

#endif // PLAYER_NAME_SCREEN_HPP