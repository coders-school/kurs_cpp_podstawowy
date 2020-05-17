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
class LinkedList {
private:
    struct Node {
        explicit Node(const T& data): data_(data) {}
        explicit Node(T&& data): data_(std::move(data)) {}

        std::unique_ptr<Node> next_ = nullptr;
        T data_;
    };

public:
    LinkedList() = default;
    ~LinkedList() = default;
    LinkedList(const LinkedList&) = delete;
    LinkedList& operator=(const LinkedList& other) = delete;
    LinkedList(LinkedList&& other) { std::swap(head_, other.head_); head_ = nullptr; }
    LinkedList& operator=(LinkedList&& other) {
        if (this != &other) {
            std::swap(head_, other.head_);
            head_ = nullptr;
        }
        return *this;
    }

    void push_front(const T& val) {
        if (!head_) {
            head_ = std::make_unique<Node>(val);
            return;
        }
        auto new_node = std::make_unique<Node>(val);
        new_node->next_ = std::move(head_);
        head_ = std::move(new_node);
    }

    void push_front(T&& val) {
        if (!head_) {
            head_ = std::make_unique<Node>(std::move(val));
            return;
        }
        auto new_node = std::make_unique<Node>(std::move(val));
        new_node->next_ = std::move(head_);
        head_ = std::move(new_node);
    }

    T& front() {
        return head_->data_;
    }

