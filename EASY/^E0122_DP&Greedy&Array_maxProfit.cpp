// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int left = 0, right = 0;
        int profit = 0;
        for (int count = 1; count < prices.size(); count++)
        {
            if (count == prices.size() - 1)
            {
                if (prices[count] > prices[count - 1])
                {
                    right = count;
                    profit += prices[right] - prices[left];
                }
                return profit;
            }
            if (prices[count] <= prices[count - 1] && prices[count] <= prices[count + 1])
            {
                left = count;
            }
            else if (prices[count] > prices[count - 1] && prices[count] >= prices[count + 1])
            {
                right = count;
                profit += prices[right] - prices[left];
                left = 0;
                right = 0;
            }
        }
        return 0;
    }
};

// Greedy
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int ans = 0;
//         int n = prices.size();
//         for (int i = 1; i < n; ++i)
//         {
//             ans += max(0, prices[i] - prices[i - 1]);
//         }
//         return ans;
//     }
// };

// DP
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int n = prices.size();
//         int dp0 = 0, dp1 = -prices[0];
//         for (int i = 1; i < n; ++i)
//         {
//             int newDp0 = max(dp0, dp1 + prices[i]);
//             int newDp1 = max(dp1, dp0 - prices[i]);
//             dp0 = newDp0;
//             dp1 = newDp1;
//         }
//         return dp0;
//     }
// };