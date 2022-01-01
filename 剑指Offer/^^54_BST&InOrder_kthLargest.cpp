// https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-di-kda-jie-dian-lcof/
#include "SuperSet.hpp"

class Solution
{
private:
    int counter = 0, res = 0;

public:
    int kthLargest(TreeNode *root, int k)
    {
        counter = k;
        ReverseInOrderTraverse(root);
        return res;
    }

    void ReverseInOrderTraverse(TreeNode *node)
    {
        if (node == nullptr)
            return;
        ReverseInOrderTraverse(node->right);
        if (--counter == 0)
            res = node->val;
        ReverseInOrderTraverse(node->left);
    }
};