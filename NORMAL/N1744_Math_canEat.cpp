// https://leetcode-cn.com/problems/can-you-eat-your-favorite-candy-on-your-favorite-day/
#include <vector>
using namespace std;

class Solution
{
public:
    vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries)
    {
        int size = queries.size();

        vector<long long> sum(candiesCount.size());
        sum[0] = candiesCount[0];
        for (int i = 1; i < candiesCount.size(); ++i)
            sum[i] = sum[i - 1] + candiesCount[i];

        vector<bool> res(size, true);
        for (int i = 0; i < size; ++i)
        {
            long preNum;
            if (queries[i][0] == 0)
                preNum = 0;
            else
                preNum = sum[queries[i][0] - 1];
            long num = sum[queries[i][0]];
            long day = queries[i][1];
            long max = queries[i][2];
            if (max * (day + 1) <= preNum)
                res[i] = false;
            else if (day + 1 > num)
                res[i] = false;
        }
        return res;
    }
};

// common solution
// class Solution
// {
// private:
//     using LL = long long;
//
// public:
//     vector<bool> canEat(vector<int> &candiesCount, vector<vector<int>> &queries)
//     {
//         int n = candiesCount.size();
//
//         // 前缀和
//         vector<LL> sum(n);
//         sum[0] = candiesCount[0];
//         for (int i = 1; i < n; ++i)
//         {
//             sum[i] = sum[i - 1] + candiesCount[i];
//         }
//
//         vector<bool> ans;
//         for (const auto &q : queries)
//         {
//             int favoriteType = q[0], favoriteDay = q[1], dailyCap = q[2];
//
//             LL x1 = favoriteDay + 1;
//             LL y1 = (LL)(favoriteDay + 1) * dailyCap;
//             LL x2 = (favoriteType == 0 ? 1 : sum[favoriteType - 1] + 1);
//             LL y2 = sum[favoriteType];
//
//             ans.push_back(!(x1 > y2 || y1 < x2));
//         }
//         return ans;
//     }
// };