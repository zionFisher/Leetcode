// https://leetcode-cn.com/problems/coin-change-2/
#include <vector>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int &coin : coins)
        {
            for (int i = coin; i <= amount; i++)
            {
                dp[i] += dp[i - coin];
            }
        }
        return dp[amount];
    }
};

// more common solution
// class Solution
// {
// public:
//     int change(int amount, vector<int> &coins)
//     {
//         int len = coins.size();
//         vector<vector<int>> dp(len + 1, vector<int>(amount + 1, 0));
//         for (int i = 0; i <= len; ++i)
//         {
//             dp[i][0] = 1;
//         }
//         for (int j = 1; j <= amount; ++j)
//         {
//             for (int i = 1; i <= len; ++i)
//             {
//                 int val = coins[i - 1];
//                 for (int n = 0; n * val <= j; n++)
//                 {
//                     dp[i][j] += dp[i - 1][j - n * val];
//                 }
//             }
//         }
//         return dp[len][amount];
//     }
// };