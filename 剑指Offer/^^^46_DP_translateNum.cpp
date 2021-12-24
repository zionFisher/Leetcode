// https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    int translateNum(int num)
    {
        int DP0 = 0, DP1 = 1, DP2 = 1;
        string str = to_string(num);

        for (int i = 1; i < str.size(); i++)
        {
            DP0 = DP1;
            DP1 = DP2;
            string word = str.substr(i - 1, 2);
            if (word <= "25" && word >= "10")
                DP2 += DP0;
        }

        return DP2;
    }
};