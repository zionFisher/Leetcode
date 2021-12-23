// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-ii-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if (root == nullptr)
            return vector<vector<int>>();

        queue<TreeNode*> que;
        vector<vector<int>> res;

        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            res.push_back(vector<int>());
            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = que.front();
                que.pop();
                res.back().push_back(node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
        }

        return res;
    }
};