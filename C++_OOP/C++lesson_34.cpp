#include <iostream>
#include <map>
#include <vector>
#define interface struct

//template <typename TType>
//concept Addable = requires(TType object)
//{
//    { object + object }; // TType operator+(const TType&);
//};
//
//template <typename TType>
//concept IsDestructible = requires(TType object, int Value)
//{
//    { object.Destroy(Value) }; // void Destroy(int);
//};
//
//template <typename T>
//T sum(T a, T b) requires Addable<T> // && std::integral<T>
//{
//    return a + b;
//}
//
//// ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
//interface IDestructable // NOLINT(clang-diagnostic-non-virtual-dtor)
//{
//    virtual void Destroy() = 0;
////virtual void Construct() = 0;
//};
//
//class Number
//{
//    friend std::ostream& operator<<(std::ostream& os, const Number& Number);
//
//public:
//    Number(int Number) : My_Number(Number)
//    {
//    }
//
//    Number operator +(const Number& Right) const
//    {
//        return My_Number + Right.My_Number;
//    }
//
//    void Destroy(int)
//    {
//        std::cout << "Object Destroyed!" << '\n';
//    }
//
//private:
//    int My_Number;
//};
//
//template <typename TType> requires std::derived_from<TType, IDestructable> //IsDestructible<TType>
//class Container
//{
//public:
//    ~Container()
//    {
//        for (auto& Value : My_Data)
//        {
//            Value.Destroy();
//        }
//    }
//
//    void Add(const TType& Value)
//    {
//        My_Data.push_back(Value);
//    }
//
//private:
//    std::vector<TType> My_Data;
//};
//
//std::ostream& operator<<(std::ostream& os, const Number& Number)
//{
//    os << Number.My_Number;
//
//    return os;
//}

//int main(int argc, char* argv[])
//{
//     Number Num1{20};
//     Number Num2{30};
//    
//     std::cout << sum(Num1, Num2) << '\n';
//
//
//    Container<Number> MyContainer;
//
//    MyContainer.Add(42);
//
//    return 0;
//}
