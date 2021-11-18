// https://leetcode-cn.com/problems/power-of-four/

// NiuBi solution
class Solution
{
public:
    bool isPowerOfFour(int n)
    {
        switch (n)
        {
        case 1:
            return true;
        case 4:
            return true;
        case 16:
            return true;
        case 64:
            return true;
        case 256:
            return true;
        case 1024:
            return true;
        case 4096:
            return true;
        case 16384:
            return true;
        case 65536:
            return true;
        case 262144:
            return true;
        case 1048576:
            return true;
        case 4194304:
            return true;
        case 16777216:
            return true;
        case 67108864:
            return true;
        case 268435456:
            return true;
        case 1073741824:
            return true;
        default:
            return false;
        }
        return false;
    }
};

// Bit Opreation
// class Solution
// {
// public:
//     bool isPowerOfFour(int n)
//     {
//         return n > 0 && (n & (n - 1)) == 0 && (n & 0xaaaaaaaa) == 0;
//     }
// };

// mode solution
// class Solution
// {
// public:
//     bool isPowerOfFour(int n)
//     {
//         return n > 0 && (n & (n - 1)) == 0 && n % 3 == 1;
//     }
// };