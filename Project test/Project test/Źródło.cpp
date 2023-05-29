#include <iostream>
#include "./Engine.h"

Engine *engine = nullptr;


int main(){    
    engine = new Engine();     //Konstruktor

    while(engine->running()){
            engine->insert();   //Wprowadzania
    }
    delete engine;
    return 0;
}