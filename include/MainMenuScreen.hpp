#ifndef MAINMENUSCREEN_HPP
#define MAINMENUSCREEN_HPP

#include "IScreen.hpp"
#include "ScreenContext.hpp"

class MainMenuScreen : public IScreen {
private:

public:
    MainMenuScreen(ScreenContext* ctx);
    void display() override;
    void handleInput(char choice) override;
};

#endif // MAINMENUSCREEN_HPP
