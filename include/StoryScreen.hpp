#ifndef STORYSCREEN_HPP
#define STORYSCREEN_HPP

#include "IScreen.hpp"
#include "ScreenContext.hpp"

class StoryScreen : public IScreen {
private:

public:
    StoryScreen(ScreenContext* ctx);
    void display() override;
    void handleInput(char choice) override;
};

#endif // STORYSCREEN_HPP
