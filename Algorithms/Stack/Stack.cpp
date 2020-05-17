#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <optional>
#include <random>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

constexpr size_t kVecSize = 100;

template <typename T>
class Stack {
private:
    struct Node {
        explicit Node(const T& data): data_(data) {}
        explicit Node(T&& data): data_(std::move(data)) {}

        std::unique_ptr<Node> next_ = nullptr;
        T data_;
    };

public:
    Stack() = default;
    ~Stack() = default;
    Stack(const Stack& other) = delete;
    Stack& operator=(const Stack& other) = delete;
    Stack(Stack&& other) { std::swap(head_, other.head_); head_ = nullptr; }
    Stack& operator=(Stack&& other) {
        if (this != &other)
            std::swap(head_, other.head_);
            head_ = nullptr;
        return *this;
    }

    void push(const T& val) {
        if (!head_) {
            head_ = std::make_unique<Node>(val);
            return;
        }
        auto new_node = std::make_unique<Node>(val);
        new_node->next_ = std::move(head_);
        head_ = std::move(new_node);
    }

    void push(T&& val) {
        if (!head_) {
            head_ = std::make_unique<Node>(std::move(val));
            return;
        }
        auto new_node = std::make_unique<Node>(std::move(val));
        new_node->next_ = std::move(head_);
        head_ = std::move(new_node);
    }

    std::optional<T> pop() {
        if (!head_) 
            return std::nullopt;
        auto return_val = std::move(head_->data_);
        head_ = std::move(head_->next_);
        return return_val;
    }

    void display() const {
        for_each([](const auto* node){ std::cout << node->data_ << ' '; });
        std::cout << '\n';
    }

    bool empty() const { return !(bool)head_; }

    size_t size() const { 
        size_t size {};
        for_each([&size](const auto* node){ ++size; });
        return size;
    }

private:
    template<typename FUN> 
    void for_each(FUN fun) const {
        if (!head_)
            return;
        const auto* node = head_.get();
        while (node->next_) {
            fun(node);
            node = node->next_.get();
        }
        fun(node);
    }

    std::unique_ptr<Node> head_;
};

class StackTest : public testing::Test {
public:
    std::vector<int> getShuffleVec(size_t size) {
        std::vector<int> vec(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        
        std::iota(begin(vec), end(vec), 0);
        std::shuffle(begin(vec), end(vec), gen);
        return vec;
    }

    std::vector<int> asVector(Stack<int>&& stack) {
        std::vector<int> result;
        result.reserve(stack.size());
        while (!stack.empty()) {
            result.push_back(*stack.pop());
        }
        return result;
    }
};

TEST_F(StackTest, ShouldPopValue) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_EQ(stack.pop(), 3);
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.pop(), 1);
}

TEST_F(StackTest, ShouldBeEmpty) {
    Stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_FALSE(stack.empty());
    EXPECT_EQ(stack.pop(), 3);
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.pop(), 1);
    EXPECT_TRUE(stack.empty());
}

TEST_F(StackTest, ShouldReturnSize) {
    Stack<int> stack;
    auto vec = getShuffleVec(kVecSize);
    for (const auto& el : vec) {
        stack.push(el);
    }
    EXPECT_EQ(vec.size(), stack.size());
}

TEST_F(StackTest, ShouldAppendNewValue) {
    Stack<int> stack;
    stack.push(200);
    stack.push(300);
    stack.push(400);
    auto vec = getShuffleVec(kVecSize);
    for (const auto& el : vec) {
        stack.push(el);
    }
    std::reverse(begin(vec), end(vec));
    vec.push_back(400);
    vec.push_back(300);
    vec.push_back(200);
    EXPECT_EQ(vec, asVector(std::move(stack)));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}