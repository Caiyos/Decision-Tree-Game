#ifndef SINGLEPLAYERSTATSSCREEN_HPP
#define SINGLEPLAYERSTATSSCREEN_HPP

#include "IScreen.hpp"
#include "ScreenContext.hpp"

#include <string.h>

class SinglePlayerStatsScreen : public IScreen {
private:
    ScreenContext* context;
    
    std::string playerName;
    
public:
    SinglePlayerStatsScreen(ScreenContext* ctx, const std::string& name);
    void display() override;
    void handleInput(char choice) override;
};

#endif // SINGLEPLAYERSTATSSCREEN_HPP
