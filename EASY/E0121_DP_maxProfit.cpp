// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/
#include <vector>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int minprice = int(1e9);
        int maxprofit = 0;
        for (auto price : prices)
        {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(minprice, price);
        }
        return maxprofit;
    }
};

// DP
// class Solution
// {
// public:
//     int maxProfit(vector<int> &prices)
//     {
//         int n = prices.size();
//         if (n == 0)
//             return 0; // 边界条件
//         int minprice = prices[0];
//         vector<int> dp(n, 0);

//         for (int i = 1; i < n; i++)
//         {
//             minprice = min(minprice, prices[i]);
//             dp[i] = max(dp[i - 1], prices[i] - minprice);
//         }
//         return dp[n - 1];
//     }
// };