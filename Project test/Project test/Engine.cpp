#include "./Engine.h"

using namespace std;

Engine::Engine(){
    customers = FileMenager::read_customes();
    if(customers.size() > 0){
        customers_id = customers[customers.size()-1]->get_id() + 1;
    }
    tools = FileMenager::read_tools();
    if(tools.size() > 0){
        tools_id = tools[tools.size()-1]->get_id() + 1;
    }
    rentals = FileMenager::read_rentals();
    if(rentals.size() > 0){
        rentals_id = rentals[rentals.size() - 1] ->get_id() + 1;
    }
}

Engine::~Engine(){
    for(int x = 0; x < tools.size(); x++){
        delete tools[x];
    }
    for (int x = 0; x < customers.size(); x++) {
        delete customers[x];
    }
    for (int x = 0; x < rentals.size(); x++) {
        delete rentals[x];
    }
}

void Engine::insert() {
    int choice = UI::base_menu();
    int user_id = 5;
    int position = -1;
    Rental *new_rental;
    switch (choice){
        case 1:
            //Wypozyczenie
            new_rental = UI::add_rental(rentals_id, customers, tools);
            if(new_rental != 0){
                rentals.push_back(new_rental);
                rentals_id++;
                std::cout << "\nDodano wyporzyczenie\n";
            }else{
                std::cout << "\033[95mERROR\033[0m::BAD ID IN CUSTOMERS ID OR TOOLS ID\n";
            }
            break;
        case 2:
            std::cout<<"podaj ID: ";
            std::cin>>user_id;
            for(int x = 0; x < rentals.size(); x++){
                if(rentals[x]->get_id() == user_id){
                    position = x;
                }
            }
            if(position < 0){
                std::cout << "\033[93mERROR\033[0m::BAD ID\n";
            }else{
                UI::delete_data("rental", rentals[position]->get_id());
                rentals.erase(rentals.begin()+position);
                            std::cout << "\nWypozyczenie usunieto z listy\n";
            }
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
                    if(customers[h]->get_id() == rentals[x]->get_customer_id()){
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
            std::cout << "\nDodano narzedzie\n";
            break;
        case 6:
            std::cout<<"podaj ID: ";
            std::cin>>user_id;
            for(int x = 0; x < tools.size(); x++){
                if(tools[x]->get_id() == user_id){
                    position = x;
                }
            }
            if(position < 0){
                std::cout << "\033[93mERROR\033[0m::BAD ID\n";
            }else{
                UI::delete_data("tool",tools[position]->get_id());
                tools.erase(tools.begin()+position);
                std::cout << "\nUsunieto narzedzie\n";
            }
            break;
        case 7:
            for (int x = 0; x < customers.size(); x++) {
                customers[x]->print();
            }
            break;
        case 8:
            customers.push_back(UI::add_customer(customers_id));
            customers_id++;
            std::cout << "\nDodano klienta\n";
            break;
        case 9:
            std::cout<<"podaj ID: ";
            std::cin>>user_id;
            for(int x = 0; x < customers.size(); x++){
                if(customers[x]->get_id() == user_id){
                    position = x;
                }
            }
            if(position < 0){
                std::cout << "\033[93mERROR\033[0m::BAD ID\n";
            }else{
                UI::delete_data("customer",customers[position]->get_id());
                customers.erase(customers.begin()+position);
                std::cout << "\nUsunieto klienta\n";
            }
            break;
        case 10:
            is_running = false;
            break;
        default:
            break;
    }
}

