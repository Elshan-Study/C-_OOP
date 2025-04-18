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

void write_to_file(const std::string file_name, Directory*& array, size_t& size)
{
    std::ofstream out(file_name, std::ios::binary);

    if (!out.is_open())
    {
        throw std::runtime_error("Cannot open file");
    }

    out.write(reinterpret_cast<const char*>(&size), sizeof(size_t));

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

void read_from_file(std::string file_name, Directory*& array, size_t& size)
{
    std::ifstream in(file_name, std::ios::binary);

    if (!in.is_open())
    {
        throw std::runtime_error("Cannot open file");
    }

    in.read(reinterpret_cast<char*>(&size), sizeof(size_t));

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

void print_directory(Directory& d)
{
    std::cout << "Firm Name: " << d.getFirmName() << "\n";
    std::cout << "Owner: " << d.getOwner() << "\n";
    std::cout << "Phone: " << d.getPhone() << "\n";
    std::cout << "Address: " << d.getAddress() << "\n";
    std::cout << "Occupation: " << d.getOccupation() << "\n";
    std::cout << "-----------------------------\n";
}

void search_by_field(Directory* data, size_t size, const std::string& query, const std::string& field)
{
    bool found = false;
    for (size_t i = 0; i < size; ++i)
    {
        std::string value;
        if (field == "firm") value = data[i].getFirmName();
        else if (field == "owner") value = data[i].getOwner();
        else if (field == "phone") value = data[i].getPhone();
        else if (field == "occupation") value = data[i].getOccupation();
        else continue;

        if (value.find(query) != std::string::npos)
        {
            print_directory(data[i]);
            found = true;
        }
    }
    if (!found) std::cout << "No matches found.\n";
}

void add_entry(Directory*& data, size_t& size)
{
    std::string firm, owner, phone, address, occupation;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    std::cout << "Enter firm name: "; std::getline(std::cin, firm);
    std::cout << "Enter owner name: "; std::getline(std::cin, owner);
    std::cout << "Enter phone number: "; std::getline(std::cin, phone);
    std::cout << "Enter address: "; std::getline(std::cin, address);
    std::cout << "Enter occupation: "; std::getline(std::cin, occupation);

    Directory* new_data = new Directory[size + 1];
    for (size_t i = 0; i < size; ++i)
        new_data[i] = data[i];

    new_data[size] = Directory(firm, owner, phone, address, occupation);

    delete[] data;
    data = new_data;
    ++size;
}

void show_all(Directory* data, size_t size)
{
    if (size == 0)
    {
        std::cout << "Directory is empty.\n";
        return;
    }

    for (size_t i = 0; i < size; ++i)
        print_directory(data[i]);
}

void show_menu()
{
    std::cout << "\n=== Directory Menu ===\n";
    std::cout << "1. Search by Firm Name\n";
    std::cout << "2. Search by Owner\n";
    std::cout << "3. Search by Phone\n";
    std::cout << "4. Search by Occupation\n";
    std::cout << "5. Show All Records\n";
    std::cout << "6. Add New Record\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

int main()
{
    Directory* directory = new Directory[10];
    size_t size = 0;
    read_from_file("hw29.txt", directory, size);

    char choice;
    while (true)
    {
        show_menu();
        std::cin >> choice;

        switch (choice-48)
        {
        case 1:
        {
            std::string query;
            std::cout << "Enter firm name to search: ";
            std::cin.ignore(); std::getline(std::cin, query);
            search_by_field(directory, size, query, "firm");
            break;
        }
        case 2:
        {
            std::string query;
            std::cout << "Enter owner name to search: ";
            std::cin.ignore(); std::getline(std::cin, query);
            search_by_field(directory, size, query, "owner");
            break;
        }
        case 3:
        {
            std::string query;
            std::cout << "Enter phone number to search: ";
            std::cin.ignore(); std::getline(std::cin, query);
            search_by_field(directory, size, query, "phone");
            break;
        }
        case 4:
        {
            std::string query;
            std::cout << "Enter occupation to search: ";
            std::cin.ignore(); std::getline(std::cin, query);
            search_by_field(directory, size, query, "occupation");
            break;
        }
        case 5:
            show_all(directory, size);
            break;
        case 6:
            add_entry(directory, size);
            write_to_file("hw29.txt", directory, size);
            break;
        case 0:
            std::cout << "Exiting...\n";
            delete[] directory;
            return 0;
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    }
}