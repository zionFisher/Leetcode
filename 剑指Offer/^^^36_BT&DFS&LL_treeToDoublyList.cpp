// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-yu-shuang-xiang-lian-biao-lcof/
#include "SuperSet.hpp"

class Solution
{
private:
    Node *first, *pre;

public:
    Node *treeToDoublyList(Node *root)
    {
        if (root == nullptr)
            return nullptr;

        first = FindFirst(root);
        DFS(root);
        first->left = pre;
        pre->right = first;

        return first;
    }

    void DFS(Node *node)
    {
        if (node == nullptr)
            return;
        DFS(node->left);
        node->left = pre;
        if (pre != nullptr)
            pre->right = node;
        pre = node;
        DFS(node->right);
    }

    Node *FindFirst(Node *root)
    {
        if (root->left == nullptr)
            return root;
        return FindFirst(root->left);
    }
}; 