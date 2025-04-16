#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include "SuperVector.h"
#include "SuperVectorT.h"
#include "Expedition.h"
#include "Directory.h"

//homework 28

//void readExpeditions(const std::string& filename, SuperVectorT<Expedition*>& expeditions) {
//    std::ifstream inFile(filename);
//    std::string line;
//
//    if (!inFile)
//    {
//        return;
//    }
//
//    while (getline(inFile, line)) {
//        std::stringstream buffer(line);
//        std::string type, name;
//        int year;
//        float temperature;
//
//        std::getline(buffer, type, ';');
//        std::getline(buffer, name, ';');
//        buffer >> year;
//        buffer.ignore();
//        buffer >> temperature;
//
//        if (type == "North") {
//            expeditions.PushBack(new NorthPoleExpedition(name, year, temperature));
//        }
//        else if (type == "South") {
//            expeditions.PushBack(new SouthPoleExpedition(name, year, temperature));
//        }
//    }
//
//    inFile.close();
//}
//
//void saveExpeditions(const std::string& filename, const SuperVectorT<Expedition*>& expeditions) {
//    std::ofstream outFile(filename);
//
//    for (int i = 0; i < expeditions.Size(); ++i) {
//        auto expedition = expeditions[i];
//        if (dynamic_cast<NorthPoleExpedition*>(expedition)) {
//            static_cast<NorthPoleExpedition*>(expedition)->saveToFile(outFile);
//        }
//        else if (dynamic_cast<SouthPoleExpedition*>(expedition)) {
//            static_cast<SouthPoleExpedition*>(expedition)->saveToFile(outFile);
//        }
//    }
//}
//
//int main()
//{
//    SuperVectorT<Expedition*> expeditions;
//
//    readExpeditions("expeditions.txt", expeditions);
//
//    for (int i = 0; i < expeditions.Size(); ++i) {
//        expeditions[i]->printInfo();
//    }
//
//
//    saveExpeditions("expeditions_out.txt", expeditions);
//
//    for (int i = 0; i < expeditions.Size(); ++i) {
//        delete expeditions[i];
//    }
//
//	return 0;
//}


//homework 29

void write_to_file(const std::string file_name, Directory array[], const size_t size)
{
    std::ofstream out(file_name, std::ios::binary);

    if (!out.is_open())
    {
        throw std::runtime_error("Cannot open file");
    }

    for (size_t i = 0; i < size; i++)
    {
        size_t string_size = array[i].getFirmName().size();
        out.write(reinterpret_cast<char*>(&string_size), sizeof(size_t));
        out.write(array[i].getFirmName().data(), string_size);

        string_size = array[i].getOwner().size();
        out.write(reinterpret_cast<char*>(&string_size), sizeof(size_t));
        out.write(array[i].getOwner().data(), string_size);

        string_size = array[i].getPhone().size();
        out.write(reinterpret_cast<char*>(&string_size), sizeof(size_t));
        out.write(array[i].getPhone().data(), string_size);

        string_size = array[i].getAddress().size();
        out.write(reinterpret_cast<char*>(&string_size), sizeof(size_t));
        out.write(array[i].getAddress().data(), string_size);

        string_size = array[i].getOccupation().size();
        out.write(reinterpret_cast<char*>(&string_size), sizeof(size_t));
        out.write(array[i].getOccupation().data(), string_size);
    }
   
    out.close();
}

void read_from_file(std::string file_name, Directory array[], const size_t size)
{
    std::ifstream in(file_name, std::ios::binary);

    if (!in.is_open())
    {
        throw std::runtime_error("Cannot open file");
    }

    for (size_t i = 0; i < size; i++)
    {
        size_t string_size;

        in.read(reinterpret_cast<char*>(&string_size), sizeof(size_t));
        array[i].getFirmName().resize(string_size);
        in.read(&array[i].getFirmName()[0], string_size);

        in.read(reinterpret_cast<char*>(&string_size), sizeof(size_t));
        array[i].getOwner().resize(string_size);
        in.read(&array[i].getOwner()[0], string_size);

        in.read(reinterpret_cast<char*>(&string_size), sizeof(size_t));
        array[i].getPhone().resize(string_size);
        in.read(&array[i].getPhone()[0], string_size);

        in.read(reinterpret_cast<char*>(&string_size), sizeof(size_t));
        array[i].getAddress().resize(string_size);
        in.read(&array[i].getAddress()[0], string_size);

        in.read(reinterpret_cast<char*>(&string_size), sizeof(size_t));
        array[i].getOccupation().resize(string_size);
        in.read(&array[i].getOccupation()[0], string_size);
    }

    in.close();

}

int main()
{
    const size_t SIZE = 20;
    auto peoples{ std::make_unique<Directory[]>(SIZE) };

    /*Directory p1("Toyota", "Misaki", "+7 88", "Tokio", "Cars");
    peoples[0] = p1;*/

    /*write_to_file("hw29.txt", peoples.get(), SIZE);*/
    read_from_file("hw29.txt", peoples.get(), SIZE);
    std::cout << peoples[0].getFirmName();

    return 0;
}