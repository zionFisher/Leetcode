// https://leetcode-cn.com/problems/er-cha-shu-de-jing-xiang-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    TreeNode* mirrorTree(TreeNode* root)
    {
        if (!root)
            return nullptr;

        TreeNode *newNode = new TreeNode(root->val);
        newNode->left = mirrorTree(root->right);
        newNode->right = mirrorTree(root->left);
        return newNode;
    }
};