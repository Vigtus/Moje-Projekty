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


        /*
        Funkcja bierze za argument typ do usuniecia i jego id   
        Jeœli znajdzie ten typ w pliku i to idi, to do nowo utworzonego
        Pliku nie dopisuje tego narzsedzia/klienta/wypozyczenia
        */
        static void delete_data(std::string type, int id);
    private:
};