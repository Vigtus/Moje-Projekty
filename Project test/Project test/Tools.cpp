#include "./Tools.h"

//Tool

Tool::Tool(int id, double price, std::string name){
    tool_id=id;
    tool_price = price;
    tool_name = name;
}

double Tool::get_price(){
    return tool_price;
}

int Tool::get_id(){
    return tool_id;
}

std::string Tool::get_name(){
    return tool_name;
}

//Generator

Generator::Generator(int id, double price, std::string name, bool digital): Tool(id,price,name){
    g_digital = digital;
}

void Generator::print_data(){
    //Wysweitlic price,id,name,digital
    std::cout << "NAME: " << get_name() << " | ID: " << get_id() << " | PRICE: " << get_price() << " | DIGITAL?" << g_digital << std::endl;
}
