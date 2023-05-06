#pragma once
#include "./Include.cpp"

class Customer{
public:
	Customer(int id,std::string l_name,std:: string s_name);

	int get_id();
	void print();

private:
	int c_id;
	std::string last_name;
	std::string sure_name;
};