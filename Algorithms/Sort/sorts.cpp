#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <random>
#include <iterator>
#include <map>
#include <queue>
#include <chrono>

#include "gtest/gtest.h"

constexpr size_t kVecSize = 1'000;

std::vector<int> BubleSort(std::vector<int> vec) {
    for (size_t j = 0 ; j < vec.size() - 1; ++j) {
        bool isSwap = false;
        for (size_t i = 0 ; i < vec.size() - 1 - j ; ++i) {
            if (vec[i] > vec[i + 1]) {
                std::swap(vec[i], vec[i + 1]);
                isSwap = true;
            }
        }
        if (!isSwap)
            return vec;
    }
    return vec;
}

std::vector<int> SortbByChoice(std::vector<int> vec) {
    for (size_t i = 0 ; i < vec.size() - 1 ; ++i) {
        auto max = std::min_element(std::next(std::begin(vec), i), end(vec));
        std::swap(vec[i], *max);
    }
    return vec;
}

std::vector<int> SortbByInsert(std::vector<int> vec) {
    for (size_t i = 1 ; i < vec.size() ; ++i) {
        auto current = vec[i];
        int j = 0;
        for (j = i - 1 ; j >= 0 ; --j) {
            if (vec[j] > current)
                std::swap(vec[j + 1], vec[j]);
            else
                break;
        }
        std::swap(vec[j + 1], current);
    }
    return vec;
}

template <typename IT>
std::vector<typename IT::value_type> Merge(IT begin, IT middle, IT end) {
    std::vector<typename IT::value_type> vec;
    vec.reserve(std::distance(begin, end));
    auto left = begin;
    auto right = middle;

    while (left != middle && right != end) {
        vec.push_back(*left > *right ? std::move(*right++) : std::move(*left++));
    }
    // Left or right side could have elements, never both of them
    vec.insert(vec.end(), left, middle);
    vec.insert(vec.end(), right, end);

    return vec;
}

template <typename IT>
void MergeHelper(IT begin, IT end) {
    if (auto size = std::distance(begin, end) ; size > 1)
    {
        auto middle = size / 2;
        MergeHelper(begin, std::next(begin, middle));
        MergeHelper(std::next(begin, middle), end);
        auto&& vec = Merge(begin, std::next(begin, middle), end);
        std::move(vec.begin(), vec.end(), begin);
    }
}

std::vector<int> MergeSort(std::vector<int> vec) {
    MergeHelper(vec.begin(), vec.end());
    return vec;
}

// 4 9 6 3 0 3 6 7 8 -> pivot 4
// 4 9 6
// 3 9 6 4
// 3 0 6 4 9
// 3 0 3 4 9 6 7 8
// 4 3 0 3 9 6 7 8
template <typename IT>
IT Partition(IT begin, IT end) {
    IT first = begin;
    IT middle = begin;
    auto pivot = *begin;
    // start from second element, because first is pivot
    while (++first != end) {
        if (pivot > *first)
            std::swap(*first, *++middle);
    }
    // We don't want to change posioton of pivot, so back him to begin
    std::swap(*begin, *middle);
    return middle;
}

template <typename IT>
void QuickSortHelper(IT begin, IT end) {
    if (auto size = std::distance(begin, end) ; size > 0)
    {
        auto pivot_point = Partition(begin, end);
        QuickSortHelper(begin, pivot_point);
        QuickSortHelper(++pivot_point, end);
    }
}

std::vector<int> QuickSort(std::vector<int> vec) {
    QuickSortHelper(vec.begin(), vec.end());
    return vec;
}

std::vector<int> SortByCounting(const std::vector<int>& vec) {
    std::map<int, size_t> counter;
    for (const auto& el : vec) {
        ++counter[el];
    }
    std::vector<int> result;
    result.reserve(vec.size());
    for (const auto& [value, count] : counter) {
        for (size_t i = 0 ; i < count ; ++i)
            result.push_back(value);
    }
    return result;
}

std::vector<int> PositionSorting(std::vector<int> vec) {
    auto max = *std::max_element(begin(vec), end(vec));
    int divider = 1;
    do {
        std::vector<std::deque<size_t>> queues(10);
        for (size_t i = 0 ; i < vec.size() ; ++i) {
            queues[vec[i] / divider % 10].push_back(vec[i]);
        }
        divider *= 10;
        vec.clear();
        for (auto&& queue : queues) {
            vec.insert(vec.end(), std::make_move_iterator(queue.begin()), std::make_move_iterator(queue.end()));
        }
    } while (divider <= max);

    return vec;
}

