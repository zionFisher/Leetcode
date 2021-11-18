// https://leetcode-cn.com/problems/house-robber/
#include <vector>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int size = nums.size();
        if (size == 1)
        {
            return nums[0];
        }
        int dp[size];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < size; ++i)
        {
            dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        }
        return dp[size - 1];
    }
};

// better solution
// int rob(vector<int> &nums)
// {
//     int prev = 0;
//     int curr = 0;
//
//     // 每次循环，计算“偷到当前房子为止的最大金额”
//     for (int i : nums)
//     {
//         // 循环开始时，curr 表示 dp[k-1]，prev 表示 dp[k-2]
//         // dp[k] = max{ dp[k-1], dp[k-2] + i }
//         int temp = max(curr, prev + i);
//         prev = curr;
//         curr = temp;
//         // 循环结束时，curr 表示 dp[k]，prev 表示 dp[k-1]
//     }
//
//     return curr;
// }

// NB solution
// int rob(vector<int> &nums)
// {
//     int sumOdd = 0;
//     int sumEven = 0;
//
//     for (int i = 0; i < nums.size(); i++)
//     {
//         if (i % 2 == 0)
//         {
//             sumEven += nums[i];
//             sumEven = max(sumOdd, sumEven);
//         }
//         else
//         {
//             sumOdd += nums[i];
//             sumOdd = max(sumOdd, sumEven);
//         }
//     }
//     return max(sumOdd, sumEven);
// }