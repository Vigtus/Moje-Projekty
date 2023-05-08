#include "./FileMenager.h"



std::vector<Customer*> FileMenager::read_customes(){
    std::vector<Customer*> vectorek;
    std::string line;
    std::vector<std::string> elements;
    std::ifstream file(PATH);
    while(std::getline(file,line)){
        std::string delimiter = "|";
        size_t pos = 0;
        std::string token;
        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            elements.push_back(token);
            line.erase(0, pos + delimiter.length());
        }
        if(elements.size()>0){
            if(elements[0] == "$CUSTOMER"){
                //create new customer
                //id, surname, name
                vectorek.push_back(new Customer(std::stoi(elements[1]),elements[2],elements[3]));
            }
        }
        elements.clear();
    }
    file.close();
    return vectorek;
}