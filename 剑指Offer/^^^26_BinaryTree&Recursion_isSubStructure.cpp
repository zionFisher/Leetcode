// https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    bool isSubStructure(TreeNode* A, TreeNode* B)
    {
        if (A == nullptr || B == nullptr)
            return false;
        return recur(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }

    bool recur(TreeNode *A, TreeNode *B)
    {
        if(B == nullptr)
            return true;
        if(A == nullptr || A->val != B->val)
            return false;
        return recur(A->left, B->left) && recur(A->right, B->right);
    }
};