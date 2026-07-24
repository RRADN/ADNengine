#pragma once 

class Events {
public:
    Events();
    ~Events() = default;

    bool update();

private:
    bool shouldClose;

    void inputCase();
};