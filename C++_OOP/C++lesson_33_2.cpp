#include <iostream>
#include <vector>

// generic spec
template <typename TType>
class Array
{
public:
    Array()
    {
        std::cout << "Array<TType>::Array()" << '\n';
    }

    void AddValue(const TType& Value)
    {
    }
};

// full spec
template <>
class Array<bool>
{
public:
    Array()
    {
        std::cout << "Array<bool>::Array()" << '\n';
    }

    void AddValue(bool Value)
    {
    }
};

// partial spec
template <typename TType> // TType != TType*
class Array<TType*> // *, &, &&, [], const
{
public:
    Array()
    {
        std::cout << "Array<TType*>::Array()" << '\n';
    }

    void AddValue(TType* Value)
    {
    }
};

template <typename T>
void PrintSum(T a, T b)
{
    std::cout << a + b << '\n';
}

class Object
{
public:
    Object(int Value, std::string& ValueName, bool)
    {
        std::cout << "Object::Object(int Value, std::string& ValueName, bool)" << '\n';
    }
};

// template <typename... TArgs>
// void print(TArgs... Args)
// {
//     // std::cout << Args... << '\n'; // std::cout << 42, 13, std::string{"hello"}, '@', 42.9 << '\n';
//
//     ((std::cout << Args << '\n'), ...); // std::cout << 42 << '\n'; std::cout << 13 << '\n';
// }

void Print()
{
}

//template <typename T, typename... TArgs>
//void Print(T arg, TArgs... args)
//{
//    std::cout << arg << '\n';
//
//    Print(args...);
//}
//
//template <typename... TArgs>
//auto Sum(TArgs... Args)
//{
//    return (Args + ...); // 10 + 20 + 30
//}

template <typename TType>
class MyArray
{
public:
    template <typename... TArgs>
    void EmplaceBack(TArgs&&... Args)
    {
        TType Instance{ std::forward<TArgs>(Args)... };
    }
};

template<typename T>
void Foo(T& Ref)
{
    std::cout << "LRef" << '\n';
}

template<typename T>
void Foo(T&& Ref)
{
    std::cout << "RRef" << '\n';
}

template<class T>
void Wrapper(T&& arg)
{
    Foo(std::forward<T>(arg));
}


//int main(int argc, char* argv[])
//{
//    int Value = 42;
//    Wrapper(Value);
//
//
//    /////////// Variadic templates
//    // Print(42, 13, std::string{"hello"}, '@', 42.9);
//    ////
//    // Print(42, 13, std::string{"hello"}, '@', 42.9);
//    // Print(13, std::string{"hello"}, '@', 42.9);
//    // Print(std::string{"hello"}, '@', 42.9);
//    // Print('@', 42.9);
//    // Print(42.9);
//    // Print();
//
//    // std::cout << Sum(10, 20, 30) << '\n';
//
//    // {
//    //     int Value = 42;
//    //     std::string ValueName = "Test";
//    //     bool boolValue = true;
//    //
//    //     MyArray<Object> MyArr;
//    //
//    //     MyArr.EmplaceBack(Value, ValueName, boolValue);
//    // }
//
//
//    // using std::cout;
//    //
//    // std::vector<Object> Objects;
//    //
//    // int Value = 42;
//    // std::string ValueName = "Test";
//    // bool boolValue = true;
//    //
//    // Objects.emplace_back(Value, ValueName, boolValue);
//
//    // int Value = 42;
//    // int& LRef = Value; // lvalue reference
//    // int&& RRef = 42; // rvalue reference
//    // auto&& UniversalRef = 42;
//
//    //
//    // std::cout << &RRef << '\n';
//
//    // Array<int> Values1;
//    // Array<bool> Values2;
//    // Array<int*> Values3;
//    //
//    // Values1.AddValue(42);
//    // Values2.AddValue(true);
//    // Values3.AddValue(nullptr);
//
//    return 0;
//}
