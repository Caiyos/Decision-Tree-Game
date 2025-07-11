#ifndef SCREENCONTEXT_HPP
#define SCREENCONTEXT_HPP

#include "IScreen.hpp"

class ScreenContext {
private:
    IScreen* currentState;

public:
    void setState(IScreen* state);
    void display();
    void handleInput(char choice);
};

#endif // SCREENCONTEXT_HPP