#pragma once
#include <iostream>

size_t global_ref_count = 0;

template<typename T>
class SharedPtr
{
private:
    T* ptr;
    bool is_array;
    void release()
    {
        if (ptr) {
            if (--global_ref_count == 0) {
                if (is_array) {
                    delete[] ptr;
                }
                else {
                    delete ptr;
                }
            }
        }
        ptr = nullptr;
        is_array = false;
    }

public:
    SharedPtr() : ptr(nullptr), is_array(false) { ++global_ref_count; }

    explicit SharedPtr(T* p, bool array = false) : ptr(p), is_array(array) { ++global_ref_count; }

    SharedPtr(const SharedPtr& other) noexcept
        : ptr(other.ptr), is_array(other.is_array)
    {
        ++global_ref_count;
    }

    SharedPtr& operator=(const SharedPtr& other) noexcept
    {
        if (this != &other) {
            release();
            ptr = other.ptr;
            is_array = other.is_array;
            ++global_ref_count;
        }
        return *this;
    }

    SharedPtr(SharedPtr&& other) noexcept
        : ptr(other.ptr), is_array(other.is_array)
    {
        other.ptr = nullptr;
        other.is_array = false;
    }

    SharedPtr& operator=(SharedPtr&& other) noexcept
    {
        if (this != &other) {
            release();
            ptr = other.ptr;
            is_array = other.is_array;
            other.ptr = nullptr;
            other.is_array = false;
        }
        return *this;
    }

    ~SharedPtr()
    {
        release();
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

    size_t use_count() const { return global_ref_count; }

    void reset(T* new_ptr = nullptr, bool array = false)
    {
        release();
        ptr = new_ptr;
        is_array = array;
        ++global_ref_count;
    }
};
