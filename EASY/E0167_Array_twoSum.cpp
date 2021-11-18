// https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
#include <iostream>
#include <vector>        // Array
#include <unordered_map> // HashSet
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int begin = 0, end = nums.size() - 1;
        while (begin < end)
        {
            if (nums[begin] + nums[end] == target)
            {
                return {begin + 1, end + 1};
            }
            else if (nums[begin] + nums[end] < target)
            {
                ++begin;
            }
            else if (nums[begin] + nums[end] > target)
            {
                --end;
            }
        }

        return {};
    }
};