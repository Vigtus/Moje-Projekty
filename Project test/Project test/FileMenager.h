#pragma once
#include "./Include.cpp"
#include "./Rental.h"
#include "./Tools.h"
#include "./Customers.h"

class FileMenager{
    public:
        /*Funckja zwraca vector klientow, ktory tworzy na podstawie odczytu z bazy*/
        static std::vector<Customer*> read_customes();
        /*Funckja zwraca vector narzedzi, ktory tworzy na podstawie odczytu z bazy*/
        static std::vector<Tool_Template*> read_tools();
        /*Funckja zwraca vector Wypozyczen, ktory tworzy na podstawie odczytu z bazy*/
        static std::vector<Rental*> read_rentals();
    private:
    
};
