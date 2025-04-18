#include <iostream>
#include <list>
#include <vector>

class Array
{
public:
    class Iterator
    {
    public:
        Iterator(int* Current) : My_Current(Current)
        {
        }

        // lhs = this;
        bool operator!=(const Iterator& rhs) const
        {
            return My_Current != rhs.My_Current;
        }

        int& operator*() const
        {
            return *My_Current;
        }

        Iterator& operator++()
        {
            ++My_Current;

            return *this;
        }

    private:
        int* My_Current;
    };

    ~Array()
    {
        delete[] My_Data;
    }

    Array()
    {
        My_Data = new int[My_DefaultCapacity];
        My_Capacity = My_DefaultCapacity;
        My_Length = 0;
    }

    void Append(int Value)
    {
        if (My_Length == My_Capacity)
        {
            return;
        }

        My_Data[My_Length++] = Value;
    }

    Iterator begin()
    {
        return Iterator{ My_Data };
    }

    Iterator end()
    {
        return Iterator{ My_Data + My_Length };
    }

private:
    int* My_Data;
    size_t My_Length;
    size_t My_Capacity;
    static constexpr int My_DefaultCapacity = 15;
};

class Object
{
public:
    Object()
    {
        std::cout << "Object::Object()" << '\n';
    }

    Object(const Object& Other)
    {
        std::cout << "Object::Object(const Object& Other)" << '\n';
    }
};

//int main(int argc, char* argv[])
//{
//    //// Range based for
//    // int Arr[3]{10, 20, 30};
//    //
//    // for (int Value : Arr)
//    // {
//    //     std::cout << Value << '\n';
//    // }
//    //
//    // int* addr = (int*)0xfffff;
//    //
//    // std::cout << *addr << '\n'; // Won't run!
//    //
//    // Array My_Array;
//    //
//    // My_Array.Append(10);
//    // My_Array.Append(20);
//    // My_Array.Append(30);
//    // My_Array.Append(40);
//    // My_Array.Append(50);
//    //
//    // for (int Element : My_Array)
//    // {
//    //     std::cout << Element << '\n';
//    // }
//
//    /////////////// STD VECTOR & RANGE BASED FOR
//    // std::vector<Object> My_Array;
//    //
//    // My_Array.emplace_back();
//    // My_Array.emplace_back();
//    // My_Array.emplace_back();
//    //
//    // for (auto& Element : My_Array)
//    // {
//    //     
//    // }
//
//    /////////////// STD VECTOR
//    std::vector<int> My_Array;
//
//    My_Array.push_back(10);
//    My_Array.push_back(20);
//    My_Array.push_back(30);
//
//    My_Array.begin() + 1;
//
//    for (auto Element : My_Array)
//    {
//        std::cout << Element << '\n';
//    }
//
//    /////////////// Range based for under hood
//    // auto begin = My_Array.begin();
//    // auto end = My_Array.end();
//    //
//    // while (begin != end)
//    // {
//    //     std::cout << *begin << '\n';
//    //
//    //     ++begin;
//    // }
//
//    return 0;
//}
