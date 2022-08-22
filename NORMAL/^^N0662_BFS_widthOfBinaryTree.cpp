// https://leetcode.cn/problems/maximum-width-of-binary-tree/
#include "SuperSet.hpp"

class Solution
{
private:
    long long width = -1;

public:
    int widthOfBinaryTree(TreeNode* root)
    {
        queue<pair<TreeNode *, pair<long long, long long>>> que;
        que.push({ root, { 0, 0 } });
        BFS(que);

        return width;
    }

    void BFS(queue<pair<TreeNode *, pair<long long, long long>>> &que)
    {
        if (que.size() == 0)
            return;

        auto front = que.front();
        auto back = que.back();

        if (back.second.second == front.second.second)
            width = max(back.second.first - front.second.first + 1, width);

        long long index = front.second.first % INT_MAX;
        if (front.first->left != nullptr)
            que.push({ front.first->left, { index * 2 + 1 , front.second.second + 1 }});
        if (front.first->right != nullptr)
            que.push({ front.first->right, { index * 2 + 2 , front.second.second + 1 }});

        que.pop();

        BFS(que);
    }
};