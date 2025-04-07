#include <iostream>
#include <string>
#include <cassert>

class file_exception : public std::exception
{
private:
    std::string _msg;
public:
    file_exception(const std::string& msg) : _msg(msg) {}

    char const* what() const noexcept override
    {
        return _msg.c_str();
    }
};


//==================================================
class Calculator
{
public:
    static double divide(double num1, double num2)
    {
        if (num2 == 0)
        {
            throw std::invalid_argument("Divide by 0");
        }
        //assert(num2 != 0);
        return num1 / num2;
    }
};
//==================================================
// class Biba
// {
//     public:
//     virtual ~Biba(){}
// };
//
// class Boba : public Biba {};
//==================================================

int main() {

    // try
    // {
    //     int a = 5, b = 0;
    //
    //     if (b == 0)
    //     {
    //         throw std::invalid_argument("Invalid Input. Zero division error");
    //     }
    //     
    //     std::cout << a / b << '\n';
    // }
    // catch (std::exception &e)
    // {
    //     std::cout << "Test" << '\n';
    //     std::cout << e.what() << '\n';
    // }
    //==================================================
    // try
    // {
    //     std::cout<<Calculator::divide(5,2) << "\n";
    // }
    // catch (std::invalid_argument& e)
    // {
    //     std::cout << e.what() << "\n";
    // }

    //std::cout<<Calculator::divide(5,0) << "\n";

    //==================================================

    // Boba boba;
    // Biba* b = &boba;

    // Biba* b = nullptr;
    //
    // // std::cout<< typeid(*b).name() << '\n';
    // try
    // {
    //     std::cout<< typeid(*b).name() << '\n';
    // }
    // catch (const std::bad_typeid& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }
    //
    //==================================================

    try
    {
        throw file_exception("Test");
    }
    catch (file_exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}