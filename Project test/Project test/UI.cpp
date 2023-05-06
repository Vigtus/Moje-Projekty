#include "./UI.h"

int UI::base_menu(){
    int wybor;
    std::cout << "Wybierz: ";
    std::cin >> wybor;
    std::cout<< std::endl;
    return wybor;
}

Tool_Template* UI::add(int id){
    std::string name;
    double price;
    int tool_type;
    bool is_digital;
    int range;
    std::cout << "\nPRICE: ";
    std::cin>> price;
    std::cout << "\nNAME: ";
    std::cin >> name;
    std::cout<< "\nSELECT TOOL TYPE: \n1.GENERATOR \n 2.MULTIMETR \n 3.OSCILOSCOPE\n WYBOR:: ";
    std::cin >> tool_type;
    switch(tool_type){
        case 1:
            std::cout << "\nDIGITAL [1|0]: ";
            std::cin >> is_digital;
            return new Generator(id,price,name,is_digital);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            break;
    }
    return 0;
}

Customer* UI::add_customer(int id){
    std::string name;
    std::string surname;
    std::cout<<"Podaj imie: ";
    std::cin>>name;
    std::cout<<std::endl<< "Podaj nazwisko: ";
    std::cin>>surname;
    return new Customer(id,surname,name);
}

Rental* UI::add_rental(int id){
    return new Rental(1,1,1,1,1,"1");
}