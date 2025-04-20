#pragma once
#include <iostream>

template <typename T>
struct LinkedListNode
{
    T My_Value{};
    LinkedListNode* My_Next{};
    LinkedListNode* My_Prev{};
};

template <typename T>
class LinkedList
{
private:
    LinkedListNode<T>* My_Head;
    LinkedListNode<T>* My_Tail;
    size_t My_Length;

    class Iterator
    {
    private:
        LinkedListNode<T>* Ptr;

    public:
        Iterator(LinkedListNode<T>* node = nullptr) : Ptr(node) {}

        Iterator& operator++()
        {
            if (Ptr) Ptr = Ptr->My_Next;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        Iterator& operator--()
        {
            if (Ptr) Ptr = Ptr->My_Prev;
            return *this;
        }

        Iterator operator--(int)
        {
            Iterator temp = *this;
            --(*this);
            return temp;
        }

        Iterator operator+(int n) const
        {
            Iterator temp = *this;
            for (int i = 0; i < n && temp.Ptr; ++i)
                ++temp;
            return temp;
        }

        Iterator operator-(int n) const
        {
            Iterator temp = *this;
            for (int i = 0; i < n && temp.Ptr; ++i)
                --temp;
            return temp;
        }

        T& operator*() const
        {
            return Ptr->My_Value;
        }

        bool operator==(const Iterator& other) const { return Ptr == other.Ptr; }
        bool operator!=(const Iterator& other) const { return Ptr != other.Ptr; }

        LinkedListNode<T>* GetNode() const { return Ptr; }
    };

    void CopyFrom(const LinkedList& other)
    {
        auto Current = other.My_Head;
        while (Current)
        {
            InsertAtEnd(Current->My_Value);
            Current = Current->My_Next;
        }
    }

    void MoveFrom(LinkedList&& other)
    {
        My_Head = other.My_Head;
        My_Tail = other.My_Tail;
        My_Length = other.My_Length;

        other.My_Head = nullptr;
        other.My_Tail = nullptr;
        other.My_Length = 0;
    }

public:
    ~LinkedList()
    {
        Clear();
    }

    LinkedList() : My_Head(nullptr), My_Tail(nullptr), My_Length(0) {};

    LinkedList(const LinkedList& other) : My_Head(nullptr), My_Tail(nullptr), My_Length(0)
    {
        CopyFrom(other);
    }

    LinkedList(LinkedList&& other) noexcept : My_Head(nullptr), My_Tail(nullptr), My_Length(0)
    {
        MoveFrom(std::move(other));
    }

    LinkedList& operator=(const LinkedList& other)
    {
        if (this != &other)
        {
            Clear();
            CopyFrom(other);
        }
        return *this;
    }

    LinkedList& operator=(LinkedList&& other) noexcept
    {
        if (this != &other)
        {
            Clear();
            MoveFrom(std::move(other));
        }
        return *this;
    }

    LinkedListNode<T>* GetHead() const { return My_Head; }

    LinkedListNode<T>& InsertAtEnd(const T& Value)
    {
        auto NewNode = new LinkedListNode<T>;
        NewNode->My_Value = Value;

        if (My_Length == 0)
        {
            My_Head = My_Tail = NewNode;
        }
        else
        {
            My_Tail->My_Next = NewNode;
            NewNode->My_Prev = My_Tail;

            My_Tail = NewNode;
        }

        ++My_Length;

        return *NewNode;
    }

    void PopFront()
    {
        if (!My_Head) return;

        auto OldHead = My_Head;
        My_Head = My_Head->My_Next;

        if (My_Head)
            My_Head->My_Prev = nullptr;
        else
            My_Tail = nullptr;

        delete OldHead;
        --My_Length;
    }

    void PopBack()
    {
        if (!My_Tail) return;

        auto OldTail = My_Tail;
        My_Tail = My_Tail->My_Prev;

        if (My_Tail)
            My_Tail->My_Next = nullptr;
        else
            My_Head = nullptr;

        delete OldTail;
        --My_Length;
    }

    void Clear()
    {
        while (My_Head)
        {
            PopFront();
        }
    }

    bool Empty() const
    {
        return My_Length == 0;
    }

    LinkedListNode<T>& InsertAfter(const T& value, LinkedListNode<T>* node)
    {
        if (!node)
            throw std::invalid_argument("InsertAfter: node is null");

        auto NewNode = new LinkedListNode<T>{ value };

        NewNode->My_Next = node->My_Next;
        NewNode->My_Prev = node;

        if (node->My_Next)
            node->My_Next->My_Prev = NewNode;
        else
            My_Tail = NewNode;

        node->My_Next = NewNode;

        ++My_Length;
        return *NewNode;
    }

    void Remove(LinkedListNode<T>* node)
    {
        if (!node) return;

        if (node->My_Prev)
            node->My_Prev->My_Next = node->My_Next;
        else
            My_Head = node->My_Next;

        if (node->My_Next)
            node->My_Next->My_Prev = node->My_Prev;
        else
            My_Tail = node->My_Prev;

        delete node;
        --My_Length;
    }

    void Reverse()
    {
        auto Current = My_Head;
        LinkedListNode<T>* Temp = nullptr;

        while (Current)
        {
            Temp = Current->My_Prev;
            Current->My_Prev = Current->My_Next;
            Current->My_Next = Temp;
            Current = Current->My_Prev;
        }

        std::swap(My_Head, My_Tail);
    }

    void PrintForward() const
    {
        auto Current = My_Head;
        while (Current)
        {
            std::cout << Current->My_Value << " ";
            Current = Current->My_Next;
        }
        std::cout << '\n';
    }

    void PrintBackward() const
    {
        auto Current = My_Tail;
        while (Current)
        {
            std::cout << Current->My_Value << " ";
            Current = Current->My_Prev;
        }
        std::cout << '\n';
    }

    Iterator begin() const { return Iterator(My_Head); }
    Iterator end() const { return Iterator(nullptr); } 

};

