// https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
#include "BinaryTree.hpp"
#include <queue>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return vector<vector<int>>();
        }
        queue<TreeNode *> que;
        vector<vector<int>> res;
        int level = -1;
        que.push(root);

        while (!que.empty())
        {
            level++;
            int size = que.size();
            res.push_back(vector<int>());
            for (int i = 0; i < size; ++i)
            {
                TreeNode *node = que.front();
                que.pop();
                res[level].push_back(node->val);
                if (node->left)
                {
                    que.push(node->left);
                }
                if (node->right)
                {
                    que.push(node->right);
                }
            }
        }

        return res;
    }
};