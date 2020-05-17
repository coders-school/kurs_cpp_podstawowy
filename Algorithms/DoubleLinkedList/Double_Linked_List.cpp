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
class DoubleLinkedList {
private:
    struct Node {
        explicit Node(const T& data): data_(data) {}
        explicit Node(T&& data): data_(std::move(data)) {}

        std::unique_ptr<Node> next_ = nullptr;
        Node* prev_ = nullptr;
        T data_;
    };

public:
    DoubleLinkedList() = default;
    ~DoubleLinkedList() = default;
    DoubleLinkedList(const DoubleLinkedList&) = delete;
    DoubleLinkedList& operator=(const DoubleLinkedList& other) = delete;
    DoubleLinkedList(DoubleLinkedList&& other) { std::swap(head_, other.head_); head_ = nullptr; }
    DoubleLinkedList& operator=(DoubleLinkedList&& other) {
        if (this != &other) {
            std::swap(head_, other.head_);
            head_ = nullptr;
        }
        return *this;
    }

    // push_front and push_back could be one template
    // argument with perfect forwarding, but you must
    // ensure that template argument is the same type
    // as class argument.
    void push_front(const T& val) {
        if (!head_) {
            create_head(val);
        } else {
            push_front_helper(val);
        }
    }

    void push_front(T&& val) {
        if (!head_) {
            create_head(std::move(val));
        } else {
            push_front_helper(std::move(val));
        }
    }

    void push_back(const T& val) {
        if (!head_) {
            create_head(val);
            return;
        }
        push_back_helper(val);
    }

    void push_back(T&& val) {
        if (!head_) {
            create_head(std::move(val));
            return;
        }
        push_back_helper(std::move(val));
    }

    // Call this function is not safe when list is empty
    // second version is to check this and return 
    // std::optional<T>
    T& front() {
        return head_->data_;
    }

    // Call this function is not safe when list is empty
    // second version is to check this and return 
    // std::optional<T>
    T& back() {
        return tail_->data_;
    }

    // Safe when list is empty
    std::optional<T> pop_front() {
        if (!head_) 
            return std::nullopt;
        auto return_val = std::move(head_->data_);
        head_ = std::move(head_->next_);
        head_ ? head_->prev_ = nullptr : tail_ = nullptr;
        return return_val;
    }

    // Safe when list is empty
    std::optional<T> pop_back() {
        if (!head_) 
            return std::nullopt;
        auto return_val = std::move(tail_->data_);
        tail_ = tail_->prev_;
        tail_ ? tail_->next_ = nullptr : head_ = nullptr;
        return return_val;
    }

    void display_forward() const {
        for_each([](const auto* node){ std::cout << node->data_ << ' '; });
        std::cout << '\n';
    }

    void display_backward() const {
        for_each_backward([](const auto* node){ std::cout << node->data_ << ' '; }, tail_);
        std::cout << '\n';
    }

    bool empty() const { return !(bool)head_; }

    size_t size() const { 
        size_t size {};
        for_each([&size](const auto* node){ ++size; });
        return size;
    }

    template<typename FUN> 
    void for_each(FUN&& fun) const {
        if (!head_)
            return;
        for_each(std::forward<FUN&&>(fun), head_.get());
    }

    void qsort() {
        head_ = recursive_sort(std::move(head_));
    }

    void merge_sort() {
        head_ = recursive_sort(std::move(head_));
    }

private:
    template<typename FUN> 
    void for_each(FUN fun, Node* node) const {
        while (node->next_) {
            fun(node);
            node = node->next_.get();
        }
        fun(node);
    }

    template<typename FUN> 
    void for_each_backward(FUN fun, Node* node) const {
        while (node) {
            fun(node);
            node = node->prev_;
        }
    }

    // Example of perfect forward functions
    template <typename U>
    void create_head(U&& val) {
        head_ = std::make_unique<Node>(std::forward<U>(val));
        tail_ = head_.get();
    }

    template <typename U>
    void push_front_helper(U&& val) {
        auto new_node = std::make_unique<Node>(std::forward<U>(val));
        head_->prev_ = new_node.get();
        new_node->next_ = std::move(head_);
        head_ = std::move(new_node);
    }

    template <typename U>
    void push_back_helper(U&& val) {
        auto new_node = std::make_unique<Node>(std::forward<U>(val));
        new_node->prev_ = tail_;
        tail_->next_ = std::move(new_node);
        tail_ = tail_->next_.get();
    }

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
    Node* tail_;
};

class DoubleLinkedListTest : public testing::Test {
public:
    std::vector<int> getShuffleVec(size_t size) {
        std::vector<int> vec(size);
        std::random_device rd;
        std::mt19937 gen(rd());
        
        std::iota(begin(vec), end(vec), 0);
        std::shuffle(begin(vec), end(vec), gen);
        return vec;
    }

