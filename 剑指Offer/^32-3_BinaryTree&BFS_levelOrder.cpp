// https://leetcode-cn.com/problems/cong-shang-dao-xia-da-yin-er-cha-shu-iii-lcof/
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
        bool isOdd = false;

        que.push(root);
        while (!que.empty())
        {
            int size = que.size();
            vector<int> level;
            isOdd = !isOdd;
            for (int i = 0; i < size; ++i)
            {
                TreeNode* node = que.front();
                que.pop();
                level.push_back(node->val);
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            if (!isOdd)
            {
                res.push_back(vector<int>());
                for (int i = level.size() - 1; i > -1; --i)
                    res.back().push_back(level[i]);
            }
            else
                res.push_back(level);
        }

        return res;
    }
};