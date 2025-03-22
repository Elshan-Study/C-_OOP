#pragma once
#include <iostream>

template<typename T>
class UniquePtr
{
private:
    T* ptr;
    bool is_array;

public:
    UniquePtr() : ptr(nullptr), is_array(false) {}

    explicit UniquePtr(T* p, bool array = false) : ptr(p), is_array(array) {}

    UniquePtr(const UniquePtr&) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;

    UniquePtr(UniquePtr&& other) noexcept
        : ptr(other.ptr), is_array(other.is_array)
    {
        other.ptr = nullptr;
        other.is_array = false;
    }

    UniquePtr& operator=(UniquePtr&& other) noexcept
    {
        if (this != &other)
        {
            reset();
            ptr = other.ptr;
            is_array = other.is_array;
            other.ptr = nullptr;
            other.is_array = false;
        }
        return *this;
    }

    ~UniquePtr()
    {
        reset();
    }

    T* get() const { return ptr; }
    T& operator*() { return *ptr; }
    const T& operator*() const { return *ptr; }
    T* operator->() { return ptr; }
    const T* operator->() const { return ptr; }

    T& operator[](size_t index)
    {
        return ptr[index];
    }

    void reset(T* new_ptr = nullptr, bool array = false)
    {
        if (ptr)
        {
            if (is_array)
                delete[] ptr;
            else
                delete ptr;
        }
        ptr = new_ptr;
        is_array = array;
    }
};
