#ifndef RANKINGSCREEN_HPP
#define RANKINGSCREEN_HPP

#include "IScreen.hpp"
#include "ScreenContext.hpp"

#include "pairList.hpp"

class RankingScreen : public IScreen {
private:
    ScreenContext* context;

public:
    RankingScreen(ScreenContext* ctx);
    void display() override;
    void handleInput(char choice) override;
};

#endif // RANKINGSCREEN_HPP
