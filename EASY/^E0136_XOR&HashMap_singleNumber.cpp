// https://leetcode-cn.com/problems/single-number/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> map;
        int target = -1;
        for (auto x : nums)
        {
            if (map.find(x) != map.end())
            {
                map[x] = 2;
            }
            else
            {
                map[x] = 1;
            }
        }
        for (auto x : nums)
        {
            if (map[x] == 1)
            {
                target = x;
            }
        }
        return target;
    }
};

// XOR Bit Operation
// class Solution
// {
// public:
//     int singleNumber(vector<int> &nums)
//     {
//         int ret = 0;
//         for (auto e : nums)
//             ret ^= e;
//         return ret;
//     }
// };