// https://leetcode.cn/problems/print-binary-tree/
#include "SuperSet.hpp"

class Solution
{
private:
    vector<vector<string>> res;
    int height;

public:
    vector<vector<string>> printTree(TreeNode *root)
    {
        height = DFS(root, 0);

        res.resize(height + 1);
        for (auto &it : res)
            it.resize(pow(2, height + 1) - 1);

        int posX = (res[0].size() - 1) / 2;
        DFSPos(root, 0, posX);

        return res;
    }

    int DFS(TreeNode *node, int height)
    {
        if (node == nullptr)
            return height;

        int res = height;

        if (node->left != nullptr)
            res = DFS(node->left, height + 1);
        if (node->right != nullptr)
            res = max(res, DFS(node->right, height + 1));
        
        return res;
    }

    void DFSPos(TreeNode *node, int posY, int posX)
    {
        if (node == nullptr)
            return;

        res[posY][posX] = to_string(node->val);

        int childrenPosY = posY + 1;
        int leftChildPosX = posX - pow(2, height - posY - 1);
        int rightChildPosX = posX + pow(2, height - posY - 1);

        if (node->left != nullptr)
            DFSPos(node->left, childrenPosY, leftChildPosX);
        if (node->right != nullptr)
            DFSPos(node->right, childrenPosY, rightChildPosX);
    }
};