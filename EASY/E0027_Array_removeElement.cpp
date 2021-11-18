// https://leetcode-cn.com/problems/remove-element/
#include <iostream>
#include <vector>
using namespace std;

class Solution 
{
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int k = 0;
        for (auto x : nums)
            if (x != val)
                nums[k++] = x;
        return k;
    }
};