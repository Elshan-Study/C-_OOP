//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//
//class User
//{
//private:
//    char _name[20];
//    int _age;
//    char _email[50];
//    char _password[50];
//
//    void setPassword(const char* newPassword)
//    {
//        if (newPassword != nullptr && strlen(newPassword) >= 8 && strlen(newPassword) <= 16
//            && newPassword != _password)
//        {
//            strncpy(_password, newPassword, strlen(newPassword));
//            _password[strlen(newPassword) - 1] = '\0';
//        }
//    }
//public:
//    User() // default constructor
//    {
//        strncpy(_name, "Unknown", sizeof(_name));
//        _age = 0;
//        strncpy(_email, "Unknown", sizeof(_email));
//        strncpy(_password, "Unknown", sizeof(_password));
//    }
//
//
//    // constructor with parameters
//    User(const char* name, const int age, const char* email, const char* password)
//    {
//        setName(name);
//        setAge(age);
//        setEmail(email);
//        setPassword(password);
//    }
//
//    const char* getName() const { return _name; }
//    int getAge() const { return _age; }
//    const char* getEmail() const { return _email; }
//    const char* getPassword() const { return _password; }
//
//    void setName(const char* newName)
//    {
//        if (newName && _name[0] != '\0')
//        {
//            strncpy(_name, newName, sizeof(_name));
//            _name[strlen(newName) - 1] = '\0';
//        }
//    }
//
//    void setAge(const int newAge)
//    {
//        if (newAge > 0)
//        {
//            _age = newAge;
//        }
//    }
//
//    void setEmail(const char* newEmail)
//    {
//        if (newEmail && _email[0] != '\0')
//        {
//            strncpy(_email, newEmail, sizeof(_email));
//            _email[strlen(newEmail) - 1] = '\0';
//        }
//    }
//
//
//
//};
//
//void DisplayInfo(const User& user)
//{
//    std::cout << "Name: " << user.getName()
//        << "\nAge: " << user.getAge()
//        << "\nEmail: " << user.getEmail()
//        << "\nPassword: " << user.getPassword()
//        << "\n";
//}

//int main()
//{
//    // User user; // call default constructor
//    User user("Aftandil", 40, "biba@gmail.com", "12345678"); // call  constructor with parameters
//    DisplayInfo(user);
//    return 0;
//}