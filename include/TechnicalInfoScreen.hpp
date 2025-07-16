#ifndef TECHNICALINFOSCREEN_HPP
#define TECHNICALINFOSCREEN_HPP

#include "IScreen.hpp"
#include "ScreenContext.hpp"

class TechnicalInfoScreen : public IScreen {
private:
    ScreenContext* context;

public:
    TechnicalInfoScreen(ScreenContext* ctx);
    void display() override;
    void handleInput(char choice) override;
};

#endif // TECHNICALINFOSCREEN_HPP