// https://leetcode-cn.com/problems/er-cha-shu-zhong-he-wei-mou-yi-zhi-de-lu-jing-lcof/
#include "SuperSet.hpp"

class Solution
{
private:
    vector<vector<int>> res;
    vector<int> path;

public:
    vector<vector<int>> pathSum(TreeNode* root, int target)
    {
        DFS(root, target, 0);
        return res;
    }

    void DFS(TreeNode *node, int target, int preSum)
    {
        if (node == nullptr)
            return;
        preSum += node->val;
        path.push_back(node->val);
        if (preSum == target && node->left == node->right && node->left == nullptr)
            res.push_back(path);
        DFS(node->left, target, preSum);
        DFS(node->right, target, preSum);
        path.pop_back();
    }
};