//https://leetcode-cn.com/problems/binary-tree-tilt/
#include "BinaryTree.hpp"
#include <cmath>

class Solution
{
public:
    int findTilt(TreeNode* root)
    {
        findSum(root);
        return sum;
    }

    int findSum(TreeNode* root)
    {
        if (root == nullptr)
            return 0;
        int l = findSum(root->left);
        int r = findSum(root->right);
        sum += abs(l - r);
        return root->val + l + r;
    }

private:
    int sum = 0;
};