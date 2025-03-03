#include <iostream>

class User
{
private:
    char name[20];
    int age;
    char email[50];
    char password[50];

public:

    User() {
        std::cout << "\n";
    }


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
    User user;

    return 0;
}


