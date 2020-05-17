#include <algorithm>
#include <iostream>
#include <memory>
#include <numeric>
#include <optional>
#include <random>
#include <utility>
#include <vector>

#include "gtest/gtest.h"

constexpr size_t kVecSize = 10;

template <typename T>
class Queue {
private:
    struct Node {
        Node() = default;
        explicit Node(const T& data): data_(data) {}
        explicit Node(T&& data): data_(std::move(data)) {}

        std::unique_ptr<Node> next_ = nullptr;
        T data_;
    };

public:
    Queue() = default;
    ~Queue() = default;
    Queue(const Queue& other) = delete;
    Queue& operator=(const Queue& other) = delete;
    Queue(Queue&& other) {
        std::swap(head_, other.head_);
        head_ = nullptr;
        tail_ = other.tail_; 
    }
    Queue& operator=(Queue&& other) {
        if (this != &other) {
            std::swap(head_, other.head_);
            head_ = nullptr;
            tail_ = other.tail_;
        }
        return *this;
    }

    void push(const T& val) {
        if (!head_) {
            head_ = std::make_unique<Node>(val);
            tail_ = head_.get();
            return;
        }
        tail_->next_ = std::make_unique<Node>(val);
        tail_ = tail_->next_.get();
    }

    void push(T&& val) {
        if (!head_) {
            head_ = std::make_unique<Node>(std::move(val));
            tail_ = head_.get();
            return;
        }
        tail_->next_ = std::make_unique<Node>(val);
        tail_ = tail_->next_.get();
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
    Node* tail_;
};

class QueueTest : public testing::Test {
public:
    std::vector<int> getShuffleVec(size_t size) {
        std::vector<int> vec(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        
        std::iota(begin(vec), end(vec), 0);
        std::shuffle(begin(vec), end(vec), gen);
        return vec;
    }

    std::vector<int> asVector(Queue<int>&& queue) {
        std::vector<int> result;
        result.reserve(queue.size());
        while (!queue.empty()) {
            result.push_back(*queue.pop());
        }
        return result;
    }
};

TEST_F(QueueTest, ShouldPopValue) {
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    EXPECT_EQ(queue.pop(), 1);
    EXPECT_EQ(queue.pop(), 2);
    EXPECT_EQ(queue.pop(), 3);
}

TEST_F(QueueTest, ShouldBeEmpty) {
    Queue<int> queue;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    EXPECT_FALSE(queue.empty());
    EXPECT_EQ(queue.pop(), 1);
    EXPECT_EQ(queue.pop(), 2);
    EXPECT_EQ(queue.pop(), 3);
    EXPECT_TRUE(queue.empty());
}

TEST_F(QueueTest, ShouldReturnSize) {
    Queue<int> queue;
    auto vec = getShuffleVec(kVecSize);
    for (const auto& el : vec) {
        queue.push(el);
    }
    EXPECT_EQ(vec.size(), queue.size());
}

TEST_F(QueueTest, ShouldAppendNewValue) {
    Queue<int> queue;
    auto vec = getShuffleVec(kVecSize);
    for (const auto& el : vec) {
        queue.push(el);
    }
    queue.push(200);
    queue.push(300);
    queue.push(400);
    vec.push_back(200);
    vec.push_back(300);
    vec.push_back(400);
    EXPECT_EQ(vec, asVector(std::move(queue)));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}