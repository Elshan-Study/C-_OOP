#pragma once
#include <iostream>
#include <sstream>
#include <fstream>

class Expedition {
protected:
    std::string name;
    int year;
    float temperature;
public:
    Expedition(const std::string& name, int year, float temperature) : name(name), year(year), temperature(temperature) {}
    virtual void printInfo() const = 0;  
    virtual ~Expedition() {}
};

class NorthPoleExpedition : public Expedition {
public:
    NorthPoleExpedition(const std::string& name, int year, float temperature): Expedition(name, year, temperature) {}

    void printInfo() const override {
        std::cout << "North Pole Expedition: " << name << ", Year: " << year << ", Temperature: " << temperature << "°C" << std::endl;
    }

    void saveToFile(std::ofstream& outFile) {
        if (!outFile)
        {
            return;
        }

        outFile << "North;" << name << ";" << year << ";" << temperature << std::endl;

        /*outFile.close();*/
    }
};

class SouthPoleExpedition : public Expedition {

public:
    SouthPoleExpedition(const std::string& name, int year, float temperature) : Expedition(name, year, temperature) {}


    void printInfo() const override {
        std::cout << "South Pole Expedition: " << name << ", Year: " << year << ", Temperature: " << temperature << "°C" << std::endl;
    }

    void saveToFile(std::ofstream& outFile) {
        if (!outFile)
        {
            return;
        }

        outFile << "South;" << name << ";" << year << ";" << temperature << std::endl;

        /*outFile.close();*/
    }
};

