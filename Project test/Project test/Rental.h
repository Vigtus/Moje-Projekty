#pragma once
#include "./Include.cpp"
#include "./Tools.h"
#include "./Customers.h"

class Rental{
public:
    Rental(int c_id, int c_tool_id, int c_customer_id, double c_cost, int c_days, std::string c_start_date);
    void print(Tool_Template *tool, Customer *customer);
    
    int get_id(){return id;}
    int get_tool_id(){return tool_id;}
    int get_customer_id(){return customer_id;}
private:
    int id;
    int tool_id;
    int customer_id;
    double cost;
    int days;
    std::string start_date;
};

/*
    ID
    TOOL_ID
    CUSOTMER_ID
    COST
    DAYS
    START_DATE
*/

