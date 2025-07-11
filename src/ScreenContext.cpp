#include "ScreenContext.hpp"

void ScreenContext::setState(IScreen* state) {
    currentState = state;
}

void ScreenContext::display() {
    if (currentState) currentState->display();
}

void ScreenContext::handleInput(char choice) {
    if (currentState) currentState->handleInput(choice);
}
