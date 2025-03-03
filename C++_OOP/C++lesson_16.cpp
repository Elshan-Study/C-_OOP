#include <iostream>

class User
{
    char name[20];
    int age;
    char email[50];
    char password[50];

    void display_info() {

        std::cout << "Name: " << name;
        std::cout << "\nAge: " << age;
        std::cout << "\nEmail: " << email;
        std::cout << "\nPassword: " << password;
        std::cout << "\n";
    }
};

int main()
{
    

    return 0;
}


