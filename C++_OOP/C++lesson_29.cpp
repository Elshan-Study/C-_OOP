#include <iostream>
#include <fstream>
#include <string>


struct Person
{
    std::string name;
    int age;
    double height;

    Person() = default;
    Person(std::string name, int age, double height) : name(name), age(age), height(height) {}
};

void write_struct_to_file(const std::string file_name, const Person& person)
{
    std::ofstream out(file_name, std::ios::binary);

    if (!out)
    {
        throw std::runtime_error("Cannot open file");
    }

    size_t name_size = person.name.size();
    out.write(reinterpret_cast<char*>(&name_size), sizeof(size_t));
    out.write(person.name.data(), name_size);

    out.write(reinterpret_cast<const char*>(&person.age), sizeof(int));
    out.write(reinterpret_cast<const char*>(&person.height), sizeof(double));

    out.close();
}

void read_struct_from_file(std::string file_name, Person& person)
{
    std::ifstream in(file_name, std::ios::binary);

    if (!in)
    {
        throw std::runtime_error("Cannot open file");
    }

    size_t name_size;

    in.read(reinterpret_cast<char*>(&name_size), sizeof(size_t));
    person.name.resize(name_size);
    in.read(&person.name[0], name_size);

    in.read(reinterpret_cast<char*>(&person.age), sizeof(int));
    in.read(reinterpret_cast<char*>(&person.height), sizeof(double));

    in.close();

}




//int main() {
//    // Person person("Bagdagul", 30, 1.55);
//    // write_struct_to_file("Bagdagul.bin", person);
//
//    Person person;
//    read_struct_from_file("Bagdagul.bin", person);
//
//    std::cout << "Person name: " << person.name << "\n" << person.age << "\n" << person.height << "\n";
//    return 0;
//}