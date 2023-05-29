#pragma once
#include "./Tools.h"
#include "./Customers.h"
#include "./Rental.h"
#include "./Include.cpp"

class UI{
    public:
        /* Wyœwietlenie podstawowego menu */
        static int base_menu();
        /* Dodanie narzêdzia, funckcja zwraca new Tool...*/
        static Tool_Template* add(int id);
        /* Dodanie klienta, funkcja zwraca new Customer */
        static Customer* add_customer(int id);
        /* Dodanie wyporzyczenie, funkcja zwraca new Rental lub 0 jesli dane wejsciowe sa nieprawidlowe */
        static Rental* add_rental(int id, std::vector<Customer*> &customers, std::vector<Tool_Template*> &tools);


        /*
        Funkcja bierze za argument typ do usuniecia i jego id   
        Jeœli znajdzie ten typ w pliku i to idi, to do nowo utworzonego
        Pliku nie dopisuje tego narzsedzia/klienta/wypozyczenia
        */
        static void delete_data(std::string type, int id);
};