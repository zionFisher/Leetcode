// https://leetcode-cn.com/problems/hamming-distance/

class Solution
{
public:
    int hammingDistance(int x, int y)
    {
        int res = 0;
        for (int i = 0; i < 32; ++i)
        {
            if ((x & 1 && y & 1) || (~x & 1 && ~y & 1))
                ;
            else
                res++;
            x = x >> 1;
            y = y >> 1;
        }
        return res;
    }
};

// Brian Kernighan algorithm (zero counter)
// class Solution
// {
// public:
//     int hammingDistance(int x, int y)
//     {
//         int s = x ^ y, ret = 0;
//         while (s)
//         {
//             s &= s - 1;
//             ret++;
//         }
//         return ret;
//     }
// };

// solution in a project
// class Solution
// {
// public:
//     int hammingDistance(int x, int y)
//     {
//         return __builtin_popcount(x ^ y);
//     }
// };

// common solution
// class Solution
// {
// public:
//     int hammingDistance(int x, int y)
//     {
//         int s = x ^ y, ret = 0;
//         while (s)
//         {
//             ret += s & 1;
//             s >>= 1;
//         }
//         return ret;
//     }
// };