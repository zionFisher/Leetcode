//
#include <cinttypes>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        for (int i = 0; i < 32; ++i)
        {
            if (n & 1)
                res++;
            n = n >> 1;
        }
        return res;
    }
};

// smart solution!
// class Solution
// {
// public:
//     int hammingWeight(uint32_t n)
//     {
//         int ret = 0;
//         while (n)
//         {
//             n &= n - 1;
//             ret++;
//         }
//         return ret;
//     }
// };