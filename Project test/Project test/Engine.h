#pragma once
#include "./Include.cpp"
#include "./Tools.h"

class Engine {
    public:
        Engine();
        ~Engine();

        void insert();
        void update();
        void write();
        void clear();

        bool running() { return is_running; };
    private:
        bool is_running = true;
        Tool_Template *tools[10];
        int size = 0;
};


