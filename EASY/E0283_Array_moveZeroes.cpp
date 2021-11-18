// https://leetcode-cn.com/problems/move-zeroes/
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    void moveZeroes(vector<int>& nums) 
    {
        int i = 0;
        for (int k : nums)
            if (k)
                nums[i++] = k;
        for (int j = i; j < nums.size(); ++j)
           nums[j] = 0;
    }
};
