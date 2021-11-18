// https://leetcode-cn.com/problems/validate-binary-search-tree/
#include "BinaryTree.hpp"
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> res;

    bool isValidBST(TreeNode *root)
    {
        inOrder(root);
        for (int i = 0; i < res.size() - 1; ++i)
        {
            if (res[i] >= res[i + 1])
            {
                return false;
            }
        }
        return true;
    }

    void inOrder(TreeNode *root)
    {
        if (!root)
        {
            return;
        }
        if (root->left)
        {
            inOrder(root->left);
        }
        res.push_back(root->val);
        if (root->right)
        {
            inOrder(root->right);
        }
    }
};

// java
// class Solution
// {
//     long pre = Long.MIN_VALUE;
//
//     public boolean isValidBST(TreeNode root)
//     {
//         if (root == null)
//         {
//             return true;
//         }
//         // 访问左子树
//         if (!isValidBST(root.left))
//         {
//             return false;
//         }
//         // 访问当前节点：如果当前节点小于等于中序遍历的前一个节点，说明不满足BST，返回 false；否则继续遍历。
//         if (root.val <= pre)
//         {
//             return false;
//         }
//         pre = root.val;
//         // 访问右子树
//         return isValidBST(root.right);
//     }
// }

// recurse
// class Solution
// {
// public:
//     bool helper(TreeNode *root, long long lower, long long upper)
//     {
//         if (root == nullptr)
//         {
//             return true;
//         }
//         if (root->val <= lower || root->val >= upper)
//         {
//             return false;
//         }
//         return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
//     }
//     bool isValidBST(TreeNode *root)
//     {
//         return helper(root, LONG_MIN, LONG_MAX);
//     }
// };

// no need for global var
// class Solution
// {
// public:
//     bool isValidBST(TreeNode *root)
//     {
//         stack<TreeNode *> stack;
//         long long inorder = (long long)INT_MIN - 1;

//         while (!stack.empty() || root != nullptr)
//         {
//             while (root != nullptr)
//             {
//                 stack.push(root);
//                 root = root->left;
//             }
//             root = stack.top();
//             stack.pop();
//             // 如果中序遍历得到的节点的值小于等于前一个 inorder，说明不是二叉搜索树
//             if (root->val <= inorder)
//             {
//                 return false;
//             }
//             inorder = root->val;
//             root = root->right;
//         }
//         return true;
//     }
// };