    std::vector<int> asVector(DoubleLinkedList<int>&& list) {
        std::vector<int> result;
        result.reserve(list.size());
        while (!list.empty()) {
            result.push_back(*list.pop_front());
        }
        return result;
    }
};

TEST_F(DoubleLinkedListTest, ShouldPushFront) {
    DoubleLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    EXPECT_EQ(list.front(), 3);
    EXPECT_EQ(list.back(), 1);
}

TEST_F(DoubleLinkedListTest, ShouldPushBack) {
    DoubleLinkedList<int> list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    EXPECT_EQ(list.front(), 1);
    EXPECT_EQ(list.back(), 3);
}

TEST_F(DoubleLinkedListTest, ShouldPushFrontAndBack) {
    DoubleLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_back(4);
    EXPECT_EQ(list.front(), 3);
    EXPECT_EQ(list.back(), 4);
    list.push_back(5);
    list.push_front(6);
    EXPECT_EQ(list.front(), 6);
    EXPECT_EQ(list.back(), 5);
}

TEST_F(DoubleLinkedListTest, ShouldPopFront) {
    DoubleLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    EXPECT_EQ(list.pop_front(), 3);
    EXPECT_EQ(list.pop_front(), 2);
    EXPECT_EQ(list.pop_front(), 1);
}

TEST_F(DoubleLinkedListTest, ShouldPopBack) {
    DoubleLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    EXPECT_EQ(list.pop_back(), 1);
    EXPECT_EQ(list.pop_back(), 2);
    EXPECT_EQ(list.pop_back(), 3);
}

TEST_F(DoubleLinkedListTest, ShouldPopFrontAndBack) {
    DoubleLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_back(4);
    list.push_back(5);
    list.push_front(6);
    EXPECT_EQ(list.pop_back(), 5);
    EXPECT_EQ(list.pop_front(), 6);
    EXPECT_EQ(list.pop_back(), 4);
    EXPECT_EQ(list.pop_front(), 3);
    EXPECT_EQ(list.pop_back(), 1);
    EXPECT_EQ(list.pop_front(), 2);
}

TEST_F(DoubleLinkedListTest, ShouldBeEmptyWhenPopFront) {
    DoubleLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.pop_front(), 3);
    EXPECT_EQ(list.pop_front(), 2);
    EXPECT_EQ(list.pop_front(), 1);
    EXPECT_TRUE(list.empty());
}

TEST_F(DoubleLinkedListTest, ShouldBeEmptyWhenPopBack) {
    DoubleLinkedList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    EXPECT_FALSE(list.empty());
    EXPECT_EQ(list.pop_back(), 1);
    EXPECT_EQ(list.pop_back(), 2);
    EXPECT_EQ(list.pop_back(), 3);
    EXPECT_TRUE(list.empty());
}

TEST_F(DoubleLinkedListTest, ShouldReturnSize) {
    DoubleLinkedList<int> list;
    auto vec = getShuffleVec(kVecSize);
    for (const auto& el : vec) {
        list.push_front(el);
    }
    EXPECT_EQ(vec.size(), list.size());
}

TEST_F(DoubleLinkedListTest, ShouldAppendFrontNewValue) {
    DoubleLinkedList<int> list;
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

TEST_F(DoubleLinkedListTest, ShouldAppendBackNewValue) {
    DoubleLinkedList<int> list;
    list.push_back(200);
    list.push_back(300);
    list.push_back(400);
    auto vec = getShuffleVec(kVecSize);
    for (const auto& el : vec) {
        list.push_front(el);
    }
    std::reverse(begin(vec), end(vec));
    vec.push_back(200);
    vec.push_back(300);
    vec.push_back(400);
    EXPECT_EQ(vec, asVector(std::move(list)));
}

TEST_F(DoubleLinkedListTest, ShoudlCallFunctionForEachElement) {
    DoubleLinkedList<int> list;
    auto vec = getShuffleVec(kVecSize);
    for (const auto& el : vec) {
        list.push_front(el);
    }
    auto plus5 = [](auto el){ return el += 5; };
    std::reverse(begin(vec), end(vec));
    std::for_each(begin(vec), end(vec), plus5);
    list.for_each(plus5);
    EXPECT_EQ(vec.size(), list.size());
    EXPECT_EQ(vec, asVector(std::move(list)));
}

TEST_F(DoubleLinkedListTest, ShouldMergeSort) {
    DoubleLinkedList<int> list;
    auto vec = getShuffleVec(kVecSize);
    for (const auto& el : vec) {
        list.push_front(el);
    }

    std::sort(begin(vec), end(vec), std::greater<int>{});
    list.merge_sort();
    EXPECT_EQ(vec, asVector(std::move(list)));
}

TEST_F(DoubleLinkedListTest, ShouldQuickSort) {
    DoubleLinkedList<int> list;
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