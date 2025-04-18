#include <iostream>

//class Object
//{
//public:
//    ~Object()
//    {
//        std::cout << "~Object::Object()" << '\n';
//    }
//
//    Object()
//    {
//        std::cout << "Object::Object()" << '\n';
//    }
//
//    int GetValue() const
//    {
//        return My_Value;
//    }
//
//private:
//    int My_Value = 42;
//};


// template <typename TType>
// class Array
// {
// public:
//     TType& operator[](size_t Index)
//     {
//         return My_Array[Index];
//     }
//
//     const TType& operator[](size_t Index) const
//     {
//         return My_Array[Index];
//     }
//
// private:
//     TType My_Array[3]{};
// };

//template <typename TType>
//struct LinkedListNode
//{
//    TType My_Value{};
//    LinkedListNode* My_Next{};
//    LinkedListNode* My_Prev{};
//};
//
//template <typename TType>
//class LinkedList
//{
//public:
//    ~LinkedList()
//    {
//        if (My_Length == 0)
//        {
//            return;
//        }
//
//        auto Current = My_Head;
//
//        while (Current != nullptr)
//        {
//            auto Temp = Current->My_Next;
//
//            delete Current;
//
//            Current = Temp;
//        }
//    }
//
//    LinkedList() : My_Head{}, My_Tail{}, My_Length{ 0 }
//    {
//    }
//
//    LinkedListNode<TType>& InsertAtEnd(const TType& Value)
//    {
//        auto NewNode = new LinkedListNode<TType>;
//        NewNode->My_Value = Value;
//
//        if (My_Length == 0)
//        {
//            My_Head = My_Tail = NewNode;
//        }
//        else
//        {
//            My_Tail->My_Next = NewNode;
//            NewNode->My_Prev = My_Tail;
//
//            My_Tail = NewNode;
//        }
//
//        ++My_Length;
//
//        return *NewNode;
//    }
//
//    // LinkedListNode<TType>& InsertAfter(const TType& Value, LinkedListNode<TType>& Position)
//    // {
//    //     
//    // }
//private:
//    LinkedListNode<TType>* My_Head;
//    LinkedListNode<TType>* My_Tail;
//    size_t My_Length;
//};

//int main(int argc, char* argv[])
//{
//    // Object* objs = reinterpret_cast<Object*>(operator new(sizeof(Object) * 3));
//    //
//    // memset(objs, 0, sizeof(Object) * 3);
//    //
//    // new (objs) Object();
//    //
//    // std::cout << objs->GetValue() << '\n';
//    //
//    // //
//    //
//    // objs->~Object();
//    //
//    // //
//    //
//    // operator delete(objs);
//
//
//    // LinkedList<int> MyLL;
//    //
//    // MyLL.InsertAtEnd(10);
//    // auto& Middle = MyLL.InsertAtEnd(20);
//    // MyLL.InsertAtEnd(30);
//
//
//    // Array<int> My_Array;
//    //
//    // My_Array[1] = 42;
//    //
//    // std::cout << My_Array[1];
//
//    return 0;
//}
