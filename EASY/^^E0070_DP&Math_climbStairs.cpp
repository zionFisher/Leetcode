// https://leetcode-cn.com/problems/climbing-stairs/
#include <algorithm>
using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
        {
            return 1;
        }

        int a = 1, b = 1, t = 1, counter = 1;

        while (counter++ < n)
        {
            swap(a, b);
            swap(b, t);
            t = a + b;
        }
        return t;
    }
};