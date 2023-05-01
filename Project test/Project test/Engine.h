#pragma once
#include "./Include.cpp"
#include "./Tools.h"
#include "./UI.h"

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
        int tools_id = 1;
        std::vector <Tool_Template*> tools;
        // Tool_Template *tools[10];
        int size = 0;
};


