#pragma once
#include <iostream>
#include <list>

template<typename T>
class Queue {
private:
    std::list<T> data;

public:
    Queue() = default;
    Queue(const Queue& other) = default;
    Queue(Queue&& other) noexcept = default;
    Queue& operator=(const Queue& other) = default;
    Queue& operator=(Queue&& other) noexcept = default;
    ~Queue() = default;

    void Enqueue(const T& element) {
        data.push_back(element);
    }

    void Dequeue() {
        if (!data.empty())
            data.pop_front();
    }

    T& Front() {
        return data.front();
    }

    T& Back() {
        return data.back();
    }

    const T& Front() const {
        return data.front();
    }

    const T& Back() const {
        return data.back();
    }

    size_t Count() const {
        return data.size();
    }

    bool Empty() const {
        return data.empty();
    }

    friend std::ostream& operator<<(std::ostream& os, const Queue<T>& queue) {
        for (const auto& elem : queue.data) {
            os << elem << " ";
        }
        return os;
    }
};


