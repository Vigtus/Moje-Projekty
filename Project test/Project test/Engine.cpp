#include "./Engine.h"

using namespace std;

Engine::Engine(){
}

Engine::~Engine(){
    cout << "destruktor\n";
}

void Engine::insert() {
    int choice = UI::base_menu();
    switch (choice){
        case 4:
            for(int x = 0; x < tools.size(); x++){
                tools[x]->print_data();
            }
            break;
        case 5:
            tools.push_back(UI::add(tools_id));
            tools_id+1;
            break;
        case 6:
            //znalezc element o takim id
            int user_id = 5;
            int position;
            for(int x = 0; x < tools.size(); x++){
                if(tools[x]->get_id() == user_id){
                    position = x;
                }
            }
            //usuwanie
            break;
        case 10:
            is_running = false;
            break;
        default:
            break;
    }
}

void Engine::update() {
    //cout << "update\n";
}

void Engine::write() {
    // for(int x = 0; x < tools.size(); x++){
    //     tools[x]->print_data();
    // }
}

void Engine::clear(){
    cout << "Czyszczenie\n";
    //Bedziemy usuwac wszytkie wskazniki z "new"
    //I ta funckja bedzie po pêtli
}