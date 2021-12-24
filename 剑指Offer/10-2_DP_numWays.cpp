// https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    int numWays(int n)
    {
        if (n < 2)
            return 1;

        int a = 0, b = 1, sum = 2;
        for (int i = 3; i <= n; ++i)
        {
            a = b;
            b = sum;
            sum = (a + b) % 1000000007;
        }

        return sum;
    }
};