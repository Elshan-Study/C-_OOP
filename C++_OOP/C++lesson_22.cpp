#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//template <typename T>
//class Box
//{
//private:
//    T value;
//public:
//    Box(T value)
//    {
//        this->value = value;
//    }
//};
//
//template<>
//class Box<int>
//{
//};


template <typename T>
void print_numbers(std::initializer_list<T> numbers)
{
    for (auto i : numbers)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";
}

int main()
{
   /* Box<int> box(5);
    Box<double> box_2(5.34);*/

    print_numbers<int>({ 1, 2, 3, 4, 5, 6 });
   
    return 0;
}