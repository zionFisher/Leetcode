// https://leetcode-cn.com/problems/maximum-subarray/
#include <vector>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            return nums[0];
        }

        int size = nums.size();
        vector<int> dp(size);
        dp[0] = nums[0];
        int result = dp[0];

        for (int i = 0; i < size - 1; ++i)
        {
            dp[i + 1] = max(nums[i + 1], dp[i] + nums[i + 1]);
            result = max(result, dp[i + 1]);
        }

        return result;
    }
};

// better DP
// class Solution
// {
// public:
//     int maxSubArray(vector<int> &nums)
//     {
//         int pre = 0, maxAns = nums[0];
//         for (const auto &x : nums)
//         {
//             pre = max(pre + x, x);
//             maxAns = max(maxAns, pre);
//         }
//         return maxAns;
//     }
// };