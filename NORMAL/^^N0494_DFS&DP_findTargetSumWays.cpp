// https://leetcode-cn.com/problems/target-sum/
#include <cmath>
#include <vector>
using namespace std;

// DFS
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        return findTargetSumWays(nums, nums.size(), target);
    }

    int findTargetSumWays(vector<int> &nums, int size, int target)
    {
        if (size == 1)
            if (nums[0] == 0 and target == 0)
                return 2;
            else if (abs(nums[0]) == abs(target))
                return 1;
            else
                return 0;

        int offsetN = target - nums[size - 1];
        int offsetP = target + nums[size - 1];
        int resN = findTargetSumWays(nums, size - 1, offsetN);
        int resP = findTargetSumWays(nums, size - 1, offsetP);
        return resN + resP;
    }
};

// or like this ↓
// class Solution
// {
// public:
//     int findTargetSumWays(vector<int> &nums, int target)
//     {
//         return findTargetSumWays(nums, nums.size(), target);
//     }
//
//     int findTargetSumWays(vector<int> &nums, int size, int target)
//     {
//         if (size == 1)
//             if (nums[0] == 0 and target == 0)
//                 return 2;
//             else if (abs(nums[0]) == abs(target))
//                 return 1;
//             else
//                 return 0;
//
//         return findTargetSumWays(nums, size - 1, target - nums[size - 1]) +
//                findTargetSumWays(nums, size - 1, target + nums[size - 1]);
//     }
// };

// DP
// class Solution
// {
// public:
//     int findTargetSumWays(vector<int> &nums, int target)
//     {
//         int sum = 0;
//         for (int &num : nums)
//         {
//             sum += num;
//         }
//         int diff = sum - target;
//         if (diff < 0 || diff % 2 != 0)
//         {
//             return 0;
//         }
//         int neg = diff / 2;
//         vector<int> dp(neg + 1);
//         dp[0] = 1;
//         for (int &num : nums)
//         {
//             for (int j = neg; j >= num; j--)
//             {
//                 dp[j] += dp[j - num];
//             }
//         }
//         return dp[neg];
//     }
// };

// DP
// class Solution
// {
// public:
//     int findTargetSumWays(vector<int> &nums, int S)
//     {
//         int sum = 0;
//         for (int i = 0; i < nums.size(); i++)
//             sum += nums[i];
//         if (S > sum)
//             return 0; // 此时没有方案
//         if ((S + sum) % 2 == 1)
//             return 0; // 此时没有方案
//         int bagSize = (S + sum) / 2;
//         vector<int> dp(bagSize + 1, 0);
//         dp[0] = 1;
//         for (int i = 0; i < nums.size(); i++)
//         {
//             for (int j = bagSize; j >= nums[i]; j--)
//             {
//                 dp[j] += dp[j - nums[i]];
//             }
//         }
//         return dp[bagSize];
//     }
// };