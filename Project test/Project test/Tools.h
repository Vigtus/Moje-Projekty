#pragma once
#include "./Include.cpp"


class Tool_Template {
    public:
        virtual double get_price(){return 0;}
        virtual std::string get_name(){return "";}
        virtual int get_id(){return 0;}
        virtual void print_data(){}
};

class Tool :public Tool_Template{
    public:
        Tool(int id, double price, std::string name);
        ~Tool();

        double get_price();
        std::string get_name();
        int get_id();
        
    private:
        int tool_id;
        double tool_price;
        std::string tool_name;
};

class Generator: public Tool{
    public:
        Generator(int id, double price, std::string name, bool digital);
        ~Generator();

        void print_data();
    private:
        bool g_digital;
};

class Multimeter: public Tool{
    public:
        Multimeter(int id, double price, std::string name, bool digital, double resolution, double accuracy, int range);
        ~Multimeter();

        void print_data();
    private:
        bool m_digital;
        double m_resolution;
        double m_accuracy;
        int m_range;
};

class Oscilloscope : public Tool {
public:
    Oscilloscope(int id, double price, std::string name, bool digital, double resolution, double accuracy, int range);
    ~Oscilloscope();

    void print_data();
private:
    bool o_digital;
    double o_resolution;
    double o_accuracy;
    int o_range;
};