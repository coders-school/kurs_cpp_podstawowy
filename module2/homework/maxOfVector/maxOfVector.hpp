#pragma once
#include <limits>
#include <memory>
#include <vector>

struct Node
{
    int data;
    std::shared_ptr<Node> left;
    std::shared_ptr<Node> right;

    Node(int d)
    {
        data = d;
        left = right = nullptr;
    }
};

int findMax(std::shared_ptr<Node> node)
{
    std::shared_ptr<Node> current = node;
    while (current->right != nullptr)
        current = current->right;

    return (current->data);
}

struct BinaryTree
{
    std::shared_ptr<Node> insert(std::shared_ptr<Node> root, int data)
    {
        if (root == nullptr)
        {
            return std::shared_ptr<Node>(new Node(data));
        }
        else
        {
            std::shared_ptr<Node> cur;
            if (data <= root->data)
            {
                cur = insert(root->left, data);
                root->left = cur;
            }
            else
            {
                cur = insert(root->right, data);
                root->right = cur;
            }
            return root;
        }
    }
};

int maxOfVector(const std::vector<int>& vec)
{
    BinaryTree bt;
    std::shared_ptr<Node> current = nullptr;
    for (auto i : vec)
    {
        current = bt.insert(current, i);
    }
    return findMax(current);
}
