// https://leetcode.cn/problems/shuffle-the-array/description/

#include "SuperSet.hpp"

class Solution
{
public:
    vector<int> shuffle(vector<int>& nums, int n)
    {
        vector<int> res(nums.size(), 0);

        int counter = 0;
        for ( int front = 0, back = n; front < n; )
        {
            res[counter++] = nums[front++];
            res[counter++] = nums[back++];
        }

        return res;
    }
};