    std::optional<T> pop_front() {
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

    void qsort() {
        head_ = recursive_sort(std::move(head_));
    }

    void merge_sort() {
        head_ = recursive_sort(std::move(head_));
    }

private:
    std::unique_ptr<Node> recursive_merge_sort(std::unique_ptr<Node> head) {
        if (!head_ && head_->next_)
            return head;
        auto [first_part, second_part] = divide(std::move(head));
        return merge(recursive_merge_sort(first_part), 
            recursive_merge_sort(second_part));
        
    }

    std::unique_ptr<Node> merge(std::unique_ptr<Node> left, 
                                std::unique_ptr<Node> right) {
        std::unique_ptr<Node> result;
        while (left && right) {
            left->data_ > right->data_ 
                ? append(result, left)
                : append(result, right);
            }
        while (left) append(result, left);
        while (right) append(result, right);
        return result;
    }

    void append(std::unique_ptr<Node>& head, std::unique_ptr<Node>& node) {
        Node* node_ptr = nullptr;
        if (!head) {
            node_ptr = node;
        } else {
            node_ptr = node;
            std::swap(node->next_, head);
        }
        std::swap(head, node);
        std::swap(node, node_ptr->next_);
    }

    std::pair<std::unique_ptr<Node>, std::unique_ptr<Node>> 
    divide(std::unique_ptr<Node> head) {
        auto middle = count_elements(head.get()) / 2;
        std::unique_ptr<Node> first_part;
        std::unique_ptr<Node> second_part;
        auto* node = head.get();
        for (int i = 0 ; i < middle ; ++i) {
            node = node->ndex_.get();
        }
        second_part = std::move(node->next_);
        first_part = std::move(head);
        return {first_part, second_part};
    }

    int count_elements(const Node* node) {
        size_t size {};
        while (node->next_) {
            node = node->next_.get();
            ++size;
        }
        return ++size;
    }

    std::unique_ptr<Node> recursive_sort(std::unique_ptr<Node> head) {
        if (!head || !head->next_)
            return head;

        std::unique_ptr<Node> new_head;
        std::unique_ptr<Node> partition_node;
        partition(std::move(head), new_head, partition_node);

        auto lower_part = recursive_sort(std::move(new_head));
        auto higher_part = recursive_sort(std::move(partition_node));
        return splice(std::move(lower_part), std::move(higher_part));
    }

    Node* get_tail(const std::unique_ptr<Node>& head) {
        Node* node = nullptr;
        if (head) {
            node = head.get();
            while (node->next_) {
                node = node->next_.get();
            }
        }
        return node;
    }

    std::unique_ptr<Node> splice(std::unique_ptr<Node> lower, std::unique_ptr<Node> greater) {
        if (auto* tail = get_tail(greater))
            tail->next_ = std::move(lower);
        else
            return lower;
        return greater;
    }

    void swap_head(std::unique_ptr<Node>& head,
                std::unique_ptr<Node>& new_head) {
        auto head_next = std::move(head->next_);
        std::swap(head->next_, new_head);
        std::swap(new_head, head);
        std::swap(head, head_next);
    }

    void initialize_new_head(std::unique_ptr<Node>& head,
                            std::unique_ptr<Node>& new_head) {
        auto* tmp = head.get();
        std::swap(new_head, head);
        std::swap(head, tmp->next_);             
    }

    void partition(std::unique_ptr<Node> head,
                std::unique_ptr<Node>& new_head,
                std::unique_ptr<Node>& pivot_node) {
        auto pivot = head->data_;
        while (head) {
            if (head->data_ < pivot) {
                if (!new_head) {
                    initialize_new_head(head, new_head);
                    continue;
                }
                swap_head(head, new_head);
            } else {
                if (!pivot_node) {
                    initialize_new_head(head, pivot_node);
                    continue;
                }
                swap_head(head, pivot_node);
            }
        }
    }

    std::unique_ptr<Node> head_;
};

class LinkedListTest : public testing::Test {
public:
    std::vector<int> getShuffleVec(size_t size) {
        std::vector<int> vec(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        
        std::iota(begin(vec), end(vec), 0);
        std::shuffle(begin(vec), end(vec), gen);
        return vec;
    }

    std::vector<int> asVector(LinkedList<int>&& list) {
        std::vector<int> result;
        result.reserve(list.size());
        while (!list.empty()) {
            result.push_back(*list.pop_front());
        }
        return result;
    }
};

TEST_F(LinkedListTest, ShouldPopValue) {
    LinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    EXPECT_EQ(list.pop_front(), 3);
    EXPECT_EQ(list.pop_front(), 2);
    EXPECT_EQ(list.pop_front(), 1);
}

TEST_F(LinkedListTest, ShouldBeEmpty) {
    LinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.pop_front(), 3);
    EXPECT_EQ(list.pop_front(), 2);
    EXPECT_EQ(list.pop_front(), 1);
    EXPECT_TRUE(list.empty());
}

TEST_F(LinkedListTest, ShouldReturnSize) {
    LinkedList<int> list;
    auto vec = getShuffleVec(kVecSize);
    for (const auto& el : vec) {
        list.push_front(el);
    }
    EXPECT_EQ(vec.size(), list.size());
}

TEST_F(LinkedListTest, ShouldAppendNewValue) {
    LinkedList<int> list;
    list.push_front(200);
    list.push_front(300);
    list.push_front(400);
    auto vec = getShuffleVec(kVecSize);
    for (const auto& el : vec) {
        list.push_front(el);
    }
    std::reverse(begin(vec), end(vec));
    vec.push_back(400);
    vec.push_back(300);
    vec.push_back(200);
    EXPECT_EQ(vec, asVector(std::move(list)));
}

TEST_F(LinkedListTest, ShoudlCallFunctionForEachElement) {
    LinkedList<int> list;
    auto vec = getShuffleVec(kVecSize);
    for (const auto& el : vec) {
        list.push_front(el);
    }
    auto plus5 = [](auto& el){ return el +=5; };
    std::reverse(begin(vec), end(vec));
    std::for_each(begin(vec), end(vec), plus5);
    list.for_each(plus5);
    EXPECT_EQ(vec.size(), list.size());
	EXPECT_EQ(vec, asVector(std::move(list)));
}

TEST_F(LinkedListTest, ShouldMergeSort) {
    LinkedList<int> list;
    auto vec = getShuffleVec(kVecSize);
    for (const auto& el : vec) {
        list.push_front(el);
    }

    std::sort(begin(vec), end(vec), std::greater<int>{});
    list.merge_sort();
    EXPECT_EQ(vec, asVector(std::move(list)));
}

TEST_F(LinkedListTest, ShouldQuickSort) {
    LinkedList<int> list;
    auto vec = getShuffleVec(kVecSize);
    for (const auto& el : vec) {
        list.push_front(el);
    }

    std::sort(begin(vec), end(vec), std::greater<int>{});
    list.qsort();
    EXPECT_EQ(vec, asVector(std::move(list)));
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}