// https://leetcode-cn.com/problems/perfect-squares/
#include <cmath>
#include <vector>
using namespace std;

class Solution
{
public:
    int numSquares(int n)
    {
        vector<int> f(n + 1);
        for (int i = 1; i <= n; i++)
        {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; j++)
            {
                minn = min(minn, f[i - j * j]);
            }
            f[i] = minn + 1;
        }
        return f[n];
    }
};

// DP
// class Solution
// {
// public:
//     int numSquares(int n)
//     {
//         vector<int> dp(n + 1, INT_MAX);
//         dp[0] = 0;
//         for (int i = 1; i * i <= n; i++)
//         { // 遍历物品
//             for (int j = 1; j <= n; j++)
//             { // 遍历背包
//                 if (j - i * i >= 0)
//                 {
//                     dp[j] = min(dp[j - i * i] + 1, dp[j]);
//                 }
//             }
//         }
//         return dp[n];
//     }
// };

// DP
// class Solution
// {
// public:
//     int numSquares(int n)
//     {
//         int sq = sqrt(n);
//         vector<vector<int>> dp(sq + 1, vector<int>(n + 1, 0));
//         vector<int> minValue(n + 1, INT_MAX);
//         for (int i = 1; i < sq + 1; ++i)
//             for (int j = 1; j < n + 1; ++j)
//             {
//                 if (j < i * i)
//                     dp[i][j] = minValue[j];
//                 else
//                     dp[i][j] = dp[i][j - i * i] + 1;
//                 minValue[j] = min(dp[i][j], minValue[j]);
//             }
//
//         return minValue[n];
//     }
// };