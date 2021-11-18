// https://leetcode-cn.com/problems/rotate-array/solution/xuan-zhuan-shu-zu-by-leetcode-solution-nipk/
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int length = nums.size();
        int temp[length];
        for (int i = 0; i < length; i++)
        {
            temp[i] = nums[i];
        }

        for (int i = 0; i < length; i++)
        {
            nums[(i + k) % length] = temp[i];
        }
    }
};

// gcd in <numeric> 
// class Solution
// {
// public:
//     void rotate(vector<int> &nums, int k)
//     {
//         int n = nums.size();
//         k = k % n;
//         int count = gcd(k, n);
//         for (int start = 0; start < count; ++start)
//         {
//             int current = start;
//             int prev = nums[start];
//             do
//             {
//                 int next = (current + k) % n;
//                 swap(nums[next], prev);
//                 current = next;
//             } while (start != current);
//         }
//     }
// };