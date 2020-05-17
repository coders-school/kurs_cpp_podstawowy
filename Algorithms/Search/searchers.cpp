#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <random>
#include <iterator>
#include <map>
#include <queue>
#include <chrono>
#include <numeric>
#include <math.h>

#include "gtest/gtest.h"

constexpr size_t kVecSize = 1'000;
constexpr int kSearchVal = 512;
constexpr int kWrongVal = 1024;

int LinearSearch(const std::vector<int>& vec, int number) {
    for (const auto& el : vec)
        if (el == number)
            return number;
    return -1;
}

template <typename IT, typename T = IT::type_value>
T BinarySearchHelper(IT begin, IT end, T value) {
    if (auto distance = std::distance(begin, end) ; distance > 0) {
        auto mid = std::next(begin, distance / 2);
        if (*mid == value)
            return *mid;
        else if (value < *mid)
            return BinarySearchHelper(begin, mid, value);
        else
            return BinarySearchHelper(++mid, end, value);
    }
    return *begin == value ? *begin : -1;
}

int BinarySearch(const std::vector<int>& vec, int number) {
    return BinarySearchHelper(vec.begin(), vec.end(), number);
}

template <typename IT, typename T = IT::type_value>
T TernarSearchHelper(IT begin, IT end, T value) {
    if (auto distance = std::distance(begin, end) ; distance > 0) {
        auto first = std::next(begin, distance / 3);
        auto second = std::next(first, distance / 3);
        if (*first == value)
            return *first;
        else if (*second == value)
            return *second;
        else if (value < *first)
            return TernarSearchHelper(begin, first, value);
        else if (value < *second)
            return TernarSearchHelper(++first, second, value);
        else
            return TernarSearchHelper(++second, end, value);
    }
    return *begin == value ? *begin : -1;
}

int TernarSearch(const std::vector<int>& vec, int number) {
    return TernarSearchHelper(vec.begin(), vec.end(), number);
}

template <typename IT, typename T = IT::type_value>
T InterpolarySearchHelper(IT begin, IT end, T value) {
    if (auto distance = std::distance(begin, end) ; distance > 0) {
        auto pivot = (value - *begin) * (distance / (*std::prev(end) - *begin));
        auto mid = std::next(begin, pivot);
        if (*mid == value)
            return *mid;
        else if (value < *mid)
            return InterpolarySearchHelper(begin, mid, value);
        else
            return InterpolarySearchHelper(++mid, end, value);
    }
    return *begin == value ? *begin : -1;
}

int InterpolarySearch(const std::vector<int>& vec, int number) {
    return InterpolarySearchHelper(vec.begin(), vec.end(), number);
}

template <typename IT, typename T = IT::type_value>
T JumpSearchHelper(IT begin, IT end, T value) {
    auto distance = std::distance(begin, end);
    auto jump = std::sqrt(distance);
    for (; begin < end ; std::advance(begin, jump)) {
        if (value < *begin)
            return BinarySearchHelper(std::prev(begin, jump), begin, value);
    }
    return BinarySearchHelper(std::prev(begin, jump), begin, value);
}

int JumpSearch(const std::vector<int>& vec, int number) {
    return JumpSearchHelper(vec.begin(), vec.end(), number);
}

template <typename IT, typename T = IT::type_value>
T ExpotentialSearchHelper(IT begin, IT end, T value) {
    auto jump = 2;
    for (; begin < end ; std::advance(begin, jump)) {
        if (value < *begin)
            return BinarySearchHelper(std::prev(begin, jump), begin, value);
        jump *=2;
    }
    return BinarySearchHelper(std::prev(begin, jump), begin, value);
}

int ExpotentialSearch(const std::vector<int>& vec, int number) {
    return ExpotentialSearchHelper(vec.begin(), vec.end(), number);
}

class SearchTest : public testing::Test {
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

TEST_F(SearchTest, ShouldFindValue) {
    auto vec = getShuffleVec(kVecSize);
    EXPECT_EQ(LinearSearch(vec, kSearchVal), kSearchVal);
    std::sort(begin(vec), end(vec));
    EXPECT_EQ(ExpotentialSearch(vec, kSearchVal), kSearchVal);
    EXPECT_EQ(JumpSearch(vec, kSearchVal), kSearchVal);
    EXPECT_EQ(InterpolarySearch(vec, kSearchVal), kSearchVal);
    EXPECT_EQ(TernarSearch(vec, kSearchVal), kSearchVal);
    EXPECT_EQ(BinarySearch(vec, kSearchVal), kSearchVal);

}

TEST_F(SearchTest, ShouldNotFindValue) {
    auto vec = getShuffleVec(kVecSize);
    EXPECT_EQ(LinearSearch(vec, kWrongVal), -1);
    std::sort(begin(vec), end(vec));
    EXPECT_EQ(ExpotentialSearch(vec, kWrongVal), -1);
    EXPECT_EQ(JumpSearch(vec, kWrongVal), -1);
    EXPECT_EQ(InterpolarySearch(vec, kWrongVal), -1);
    EXPECT_EQ(TernarSearch(vec, kWrongVal), -1);
    EXPECT_EQ(BinarySearch(vec, kWrongVal), -1);
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

// int main() {
//     std::random_device rd;
//     std::mt19937 gen(rd());
//     std::uniform_int_distribution<> dis(0, 10'000'000);
//     std::vector<int> vec(500'000'000);
//     std::generate(begin(vec), end(vec), [&gen, &dis](){ return dis(gen); });
//     int search_value = 6'966'669;
//     vec.push_back(search_value);
//     std::sort(begin(vec), end(vec));

//     auto start = std::chrono::steady_clock::now();  
//     auto el = LinearSearch(vec, search_value);
//     std::cout << "FOUND EL: " << el << std::endl;
//     auto stop = std::chrono::steady_clock::now();    
//     std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << "ns" << std::endl;

//     start = std::chrono::steady_clock::now();  
//     auto el2 = BinarySearch(vec, search_value);
//     std::cout << "FOUND EL: " << el2 << std::endl;
//     stop = std::chrono::steady_clock::now();    
//     std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << "ns" << std::endl;

//     start = std::chrono::steady_clock::now(); 
//     auto el3 = TernarSearch(vec, search_value);
//     std::cout << "FOUND EL: " << el3 << std::endl;
//     stop = std::chrono::steady_clock::now();    
//     std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << "ns" << std::endl;

//     start = std::chrono::steady_clock::now(); 
//     auto el4 = InterpolarySearch(vec, search_value);
//     std::cout << "FOUND EL: " << el4 << std::endl;
//     stop = std::chrono::steady_clock::now();    
//     std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << "ns" << std::endl;

//     start = std::chrono::steady_clock::now(); 
//     auto el5 = JumpSearch(vec, search_value);
//     std::cout << "FOUND EL: " << el5 << std::endl;
//     stop = std::chrono::steady_clock::now();    
//     std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << "ns" << std::endl;

//     start = std::chrono::steady_clock::now(); 
//     auto el6 = ExpotentialSearch(vec, search_value);
//     std::cout << "FOUND EL: " << el6 << std::endl;
//     stop = std::chrono::steady_clock::now();    
//     std::cout << "TIME: " << std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start).count() << "ns" << std::endl;

//     return 0;
// }