// https://leetcode-cn.com/problems/power-of-three/
#include <cmath>
using namespace std;

// stupid solution
class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n == 1)
            return true;
        else if (n < 3)
            return false;

        double res = log(n) / log(3);
        int judge = res;
        double rr = abs(res - judge);
        if (rr < 1e-12 || abs(rr - 1) < 1e-12)
            return true;
        return false;
    }
};

// common solution in java
// public class Solution
// {
// public
//     boolean isPowerOfThree(int n)
//     {
//         if (n < 1)
//         {
//             return false;
//         }
//
//         while (n % 3 == 0)
//         {
//             n /= 3;
//         }
//
//         return n == 1;
//     }
// }