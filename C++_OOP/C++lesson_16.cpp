#include <iostream>

class User
{
private:
    char name[20];
    int age;
    char email[50];
    char password[50];

public:

    User() 
    {    /* default constructor*/
  
        strncpy_s(name, "Unknown", sizeof(name));
        age = 0;
        strncpy_s(email, "Unknown", sizeof(email));
        strncpy_s(password, "Unknown", sizeof(password));
    }

    int GetAge() { return age; }
    void SetAge(int age) { this->age = age; }
};

void display_info(User user) {

    std::cout << "Name: " << name;
    std::cout << "\nAge: " << age;
    std::cout << "\nEmail: " << email;
    std::cout << "\nPassword: " << password;
    std::cout << "\n";
}

int main()
{
    User user;

    return 0;
}


