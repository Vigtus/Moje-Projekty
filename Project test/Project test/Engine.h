#pragma once
#include "./Include.cpp"
#include "./Tools.h"
#include "./UI.h"
#include "./Customers.h"
#include "./Rental.h"
#include "./FileMenager.h"

class Engine {
    public:
        /* Konstruktor, odczyt z bazy danych/pamieci i przypisanie do vectorow */
        Engine();
        ~Engine();

        /*G³ówna funckcja, w niej odbywa sie wszystko*/
        void insert();
        /*Funkcja sprawdzajaca, czy pentla ma sie dalej wykonywac*/
        bool running() { return is_running; };
    private:
        bool is_running = true;
        int tools_id = 1, customers_id = 1, rentals_id = 1;
        std::vector <Tool_Template*> tools;
        std::vector <Customer*> customers;
        std::vector <Rental*> rentals;
        int size = 0;
};