using namespace std::chrono_literals;

class SortTest : public testing::Test {
public:
    std::vector<int> getShuffleVec(size_t size) {
        std::vector<int> vec(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        
        std::iota(begin(vec), end(vec), 0);
        std::shuffle(begin(vec), end(vec), gen);
        return vec;
    }
};

TEST_F(SortTest, ShouldMergeSort) {
    auto vec = getShuffleVec(kVecSize);
    auto res = MergeSort(vec);
    std::sort(begin(vec), end(vec));
    EXPECT_EQ(vec, res);
}

TEST_F(SortTest, ShouldQuickSort) {
    auto vec = getShuffleVec(kVecSize);
    auto res = QuickSort(vec);
    std::sort(begin(vec), end(vec));
    EXPECT_EQ(vec, res);
}

TEST_F(SortTest, ShouldPositionSort) {
    auto vec = getShuffleVec(kVecSize);
    auto res = PositionSorting(vec);
    std::sort(begin(vec), end(vec));
    EXPECT_EQ(vec, res);
}

TEST_F(SortTest, ShouldSortByCounting) {
    auto vec = getShuffleVec(kVecSize);
    auto res = SortByCounting(vec);
    std::sort(begin(vec), end(vec));
    EXPECT_EQ(vec, res);
}

TEST_F(SortTest, ShouldSortByInsert) {
    auto vec = getShuffleVec(kVecSize);
    auto res = SortbByInsert(vec);
    std::sort(begin(vec), end(vec));
    EXPECT_EQ(vec, res);
}

TEST_F(SortTest, ShouldSortByChoice) {
    auto vec = getShuffleVec(kVecSize);
    auto res = SortbByChoice(vec);
    std::sort(begin(vec), end(vec));
    EXPECT_EQ(vec, res);
}

TEST_F(SortTest, ShouldBubleSort) {
    auto vec = getShuffleVec(kVecSize);
    auto res = BubleSort(vec);
    std::sort(begin(vec), end(vec));
    EXPECT_EQ(vec, res);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// int main() {
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> dis(1, 100'000);
//     std::vector<int> vec(5'000'000);
//     std::generate(begin(vec), end(vec), [&gen, &dis](){ return dis(gen); });
//     auto print = [](const auto& vec) {
//         std::copy(begin(vec), end(vec), std::ostream_iterator<int>(std::cout, " | "));
//         std::cout << '\n' << std::string(80, '_') << "\n\n";
//     };   
//     print(vec);

//     // BUBLE
//     auto start = std::chrono::steady_clock::now();
//     auto vec2 = BubleSort(vec);
//     auto stop = std::chrono::steady_clock::now();
//     std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << std::endl;

//     // CHOICE
//     start = std::chrono::steady_clock::now();
//     auto vec3 = SortbByChoice(vec);
//     stop = std::chrono::steady_clock::now();    
//     std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << std::endl;

//     // INSERT
//     start = std::chrono::steady_clock::now();
//     auto vec4 = SortbByInsert(vec);
//     stop = std::chrono::steady_clock::now();    
//     std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::milliseconds>(stop - start).count() << std::endl;

//     // MERGE
//     auto start = std::chrono::steady_clock::now();
//     auto vec5 = MergeSort(vec);
//     auto stop = std::chrono::steady_clock::now();    
//     std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << "ms" << std::endl;

//     // QUICK
//     start = std::chrono::steady_clock::now();
//     auto vec6 = QuickSort(vec);
//     stop = std::chrono::steady_clock::now();    
//     std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << "ms" << std::endl;

//     // COUNTING
//     start = std::chrono::steady_clock::now();
//     auto vec7 = SortByCounting(vec);
//     stop = std::chrono::steady_clock::now();    
//     std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << "ms" << std::endl;

//     // POSITION
//     start = std::chrono::steady_clock::now();
//     auto vec8 = PositionSorting(vec);
//     stop = std::chrono::steady_clock::now();    
//     std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << "ms" << std::endl;

//     // STL
//     start = std::chrono::steady_clock::now();
//     std::sort(begin(vec), end(vec));
//     stop = std::chrono::steady_clock::now();    
//     std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count() << "ms" << std::endl;
// }