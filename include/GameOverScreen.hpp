#ifndef GAMEOVERSCREEN_HPP
#define GAMEOVERSCREEN_HPP

#include "IScreen.hpp"
#include "ScreenContext.hpp"

class GameOverScreen : public IScreen {
private:
    std::string message;

public:
    GameOverScreen(ScreenContext* ctx);
    void display() override;
    void handleInput(char choice) override;
};

#endif // GAMEOVERSCREEN_HPP
