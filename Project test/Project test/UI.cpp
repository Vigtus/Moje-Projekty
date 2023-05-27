#include "./UI.h"

int UI::base_menu(){
    int wybor;
    std::cout << "Wybierz: ";
    std::cin >> wybor;
    std::cout<< std::endl;
    return wybor;
}

Tool_Template* UI::add(int id){
    std::string name;
    double price, resolution, accuracy;
    int tool_type;
    bool is_digital;
    int range;
    std::cout << "\nPRICE: ";
    std::cin>> price;
    std::cout << "\nNAME: ";
    std::cin >> name;
    std::cout<< "\nSELECT TOOL TYPE: \n1.GENERATOR \n 2.MULTIMETR \n 3.OSCILOSCOPE\n WYBOR:: ";
    std::cin >> tool_type;            
    std::ofstream file(PATH,std::ios::app);
    switch(tool_type){
        case 1:
            std::cout << "\nDIGITAL [1|0]: ";
            std::cin >> is_digital;
            file << "$GENERATOR" << '|' << id << '|' << price << '|' << name << "|" << is_digital << "|" <<"\n";
            file.close();
            return new Generator(id,price,name,is_digital);
            break;
        case 2:
            std::cout << "\nDIGITAL [1|0]: ";
            std::cin >> is_digital;
            std::cout << "RESOLUTION: ";
            std::cin >> resolution;
            std::cout << "ACCURACY: ";
            std::cin >> accuracy;
            std::cout << "RANGE: ";
            std::cin >> range;
            file << "$MULTIMETR" << '|' << id << '|' << price << '|' << name << "|" << is_digital << "|" << resolution << "|" << accuracy << "|" << range << "|" << "\n";
            file.close();
            return new Multimeter(id,price,name,is_digital,resolution,accuracy,range);    
            break;
        case 3:
            std::cout << "\nDIGITAL [1|0]: ";
            std::cin >> is_digital;
            std::cout << "RESOLUTION: ";
            std::cin >> resolution;
            std::cout << "ACCURACY: ";
            std::cin >> accuracy;
            std::cout << "RANGE: ";
            std::cin >> range;
            file << "$OSCILLOSCOPE" << '|' << id << '|' << price << '|' << name << "|" << is_digital << "|" << resolution << "|" << accuracy << "|" << range << "|" << "\n";
            file.close();
            return new Oscilloscope(id, price, name, is_digital, resolution, accuracy, range);
            break;
        default:
            //nic tu nie ma
            break;
    }
    return 0;
}

Customer* UI::add_customer(int id){
    std::string name;
    std::string surname;
    std::cout<<"Podaj imie: ";
    std::cin>>name;
    std::cout<<std::endl<< "Podaj nazwisko: ";
    std::cin>>surname;
    std::ofstream file(PATH,std::ios::app);
    file << "$CUSTOMER" << '|' << id << '|' << surname << '|' << name << "|" <<"\n";
    file.close();
    return new Customer(id,surname,name);
    //Zapisywanie
}

Rental* UI::add_rental(int id){
    int tool_id, customer_id, c_days;
    std::string date;
    std::cout<<"Wprowadz kolejno: tool_id, customer_id, dni, date" << std::endl;
    std::cin>>tool_id;
    std::cin>>customer_id;
    std::cin>>c_days;
    std::cin>> date;
    std::ofstream file(PATH,std::ios::app);
    file << "$RENTAL" << '|' << id << '|' << tool_id << '|' << customer_id << "|" << "1" << "|" << c_days << "|"<<date << "|" << "\n";
    file.close();
    return new Rental(id,tool_id,customer_id,1,c_days,date);
}

void UI::delete_data(std::string type, int id){
    std::vector<std::string> lines_to_add;
    std::string line;
    std::vector<std::string> elements;
    std::ifstream file(PATH);
    while(std::getline(file,line)){
        std::string delimiter = "|";
        std::string linia = line;
        size_t pos = 0;
        std::string token;
        while ((pos = line.find(delimiter)) != std::string::npos) {
            token = line.substr(0, pos);
            elements.push_back(token);
            line.erase(0, pos + delimiter.length());
        }
        if(elements.size()>0){
            if(elements[0] == "$GENERATOR" || elements[0] == "$OSCYLOSCOPE" || elements[0] == "$MULTIMETR"){
                if (type != "tool")
                {
                    lines_to_add.push_back(linia);
                }else{
                    if(std::stoi(elements[1]) != id){
                        lines_to_add.push_back(linia);
                    }
                }
            }
            if(elements[0] == "$CUSTOMER"){
                if (type != "customer")
                {
                    lines_to_add.push_back(linia);
                }else{
                    if(std::stoi(elements[1]) != id){
                        lines_to_add.push_back(linia);
                    }
                }
            }
            if(elements[0] == "$RENTAL"){
                if (type != "rental")
                {
                    lines_to_add.push_back(linia);
                }else{
                    if(std::stoi(elements[1]) != id){
                        lines_to_add.push_back(linia);
                    }
                }
            }
        }
        elements.clear();
    }
    file.close();
    //Musimy zapisac wszystko do pliku na nowo
    std::ofstream file_to_save(PATH);
    for(int x = 0; x < lines_to_add.size(); x++){
        file_to_save << lines_to_add[x] << '\n';
    }
    file_to_save.close();
}