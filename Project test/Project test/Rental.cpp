#include "./Rental.h"

Rental::Rental(int c_id, int c_tool_id, int c_customer_id, double c_cost, int c_days, std::string c_start_date) {
    id = c_id;
    tool_id = c_tool_id;
    customer_id = c_customer_id;
    cost = c_cost;
    days = c_days;
    start_date = c_start_date;
};



void Rental::print(Tool_Template *tool, Customer *customer){
    std::cout<< "ID: " << id << " | Tool: ";
    tool->print_data();
    std::cout << " | Customer: ";
    customer->print();
    std::cout << "Start: " << start_date << " | Days: " << days << " | Total cost: " << days*tool->get_price() << std::endl;
}