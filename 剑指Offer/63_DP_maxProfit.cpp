// https://leetcode-cn.com/problems/gu-piao-de-zui-da-li-run-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    int maxProfit(vector<int>& prices)
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

// class Solution
// {
// public:
//     int maxProfit(vector<int>& prices)
//     {
//         int DP0 = 0, DP1 = 0, size = prices.size();
//         int preMin = INT_MAX;
//
//         for (int i = 0; i < size; ++i)
//         {
//             if (prices[i] < preMin)
//                 preMin = prices[i];
//             DP1 = DP0 > (prices[i] - preMin) ? DP0 : (prices[i] - preMin);
//             DP0 = DP1;
//         }
//
//         return DP1;
//     }
// };