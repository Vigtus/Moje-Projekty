#include <iostream>
#include "./Engine.h"

Engine *engine = nullptr;


int main(){    
    engine = new Engine();     //Konstruktor

    while(engine->running()){
            engine->insert();   //Wprowadzania
            engine->update();   //Update
            engine->write();    //Write
    }
    engine->clear();

    return 0;
}