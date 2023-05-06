#include "./Customers.h"

Customer::Customer(int id,std::string l_name,std::string s_name){
    c_id = id;
    last_name = l_name;
    sure_name = s_name;
    
}

void Customer::print() {
    std::cout << "Id: " << c_id << " |Nazwisko: " << last_name << " |Imie: " << sure_name << std::endl;
};

int Customer::get_id(){
    return c_id;
}