// https://leetcode-cn.com/problems/symmetric-tree/
#include "BinaryTree.hpp"

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        return isMirror(root, root);
    }

    bool isMirror(TreeNode *left, TreeNode *right)
    {
        if (left == nullptr && right == nullptr)
        {
            return true;
        }
        if (left == nullptr || right == nullptr)
        {
            return false;
        }
        if (left->val != right->val)
        {
            return false;
        }
        return isMirror(left->left, right->right) && isMirror(left->right, right->left);
    }
};

// iteration
// class Solution
// {
// public:
//     bool check(TreeNode *u, TreeNode *v)
//     {
//         queue<TreeNode *> q;
//         q.push(u);
//         q.push(v);
//         while (!q.empty())
//         {
//             u = q.front();
//             q.pop();
//             v = q.front();
//             q.pop();
//             if (!u && !v)
//                 continue;
//             if ((!u || !v) || (u->val != v->val))
//                 return false;
//
//             q.push(u->left);
//             q.push(v->right);
//
//             q.push(u->right);
//             q.push(v->left);
//         }
//         return true;
//     }
//
//     bool isSymmetric(TreeNode *root)
//     {
//         return check(root, root);
//     }
// };