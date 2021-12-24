// https://leetcode-cn.com/problems/lian-xu-zi-shu-zu-de-zui-da-he-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int pre = 0, maxAns = nums[0];
        for (const auto &x: nums)
        {
            pre = max(pre + x, x);
            maxAns = max(maxAns, pre);
        }
        return maxAns;
    }
};