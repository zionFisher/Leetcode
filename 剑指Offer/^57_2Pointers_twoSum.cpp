// https://leetcode-cn.com/problems/he-wei-sde-liang-ge-shu-zi-lcof/
#include "SuperSet.hpp"

// Notice that this is different from the Leetcode problem 1 in that the array is ordered
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int size = nums.size(), ptr1 = 0, ptr2 = size - 1;

        while (nums[ptr1] + nums[ptr2] != target)
        {
            while (nums[ptr1] + nums[ptr2] > target)
                ptr2--;
            while (nums[ptr1] + nums[ptr2] < target)
                ptr1++;
        }

        return vector<int> { nums[ptr1], nums[ptr2] };
    }
};