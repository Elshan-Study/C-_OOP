#pragma once
#include <iostream>
#include <vector>

template<typename T>
struct Less {
    bool operator()(const T& a, const T& b) const {
        return a > b; 
    }
};

template<typename T>
struct Greater {
    bool operator()(const T& a, const T& b) const {
        return a < b; 
    }
};

template<typename T, typename Compare = Less<T>>
class PriorityQueue {
private:
    std::vector<T> data;
    Compare comp;

    void heapifyUp(size_t index) {
        while (index > 0) {
            size_t parent = (index - 1) / 2;
            if (comp(data[parent], data[index])) {
                std::swap(data[parent], data[index]);
                index = parent;
            }
            else break;
        }
    }

    void heapifyDown(size_t index) {
        size_t size = data.size();
        while (true) {
            size_t left = 2 * index + 1;
            size_t right = 2 * index + 2;
            size_t largest = index;

            if (left < size && comp(data[largest], data[left])) {
                largest = left;
            }
            if (right < size && comp(data[largest], data[right])) {
                largest = right;
            }

            if (largest != index) {
                std::swap(data[index], data[largest]);
                index = largest;
            }
            else break;
        }
    }

public:
    PriorityQueue() = default;
    PriorityQueue(const Compare& comparator) : comp(comparator) {}

    void Enqueue(const T& element) {
        data.push_back(element);
        heapifyUp(data.size() - 1);
    }

    void Dequeue() {
        if (!data.empty()) {
            std::swap(data.front(), data.back());
            data.pop_back();
            heapifyDown(0);
        }
    }

    T& Front() {
        return data.front();
    }

    const T& Front() const {
        return data.front();
    }

    size_t Count() const {
        return data.size();
    }

    bool Empty() const {
        return data.empty();
    }

    friend std::ostream& operator<<(std::ostream& os, const PriorityQueue<T, Compare>& queue) {
        for (const auto& elem : queue.data) {
            os << elem << " ";
        }
        return os;
    }
};

