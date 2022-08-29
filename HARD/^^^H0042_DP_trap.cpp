// https://leetcode.cn/problems/trapping-rain-water/
#include "SuperSet.hpp"

class Solution
{
public:
    int trap(vector<int>& height)
    {
        int res = 0;
        int size = height.size();
        vector<int> leftMax(size, 0);
        leftMax[0] = height[0];
        vector<int> rightMax(size, 0);
        rightMax[size - 1] = height[size - 1];

        for (int i = 1; i < size; ++i)
            leftMax[i] = max(height[i], leftMax[i - 1]);

        for (int i = size - 2; i > -1; --i)
            rightMax[i] = max(height[i], rightMax[i + 1]);

        for (int i = 0; i < size; ++i)
            res += min(leftMax[i], rightMax[i]) - height[i];

        return res;
    }
};