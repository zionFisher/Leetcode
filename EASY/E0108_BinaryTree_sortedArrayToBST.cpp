// https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/
#include "BinaryTree.hpp"
#include <vector>
using namespace std;

class Solution
{
public:
    TreeNode* sortedArrayToBST(vector<int>& nums)
    {
        return build(nums, 0, nums.size() - 1);
    }

    TreeNode* build(vector<int>& nums, int low, int high)
    {
        if (low > high)
        {
            return nullptr;
        } 
        int rootNum = low + (high - low) / 2;;
        TreeNode* root = new TreeNode(nums[rootNum]);
        root->left = build(nums, low, rootNum - 1);
        root->right = build(nums, rootNum + 1, high);
        return root;
    }
};