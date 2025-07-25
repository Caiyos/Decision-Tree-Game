#ifndef ISCREEN_HPP
#define ISCREEN_HPP

class ScreenContext;
class IScreen {
protected:
    ScreenContext* context; 

public:
    IScreen(ScreenContext* ctx) : context(ctx) {}

    virtual void display() = 0;
    virtual void handleInput(char choice) = 0;
    virtual ~IScreen() = default;
};

#endif // ISCREEN_HPP
