#ifndef ISCREEN_HPP
#define ISCREEN_HPP

class IScreen {
public:
    virtual void display() = 0;
    virtual void handleInput(char choice) = 0;
    virtual ~IScreen() = default;
};

#endif // ISCREEN_HPP
