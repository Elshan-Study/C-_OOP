#pragma once
#include <functional>
#include <stdexcept>
#include "SuperVectorT.h"

template<typename K, typename V>
class HashTable {
private:
    struct Entry {
        K key;
        V value;
        bool isActive;

        Entry() : isActive(false) {}
        Entry(const K& k, const V& v) : key(k), value(v), isActive(true) {}
    };

    SuperVectorT<SuperVectorT<Entry>> buckets;
    size_t numElements;

    size_t getBucketIndex(const K& key, size_t mod = 0) const {
        size_t size = mod == 0 ? buckets.Size() : mod;
        return std::hash<K>{}(key) % size;
    }

    void Rehash(size_t newBucketCount) {
        SuperVectorT<SuperVectorT<Entry>> newBuckets(newBucketCount);
        for (size_t i = 0; i < newBucketCount; ++i) {
            newBuckets[i] = SuperVectorT<Entry>();
        }

        for (size_t i = 0; i < buckets.Size(); ++i) {
            for (size_t j = 0; j < buckets[i].Size(); ++j) {
                if (buckets[i][j].isActive) {
                    const Entry& e = buckets[i][j];
                    size_t newIndex = getBucketIndex(e.key, newBucketCount);
                    newBuckets[newIndex].PushBack(Entry(e.key, e.value));
                }
            }
        }

        buckets = newBuckets;
    }

public:
    HashTable(size_t bucketCount = 16) : buckets(bucketCount), numElements(0) {
        for (size_t i = 0; i < bucketCount; ++i) {
            buckets[i] = SuperVectorT<Entry>();
        }
    }

    ~HashTable() = default;
    HashTable(const HashTable& other) = default;
    HashTable& operator=(const HashTable& other) = default;
    HashTable(HashTable&& other) noexcept = default;
    HashTable& operator=(HashTable&& other) noexcept = default;

    void Add(const K& key, const V& value) {
        if (GetLoadFactor() > 0.7f) {
            Rehash(buckets.Size() * 2);
        }

        size_t index = getBucketIndex(key);
        SuperVectorT<Entry>& bucket = buckets[index];

        for (size_t i = 0; i < bucket.Size(); ++i) {
            if (bucket[i].isActive && bucket[i].key == key) {
                bucket[i].value = value;
                return;
            }
        }

        bucket.PushBack(Entry(key, value));
        ++numElements;
    }

    void Remove(const K& key) {
        size_t index = getBucketIndex(key);
        SuperVectorT<Entry>& bucket = buckets[index];

        for (size_t i = 0; i < bucket.Size(); ++i) {
            if (bucket[i].isActive && bucket[i].key == key) {
                bucket[i].isActive = false;
                --numElements;
                return;
            }
        }
    }

    V& operator()(const K& key) {
        size_t index = getBucketIndex(key);
        SuperVectorT<Entry>& bucket = buckets[index];

        for (size_t i = 0; i < bucket.Size(); ++i) {
            if (bucket[i].isActive && bucket[i].key == key) {
                return bucket[i].value;
            }
        }

        throw std::out_of_range("Key not found");
    }

    float GetLoadFactor() const {
        return static_cast<float>(numElements) / buckets.Size();
    }
};
