// https://leetcode-cn.com/problems/last-stone-weight-ii/
#include <vector>
#include <numeric>
using namespace std;

class Solution
{
public:
    int lastStoneWeightII(vector<int> &stones)
    {
        int sum = accumulate(stones.begin(), stones.end(), 0);
        vector<vector<int>> dp(stones.size() + 1, vector<int>(sum / 2 + 1, 0));

        int target = sum / 2;
        for (int i = 0; i < stones.size(); ++i)
            for (int j = 1; j <= target; ++j)
                if (j < stones[i])
                    dp[i + 1][j] = dp[i][j];
                else
                    dp[i + 1][j] = max(dp[i][j], dp[i][j - stones[i]] + stones[i]);
        return sum - dp[stones.size()][target] - dp[stones.size()][target];
    }
};