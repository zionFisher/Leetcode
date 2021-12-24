// https://leetcode-cn.com/problems/fei-bo-na-qi-shu-lie-lcof/
#include "SuperSet.hpp"

class Solution
{
public:
    int fib(int n)
    {
        if (n < 2)
            return n;

        int a = 0, b = 0, sum = 1;
        for (int i = 2; i <= n; ++i)
        {
            a = b;
            b = sum;
            sum = (a + b) % 1000000007;
        }

        return sum;
    }
};