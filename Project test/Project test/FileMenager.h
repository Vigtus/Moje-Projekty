#pragma once
#include "./Include.cpp"
#include "./Rental.h"
#include "./Tools.h"
#include "./Customers.h"

class FileMenager{
    public:
        static std::vector<Customer*> read_customes();
        static std::vector<Tool_Template*> read_tools();
        static std::vector<Rental*> read_rentals();
    private:
    
};
