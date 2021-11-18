// https://leetcode-cn.com/problems/contains-duplicate/solution/cun-zai-zhong-fu-yuan-su-by-leetcode-sol-iedd/
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_set<int> s;
        for (int x : nums)
        {
            if (s.find(x) != s.end())
            {
                return true;
            }
            s.insert(x);
        }
        return false;
    }
};

// sort()
// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         for (int i = 0; i < n - 1; i++) {
//             if (nums[i] == nums[i + 1]) {
//                 return true;
//             }
//         }
//         return false;
//     }
// };