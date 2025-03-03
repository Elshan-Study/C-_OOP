#include <iostream>

class User
{
private:
    char _name[20];
    int _age;
    char _email[50];
    char _password[50];

    void setPassword(const char* newPassword) {
        if (newPassword != nullptr && strlen(newPassword) >= 8 && strlen(newPassword) <= 16 && newPassword != _password)
        {
            strncpy_s(_password, newPassword, sizeof(newPassword));
            _password[strlen(newPassword) - 1] = '\0';
        }
    }

public:

    User() 
    {    /* default constructor*/
  
        strncpy_s(_name, "Unknown", sizeof(_name));
        _age = 0;
        strncpy_s(_email, "Unknown", sizeof(_email));
        strncpy_s(_password, "Unknown", sizeof(_password));
    }

    User(const char* name)


    const char* getName() const { return _name; }

    int getAge() const { return _age; } /*const запрещает внутри метода менять данные*/
    const char* getEmail() const { return _email; }
    const char* getPassword() const { return _password; }

    void setName(const char* newName)
    {
        if (newName && _name != "/0")
        {
            strncpy_s(_name, "Unknown", sizeof(newName));
        }
    }

    void setAge(int newAge)
    {
        if (newAge > 0)
        {
            _age = newAge;
        }
    }
};

void displayInfo(const User& user) {

    std::cout << "Name: " << user.getName();
    std::cout << "\nAge: " << user.getAge();
    std::cout << "\nEmail: " << email;
    std::cout << "\nPassword: " << password;
    std::cout << "\n";
}

int main()
{
    User user;

    return 0;
}


