#include <iostream>
#include <vector>

//int main(int argc, char* argv[])
//{
//    using namespace std;
//    // Standard Template Library
//
//    vector<int> Vect; //
//
//    Vect.push_back(42);
//    Vect.pop_back();
//    Vect.push_back(10);
//    Vect.push_back(20);
//    Vect.push_back(30);
//
//    //Vect.erase(Vect.begin());
//    //Vect.erase(Vect.end() - 1);
//    //Vect.erase(Vect.begin(), Vect.end() - 1);
//
//    // auto begin = Vect.begin();
//    // auto end = Vect.end();
//    //
//    // while (begin != end)
//    // {
//    //     std::cout << *begin << '\n';
//    //
//    //     ++begin;
//    // }
//
//    // Vect[20] /= 2; // not safe
//
//    try
//    {
//        int& ref = Vect.at(20); // safe
//    }
//    catch (std::out_of_range& ex)
//    {
//        std::cout << ex.what() << '\n';
//    }
//
//    Vect.insert(Vect.begin() + 1, 42);
//
//    for (auto& Value : Vect)
//    {
//        std::cout << Value << '\n';
//    }
//
//    return 0;
//}
