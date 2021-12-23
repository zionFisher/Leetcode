// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    vector<int> levelOrder(TreeNode* root)
    {
        if (root == nullptr)
            return vector<int>();

        queue<TreeNode *> que;
        vector<int> res;

        que.push(root);
        while (!que.empty())
        {
            auto node = que.front();
            que.pop();
            res.push_back(node->val);
            if (node->left != nullptr)
                que.push(node->left);
            if (node->right != nullptr)
                que.push(node->right);
        }
        return res;
    }
};