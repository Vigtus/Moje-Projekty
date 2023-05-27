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

std::vector<Tool_Template*> FileMenager::read_tools(){
    std::vector<Tool_Template*> vectorek;
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
            if(elements[0] == "$GENERATOR"){
                vectorek.push_back(new Generator(std::stoi(elements[1]),double(std::stoi(elements[2])), elements[3] ,bool(std::stoi(elements[4]))));
            }
            if (elements[0] == "$MULTIMETR") {
                vectorek.push_back(new Multimeter(std::stoi(elements[1]), double(std::stoi(elements[2])), elements[3], bool(std::stoi(elements[4])), double(std::stoi(elements[5])),  double(std::stoi(elements[6])),  std::stoi(elements[7])));
            }
            if (elements[0] == "$OSCILLOSCOPE") {
                vectorek.push_back(new Oscilloscope(std::stoi(elements[1]), double(std::stoi(elements[2])), elements[3], bool(std::stoi(elements[4])), double(std::stoi(elements[5])),  double(std::stoi(elements[6])),  std::stoi(elements[7])));
            }
        }
        elements.clear();
    }
    file.close();
    return vectorek;
};

std::vector<Rental*> FileMenager::read_rentals(){
    std::vector<Rental*> vectorek;
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
            if(elements[0] == "$RENTAL"){
                //create new customer
                //id, surname, name
                vectorek.push_back(new Rental(std::stoi(elements[1]),std::stoi(elements[2]),std::stoi(elements[3]),1.00,std::stoi(elements[5]),elements[6]));
            }
        }
        elements.clear();
    }
    file.close();
    return vectorek;
};