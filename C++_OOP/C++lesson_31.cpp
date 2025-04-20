#include <iostream>
#include <functional>

// SHA256

int main()
{
    int BacketSize = 10;

    std::hash<std::string> Hasher;

    auto Hash = Hasher("Rafa"); // functor call

    std::cout << Hash % BacketSize;
}