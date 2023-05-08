#pragma once
#include "./Tools.h"
#include "./Customers.h"
#include "./Rental.h"
#include "./Include.cpp"

class UI{
    public:
        static int base_menu();
        static Tool_Template* add(int id);
        static Customer* add_customer(int id);
        static Rental* add_rental(int id);
    private:
};