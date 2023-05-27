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

Multimeter::Multimeter(int id, double price, std::string name, bool digital, double resolution, double accuracy, int range) : Tool(id, price, name) {
    m_digital = digital;
    m_resolution=resolution;
    m_accuracy=accuracy;
    m_range=range;
}

void Multimeter::print_data() {
    std::cout << "NAME: " << get_name() << " | ID: " << get_id() << " | PRICE: " << get_price() << " | DIGITAL?" << m_digital << " | RESOLUTION: " << m_resolution << " | ACCURACY: "<< m_accuracy << " | RANGE: " << m_range << std::endl;
}

Oscilloscope::Oscilloscope(int id, double price, std::string name, bool digital, double resolution, double accuracy, int range) : Tool(id, price, name) {
    o_digital = digital;
    o_resolution = resolution;
    o_accuracy = accuracy;
    o_range = range;
}
void Oscilloscope::print_data() {
    std::cout << "NAME: " << get_name() << " | ID: " << get_id() << " | PRICE: " << get_price() << " | DIGITAL?" << o_digital << " | RESOLUTION: " << o_resolution << " | ACCURACY: " << o_accuracy << " | RANGE: " << o_range << std::endl;
}