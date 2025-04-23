#include <iostream>
#include <stack>
#include <queue>
#include <random>
#include <set>

// LIFO - Last In First Out (Stack)
// FIFO - First In First Out (Queue)
// LIFO + FIFO - (Deque)



//// Functors
class Engine
{
public:
    Engine()
    {
        srand(time(0));
    }

    int Generate(int min, int max) const
    {
        return rand() % (max - min) + min;
    }
};

class Range
{
public:
    Range(int min, int max) : My_Min(min), My_Max(max)
    {
    }

    int operator()(const Engine& engine) const
    {
        return engine.Generate(My_Min, My_Max);
    }

private:
    int My_Min;
    int My_Max;
};


template<typename TComparator>
void Sort(const std::vector<int>& data)
{
    TComparator comparator{};

    int size = data.size();

    for (int i = 0; i < size - 1; ++i)
    {
        for (int j = i + 1; j < size - 1; ++j)
        {
            if (comparator(data[j], data[j + 1]))
            {
                std::swap(data[j], data[j + 1]);
            }
        }
    }
}

class Less
{
public:
    bool operator()(int lhs, int rhs) const
    {
        return lhs < rhs;
    }
};

//int main(int argc, char* argv[])
//{
//    // std::default_random_engine engine{};
//    // std::uniform_real_distribution<float> range{0, 1};
//    //
//    // std::cout << range(engine);
//
//    Engine engine;
//    Range range{ 1, 20 };
//
//    std::cout << range(engine);
//
//    Sort<Less>({ 2, 3, 4 });
//
//    // std::stack<int> stack;
//    // std::queue<int> queue;
//
//    return 0;
//}
