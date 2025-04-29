#pragma once
#include <iostream>
#include <vector>
#include <stdexcept>

template <typename T>
class Stack {
private:
    std::vector<T> data;

public:
    Stack() = default;
    ~Stack() = default;

    Stack(const Stack& other) = default;
    Stack(Stack&& other) noexcept = default;
    Stack& operator=(const Stack& other) = default;
    Stack& operator=(Stack&& other) noexcept = default;

    void Push(const T& value) {
        data.push_back(value);
    }

    T Pop() {
        if (Empty())
            throw std::out_of_range("Pop from empty stack");
        T value = data.back();
        data.pop_back();
        return value;
    }

    T& Top() {
        if (Empty())
            throw std::out_of_range("Top from empty stack");
        return data.back();
    }

    const T& Top() const {
        if (Empty())
            throw std::out_of_range("Top from empty stack");
        return data.back();
    }

    size_t Size() const {
        return data.size();
    }

    bool Empty() const {
        return data.empty();
    }

    template <typename U>
    friend void PrintStack(const Stack<U>& stack);
};

template <typename U>
void PrintStack(const Stack<U>& stack) {
    std::cout << "Stack contents (top to bottom): ";
    for (auto it = stack.data.rbegin(); it != stack.data.rend(); ++it)
        std::cout << *it << " ";
    std::cout << '\n';
}


