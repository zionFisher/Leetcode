// https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/
#include <vector>
using namespace std;

class Solution
{
public:
    int missingNumber(vector<int>& nums)
    {
        int l = 0;
        int r = nums.size();
        int m = 0;
        while(l < r)
        {
            m = (l + r) / 2;
            if(nums[m] == m)
                l = m + 1;
            else
                r = m;
        }
        return r;
    }
};

// class Solution
// {
// public:
//     int missingNumber(vector<int>& nums)
//     {
//         int size = nums.size();
//         int sum = (1 + size) * size / 2;
//         for(int i = 0; i < size; ++i)
//             sum -= nums[i];
//         return sum;
//     }
// };