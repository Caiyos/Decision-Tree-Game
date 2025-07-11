#ifndef RULESSCREEN_HPP
#define RULESSCREEN_HPP

#include "IScreen.hpp"
#include "ScreenContext.hpp"

class RulesScreen : public IScreen {
private:
    ScreenContext* context;

public:
    RulesScreen(ScreenContext* ctx);
    void display() override;
    void handleInput(char choice) override;
};

#endif // RULESSCREEN_HPP
