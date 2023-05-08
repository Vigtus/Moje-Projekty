#include "./Engine.h"

using namespace std;

Engine::Engine(){
    customers = FileMenager::read_customes();
    if(customers.size() > 0){
        customers_id = customers[customers.size()-1]->get_id() + 1;
    }
}

Engine::~Engine(){
    cout << "destruktor\n";
}

void Engine::insert() {
    int choice = UI::base_menu();
    int user_id = 5;
    int position;
    //rentals
    //tools
    //customers
    switch (choice){
        case 1:
            //Wypozyczenie
            rentals.push_back(UI::add_rental(4));
            break;
        case 2:
            //Zakonczenie wypozczenia
            break;
        case 3:
            //Lista wypozyczen
            int a,y;
            for(int x = 0; x < rentals.size(); x++){
                for(int h = 0; h < tools.size(); h++){
                    if(tools[h]->get_id() == rentals[x]->get_tool_id()){
                        a = h;
                    }
                }
                for(int h = 0; h < customers.size(); h++){
                    if(customers[h]->get_id() == rentals[x]->get_tool_id()){
                        y = h;
                    }
                }
                rentals[x]->print(tools[a],customers[y]);
            }
            break;
        case 4:
            for(int x = 0; x < tools.size(); x++){
                tools[x]->print_data();
            }
            break;
        case 5:
            tools.push_back(UI::add(tools_id));
            tools_id+=1;
            break;
        case 6:
            std::cout<<"podaj ID: ";
            std::cin>>user_id;
            for(int x = 0; x < tools.size(); x++){
                if(tools[x]->get_id() == user_id){
                    position = x;
                }
            }
            tools.erase(tools.begin()+position);
            break;
        case 7:
            for (int x = 0; x < customers.size(); x++) {
                customers[x]->print();
            }
            break;
        case 8:
            customers.push_back(UI::add_customer(customers_id));
            customers_id++;
            break;
        case 9:
            std::cout<<"podaj ID: ";
            std::cin>>user_id;
            for(int x = 0; x < customers.size(); x++){
                if(customers[x]->get_id() == user_id){
                    position = x;
                }
            }
            customers.erase(customers.begin()+position);
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