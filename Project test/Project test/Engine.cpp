#include "./Engine.h"

using namespace std;

Engine::Engine(){
}

Engine::~Engine(){
    cout << "destruktor\n";
}

void Engine::insert() {
    std::string name;
    double price;
    bool is_digital;
    std::cout << "\nNAME: ";
    std::cin >> name;
    std::cout << "\nPRICE: ";
    std::cin>> price;
    std::cout << "\nDIGITAL [1|0]: ";
    std::cin >> is_digital;
    tools[size] = new Generator(size+1,price,name,is_digital);
    size++;
}

void Engine::update() {
    cout << "update\n";
}

void Engine::write() {
    for(int x = 0; x < size; x++){
        tools[x]->print_data();
    }
}

void Engine::clear(){
    cout << "Czyszczenie\n";
    //Bedziemy usuwac wszytkie wskazniki z "new"
    //I ta funckja bedzie po pêtli
}